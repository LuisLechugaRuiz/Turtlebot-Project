#include <ros/ros.h>
#include <turtlebot_2dnav/fake_bound.h>
#include <turtlebot_2dnav/fakeLaser.h>
#include <turtlebot_2dnav/bounds_point_size.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <tf/transform_broadcaster.h>
#include <visualization_msgs/Marker.h>

class fake_laser
{
  public:
    fake_laser();
    void Processqueue();
    void PublishCloud();

  private:
  ros::NodeHandle n;
  ros::NodeHandle nh;
  ros::Publisher laser_pub;
  ros::Publisher bounds_list_pub;
  ros::Publisher markers_pub;
  ros::Subscriber bounds_sub;
  ros::ServiceServer active_srv;

  tf::TransformBroadcaster broadcaster;

  bool ON = true;
  bool update_marker = false;
  bool update_exit = false;
  int index_exit = -1;

  double resolution = 0.095;
  std::vector<double> bounds;
  pcl::PointCloud<pcl::PointXYZ> Cloud;
  pcl::PointCloud<pcl::PointXYZ> exitCloud;

  std::vector<turtlebot_2dnav::fake_bound> queue;
  std::vector<geometry_msgs::Point> markers_points;
  std::vector<geometry_msgs::Point> markers_exit;
  visualization_msgs::Marker markers;

  turtlebot_2dnav::bounds_point_size p_size;
  void boundsCallback(turtlebot_2dnav::fake_bound bound);
  int insertPoints(geometry_msgs::Point pmin, geometry_msgs::Point pmax, int points_index, bool vertical, bool left, bool exitbool);
  bool active_service(turtlebot_2dnav::fakeLaser::Request &req, turtlebot_2dnav::fakeLaser::Response &res);
  void deleteBound(int first_index, int last_index, int bound_index, bool exitbool);
  void updateBoundlist( int vector_index, int total_new_points);
  void updateMarker(int bound_index, bool exitbool, bool resize,
                    geometry_msgs::Point pointleftmin_,
                    geometry_msgs::Point pointleftmax_,
                    geometry_msgs::Point pointrightmin_,
                    geometry_msgs::Point pointrightmax_);
};
