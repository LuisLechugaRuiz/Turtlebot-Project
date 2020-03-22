#include <ros/ros.h>
#include <poi_database/ROI.h>
#include "decision_maker.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <explore_lite/greedyAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_listener.h>
#include <turtlebot_2dnav/returnCost.h>

Decision::Decision():
  nh(ros::this_node::getName()),
  acMove("move_base", true),
  acGreedy("explore_greedy", false)
{
  ROI_sub = n.subscribe("POI_database_node/ROI", 1, &Decision::ROI_callBack, this);
  cost_client = n.serviceClient<turtlebot_2dnav::returnCost>("move_base/GlobalPlanner/return_cost");
}

void Decision::ROI_callBack(poi_database::ROI New_ROI)
{
    geometry_msgs::Point Nuevo;
    if(New_ROI.isnew)
    {
      type = New_ROI.type;
      if(type == "R") database_ptr = &database_r;
      if(type == "E") database_ptr = &database_e;
      if(type == "P") database_ptr = &database_p;
      int index_ptr = database_ptr->size();
      database_ptr->push_back(New_ROI);
      received_ROIs.push_back(&database_ptr->at(index_ptr));
      new_roi_received = true;
    }
    else
    {
      received_ROIs.at(New_ROI.index)->size_x = New_ROI.size_x;
      received_ROIs.at(New_ROI.index)->size_y = New_ROI.size_y;
      received_ROIs.at(New_ROI.index)->center = New_ROI.center;
    }
}

void Decision::doneCb(const actionlib::SimpleClientGoalState& state)
{
    if (state == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
      ROS_INFO("Goal reached");
      isMoving = false;
    }
}

void Decision::getActualPose()
{
  tf::StampedTransform transform;
  listener.lookupTransform("/map","/base_link",ros::Time(0), transform);
  actualPose.header.stamp = ros::Time::now();
  actualPose.header.frame_id = "map";
  actualPose.pose.position.x = transform.getOrigin().x();
  actualPose.pose.position.y = transform.getOrigin().y();
  actualPose.pose.position.z = transform.getOrigin().z();
  actualPose.pose.orientation.x = transform.getRotation().x();
  actualPose.pose.orientation.y = transform.getRotation().y();
  actualPose.pose.orientation.z = transform.getRotation().z();
  actualPose.pose.orientation.w = transform.getRotation().w();
}

void Decision::setGoalPose(float posx, float posy, float orientationz, float orientationw)
{
  goalPose.header.stamp = ros::Time::now();
  goalPose.header.frame_id = "map";
  goalPose.pose.position.x = posx;
  goalPose.pose.position.y = posy;
  goalPose.pose.orientation.z = orientationz;
  goalPose.pose.orientation.w = orientationw;
}

void Decision::process()
{

  if (i < received_ROIs.size() && !isMoving)
  {
    //Set Greedy to false so we can control the move action
    if(greedy.greedy)
    {
      ROS_INFO("Greedy False");
      greedy.greedy = false;
      acGreedy.sendGoal(greedy);
    }

    getActualPose();

    //if is in vertical position rotate the final orientation to look frontly the ROI
    if(received_ROIs.at(i)->size_x > received_ROIs.at(i)->size_y)
    {

      setGoalPose(received_ROIs.at(i)->center.x, received_ROIs.at(i)->center.y - 1, 0.707, 0.707);
    }
    else
    {
      setGoalPose(received_ROIs.at(i)->center.x - 1, received_ROIs.at(i)->center.y, 0, 1);
    }

    cost_request.request.start = actualPose;
    cost_request.request.goal = goalPose;
    goal.target_pose = goalPose;
    cost_client.call(cost_request);

    //prueba
    int cost = cost_request.response.cost;
    std::string type2 = received_ROIs.at(i)->type;
    ROS_INFO("Moving to type: %s", type2.c_str());
    ROS_INFO("Pos x: %f", received_ROIs.at(i)->center.x);
    ROS_INFO("Pos y: %f", received_ROIs.at(i)->center.y);
    ROS_INFO("cost : %d", cost);

    acMove.sendGoal(goal, boost::bind(&Decision::doneCb, this, _1));
    isMoving = true;
    i++;
  }

  else if(!isMoving)
  {
    if(!greedy.greedy)
    {
      ROS_INFO("Greedy");
      greedy.greedy = true;
      acGreedy.sendGoal(greedy);
    }
  }
}
