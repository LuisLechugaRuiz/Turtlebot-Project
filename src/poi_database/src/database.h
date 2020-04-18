#ifndef database_H
#define database_H

#include <ros_img_processor/camera_POI_msg.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <visualization_msgs/Marker.h>
#include <turtlebot_2dnav/ROI.h>
#include <turtlebot_2dnav/CarryingPerson.h>
#include <turtlebot_2dnav/restrictCostmap.h>
#include <turtlebot_2dnav/match_bound.h>

class DatabaseNode
{
  class Bound
  {
    public:

      float max_x;
      float max_y;
      float min_x;
      float min_y;

      float size_x;
      float size_y;

      int database_color;

      bool vertical = false;
      bool checked = false;

      //The Object can be placed horizontal or vertical into the map, 2 checks are needed for each side
      bool size_x_cond_horizontal = false;
      bool size_x_cond_vertical = false;
      bool size_y_cond_horizontal = false;
      bool size_y_cond_vertical = false;

      //In case that only the cond of the smaller side is true is possible that the size still needs to expanded
      // to assure the correct work when this happens 2 controls variable are needed
      // explained in update_size_conditions
      bool size_x_cond = false;
      bool size_y_cond = false;

        //this parameters could be set from parameters server
        float min_size_small_side = 0.3;
        float max_size_small_side = 0.4;
        float tol_small_side = 0.2;
        float min_size_big_side = 0.9;
        float max_size_big_side = 1.4;
        float tol_big_side = 0.1;


      bool too_big();
      bool inRange(float new_max_x, float new_max_y, float new_min_x, float new_min_y);
      bool expand_Bound(Bound New_Bound);
      void update_size_conditions();
      bool isROI();

      Bound();
      Bound(geometry_msgs::Point p1, geometry_msgs::Point p2, int color_b);
  };

  //wait
  class ROI
  {
    public:
      float center_x;
      float center_y;
      int marker_index;
      int color;
      Bound bound;
      //Bound ROI_Bound;
      void update_ROI();
      ROI();
      ROI(Bound new_bound);
  };

  public:
    // Constructor
    DatabaseNode();

    // Destructor
    ~DatabaseNode();

    void process();

    void PublishMarkers(ROI New_ROI);


  protected:

    ros::NodeHandle nh;
    ros::NodeHandle n;

    //Publishers
    ros::Publisher ROI_pub;
    ros::Publisher markers_pub;

    ros::ServiceServer carrying_ROI_server;
    ros::ServiceClient check_bound_client;

    //Listener
    ros::Subscriber Twist_sub;
    ros::Subscriber bound_sub;
    ros::Subscriber ROI_sub;

    tf::TransformListener listener;

    //POI recived
    ros_img_processor::camera_POI_msg POI;

    float min_size = 0.25;



    void camera_transformCallback(ros_img_processor::camera_POI_msg msg);

    bool carrying_person_service(turtlebot_2dnav::CarryingPerson::Request &req, turtlebot_2dnav::CarryingPerson::Response &res);

    void match_bound(Bound bound_check, int can_index);

    void match_boundCallback(turtlebot_2dnav::match_bound bound_matched);

    void PublishROI(ROI New_ROI);

    void PublishMarkers(geometry_msgs::Point pointleft_, geometry_msgs::Point pointright_, int color_);

    bool checkifisNew(std::vector<ROI> &database, ROI New_ROI);

    //points in the mapframe
    geometry_msgs::Point pointleft;
    geometry_msgs::Point pointright;

    geometry_msgs::PoseStamped actualPose;

    std::array<float, 4> NewLimits;

    //Determine the color
    int color;
    int index = 0;
    int index_r = 0;
    int index_e = 0;
    int index_p = 0;
    int database_size;

    std::vector<int> waiting_list;


    //Getting the transform
    tf::StampedTransform transform;

    //To advice that a new point has been referenced in the map_frame (maybe change for a method to know if the callback function triggers)
    bool New_Point_notify = false;
    bool ROI_expanded = false;

    //Params:

    //float max_width = 0.9;
    //float max_height = 0.5;



    ROI global_ROI;

    //Will need to create 3 vectors of candidates, one for each type.
    std::vector<Bound> candidates_r;
    std::vector<Bound> candidates_e;
    std::vector<Bound> candidates_p;
    std::vector<Bound> *candidates_ptr;
    std::vector<Bound> candidates_waiting_check;

    //Once the candidates accomplish the requirements a ROI is created with the Bound parameters
    std::vector<ROI> database_r;
    std::vector<ROI> database_e;
    std::vector<ROI> database_p;
    std::vector<ROI> *database_ptr;


    ROI *ROI_ptr;


    visualization_msgs::Marker markers;

};
#endif
