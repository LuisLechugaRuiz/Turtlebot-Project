#include <math_operations.h>
#include <ros/ros.h>

bool Math::CostSecondLower(geometry_msgs::Pose actualPose, geometry_msgs::Point bestFrontier, geometry_msgs::Point newFrontier)
{
  float actual_angle = getAngleZfromQuaternion(actualPose);
  float dist_best_x = bestFrontier.x - actualPose.position.x;
  float dist_best_y = bestFrontier.y - actualPose.position.y;
  float dist_best = getModulus(dist_best_x, dist_best_y);
  float dist_new_x = newFrontier.x - actualPose.position.x;
  float dist_new_y = newFrontier.y - actualPose.position.y;
  float dist_new = getModulus(dist_new_x, dist_new_y);
  float total_dist = dist_best + dist_new;

  float cost_bestFrontier = getCost2Vectors(actual_angle, dist_best_x, dist_best_y, dist_best, total_dist);
  float cost_NewFrontier = getCost2Vectors(actual_angle, dist_new_x, dist_new_y, dist_new, total_dist);

  return (cost_NewFrontier < cost_bestFrontier);
}

float Math::getAngleZfromQuaternion(geometry_msgs::Pose pose)
{
  float angle = std::asin(pose.orientation.z) * 2;
  return angle;
}


float Math::getModulus(float dx, float dy)
{
  return (sqrt(pow(dx,2) + pow(dy,2)));
}


float Math::getCost2Vectors(float angle, float dx, float dy, float modulus, float totaldist)
{
  //get the actual angle
  float cos_angle = ( dx * std::cos(angle) + dy * std::sin(angle) ) / modulus;
  //when the angle is bigger the cost is bigger also!
  int quadrant = (int)(abs(cos_angle) / 1.57);
  float cost_angle = (1 - abs(cos_angle)) * quadrant;
  //Cost Distance normalizated
  float cost_distance = modulus / totaldist;
  return (cost_angle + cost_distance);
}

bool Math::sameFrontier(geometry_msgs::Point frontier1, geometry_msgs::Point frontier2)
{
  return ( (frontier1.x == frontier2.x) && (frontier1.y == frontier2.y) );
}

double Math::getDistance(nav_msgs::Path path)
{
  double path_distance = 0.00;
  int size = path.poses.size();
  for(int i = 0; i < (path.poses.size() - 1); i++)
  {
    path_distance += calculateEuclideanDistance(path.poses[i].pose.position, path.poses[i+1].pose.position);
  }
  ROS_INFO("distance: %f", path_distance);
  return path_distance;
}

double Math::calculateEuclideanDistance(geometry_msgs::Point point1, geometry_msgs::Point point2)
{
  double x = abs(point2.x - point1.x);
  double y = abs(point2.y - point1.y);
  return(sqrt(pow(x,2) + pow(y,2)));
}
