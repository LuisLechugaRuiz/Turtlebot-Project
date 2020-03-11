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
    ros::Publisher Database_POI_pub;
    ros::Publisher markers_pub;

    //Listener
    ros::Subscriber Twist_sub;
    tf::TransformListener listener;

    //POI recived
    ros_img_processor::camera_POI_msg POI;

    //POI in the mapframe
    geometry_msgs::Point map_point1;
    geometry_msgs::Point map_point2;

    std::array<float, 4> NewLimits;

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
    float height = 1.3;

    class Bound
    {
      public:
        float max_x;
        float max_y;
        float min_x;
        float min_y;
        std::array<float, 4> array;
        Bound(geometry_msgs::Point p1, geometry_msgs::Point p2);
    };
//wait
    class map_POI : public Bound
    {
      //public:
    };

    //Will need to create 3 vectors of candidates, one for each type.
    std::vector<Bound> Candidates_r;
    std::vector<Bound> Candidates_e;
    std::vector<Bound> Candidates_p;
    //Once the candidates accomplish the requirements a map_POI is created with the Bound parameters
    std::vector<map_POI> database_r;
    std::vector<map_POI> database_e;
    std::vector<map_POI> database_p;
    std::vector<map_POI> *database_ptr;

    visualization_msgs::Marker markers;



  protected:

    void camera_transformCallback(ros_img_processor::camera_POI_msg msg);

  public:

    //Suscribers
    ros::Subscriber POI_sub;

    void Orderlimits(std::array<float, 4> &limits_1, std::array<float, 4> limits_2);

    bool inRange(float min_, float max_, float value_1, float value_2);

    void process();

    void PublishMarkers();



    // Constructor
    DatabaseNode();

    // Destructor
    ~DatabaseNode();



};
#endif
