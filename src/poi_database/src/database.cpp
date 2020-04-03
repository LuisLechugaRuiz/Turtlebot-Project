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
  markers_pub = nh.advertise<visualization_msgs::Marker>("visualization_markers",10);
  ROI_pub = nh.advertise<turtlebot_2dnav::ROI>("ROI", 1);
  carrying_ROI_server = nh.advertiseService("CarryingPerson", &DatabaseNode::carrying_person_service, this);
}

void DatabaseNode::process()
{

  if(New_Point_notify)
  {

    Bound New_Bound(pointleft, pointright);
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
        float p_min_x = cit_ROI->bound.min_x;
        float p_max_x = cit_ROI->bound.max_x;
        float p_min_y = cit_ROI->bound.min_y;
        float p_max_y = cit_ROI->bound.max_y;

        bool cond_ROI = cit_ROI->bound.inRange(New_Bound.max_x, New_Bound.max_y, New_Bound.min_x, New_Bound.min_y);
        if(cond_ROI)
        {
            if(!cit_ROI->bound.size_x_cond || !cit_ROI->bound.size_y_cond) ROI_expanded = cit_ROI->bound.expand_Bound(New_Bound);
            if(ROI_expanded) cit_ROI->update_ROI();
            global_ROI = *cit_ROI;
            insideROI = true;
            break;
        }
      }

      bool isCandidate = false;
      if(!insideROI)
      {
        std::vector<Bound> *c = candidates_ptr;
        std::vector<Bound>::iterator cit_cand;
        for(cit_cand = c->begin(); cit_cand != c->end(); cit_cand++)
        {
          bool cond_cand = cit_cand->inRange(New_Bound.max_x, New_Bound.max_y, New_Bound.min_x, New_Bound.min_y);
          if(cond_cand)
          {
              cit_cand->expand_Bound(New_Bound);
              isCandidate = true;
              if(cit_cand->isROI())
              {
                ROI New_ROI(*cit_cand);
                global_ROI = New_ROI;
                database_size = database_ptr->size();
                database_ptr->push_back(New_ROI);
                candidates_ptr->erase(cit_cand);
                New_ROI_notify = true;
              }
              break;
          }
        }
      }

      if(!insideROI && !isCandidate){
        if(New_Bound.isROI())
        {
          ROI New_ROI(New_Bound);
          global_ROI = New_ROI;
          database_size = database_ptr->size();
          database_ptr->push_back(New_ROI);
          New_ROI_notify = true;
        }
        else{
            candidates_ptr->push_back(New_Bound);
          }
      }
    }
    New_Point_notify = false;
  }
}


void DatabaseNode::camera_transformCallback(ros_img_processor::camera_POI_msg msg)
{

  //Evaluate type of the ROI
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

void DatabaseNode::PublishMarkers()
{
  if(New_ROI_notify)
  {
    switch(color)
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
    database_ptr->at(database_size).marker_index = index;

    markers.color.a = 1.0;
    markers.scale.x = 1.0;
    markers.scale.y = 1.0;
    markers.scale.z = 1.0;
    markers.colors.push_back(markers.color);
    geometry_msgs::Point publish_point;
    publish_point.x = global_ROI.center_x;
    publish_point.y = global_ROI.center_y;
    publish_point.z = 0.15;
    markers.points.push_back(publish_point);

    turtlebot_2dnav::ROI ROI_publish;
    ROI_publish.Header.stamp = ros::Time::now();
    ROI_publish.Header.frame_id = "Map";
    ROI_publish.type = type;
    ROI_publish.center.x = global_ROI.center_x;
    ROI_publish.center.y = global_ROI.center_y;
    ROI_publish.size_x = global_ROI.bound.size_x;
    ROI_publish.size_y = global_ROI.bound.size_y;
    ROI_publish.index = index;
    ROI_publish.isnew = true;
    ROI_pub.publish(ROI_publish);

    index++;
  }

  if(ROI_expanded)
  {
    markers.points.at(global_ROI.marker_index).x = global_ROI.center_x;
    markers.points.at(global_ROI.marker_index).y = global_ROI.center_y;
    ROI_expanded = false;

    turtlebot_2dnav::ROI ROI_publish;
    ROI_publish.Header.stamp = ros::Time::now();
    ROI_publish.Header.frame_id = "Map";
    ROI_publish.type = type;
    ROI_publish.center.x = global_ROI.center_x;
    ROI_publish.center.y = global_ROI.center_y;
    ROI_publish.size_x = global_ROI.bound.size_x;
    ROI_publish.size_y = global_ROI.bound.size_y;
    ROI_publish.index = global_ROI.marker_index;
    ROI_publish.isnew = false;
    ROI_pub.publish(ROI_publish);

    //ROS_INFO("EXPANDED center");
  }

  markers.header.frame_id = "map";
  markers.header.stamp = ros::Time::now();
  markers.scale.x = 0.2;
  markers.scale.y = 0.2;
  markers.scale.z = 0.2;
  markers.pose.orientation.w = 1;
  markers.type = visualization_msgs::Marker::SPHERE_LIST;
  markers_pub.publish(markers);

  New_ROI_notify = false;

}


DatabaseNode::~DatabaseNode()
{
    //
}


bool DatabaseNode::Bound::inRange(float new_max_x, float new_max_y, float new_min_x, float new_min_y)
{
  float tol_y = 0.08;

  float tol_x;
  if(size_x_cond) tol_x = 0.2;
  else tol_x = 0.4;

  bool cond1;
  bool cond2;
  cond1 = min_x - tol_x <= new_max_x && new_max_x <= max_x + tol_x;
  cond2 = min_x - tol_x <= new_min_x && new_min_x <= max_x + tol_x;

  bool cond3;
  bool cond4;
  cond3 = min_y -tol_y <= new_max_y && new_max_y <= max_y + tol_y;
  cond4 = min_y -tol_y <= new_min_y && new_min_y <= max_y + tol_y;
  return ((cond1 || cond2) && (cond3 || cond4));
}

bool DatabaseNode::Bound::expand_Bound(Bound New_Bound)
{
  bool expanded = false;
  if(!size_x_cond)
  {
    max_x = std::max(max_x, New_Bound.max_x);
    min_x = std::min(min_x, New_Bound.min_x);
    float size_x_last = size_x;
    size_x = max_x - min_x;
    if((size_x - size_x_last) > 0.05)
    {
      expanded = true;
    }
  }
  if(!size_y_cond)
  {
    max_y = std::max(max_y, New_Bound.max_y);
    min_y = std::min(min_y, New_Bound.min_y);
    size_y = max_y - min_y;
    float size_y_last = size_y;
    size_y = max_y - min_y;
    if((size_y - size_y_last) > 0.05)
    {
      expanded = true;
    }
  }
  update_size_conditions();
  return expanded;
}

void DatabaseNode::Bound::update_size_conditions()
{
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
  carrying_person = true;
  int index = req.person.index;
  markers.colors[index].r = 1.0;
  markers.colors[index].g = 1.0;
  markers.colors[index].b = 1.0;
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
}

DatabaseNode::ROI::ROI()
{

}

DatabaseNode::Bound::Bound()
{

}

DatabaseNode::Bound::Bound(geometry_msgs::Point p1, geometry_msgs::Point p2)
{
  //ROS_INFO("NEW BOUND");
  max_x = std::max(p1.x, p2.x);
  max_y = std::max(p1.y, p2.y);
  min_x = std::min(p1.x, p2.x);
  min_y = std::min(p1.y, p2.y);
  size_x = max_x - min_x;
  size_y = max_y - min_y;
  update_size_conditions();
}
