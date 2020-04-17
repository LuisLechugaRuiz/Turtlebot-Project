#include "database.h"
#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <visualization_msgs/Marker.h>
#include <turtlebot_2dnav/ROI.h>

DatabaseNode::DatabaseNode():
  nh(ros::this_node::getName())
{
  ROI_sub = n.subscribe("ros_img_processor/camera_POI", 1, &DatabaseNode::camera_transformCallback, this);
  bound_sub = n.subscribe("costmap_restrictor/match_bound", 1, &DatabaseNode::match_boundCallback, this);
  markers_pub = nh.advertise<visualization_msgs::Marker>("visualization_markers",10);
  ROI_pub = nh.advertise<turtlebot_2dnav::ROI>("ROI", 1);
  check_bound_client = n.serviceClient<turtlebot_2dnav::restrictCostmap>("costmap_restrictor/restrict");
  carrying_ROI_server = nh.advertiseService("CarryingPerson", &DatabaseNode::carrying_person_service, this);
}

void DatabaseNode::process()
{

  if(New_Point_notify)
  {
    Bound New_Bound(pointleft, pointright, color);
    //check to avoid crazy ROIs.
    if(New_Bound.too_big());

    else{

      //Four posibilities:
        //-The New Bound is already saved as ROI
        //-The New Bound is inside of the range of a candidate
        //-The New Bound  meets the requirements to be a ROI
        //-The New Bound doesnt meet the requirements to be a ROI, is saved as a candidate
      std::vector<ROI> *d = database_ptr;
      std::vector<ROI>::iterator cit_ROI;
      bool insideROI = false;
      for(cit_ROI = d->begin(); cit_ROI != d->end(); cit_ROI++)
      {
        bool cond_ROI = cit_ROI->bound.inRange(New_Bound.max_x, New_Bound.max_y, New_Bound.min_x, New_Bound.min_y);
        if(cond_ROI)
        {
            insideROI = true;
            break;
        }
      }

      bool isCandidate = false;
      if(!insideROI)
      {
        int size = candidates_ptr->size();
        //ROS_INFO("candidates size: %d", size);
        //std::vector<Bound>::iterator cit_cand;
        for(int i = 0; i < candidates_ptr->size(); i++)
        {
          bool cond_cand = candidates_ptr->at(i).inRange(New_Bound.max_x, New_Bound.max_y, New_Bound.min_x, New_Bound.min_y);
          if(cond_cand)
          {
            //CANDIDATES NOW DOESNT AUTO UPDATE TO ROI, NEED CHECK ON COSTMAP!
            candidates_ptr->at(i).expand_Bound(New_Bound);
            isCandidate = true;
            if (!candidates_ptr->at(i).checked)
            {
              if ( (candidates_ptr->at(i).size_x > candidates_ptr->at(i).size_y) && (candidates_ptr->at(i).size_x > min_size) )
              {
                //ROS_INFO("IS VERTICAL");
                candidates_ptr->at(i).vertical = true;
                candidates_ptr->at(i).checked = true;
                match_bound(candidates_ptr->at(i), i);
              }
              else if ( (candidates_ptr->at(i).size_y > candidates_ptr->at(i).size_x) && (candidates_ptr->at(i).size_y > min_size) )
              {
                //ROS_INFO("IS HORIZONTAL");
                candidates_ptr->at(i).vertical = false;
                candidates_ptr->at(i).checked = true;
                match_bound(candidates_ptr->at(i), i);
              }
              break;
            }
          }
        }
        //ROS_INFO("LEFT");
      }

      if(!insideROI && !isCandidate)
      {
        ROS_INFO("NEW CANDIDATE");
        ROS_INFO("min x: %f", New_Bound.min_x);
        ROS_INFO("min y: %f", New_Bound.min_y);
        ROS_INFO("max x: %f", New_Bound.max_x);
        ROS_INFO("max y: %f", New_Bound.max_y);
        if (New_Bound.size_x > min_size)
        {
          //ROS_INFO("IS VERTICAL");
          New_Bound.vertical = true;
          New_Bound.checked = true;
          //send the index the candidate is going to take!
          match_bound(New_Bound, candidates_ptr->size() );
        }
        else if (New_Bound.size_y > min_size)
        {
          //ROS_INFO("IS HORIZONTAL");
          New_Bound.vertical = false;
          New_Bound.checked = true;
          match_bound(New_Bound, candidates_ptr->size() );
        }
        candidates_ptr->push_back(New_Bound);
      }
    }
    New_Point_notify = false;
  }
}


void DatabaseNode::camera_transformCallback(ros_img_processor::camera_POI_msg msg)
{

  //Evaluate type of the ROI
  std::string type;
  type = msg.type;
  if(type == "R")
  {
    color = 0;
    database_ptr = &database_r;
    candidates_ptr = &candidates_r;
  }
  if(type == "E")
  {
    color = 1;
    database_ptr = &database_e;
    candidates_ptr = &candidates_e;
  }
  if(type == "P")
  {
    color = 2;
    database_ptr = &database_p;
    candidates_ptr = &candidates_p;
  }

  //Evaluate point of the ROI -> Transform from camera_frame (to robot_frame) to map_frame
  geometry_msgs::Point point_cameraframeleft;
  geometry_msgs::Point point_cameraframeright;
  point_cameraframeleft.x = msg.pointleft.z;
  point_cameraframeleft.y = -msg.pointleft.x;
  point_cameraframeleft.z = -msg.pointleft.y;
  point_cameraframeright.x =  msg.pointright.z;
  point_cameraframeright.y = -msg.pointright.x;
  point_cameraframeright.z = -msg.pointright.y;

  //sometimes a non-sense point appear in the map, probably because the actual transform is different than at the moment
  // when the camera detected it (because of the robot move), we will ask for the transform at the timestamp of the msg :D
  try{
    listener.lookupTransform("map","camera_rgb_frame", msg.Header.stamp,transform);
  }
  catch (tf::TransformException &ex) {
    ROS_ERROR("%s",ex.what());
    return;
  }

  geometry_msgs::TransformStamped stampedTransform;
  tf::transformStampedTFToMsg(transform, stampedTransform);
  tf2::doTransform(point_cameraframeleft, pointleft, stampedTransform);
  tf2::doTransform(point_cameraframeright, pointright, stampedTransform);
  New_Point_notify = true;
}

void DatabaseNode::PublishMarkers(ROI New_ROI, bool New_ROI_notify)
{
  if(New_ROI_notify)
  {
    switch(New_ROI.color)
    {
      case 0:
        markers.color.r = 1.0;
        markers.color.g = 0.0;
        markers.color.b = 0.0;
        break;
      case 1:
        markers.color.r = 0.0;
        markers.color.g = 1.0;
        markers.color.b = 0.0;
        break;
      case 2:
        markers.color.r = 0.0;
        markers.color.g = 0.0;
        markers.color.b = 1.0;
        break;
    }
    //database_ptr->at(database_size).marker_index = index;

    markers.color.a = 1.0;
    markers.scale.x = 1.0;
    markers.scale.y = 1.0;
    markers.scale.z = 1.0;
    markers.colors.push_back(markers.color);
    geometry_msgs::Point publish_point;
    publish_point.x = New_ROI.center_x;
    publish_point.y = New_ROI.center_y;
    publish_point.z = 0.15;
    markers.points.push_back(publish_point);
  }

  markers.header.frame_id = "map";
  markers.header.stamp = ros::Time::now();
  markers.scale.x = 0.2;
  markers.scale.y = 0.2;
  markers.scale.z = 0.2;
  markers.pose.orientation.w = 1;
  markers.type = visualization_msgs::Marker::SPHERE_LIST;
  markers_pub.publish(markers);


  //if(ROI_expanded)
  //{
    //markers.points.at(global_ROI.marker_index).x = global_ROI.center_x;
    //markers.points.at(global_ROI.marker_index).y = global_ROI.center_y;
  //  ROI_expanded = false;

  //  turtlebot_2dnav::ROI ROI_publish;
  //  ROI_publish.Header.stamp = ros::Time::now();
  //  ROI_publish.Header.frame_id = "Map";
  //  ROI_publish.type = type;
  //  ROI_publish.center.x = global_ROI.center_x;
  //  ROI_publish.center.y = global_ROI.center_y;
  //  ROI_publish.size_x = global_ROI.bound.size_x;
  //  ROI_publish.size_y = global_ROI.bound.size_y;
  //  ROI_publish.index = global_ROI.marker_index;
  //  ROI_publish.isnew = false;
  //  ROI_pub.publish(ROI_publish);

    //ROS_INFO("EXPANDED center");
  //}


}


void DatabaseNode::PublishROI(ROI New_ROI)
{
  turtlebot_2dnav::ROI ROI_publish;
  ROI_publish.Header.stamp = ros::Time::now();
  ROI_publish.Header.frame_id = "Map";
  std::string type;
  switch(New_ROI.color)
  {
    case 0:
      type = "R";
    break;

    case 1:
      type = "E";
    break;

    case 2:
      type = "P";
    break;
  }
  ROI_publish.type = type;
  ROI_publish.center.x = New_ROI.center_x;
  ROI_publish.center.y = New_ROI.center_y;
  ROI_publish.size_x = New_ROI.bound.size_x;
  ROI_publish.size_y = New_ROI.bound.size_y;
  ROI_publish.index = index;
  ROI_publish.isnew = true;
  ROI_pub.publish(ROI_publish);
  index++;
}

DatabaseNode::~DatabaseNode()
{
    //
}


bool DatabaseNode::Bound::inRange(float new_max_x, float new_max_y, float new_min_x, float new_min_y)
{
  float tol_y;
  float tol_x;

  if (vertical)
  {
    tol_y = 0.4;
    tol_x = 0.05;
  }
  else
  {
    tol_y = 0.05;
    tol_x = 0.4;
  }

  bool cond1;
  bool cond2;
  //cond1 = min_x - tol_x <= new_max_x && new_max_x <= max_x + tol_x;
  //cond2 = min_x - tol_x <= new_min_x && new_min_x <= max_x + tol_x;

  //bool cond3;
  //bool cond4;
  //cond3 = min_y -tol_y <= new_max_y && new_max_y <= max_y + tol_y;
  //cond4 = min_y -tol_y <= new_min_y && new_min_y <= max_y + tol_y;
  float t_min_x = std::max(min_x, new_min_x);
  float t_min_y = std::max(min_y, new_min_y);
  float t_max_x = std::min(max_x, new_max_x);
  float t_max_y = std::min(max_y, new_max_y);
  cond1 = ( (t_max_x + tol_x) > t_min_x );
  cond2 = ( (t_max_y + tol_y) > t_min_y );
  return (cond1 && cond2);
  //return ((cond1 || cond2) && (cond3 || cond4));
}

void DatabaseNode::match_bound(Bound bound_check, int can_index)
{
  turtlebot_2dnav::restrictCostmap check_;
  check_.request.Point.x = (bound_check.max_x - bound_check.min_x) / 2 + bound_check.min_x;
  ROS_INFO("Point x: %f", check_.request.Point.x);
  check_.request.Point.y = (bound_check.max_y - bound_check.min_y) / 2 + bound_check.min_y;
  ROS_INFO("Point y: %f", check_.request.Point.y);
  check_.request.index = can_index;
  check_.request.isvertical = bound_check.vertical;
  check_.request.restrict = false;
  check_.request.exit = false;
  check_.request.color = bound_check.database_color;

  if (bound_check.database_color == 0) check_.request.restrict = true;
  if (bound_check.database_color == 1)
  {
    check_.request.exit = true;
    check_.request.restrict = true;
  }
  check_bound_client.call(check_);
  //ROS_INFO("COLOR SENT: %d", check_.request.color);
}


void DatabaseNode::match_boundCallback(turtlebot_2dnav::match_bound bound_matched)
{
  //ROS_INFO("BOUND RECEIVED");
  if (bound_matched.matched)
  {
    //ROS_INFO("BOUND MATCHED");
    //ROS_INFO("COLOR RECEIVED: %d", bound_matched.color);
    Bound New_Bound(bound_matched.pointleft, bound_matched.pointright, bound_matched.color);
    ROI New_ROI(New_Bound);
    bool isnewROI = true;
    switch (bound_matched.color)
    {
      case 0:
        isnewROI = checkifisNew(database_r, New_ROI);
        if(isnewROI) database_r.push_back(New_ROI);
      break;

      case 1:
        isnewROI = checkifisNew(database_e, New_ROI);
        if(isnewROI) database_e.push_back(New_ROI);
      break;

      case 2:
        isnewROI = checkifisNew(database_p, New_ROI);
        if(isnewROI) database_p.push_back(New_ROI);
      break;
    }
    if(isnewROI)
    {
      PublishMarkers(New_ROI, true);
      PublishROI(New_ROI);
    }
    //else ROS_INFO("MATCHED TWICE");
  }
  //else ROS_INFO("BOUNT NOT MATCHED");
  int size = candidates_p.size();
  //ROS_INFO("Candidate index: %d", bound_matched.index);
  //ROS_INFO("candidates P size: %d", size );
  switch (bound_matched.color)
  {
    case 0:
      candidates_r.erase( candidates_r.begin() + bound_matched.index );
    break;
    case 1:
      candidates_e.erase( candidates_e.begin() + bound_matched.index );
    break;
    case 2:
      candidates_p.erase( candidates_p.begin() + bound_matched.index );
    break;
  }
}



bool DatabaseNode::checkifisNew(std::vector<ROI> &database, ROI New_ROI)
{
  for (auto saved_ROI : database)
  {
    if(saved_ROI.bound.inRange(New_ROI.bound.max_x, New_ROI.bound.max_y, New_ROI.bound.min_x, New_ROI.bound.min_y))
    return false;
  }
  return true;
}


bool DatabaseNode::Bound::expand_Bound(Bound New_Bound)
{
  bool expanded = false;
  float size_x_last = size_x;
  float size_y_last = size_y;
  max_x = std::max(max_x, New_Bound.max_x);
  min_x = std::min(min_x, New_Bound.min_x);
  max_y = std::max(max_y, New_Bound.max_y);
  min_y = std::min(min_y, New_Bound.min_y);
  size_x = max_x - min_x;
  size_y = max_y - min_y;
  if( ((size_y - size_y_last) > 0.05) || ((size_x - size_x_last) > 0.05))
  {
    expanded = true;
    ROS_INFO("EXPANDED CANDIDATE");
    ROS_INFO("min x: %f", min_x);
    ROS_INFO("min y: %f", min_y);
    ROS_INFO("max x: %f", max_x);
    ROS_INFO("max y: %f", max_y);
  }
  return expanded;
}

void DatabaseNode::Bound::update_size_conditions()
{

  if ( (size_x > size_y) && (size_x > min_size_small_side) )
  {
    vertical = true;
  }
  else if ( (size_y > size_x) && (size_y > min_size_small_side) )
  {
    vertical = false;
  }

  //Until one of the conditions is accomplished both side conditions should be checked. Once one of the
  // conditions meet the requirements the other axis only checks the conditions of the other side.
  //If one of the conditions is the big side the other one only can be the small but in the other candidates_e
  // it could happen that the side needs to be expanded.
  if(!size_x_cond)
  {
    if(size_x > min_size_big_side && size_x < max_size_big_side)
    {
      size_x_cond_vertical = true;
    }
    else if(size_x > min_size_small_side && size_x < max_size_small_side)
    {
      size_x_cond_horizontal = true;
    }
    else if(size_x_cond_horizontal == true)
    {
      size_x_cond_horizontal = false;
    }
  }

  if(!size_y_cond)
  {
    if(size_y > min_size_big_side && size_y < max_size_big_side)
    {
      size_y_cond_horizontal = true;
    }
    else if(size_y > min_size_small_side && size_y < max_size_small_side)
    {
      size_y_cond_vertical = true;
    }
    else if(size_y_cond_vertical == true)
    {
      size_y_cond_vertical = false;
    }
  }

  //When the bound is horizontal x is the bigger size so if the x_cond_horizontal is true is enough
  // to asure x_cond = true. In the other case check first the y_cond_vertical.
  size_x_cond = size_x_cond_vertical || (size_x_cond_horizontal && size_y_cond_horizontal);
  size_y_cond = size_y_cond_horizontal || (size_x_cond_vertical && size_y_cond_vertical);
}

bool DatabaseNode::carrying_person_service(turtlebot_2dnav::CarryingPerson::Request &req, turtlebot_2dnav::CarryingPerson::Response &res)
{
  int index = req.person.index;
  markers.colors[index].r = 1.0;
  markers.colors[index].g = 1.0;
  markers.colors[index].b = 1.0;
  markers_pub.publish(markers);
  res.received = true;
}




//We will consider that is ROI if one of the 4 conditions for the side is true but the ROI can still be expanded
// so the marker needs to be relocated.
bool DatabaseNode::Bound::isROI()
{
  update_size_conditions();
  return (size_x_cond_vertical || size_y_cond_horizontal);
}

bool DatabaseNode::Bound::too_big()
{
  return(size_x > max_size_big_side || size_y > max_size_big_side || (size_x > max_size_small_side && size_y > max_size_small_side));
}

void DatabaseNode::ROI::update_ROI()
{
  center_x = (bound.max_x - bound.min_x)/2 + bound.min_x;
  center_y = (bound.max_y - bound.min_y)/2 + bound.min_y;
}

DatabaseNode::ROI::ROI(Bound new_bound)
{
  //ROS_INFO("NEW ROI");
  bound = new_bound;
  center_x = (bound.max_x - bound.min_x)/2 + bound.min_x;
  center_y = (bound.max_y - bound.min_y)/2 + bound.min_y;
  color = bound.database_color;
}

DatabaseNode::ROI::ROI()
{

}

DatabaseNode::Bound::Bound()
{

}

DatabaseNode::Bound::Bound(geometry_msgs::Point p1, geometry_msgs::Point p2, int color_b)
{
  database_color = color_b;
  max_x = std::max(p1.x, p2.x);
  max_y = std::max(p1.y, p2.y);
  min_x = std::min(p1.x, p2.x);
  min_y = std::min(p1.y, p2.y);
  size_x = max_x - min_x;
  size_y = max_y - min_y;
  update_size_conditions();
}
