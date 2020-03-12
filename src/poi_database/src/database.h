#ifndef database_H
#define database_H

#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <visualization_msgs/Marker.h>

class DatabaseNode
{
  protected:
    ros::NodeHandle nh;
    ros::NodeHandle n;

    //Publishers
    ros::Publisher Database_ROI_pub;
    ros::Publisher markers_pub;

    //Listener
    ros::Subscriber Twist_sub;
    tf::TransformListener listener;

    //POI recived
    ros_img_processor::camera_POI_msg POI;

    //points in the mapframe
    geometry_msgs::Point point1;
    geometry_msgs::Point point2;

    std::array<float, 4> NewLimits;

    //Extract type
    std::string type;

    //Determine the color
    int color;

    //Getting the transform
    tf::StampedTransform transform;

    //To advice that a new point has been referenced in the map_frame (maybe change for a method to know if the callback function triggers)
    bool New_Point_notify = false;
    bool New_ROI_notify = false;

    //Provisional, could be removed if an optimized method is added to limit the region of each object
    // or could be set as a parameter in a yaml (in progress)
    float width = 0.6;
    float height = 1.3;

    class Bound
    {
      public:
        float max_x;
        float max_y;
        float min_x;
        float min_y;
        float size_x;
        float size_y;
        void expand_Bound(Bound New_Bound);
        bool isROI();
        bool inRange(float new_max_x, float new_max_y, float new_min_x, float new_min_y);
        Bound(geometry_msgs::Point p1, geometry_msgs::Point p2);
    };

    //wait
    class ROI
    {
      public:
        float center_x;
        float center_y;
        Bound* bound;
        //Bound ROI_Bound;
        ROI();
        ROI(Bound* new_bound);
    };

    ROI global_ROI;

    //Will need to create 3 vectors of candidates, one for each type.
    std::vector<Bound> candidates_r;
    std::vector<Bound> candidates_e;
    std::vector<Bound> candidates_p;
    std::vector<Bound> *candidates_ptr;

    //Once the candidates accomplish the requirements a ROI is created with the Bound parameters
    std::vector<ROI> database_r;
    std::vector<ROI> database_e;
    std::vector<ROI> database_p;
    std::vector<ROI> *database_ptr;

    visualization_msgs::Marker markers;



  protected:

    void camera_transformCallback(ros_img_processor::camera_POI_msg msg);

  public:

    //Suscribers
    ros::Subscriber ROI_sub;

    void process();

    void PublishMarkers();



    // Constructor
    DatabaseNode();

    // Destructor
    ~DatabaseNode();

};
#endif
