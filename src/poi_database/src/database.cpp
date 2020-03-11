#include "database.h"
#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <visualization_msgs/Marker.h>



DatabaseNode::DatabaseNode():
  nh(ros::this_node::getName())
{
  POI_sub = n.subscribe("ros_img_processor/camera_POI", 1, &DatabaseNode::camera_transformCallback, this);
  markers_pub = nh.advertise<visualization_msgs::Marker>("visualization_markers",10);
}

void DatabaseNode::process()
{

  if(!NewPoint) return;
  already_saved = false;
  Bound NewBound(map_point1, map_point2);
  //lets check if the newbound is inside of an already saved once
  for(int i = 0; i<database_ptr->size(); i++)
  {
    bool cond1 = inRange(database_ptr->at(i).min_x,database_ptr->at(i).max_x, NewBound.min_x, NewBound.max_x);
    bool cond2 = (inRange(database_ptr->at(i).min_y,database_ptr->at(i).max_y, NewBound.min_y, NewBound.max_y);
    if(cond1 && cond2)
    {
        Orderlimits(database_ptr->at(i).array, NewBound.array);
    }
    else
    {
      database_ptr->push_back(Candidates);
    }
  }
  //A simple check to know if the point correspond to a saved object (a tolerance with the width of x size)
  //for(int i = 0; i<database_ptr->size(); i++)
  //{
    //if(database_ptr->at(i).x - width/2 < map_point1.x && map_point1.x  < database_ptr->at(i).x + width/2)
    //{
    //  if(database_ptr->at(i).y - height/2 < map_point1.y && map_point1.y < database_ptr->at(i).y + height/2)
    //  {
    //    already_saved = true;
    //    break;
    //  }
    //}
  //}

  if(!already_saved){
  //  database_ptr->push_back(map_point);
    //ROS_INFO("Point y %f", map_point.y);
  }

}


void DatabaseNode::camera_transformCallback(ros_img_processor::camera_POI_msg msg)
{

  //Evaluate type of the POI
  type = msg.type;
  if(type == "R")
  {
    color = 0;
    database_ptr = &database_r;
  }
  if(type == "E")
  {
    color = 1;
    database_ptr = &database_e;
  }
  if(type == "P")
  {
    color = 2;
    database_ptr = &database_p;
  }

  //Evaluate point of the POI -> Transform from camera_frame (to robot_frame) to map_frame
  geometry_msgs::Point point_cameraframe1;
  geometry_msgs::Point point_cameraframe2;
  point_cameraframe1.x = msg.pointleft.z;
  point_cameraframe1.y = -msg.pointleft.x;
  point_cameraframe1.z = -msg.pointleft.y;
  point_cameraframe2.x = msg.pointright.z;
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
  tf2::doTransform(point_cameraframe1, map_point1, stampedTransform);
  tf2::doTransform(point_cameraframe2, map_point2, stampedTransform);

  NewPoint = true;

}

void DatabaseNode::PublishMarkers()
{

  if(NewPoint && !already_saved)
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
  //  markers.color.a = 1.0;
  //  markers.colors.push_back(markers.color);
  // map_point.z = 0.15;
  //  markers.points.push_back(map_point);
  }

  markers.header.frame_id = "map";
  markers.header.stamp = ros::Time::now();
  markers.scale.x = 0.2;
  markers.scale.y = 0.2;
  markers.scale.z = 0.2;
  markers.pose.orientation.w = 1;
  markers.type = visualization_msgs::Marker::SPHERE_LIST;
  markers_pub.publish(markers);

}

DatabaseNode::~DatabaseNode()
{
    //
}

bool DatabaseNode::inRange(float min_, float max_, float value_1, float value_2)
{
  bool cond1;
  bool cond2;
  cond1 = min_ < value_1 && value_1 < max_;
  cond2 = min_ < value_2 && value_2 < max_;
  return (cond1 || cond2);
}

void DatabaseNode::Orderlimits(std::array<float, 4> &limits_1, std::array<float, 4> limits_2)
{
  limits_1[0] = std::max(limits_1[0], limits_2[0]);
  limits_1[1] = std::max(limits_1[1], limits_2[1]);
  limits_1[2] = std::min(limits_1[2], limits_2[2]);
  limits_1[3] = std::min(limits_1[3], limits_2[3]);
}

DatabaseNode::Bound::Bound(geometry_msgs::Point p1, geometry_msgs::Point p2)
{
  max_x = std::max(p1.x, p2.x);
  max_y = std::max(p1.y, p2.y);
  min_x = std::min(p1.x, p2.x);
  min_y = std::min(p1.y, p2.y);
  array = {max_x, max_y, min_x, min_y};
}
