#ifndef decision_maker_H
#define decision_maker_H

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_listener.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <turtlebot_2dnav/frontier.h>
#include <turtlebot_2dnav/CarryingPerson.h>
#include <nav_msgs/GetPlan.h>
#include <nav_msgs/Path.h>
#include <data.h>
#include <math_operations.h>
#include <visualization_msgs/Marker.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

static bool sortbydistance(const person &a, const person &b);

class Decision : public Math
{
  public:

    Decision();

    bool process();

  protected:

    ros::NodeHandle nh;
    ros::NodeHandle n;

    ros::Subscriber ROI_sub;
    ros::ServiceClient plan_client;
    ros::ServiceClient carrying_person_client;
    ros::Publisher marker_carrying_person_pub;

    tf::TransformListener listener;

    MoveBaseClient acMove;

    void inicMarkerCarryingPerson();

    void updateMarker();

    void clearMarker();

    void findNearestPerson(geometry_msgs::PoseStamped inic_pose);

    void comparePersonFrontier();

    bool checkIfFrontierWorth(geometry_msgs::PoseStamped inic);

    bool isFrontier_worth(int iteration, geometry_msgs::PoseStamped inic_pose);

    bool fastUpdateFrontier();

    bool takeRisk(bool riskymode);

    void getActualPose();

    double getDistanceProb(data Frontier, geometry_msgs::PoseStamped inic_pose);

    geometry_msgs::PoseStamped getBehindPose();

    nav_msgs::Path getPlan(geometry_msgs::PoseStamped inic, geometry_msgs::PoseStamped goal);

    void explore();

    geometry_msgs::PoseStamped setPose(data target_goal);

    void callMoveAction(geometry_msgs::PoseStamped inic_pose);

    void Frontier_callBack(turtlebot_2dnav::frontier frontier);

    void ROI_callBack(turtlebot_2dnav::ROI);

    void moving_done_Callback(const actionlib::SimpleClientGoalState &state);

    void updateFrontier();

    void updatePersonsbyDistance();

  private:

    //STATES
    enum _states {_rescuing, _exploring, _waiting};
    _states _state = _exploring;
    //This copy will let us to save a temporal state until the target is reached and then change the _state
    _states _decided_state = _exploring;

    enum _directions {_person, _exit};
    //Until a person is found dont go to the exit!
    _directions _direction = _person;

    enum _exploration_modes {_searching_exit, _searching_person, _exploring_frontier};
    _exploration_modes _exploration_mode = _searching_exit;

    enum _type_decisions {_continous_decisions, _static_decisions, _send_decision};
    _type_decisions _waiting_decisions = _continous_decisions;

    ros::Time time_inic;
    ros::Time time_now;

    ros::Subscriber frontiers_sub;

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
    double dist_x_update_frontier;
    double dist_y_update_frontier;
    double fastupdate_x_dist;
    double fastupdate_y_dist;

    //SET AS A PARAMETER!.
    double tolerance = 0.2;

    std::string type;

    bool first_frontier_received = false;
    bool explore_override = false;
    bool riskymode;
    bool rescuedTargetReached = false;
    bool calculatedNew = false;
    //Start like we already reached the first frontier!
    bool frontierTargetReached = true;
    bool exit_found = false;
    bool carrying_person = false;
    bool New_Person;

    geometry_msgs::PoseStamped NewFrontier;
    geometry_msgs::PoseStamped bestFrontier;
    geometry_msgs::PoseStamped actualPose;

    turtlebot_2dnav::CarryingPerson carrying_;
    turtlebot_2dnav::ROI carrying_ROI;

    move_base_msgs::MoveBaseGoal goal;
    nav_msgs::GetPlan plan_request;

    std::vector<data> database_r;
    std::vector<data> database_e;
    std::vector<person> database_p;

    std::vector<data>* data_ptr;

    visualization_msgs::Marker marker_carrying_person;

};



#endif
