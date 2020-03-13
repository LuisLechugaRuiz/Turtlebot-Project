#include "database.h"
#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <visualization_msgs/Marker.h>

DatabaseNode::DatabaseNode():
  nh(ros::this_node::getName())
{
  ROI_sub = n.subscribe("ros_img_processor/camera_POI", 1, &DatabaseNode::camera_transformCallback, this);
  markers_pub = nh.advertise<visualization_msgs::Marker>("visualization_markers",10);
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
      bool insideROI = false;
      std::vector<ROI> *d = database_ptr;
      std::vector<ROI>::iterator cit_ROI;
      for(cit_ROI = d->begin(); cit_ROI != d->end(); cit_ROI++)
      {
        float p_min_x = cit_ROI->bound.min_x;
        float p_max_x = cit_ROI->bound.max_x;
        float p_min_y = cit_ROI->bound.min_y;
        float p_max_y = cit_ROI->bound.max_y;
        ROS_INFO("Dentro database ROIs");
        ROS_INFO("ROI min_x: %f", p_min_x);
        ROS_INFO("ROI max_x: %f", p_max_x);
        ROS_INFO("ROI min_y: %f", p_min_y);
        ROS_INFO("ROI max_y: %f", p_max_y);
        bool cond_ROI = cit_ROI->bound.inRange(New_Bound.max_x, New_Bound.max_y, New_Bound.min_x, New_Bound.min_y);
        if(cond_ROI)
        {
            ROS_INFO("checkeado: Es ROI");
            if(!cit_ROI->bound.size_x_cond || !cit_ROI->bound.size_y_cond) cit_ROI->bound.expand_Bound(New_Bound);
            float s_x = cit_ROI->bound.size_x;
            float s_y = cit_ROI->bound.size_y;
            ROS_INFO("Size ROI x: %f", s_x);
            ROS_INFO("Size ROI y: %f", s_y);
            //if the bound is already a ROI tobedecided if recalculate the bound
            //expand_Bound(database_ptr->at(j), New_Bound.array);
            insideROI = true;
            break;
        }
      }

      bool isCandidate = false;
      if(!insideROI)
      {
        ROS_INFO("checkeado: No es ROI, checkeando candidates");
        std::vector<Bound> *c = candidates_ptr;
        std::vector<Bound>::iterator cit_cand;
        for(cit_cand = c->begin(); cit_cand != c->end(); cit_cand++)
        {
          bool cond_cand = cit_cand->inRange(New_Bound.max_x, New_Bound.max_y, New_Bound.min_x, New_Bound.min_y);
          if(cond_cand)
          {
              ROS_INFO("checkeado: es candidate");
              cit_cand->expand_Bound(New_Bound);
              isCandidate = true;
              ROS_INFO("Bound expand: ");
              float p_cand_min_x = cit_cand->min_x;
              float p_cand_max_x = cit_cand->max_x;
              float p_cand_min_y = cit_cand->min_y;
              float p_cand_max_y = cit_cand->max_y;
              ROS_INFO("Cand min_x: %f", p_cand_min_x);
              ROS_INFO("Cand max_x: %f", p_cand_max_x);
              ROS_INFO("Cand min_y: %f", p_cand_min_y);
              ROS_INFO("Cand max_y: %f", p_cand_max_y);
              if(cit_cand->isROI())
              {
                ROI New_ROI(*cit_cand);
                global_ROI = New_ROI;
                database_ptr->push_back(New_ROI);
                candidates_ptr->erase(cit_cand);
                New_ROI_notify = true;
              }
              break;
          }
        }
      }

      if(!insideROI && !isCandidate){
        ROS_INFO("checkeado: no es ni ROI, ni candidate");
        //eliminate residual points which are bigger than the max size!
        if(New_Bound.isROI())
        {
          ROS_INFO("Nuevo ROI");
          //use constructor of bound to build a ROI?
          ROI New_ROI(New_Bound);
          global_ROI = New_ROI;
          database_ptr->push_back(New_ROI);
          New_ROI_notify = true;
        }
        else{
            ROS_INFO("Nuevo Candidate");
            ROS_INFO("Size x: %f", New_Bound.size_x);
            ROS_INFO("Size y: %f", New_Bound.size_y);
            candidates_ptr->push_back(New_Bound);
          }
        //ROS_INFO("max_x = %f",New_Bound.max_x);
        //ROS_INFO("max_y = %f",New_Bound.max_y);
        //ROS_INFO("min_x = %f",New_Bound.min_x);
        //ROS_INFO("min_y = %f",New_Bound.min_y);
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
  ROS_INFO("Type: %s", type.c_str());
  ROS_INFO("Point left x: %f", pointleft.x);
  ROS_INFO("Point left y: %f", pointleft.y);
  ROS_INFO("Point left z: %f", pointleft.z);
  ROS_INFO("Point right x: %f", pointright.x);
  ROS_INFO("Point right y: %f", pointright.y);
  ROS_INFO("Point right z: %f", pointright.z);
  int r = database_r.size();
  int p = database_p.size();
  int e = database_e.size();
  ROS_INFO("Size database_r: %d", r);
  ROS_INFO("Size database_p: %d", p);
  ROS_INFO("Size database_e: %d", e);
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
    ROS_INFO("inside");
    markers.color.a = 1.0;
    markers.colors.push_back(markers.color);
    geometry_msgs::Point publish_point;
    publish_point.x = global_ROI.center_x;
    publish_point.y = global_ROI.center_y;
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

  New_ROI_notify = false;

}

DatabaseNode::~DatabaseNode()
{
    //
}

bool DatabaseNode::Bound::inRange(float new_max_x, float new_max_y, float new_min_x, float new_min_y)
{
  bool cond1;
  bool cond2;
  cond1 = min_x - 0.1 <= new_max_x && new_max_x <= max_x + 0.1;
  cond2 = min_x - 0.1 <= new_min_x && new_min_x <= max_x + 0.1;

  bool cond3;
  bool cond4;
  cond3 = min_y -0.1 <= new_max_y && new_max_y <= max_y + 0.1;
  cond4 = min_y -0.1 <= new_min_y && new_min_y <= max_y + 0.1;
  return ((cond1 || cond2) && (cond3 || cond4));
}

void DatabaseNode::Bound::expand_Bound(Bound New_Bound)
{
  ROS_INFO("EXPAND BOUND");
  if(!size_x_cond)
  {
    max_x = std::max(max_x, New_Bound.max_x);
    min_x = std::min(min_x, New_Bound.min_x);
    size_x = max_x - min_x;
  }
  if(!size_y_cond)
  {
    max_y = std::max(max_y, New_Bound.max_y);
    min_y = std::min(min_y, New_Bound.min_y);
    size_y = max_y - min_y;
  }
}

//something not going right as the size is bigger than expected!
bool DatabaseNode::Bound::isROI()
{
  if(size_x > 0.5 && size_x < 1)
  {
    size_x_cond = true;
  }
  if(size_y > 0.8 && size_y < 1.5)
  {
    size_y_cond = true;
  }
  ROS_INFO("Condiciones ROI: ");
  ROS_INFO("Size x: %f", size_x);
  ROS_INFO("Size y: %f", size_y);

  return size_y_cond;
}

bool DatabaseNode::Bound::too_big()
{
  return(size_x > 1 || size_y > 1.5);
}

DatabaseNode::ROI::ROI(Bound new_bound)
{
  ROS_INFO("NEW ROI");
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
  ROS_INFO("NEW BOUND");
  max_x = std::max(p1.x, p2.x);
  max_y = std::max(p1.y, p2.y);
  min_x = std::min(p1.x, p2.x);
  min_y = std::min(p1.y, p2.y);
  size_x = max_x - min_x;
  size_y = max_y - min_y;
}
