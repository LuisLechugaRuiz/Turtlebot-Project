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


class data
{
  public:
    data(poi_database::ROI ROI_);

    void updateData(poi_database::ROI ROI_);

    bool data_index_equal_to(int index_);

    float get_center_x ();

    float get_center_y ();

    bool is_vertical();

  protected:
    geometry_msgs::Point center;
    float size_x;
    float size_y;
    std::string type;
    int index;
};

class person : public data
{
  public:
    person(poi_database::ROI ROI_, int initial_cost);

    void updateData(int New_Cost);

    void updateData(bool rescued_);

    void set_rescued();

    bool get_rescued();

    int get_cost();

    int cost;
  private:

    bool rescued;
};


static bool sortbycost(const person &a, const person &b);

class Decision{
  public:

    Decision();

    bool process();

  protected:

    ros::NodeHandle nh;
    ros::NodeHandle n;

    ros::Subscriber ROI_sub;
    ros::ServiceClient cost_client;

    tf::TransformListener listener;

    MoveBaseClient acMove;
    ExploreGreedyClient acGreedy;


    void findNearestPerson();

    void getActualPose();

    int getCost();

    void setGoalPose(data target_goal);

    void setGreedyAction(bool state);

    void callMoveAction();

    void ROI_callBack(poi_database::ROI);

    void moving_done_Callback(const actionlib::SimpleClientGoalState &state);

  private:

    //STATES
    static const int _state_searching_exit = 0;
    static const int _state_rescuing = 1;
    static const int _state_searching_person = 2;
    static const int _state_finished = 3;
    int _state = 0;


    const int number_of_persons = 6;
    const int initial_cost = 10000000;
    const int rescued_cost = 100000000;
    int persons_rescued = 0;

    std::string type;

    bool isMoving = false;
    bool isgoing_to_person = false;
    bool carrying_person = false;

    geometry_msgs::PoseStamped actualPose;
    geometry_msgs::PoseStamped goalPose;

    move_base_msgs::MoveBaseGoal goal;
    explore_lite::greedyGoal greedy;
    turtlebot_2dnav::returnCost cost_request;

    std::vector<data> database_r;
    std::vector<data> database_e;
    std::vector<person> database_p;

    std::vector<data>* data_ptr;

};



#endif
