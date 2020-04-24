#include <explore/frontier_search.h>

#include <mutex>


#include <costmap_2d/cost_values.h>
#include <costmap_2d/costmap_2d.h>
#include <geometry_msgs/Point.h>

#include <explore/costmap_tools.h>

namespace frontier_exploration
{
using costmap_2d::LETHAL_OBSTACLE;
using costmap_2d::NO_INFORMATION;
using costmap_2d::FREE_SPACE;

FrontierSearch::FrontierSearch(costmap_2d::Costmap2D* costmap, double gain_distance_,
                               double gain_angle_, double gain_size_,
                               double min_frontier_size)
  : costmap_(costmap)
  , gain_distance_(gain_distance_)
  , gain_angle_(gain_angle_)
  , gain_size_(gain_size_)
  , min_frontier_size_(min_frontier_size)
{
  plan_client = _nh.serviceClient<nav_msgs::GetPlan>("move_base/GlobalPlanner/make_plan");
}

std::vector<Frontier> FrontierSearch::searchFrom(geometry_msgs::Pose pose)
{
  std::vector<Frontier> frontier_list;

  // Sanity check that robot is inside costmap bounds before searching
  unsigned int mx, my;
  if (!costmap_->worldToMap(pose.position.x, pose.position.y, mx, my)) {
    ROS_ERROR("Robot out of costmap bounds, cannot search for frontiers");
    return frontier_list;
  }

  // make sure map is consistent and locked for duration of search
  std::lock_guard<costmap_2d::Costmap2D::mutex_t> lock(*(costmap_->getMutex()));

  map_ = costmap_->getCharMap();
  size_x_ = costmap_->getSizeInCellsX();
  size_y_ = costmap_->getSizeInCellsY();

  // initialize flag arrays to keep track of visited and frontier cells
  std::vector<bool> frontier_flag(size_x_ * size_y_, false);
  std::vector<bool> visited_flag(size_x_ * size_y_, false);

  // initialize breadth first search
  std::queue<unsigned int> bfs;

  // find closest clear cell to start search
  unsigned int clear, pos = costmap_->getIndex(mx, my);
  if (nearestCell(clear, pos, FREE_SPACE, *costmap_)) {
    bfs.push(clear);
  } else {
    bfs.push(pos);
    ROS_WARN("Could not find nearby clear cell to start search");
  }
  visited_flag[bfs.front()] = true;

  while (!bfs.empty()) {
    unsigned int idx = bfs.front();
    bfs.pop();

    // iterate over 4-connected neighbourhood
    for (unsigned nbr : nhood4(idx, *costmap_)) {
      // add to queue all free, unvisited cells, use descending search in case
      // initialized on non-free cell
      if (map_[nbr] <= map_[idx] && !visited_flag[nbr]) {
        visited_flag[nbr] = true;
        bfs.push(nbr);
        // check if cell is new frontier cell (unvisited, NO_INFORMATION, free
        // neighbour)
      } else if (isNewFrontierCell(nbr, frontier_flag)) {
        frontier_flag[nbr] = true;
        Frontier new_frontier = buildNewFrontier(nbr, pos, frontier_flag);
        if (new_frontier.size * costmap_->getResolution() >=
            min_frontier_size_) {
          frontier_list.push_back(new_frontier);
        }
      }
    }
  }

  // set costs of frontiers
  for (auto& frontier : frontier_list) {
    frontier.cost = frontierCost(frontier, pose);
  }
  std::sort(
      frontier_list.begin(), frontier_list.end(),
      [](const Frontier& f1, const Frontier& f2) { return f1.cost < f2.cost; });

  return frontier_list;
}

nav_msgs::Path FrontierSearch::getPlan(geometry_msgs::PoseStamped inic, geometry_msgs::PoseStamped goal)
{
  plan_request.request.start = inic;
  plan_request.request.goal = goal ;
  plan_request.request.tolerance = 0.4;
  plan_client.call(plan_request);
  nav_msgs::Path actualPlan = plan_request.response.plan;
  if (actualPlan.poses[0].pose.position.z != 1000)
  {
    plan_sucess = true;
    return actualPlan;
  }
  else
  {
    int size;
    size = actualPlan.poses.size();
    ROS_INFO("size: %d", size);
    nav_msgs::Path Fail_path;
    Fail_path.header.stamp = ros::Time::now();
    Fail_path.header.frame_id = "map";

    geometry_msgs::PoseStamped fake_pose;
    fake_pose.header.stamp = ros::Time::now();
    fake_pose.header.frame_id = "map";
    fake_pose.pose.position.x = 0;
    fake_pose.pose.position.y = 0;
    fake_pose.pose.orientation.w = 1;
    Fail_path.poses.push_back(fake_pose);
    plan_sucess = false;
    return Fail_path;
  }
}

double FrontierSearch::getDistance(nav_msgs::Path path)
{
  double path_distance = 0.00;
  int size = path.poses.size();
  for(int i = 0; i < (path.poses.size() - 1); i++)
  {
    path_distance += calculateEuclideanDistance(path.poses[i].pose.position, path.poses[i+1].pose.position);
  }
  //ROS_INFO("distance: %f", path_distance);
  return path_distance;
}

double FrontierSearch::calculateEuclideanDistance(geometry_msgs::Point point1, geometry_msgs::Point point2)
{
  double x = abs(point2.x - point1.x);
  double y = abs(point2.y - point1.y);
  return(sqrt(pow(x,2) + pow(y,2)));
}

Frontier FrontierSearch::buildNewFrontier(unsigned int initial_cell,
                                          unsigned int reference,
                                          std::vector<bool>& frontier_flag)
{
  // initialize frontier structure
  Frontier output;
  output.centroid.x = 0;
  output.centroid.y = 0;
  output.size = 1;
  output.min_distance = std::numeric_limits<double>::infinity();

  // record initial contact point for frontier
  unsigned int ix, iy;
  costmap_->indexToCells(initial_cell, ix, iy);
  costmap_->mapToWorld(ix, iy, output.initial.x, output.initial.y);

  // push initial gridcell onto queue
  std::queue<unsigned int> bfs;
  bfs.push(initial_cell);

  // cache reference position in world coords
  unsigned int rx, ry;
  double reference_x, reference_y;
  costmap_->indexToCells(reference, rx, ry);
  costmap_->mapToWorld(rx, ry, reference_x, reference_y);


  while (!bfs.empty()) {
    unsigned int idx = bfs.front();
    bfs.pop();

    // try adding cells in 8-connected neighborhood to frontier
    for (unsigned int nbr : nhood8(idx, *costmap_)) {
      unsigned int mx, my;
      // check if neighbour is a potential frontier cell
      if (isNewFrontierCell(nbr, frontier_flag)) {
        // mark cell as frontier
        frontier_flag[nbr] = true;
        unsigned int mx, my;
        double wx, wy;
        costmap_->indexToCells(nbr, mx, my);
        costmap_->mapToWorld(mx, my, wx, wy);

        geometry_msgs::Point point;
        point.x = wx;
        point.y = wy;
        output.points.push_back(point);

        // update frontier size
        output.size++;

        // update centroid of frontier
        output.centroid.x += wx;
        output.centroid.y += wy;

        // determine frontier's distance from robot, going by closest gridcell
        // to robot
        double distance = sqrt(pow((double(reference_x) - double(wx)), 2.0) +
                               pow((double(reference_y) - double(wy)), 2.0));
        if (distance < output.min_distance) {
          output.min_distance = distance;
          output.middle.x = wx;
          output.middle.y = wy;
        }
        // add to queue for breadth first search
        bfs.push(nbr);
      }
    }
  }
  // average out frontier centroid
  output.centroid.x /= output.size;
  output.centroid.y /= output.size;

  return output;
}

bool FrontierSearch::isNewFrontierCell(unsigned int idx,
                                       const std::vector<bool>& frontier_flag)
{
  // check that cell is unknown and not already marked as frontier
  if (map_[idx] != NO_INFORMATION || frontier_flag[idx]) {
    return false;
  }

  // frontier cells should have at least one cell in 4-connected neighbourhood
  // that is free
  for (unsigned int nbr : nhood4(idx, *costmap_)) {
    if (map_[nbr] == FREE_SPACE) {
      return true;
    }
  }

  return false;
}

double FrontierSearch::frontierAngleCost(const Frontier& frontier, geometry_msgs::Pose robotPose)
{
  //get the actual angle
  double dx = frontier.centroid.x - robotPose.position.x;
  double dy = frontier.centroid.y - robotPose.position.y;
  double angle = std::asin(robotPose.orientation.z) * 2;
  //ROS_INFO("angle: %f", angle);
  double modulus = sqrt(pow(dx,2) + pow(dy,2));
  //ROS_INFO("modulus: %f", modulus);
  double cos_angle = ( dx * std::cos(angle) + dy * std::sin(angle) ) / modulus;
  //when the angle is bigger the cost is bigger also!
  //ROS_INFO("cos angle %f", cos_angle);
  double angle_dif = std::acos(cos_angle);
  double angle_cost;
  if ( (angle_dif > 0 && angle_dif < 1.57) || (angle_dif < 0 && angle_dif > 4.71238 ) ) angle_cost = 1 - cos_angle;
  if (angle_dif > 1.57 && angle < 4.71238) angle_cost = 1 + abs(cos_angle);
  //ROS_INFO("angle cost %f", angle_cost);
  return angle_cost;
}

double FrontierSearch::frontierDistCost(const Frontier& frontier, geometry_msgs::Pose robotPose)
{
  geometry_msgs::PoseStamped reference_pose;
  reference_pose.pose = robotPose;
  reference_pose.pose.orientation.w = 1;
  reference_pose.header.frame_id = "map";
  reference_pose.header.stamp = ros::Time::now();

  geometry_msgs::PoseStamped centroid_pose;
  centroid_pose.pose.position.x = frontier.centroid.x;
  centroid_pose.pose.position.y = frontier.centroid.y;
  centroid_pose.pose.orientation.w = 1;
  centroid_pose.header.frame_id = "map";
  centroid_pose.header.stamp = ros::Time::now();
  nav_msgs::Path New_Path = getPlan(reference_pose, centroid_pose);
  if (plan_sucess) return ( getDistance(New_Path) );
  //check if plan is unreachable!
  else
  {
    ROS_INFO("FAIL");
    return 100000.0;
  }
}

double FrontierSearch::frontierCost(const Frontier& frontier, geometry_msgs::Pose robotPose)
{
  float distance_cost = gain_distance_ * frontierDistCost(frontier, robotPose);
  float size_cost = gain_size_ * frontier.size * costmap_->getResolution();
  float angle_cost = gain_angle_ * frontierAngleCost(frontier, robotPose);
  return ( distance_cost + angle_cost - size_cost  );
}
}
