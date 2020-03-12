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

    Bound New_Bound(point1, point2);

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
      //inRange can be optimized not needing the atributes min - max
      bool cond_ROI = cit_ROI->bound->inRange(New_Bound.max_x, New_Bound.max_y, New_Bound.min_x, New_Bound.min_y);
      if(cond_ROI)
      {
          ROS_INFO("Es ROI");
          //if the bound is already a ROI tobedecided if recalculate the bound
          //expand_Bound(database_ptr->at(j), New_Bound.array);
          insideROI = true;
          break;
      }
    }

    bool isCandidate = false;
    if(!insideROI)
    {
      ROS_INFO("No es ROI");
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
              ROI New_ROI(&(*cit_cand));
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
      ROS_INFO("No es nada");
      if(New_Bound.isROI())
      {
        //use constructor of bound to build a ROI?
        ROI New_ROI(&New_Bound);
        global_ROI = New_ROI;
        database_ptr->push_back(New_ROI);
        New_ROI_notify = true;
      }
      else{
        candidates_ptr->push_back(New_Bound);
      }

      ROS_INFO("max_x = %f",New_Bound.max_x);
      ROS_INFO("max_y = %f",New_Bound.max_y);
      ROS_INFO("min_x = %f",New_Bound.min_x);
      ROS_INFO("min_y = %f",New_Bound.min_y);
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
  geometry_msgs::Point point_cameraframe1;
  geometry_msgs::Point point_cameraframe2;
  point_cameraframe1.x = msg.pointleft.z;
  point_cameraframe1.y = -msg.pointleft.x;
  point_cameraframe1.z = -msg.pointleft.y;
  point_cameraframe2.x =  msg.pointright.z;
  point_cameraframe2.y = -msg.pointright.x;
  point_cameraframe2.z = -msg.pointright.y;

  //sometimes a non-sense point appear in the map, probably because the actual transform is different than at the moment
  // when the camera detected it (because of the robot move), we will ask for the transform at the timestamp of the msg :D
  try{
    listener.lookupTransform("map","camera_rgb_frame",msg.Header.stamp,transform);
  }
  catch (tf::TransformException &ex) {
    ROS_ERROR("%s",ex.what());
    return;
  }

  geometry_msgs::TransformStamped stampedTransform;
  tf::transformStampedTFToMsg(transform, stampedTransform);
  tf2::doTransform(point_cameraframe1, point1, stampedTransform);
  tf2::doTransform(point_cameraframe2, point2, stampedTransform);

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
  cond1 = min_x < new_max_x && new_max_x < max_x;
  cond2 = min_x < new_min_x && new_min_x < max_x;

  bool cond3;
  bool cond4;
  cond3 = min_y < new_max_y && new_max_y < max_y;
  cond4 = min_y < new_min_y && new_min_y < max_y;
  return ((cond1 || cond2) && (cond3 || cond4));
}

void DatabaseNode::Bound::expand_Bound(Bound New_Bound)
{
  max_x = std::max(max_x, New_Bound.max_x);
  max_y = std::max(max_y, New_Bound.max_y);
  min_x = std::min(min_x, New_Bound.min_x);
  min_y = std::min(min_y, New_Bound.min_y);
  size_x = max_x - min_x;
  size_y = max_y - min_y;
}

bool DatabaseNode::Bound::isROI()
{
  return (size_x > 0.5 && size_y > 1);
}

DatabaseNode::ROI::ROI(Bound* new_bound)
{
  bound = new_bound;
  center_x = (bound->max_x - bound->min_x)/2 + bound->min_x;
  center_y = (bound->max_y - bound->min_y)/2 + bound->min_y;
}

DatabaseNode::ROI::ROI()
{

}

DatabaseNode::Bound::Bound(geometry_msgs::Point p1, geometry_msgs::Point p2)
{
  max_x = std::max(p1.x, p2.x);
  max_y = std::max(p1.y, p2.y);
  min_x = std::min(p1.x, p2.x);
  min_y = std::min(p1.y, p2.y);
  size_x = max_x - min_x;
  size_y = max_y - min_y;
}
