#include "decision_maker.h"

int main(int argc,char **argv)
{
  ros::init(argc, argv, "decision_maker_node");

  Decision decision;

  //Wait till all the communications are stablished
  ros::Duration(1).sleep();

  ros::Rate loopRate(10);

  while( ros::ok() )
  {
    ros::spinOnce();

    decision.process();

    loopRate.sleep();
  }

  return 0;
}
