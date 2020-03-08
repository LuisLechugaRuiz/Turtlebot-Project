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
}


void Database::camera_transformCallback(ros_img_processor::camera_POI_msg msg)
{
  visualization_msgs::Marker markers;
  markers.header.frame_id = "map";
  markers.header.stamp = ros::Time::now();
  markers.color.b = 1.0;
  markers.color.a = 1.0;
  markers.scale.x = 0.2;
  markers.scale.y = 0.2;
  markers.scale.z = 0.2;
  markers.pose.orientation.w = 1;
  markers.type = visualization_msgs::Marker::SPHERE_LIST;

  geometry_msgs::Point point_robotframe;
  point_robotframe.x = msg.point.z;
  point_robotframe.y = -msg.point.x;
  point_robotframe.z = -msg.point.y;
  tf::StampedTransform transform;

  try{
    listener.lookupTransform("map","base_footprint",ros::Time(0),transform);
  }
  catch (tf::TransformException &ex) {
    ROS_ERROR("%s",ex.what());
    return;
  }

  geometry_msgs::TransformStamped stampedTransform;
  tf::transformStampedTFToMsg(transform, stampedTransform);
  tf2::doTransform(point_robotframe, map_point, stampedTransform);
  map_point.z = 0.2;
  markers.points.push_back(map_point);
  markers_pub.publish(markers);
  //map_point.x() = point_robotframe.x


}

Database::~Database()
{
    //
}
