#include "costmap_restrictor.h"
#include <ros/ros.h>

int main(int argc,char **argv)
{
  ros::init(argc, argv, "costmap_restrictor");

  CostmapRes restrictor;
  //Wait till all the communications are stablished
  ros::Duration(1).sleep();

  ros::Rate loopRate(20);

  while( ros::ok() )
  {

    ros::spinOnce();

    loopRate.sleep();
  }
  return 0;
}
