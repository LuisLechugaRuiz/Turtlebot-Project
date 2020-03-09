#include "database.h"
#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <visualization_msgs/Marker.h>



Database::Database():
  nh(ros::this_node::getName())
{
  POI_sub = n.subscribe("ros_img_processor/camera_POI", 1, &Database::camera_transformCallback, this);
  markers_pub = nh.advertise<visualization_msgs::Marker>("visualization_markers",10);
}

void Database::process()
{

  if(!NewPoint) return;
  already_saved = false;
  //A simple check to know if the point correspond to a saved object (a tolerance with the width of x size)
  for(int i = 0; i<database_ptr->size(); i++)
  {
    if(database_ptr->at(i).x - width/2 < map_point.x && map_point.x  < database_ptr->at(i).x + width/2)
    {
      if(database_ptr->at(i).y - height/2 < map_point.y && map_point.y < database_ptr->at(i).y + height/2)
      {
        already_saved = true;
        break;
      }
    }
  }

  if(!already_saved){
    ROS_INFO("Tipo %s", type.c_str());
    ROS_INFO("Point x %f", map_point.x);
    ROS_INFO("Point y %f", map_point.y);
    database_ptr->push_back(map_point);
    //ROS_INFO("Point y %f", map_point.y);
  }

}


void Database::camera_transformCallback(ros_img_processor::camera_POI_msg msg)
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
  geometry_msgs::Point point_robotframe;
  point_robotframe.x = msg.point.z;
  point_robotframe.y = -msg.point.x;
  point_robotframe.z = -msg.point.y;
  point_robotframe.z = 0;
  //sometimes a non-sense point appear in the map, probably because the actual transform is different than at the moment
  // when the camera detected it (because of the robot move), we will ask for the transform at the timestamp of the msg :D
  try{
    listener.lookupTransform("map","base_link",msg.Header.stamp,transform);
  }
  catch (tf::TransformException &ex) {
    ROS_ERROR("%s",ex.what());
    return;
  }

  geometry_msgs::TransformStamped stampedTransform;
  tf::transformStampedTFToMsg(transform, stampedTransform);
  tf2::doTransform(point_robotframe, map_point, stampedTransform);
  NewPoint = true;

}

void Database::PublishMarkers()
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
    markers.color.a = 1.0;
    markers.colors.push_back(markers.color);
    map_point.z = 0.15;
    markers.points.push_back(map_point);
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

Database::~Database()
{
    //
}
