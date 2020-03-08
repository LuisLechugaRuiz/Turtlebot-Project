#ifndef database_H
#define database_H

#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>


class Database
{
  protected:
    ros::NodeHandle nh;
    ros::NodeHandle n;

    //Publishers
    ros::Publisher Database_POI_pub;
    ros::Publisher markers_pub;

    //Listener
    tf::TransformListener listener;

    //POI recived
    ros_img_processor::camera_POI_msg POI;

    //POI in the mapframe
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
