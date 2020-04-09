#include <ros/ros.h>
#include <turtlebot_2dnav/fake_bound.h>
#include <turtlebot_2dnav/fakeLaser.h>
#include <turtlebot_2dnav/bounds_point_size.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <tf/transform_broadcaster.h>


class fake_laser
{
  public:
    fake_laser();
    void PublishCloud();

  private:
  ros::NodeHandle n;
  ros::NodeHandle nh;
  ros::Publisher laser_pub;
  ros::Publisher bounds_list_pub;
  ros::Subscriber bounds_sub;
  ros::ServiceServer active_srv;

  tf::TransformBroadcaster broadcaster;

  bool ON = true;

  double resolution = 0.095;
  std::vector<int> bounds;
  pcl::PointCloud<pcl::PointXYZ> Cloud;
  pcl::PointCloud<pcl::PointXYZ> exitCloud;

  turtlebot_2dnav::fake_bound New_Bound;
  turtlebot_2dnav::bounds_point_size p_size;
  void boundsCallback(turtlebot_2dnav::fake_bound bound);
  int insertPoints(geometry_msgs::Point pmin, geometry_msgs::Point pmax, int points_index, bool vertical, bool exitbool);
  bool active_service(turtlebot_2dnav::fakeLaser::Request &req, turtlebot_2dnav::fakeLaser::Response &res);
  void deleteBound(int first_index, int last_index, int bound_index);
  void updateBoundlist( int vector_index, int total_new_points);
};
