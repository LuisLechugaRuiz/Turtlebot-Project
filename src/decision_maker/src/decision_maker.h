#ifndef decision_maker_H
#define decision_maker_H

#include <ros/ros.h>
#include <poi_database/ROI.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <explore_lite/greedyAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_listener.h>
#include <turtlebot_2dnav/returnCost.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef actionlib::SimpleActionClient<explore_lite::greedyAction> ExploreGreedyClient;

class Decision{
  public:

    Decision();

    void process();

  protected:

    ros::NodeHandle nh;
    ros::NodeHandle n;

    ros::Subscriber ROI_sub;
    ros::ServiceClient cost_client;

    tf::TransformListener listener;

    MoveBaseClient acMove;
    ExploreGreedyClient acGreedy;

    static bool sortbysec(const std::pair<poi_database::ROI,int> &a, const std::pair<poi_database::ROI,int> &b);

    bool ROI_isEmpty(poi_database::ROI* ROI);

    void findNearestPerson();

    void getActualPose();

    int getCost();

    void setGoalPose(poi_database::ROI ROI);

    void setGreedyAction(bool state);

    void callMoveAction();

    void ROI_callBack(poi_database::ROI);

    void moving_done_Callback(const actionlib::SimpleClientGoalState& state);

  private:

    //STATES
    static const int _state_searching_exit = 0;
    static const int _state_rescuing = 1;
    static const int _state_searching_person = 2;
    static const int _state_finished = 3;
    int _state = 0;


    const int number_of_persons = 5;
    const int initial_cost = 1000000000;
    int persons_not_rescued = 0;
    int persons_rescued = 0;

    std::string type;

    bool isMoving = false;
    bool isgoing_to_person = false;

    geometry_msgs::PoseStamped actualPose;
    geometry_msgs::PoseStamped goalPose;

    move_base_msgs::MoveBaseGoal goal;
    explore_lite::greedyGoal greedy;
    turtlebot_2dnav::returnCost cost_request;

    std::vector<poi_database::ROI> database_r;
    std::vector<poi_database::ROI> database_e;
    std::vector<poi_database::ROI> database_p;
    std::vector<poi_database::ROI> *database_ptr;
    std::vector<poi_database::ROI*> received_ROIs;
    std::vector<std::pair<poi_database::ROI,int>> cost_p_not_rescued;
    //std::vector<poi_database::ROI> already_rescued_person;


};

#endif
