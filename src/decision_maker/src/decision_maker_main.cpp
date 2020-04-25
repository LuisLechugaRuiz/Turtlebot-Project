#include "decision_maker.h"
#include <ros/ros.h>

int main(int argc,char **argv)
{
  ros::init(argc, argv, "decision_maker");

  Decision decision;

  //Wait till all the communications are stablished
  ros::Duration(1).sleep();

  ros::Rate loopRate(10);

  ros::Time initial_time = ros::Time::now();
  
  while(!decision.process() && ros::ok())
  {
    ros::spinOnce();

    loopRate.sleep();
  }

  ros::Time final_time = ros::Time::now();

  int T_sec = final_time.sec - initial_time.sec;
  int min = (int)T_sec / 60;
  int sec = T_sec % 60;

  ROS_INFO("Total Time: ");
  ROS_INFO("Minutes: %d", min);
  ROS_INFO("Seconds: %d", sec);

  return 0;
}
