#include <costmap_2d/costmap_2d.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/OccupancyGrid.h>
#include <turtlebot_2dnav/restrictCostmap.h>
#include <turtlebot_2dnav/fake_bound.h>
#include <ros/ros.h>



class CostmapRes
{
  public:
    CostmapRes();

  private:
    ros::NodeHandle nh;
    ros::NodeHandle n;
    ros::Subscriber costmap_sub_;
    ros::ServiceServer restrict_server;
    ros::Publisher bound_pub;


    struct Bound
    {
      geometry_msgs::Point point_left_min;
      geometry_msgs::Point point_right_min;
      geometry_msgs::Point point_left_max;
      geometry_msgs::Point point_right_max;
      bool vertical;
      bool recalculateleft;
      bool recalculateright;
      int count = 0;
      int index = -1;
    };



    bool RestrictService(turtlebot_2dnav::restrictCostmap::Request &req,
                                turtlebot_2dnav::restrictCostmap::Response &res);
    unsigned int getIndex(geometry_msgs::Point point);
    geometry_msgs::Point indexToCostmap(unsigned int index);
    geometry_msgs::Point CostmapToMap(geometry_msgs::Point point);
    geometry_msgs::Point MapToCostmap(geometry_msgs::Point point);
    void ProcessCostmap(const nav_msgs::OccupancyGrid::ConstPtr& msg);


    Bound restringed_zone;
    std::vector<Bound> queue;
    turtlebot_2dnav::fake_bound bound_;

    geometry_msgs::Point pleft;
    geometry_msgs::Point pright;

    unsigned int index_left;
    unsigned int index_right;
    int acum_left;
    int acum_right;
    unsigned char value;

    int index = 0;

    bool NewRestriction;
    unsigned int size_in_cells_x;
    unsigned int size_in_cells_y;
    double resolution;
    double origin_x;
    double origin_y;
    unsigned char* costmap_data;

    // special values:
    unsigned char NO_OBSTACLE = 0; // NO obstacle
    unsigned char INSCRIBED_OBSTACLE = 99;   // INSCRIBED obstacle
    unsigned char LETHAL_OBSTACLE = 100;  // LETHAL obstacle
    unsigned char UNKNOWN = static_cast<unsigned char>(-1);  // UNKNOWN

};
