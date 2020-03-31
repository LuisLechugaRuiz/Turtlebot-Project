#ifndef decision_maker_H
#define decision_maker_H

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_listener.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <turtlebot_2dnav/greedyAction.h>
#include <turtlebot_2dnav/returnCost.h>
#include <nav_msgs/GetPlan.h>
#include <nav_msgs/Path.h>
#include <data.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef actionlib::SimpleActionClient<turtlebot_2dnav::greedyAction> ExploreGreedyClient;

static bool sortbydistances(const person &a, const person &b);

class Decision{
  public:

    Decision();

    bool process();

  protected:

    ros::NodeHandle nh;
    ros::NodeHandle n;

    ros::Subscriber ROI_sub;
    ros::ServiceClient plan_client;

    tf::TransformListener listener;

    MoveBaseClient acMove;
    ExploreGreedyClient acGreedy;


    void findNearestPerson();

    void comparePersonFrontier();

    bool isFrontier_worth(int iteration);

    double calculateEuclideanDistance(geometry_msgs::Point point1, geometry_msgs::Point point2);

    bool takeRisk(bool riskymode);

    void getActualPose();

    double getDistance(nav_msgs::Path path);

    double getDistanceProb(data Frontier);

    void getGreedyresult(const actionlib::SimpleClientGoalState& state,
                         const turtlebot_2dnav::greedyResultConstPtr& result);

    nav_msgs::Path getPlan();

    void setGoalPose(data target_goal);

    void setGreedyAction(bool greedyState, bool greedyReturn);

    void callMoveAction();

    void ROI_callBack(poi_database::ROI);

    void moving_done_Callback(const actionlib::SimpleClientGoalState &state);

  private:

    //STATES
    enum _states {_searching_exit, _rescuing, _exploring, _searching_person, _finished};
    _states _state = _searching_exit;

    enum _directions {_wait, _person, _exit};
    _directions _direction = _wait;

    enum _exploration_modes {_starting, _moving, _stopped};
    _exploration_modes _exploration_mode = _starting;

    ros::Time time_inic;
    ros::Time time_now;

    int total_time_min, total_time_sec, total_time;

    int number_of_persons = 6;
    int persons_rescued = 0;
    int persons_found = 0;

    int points_exit, points_danger, points_person;
    int points_person_rescued_half_time;
    int points_person_rescued_full_time;

    int number_of_frontiers = 0;
    int exploring_iteration = 0;

    double initial_distance = 10000.00;
    double rescued_distance = 100000.00;
    double frontier_distance = 10000.00;

    //SET AS A PARAMETER!.
    double tolerance = 0.2;

    std::string type;

    bool riskymode;
    bool isMoving = false;
    bool isgoing_to_person = false;
    bool carrying_person = false;

    geometry_msgs::PoseStamped actualPose;
    geometry_msgs::PoseStamped goalPose;
    geometry_msgs::PoseStamped bestFrontier;

    move_base_msgs::MoveBaseGoal goal;
    turtlebot_2dnav::greedyGoal greedy;
    nav_msgs::GetPlan plan_request;

    std::vector<data> database_r;
    std::vector<data> database_e;
    std::vector<person> database_p;

    std::vector<data>* data_ptr;

};



#endif
