#include <nav_msgs/Path.h>

class Math
{
  protected:
    double getDistance(nav_msgs::Path path);
    double calculateEuclideanDistance(geometry_msgs::Point point1, geometry_msgs::Point point2);
    bool CostSecondLower(geometry_msgs::Pose actual, geometry_msgs::Point bestFrontier, geometry_msgs::Point newFrontier);
    float getAngleZfromQuaternion(geometry_msgs::Pose pose);
    float getCost2Vectors(float angle, float dx, float dy, float modulus, float totaldist);
    bool sameFrontier(geometry_msgs::Point frontier1, geometry_msgs::Point frontier2);
    float getModulus(float dx, float dy);

};
