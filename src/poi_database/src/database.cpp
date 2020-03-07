#include "database.h"
#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>


Database::Database() :
    nh(ros::this_node::getName())
{

POI_sub = nh.subscribe("camera_POI", 1, &Database::camera_transformCallback, this);

}

void Database::process()
{
}


void Database::camera_transformCallback(ros_img_processor::camera_POI_msg msg)
{


}

Database::~Database()
{
    //
}
