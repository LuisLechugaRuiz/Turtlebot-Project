#ifndef database_H
#define database_H

#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <visualization_msgs/Marker.h>

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

    //Extract type
    std::string type;

    //Determine the color
    int color;

    //Getting the transform
    tf::StampedTransform transform;

    //To advice that a new point has been referenced in the map_frame (maybe change for a method to know if the callback function triggers)
    bool NewPoint;
    bool already_saved;

    //Provisional, could be removed if an optimized method is added to limit the region of each object
      // or could be set as a parameter in a yaml (in progress)
      float width = 0.6;
      float height = 1.2;

    std::vector<geometry_msgs::Point> database_r;
    std::vector<geometry_msgs::Point> database_e;
    std::vector<geometry_msgs::Point> database_p;
    std::vector<geometry_msgs::Point> *database_ptr;

    visualization_msgs::Marker markers;


  protected:

    void camera_transformCallback(ros_img_processor::camera_POI_msg msg);

  public:

    //Suscribers
    ros::Subscriber POI_sub;

    void process();

    void PublishMarkers();

    // Constructor
    Database();

    // Destructor
    ~Database();



};
#endif
