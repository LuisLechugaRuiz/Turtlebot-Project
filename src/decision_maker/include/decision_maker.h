#ifndef decision_maker_H
#define decision_maker_H

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_listener.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/PoseStamped.h>
#include <turtlebot_2dnav/frontier.h>
#include <turtlebot_2dnav/CarryingPerson.h>
#include <turtlebot_2dnav/askNewFrontier.h>
#include <turtlebot_2dnav/fake_bound.h>
#include <turtlebot_2dnav/fakeLaser.h>
#include <turtlebot_2dnav/recalculateBound.h>
#include <nav_msgs/GetPlan.h>
#include <nav_msgs/Path.h>
#include <data.h>
#include <math_operations.h>
#include <visualization_msgs/Marker.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <costmap_2d/clearCostmap.h>

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
    ros::ServiceClient ask_new_frontier_client;
    ros::ServiceClient fake_laser_client;
    ros::ServiceClient clear_costmap_client;
    ros::ServiceClient recalculate_bound_client;
    ros::Publisher marker_carrying_person_pub;
    ros::Publisher fake_bound_pub;

    tf::TransformListener listener;

    MoveBaseClient acMove;

    void inicMarkerCarryingPerson();

    void updateMarker();

    void clearMarker();

    void findNearestPerson(geometry_msgs::PoseStamped inic_pose);

    void comparePersonFrontier();

    bool checkIfFrontierWorth(geometry_msgs::PoseStamped inic);

    bool checkIfStuck();

    bool isFrontier_worth(int iteration, geometry_msgs::PoseStamped inic_pose);

    bool takeRisk(bool riskymode);

    bool riskyDecision();

    void getActualPose();

    void inflationWall(data New_red_wall);

    double getDistanceProb(data Frontier, geometry_msgs::PoseStamped inic_pose);

    geometry_msgs::PoseStamped getBehindPose();

    nav_msgs::Path getPlan(geometry_msgs::PoseStamped inic, geometry_msgs::PoseStamped goal);

    void explore();

    geometry_msgs::PoseStamped setPose(data target_goal, bool frontier);

    void callMoveAction(geometry_msgs::PoseStamped inic_pose);

    void Frontier_callBack(turtlebot_2dnav::frontier frontier);

    void ROI_callBack(turtlebot_2dnav::ROI);

    void moving_done_Callback(const actionlib::SimpleClientGoalState &state);

    void updateFrontier();

    void updatePersonsbyDistance();

    void restrictCostmap(data New_data, bool exitbool);

    void fakeLaserActive(bool on);

    void recovery();

  private:

    //STATES
    enum _states {_rescuing, _exploring, _waiting};
    _states _state = _exploring;
    //This copy will let us to save a temporal state until the target is reached and then change the _state
    _states _decided_state = _exploring;

    enum _directions {_person, _exit, _frontier};
    //Until a person is found dont go to the exit!
    _directions _direction = _person;

    enum _exploration_modes {_searching_exit, _searching_person, _exploring_frontier};
    _exploration_modes _exploration_mode = _searching_exit;

    enum _type_decisions {_continous_decisions, _static_decisions};
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

    //SET AS A PARAMETER!.
    double tolerance = 0.2;

    std::string type;

    bool first_frontier_received = false;
    bool explore_override = false;
    bool riskymode;
    bool rescuedTargetReached = false;
    //Start like we already reached the first frontier!
    bool frontierTargetReached = true;
    bool exit_found = false;
    bool carrying_person = false;
    bool New_Person = false;
    bool stuck = false;

    geometry_msgs::PoseStamped NewFrontier;
    geometry_msgs::PoseStamped bestFrontier;
    geometry_msgs::PoseStamped actualPose;
    geometry_msgs::PoseStamped bestPerson;
    geometry_msgs::PoseStamped exitPosition;
    geometry_msgs::Pose prev_pose;

    turtlebot_2dnav::CarryingPerson carrying_;
    turtlebot_2dnav::ROI carrying_ROI;
    turtlebot_2dnav::askNewFrontier askNew_;
    turtlebot_2dnav::fakeLaser fakeLaser_;
    turtlebot_2dnav::recalculateBound recalculate_;
    costmap_2d::clearCostmap clearCostmap_;

    move_base_msgs::MoveBaseGoal goal;
    nav_msgs::GetPlan plan_request;

    std::vector<data> database_r;
    std::vector<data> database_e;
    std::vector<person> database_p;

    std::vector<data>* data_ptr;

    visualization_msgs::Marker marker_carrying_person;

    unsigned int stuck_time = 0;
    int move_timeout = 2;

    int points = 0;

    int index_fake = 0;
};



#endif
