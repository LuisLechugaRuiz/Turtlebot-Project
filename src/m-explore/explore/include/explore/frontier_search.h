#ifndef FRONTIER_SEARCH_H_
#define FRONTIER_SEARCH_H_

#include <ros/ros.h>
#include <costmap_2d/costmap_2d.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/GetPlan.h>

namespace frontier_exploration
{
/**
 * @brief Represents a frontier
 *
 */
struct Frontier {
  std::uint32_t size;
  double min_distance;
  double cost;
  double distance_cost;
  double angle_cost;
  double size_cost;
  geometry_msgs::Point initial;
  geometry_msgs::Point centroid;
  geometry_msgs::Point middle;
  std::vector<geometry_msgs::Point> points;
};

/**
 * @brief Thread-safe implementation of a frontier-search task for an input
 * costmap.
 */
class FrontierSearch
{
public:

  FrontierSearch()
  {
  }

  std::vector<geometry_msgs::Point> frontier_blacklist_;

  /**
   * @brief Constructor for search task
   * @param costmap Reference to costmap data to search.
   */
  FrontierSearch(costmap_2d::Costmap2D* costmap, double gain_distance_,
                 double gain_angle_, double gain_size_, double min_frontier_size);

  /**
   * @brief Runs search implementation, outward from the start position
   * @param position Initial position to search from
   * @return List of frontiers, if any
   */
  std::vector<Frontier> searchFrom(geometry_msgs::Pose pose);

protected:

  bool goalOnBlacklist(geometry_msgs::Point checkFrontier);
  /**
   * @brief Starting from an initial cell, build a frontier from valid adjacent
   * cells
   * @param initial_cell Index of cell to start frontier building
   * @param reference Reference index to calculate position from
   * @param frontier_flag Flag vector indicating which cells are already marked
   * as frontiers
   * @return new frontier
   */
  Frontier buildNewFrontier(unsigned int initial_cell, unsigned int reference,
                            std::vector<bool>& frontier_flag);

  /**
   * @brief isNewFrontierCell Evaluate if candidate cell is a valid candidate
   * for a new frontier.
   * @param idx Index of candidate cell
   * @param frontier_flag Flag vector indicating which cells are already marked
   * as frontiers
   * @return true if the cell is frontier cell
   */
  bool isNewFrontierCell(unsigned int idx,
                         const std::vector<bool>& frontier_flag);

  /**
   * @brief computes frontier cost
   * @details cost function is defined by potential_scale and gain_scale
   *
   * @param frontier frontier for which compute the cost
   * @return cost of the frontier
   */
  double frontierCost(Frontier& frontier, geometry_msgs::Pose robotPose);

  double frontierAngleCost(Frontier& frontier, geometry_msgs::Pose robotPose);

  double frontierDistCost(Frontier& frontier, geometry_msgs::Pose robotPose);

  nav_msgs::Path getPlan(geometry_msgs::PoseStamped inic, geometry_msgs::PoseStamped goal);

  double getDistance(nav_msgs::Path path);

  double calculateEuclideanDistance(geometry_msgs::Point point1, geometry_msgs::Point point2);

  bool plan_sucess = true;

private:
  ros::NodeHandle n;
  ros::ServiceClient plan_client;
  costmap_2d::Costmap2D* costmap_;
  unsigned char* map_;
  unsigned int size_x_, size_y_;
  double gain_distance_, gain_size_, gain_angle_;
  double min_frontier_size_;
  nav_msgs::GetPlan plan_request;
  double fail_distance = 100000.0;
};
}
#endif
