#ifndef decision_maker_H
#define decision_maker_H

#include <ros/ros.h>
#include <poi_database/ROI.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class Decision{
  protected:

    ros::NodeHandle nh;
    ros::NodeHandle n;

    ros::Subscriber ROI_sub;

    MoveBaseClient ac;
    move_base_msgs::MoveBaseGoal goal;

    void ROI_callBack(poi_database::ROI);


  public:

    std::string type;

    bool new_roi_received = false;

    int i = 0;

    void process();
    std::vector<poi_database::ROI *> received_ROIs;
    std::vector<poi_database::ROI> database_r;
    std::vector<poi_database::ROI> database_e;
    std::vector<poi_database::ROI> database_p;
    std::vector<poi_database::ROI> *database_ptr;
    Decision();
};

#endif
