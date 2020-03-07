#ifndef database_H
#define database_H

#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>


class Database
{
  protected:
    ros::NodeHandle nh;
    ros::NodeHandle n;

    //Publishers
    ros::Publisher Database_POI_pub;

    //Listener

    ros_img_processor::camera_POI_msg POI;

    geometry_msgs::Point map_point;

    std::vector<ros_img_processor::camera_POI_msg> database_r;
    std::vector<ros_img_processor::camera_POI_msg> database_e;
    std::vector<ros_img_processor::camera_POI_msg> database_p;


  protected:

    void camera_transformCallback(ros_img_processor::camera_POI_msg msg);

  public:

    //Suscribers
    ros::Subscriber POI_sub;

    void process();

    // Constructor
    Database();

    // Destructor
    ~Database();



};
#endif
