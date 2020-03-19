#include <ros/ros.h>
#include <poi_database/ROI.h>
#include "decision_maker.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

Decision::Decision():
  nh(ros::this_node::getName()),ac("move_base", true)
  {
    ROI_sub = n.subscribe("POI_database_node/ROI", 1, &Decision::ROI_callBack, this);
  }

  //while(!ac.waitForServer(ros::Duration(5.0))){
  //ROS_INFO("Waiting for the move_base action server to come up");
  //}


void Decision::ROI_callBack(poi_database::ROI New_ROI){
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

void Decision::process(){
  //Try to move in order to every ROI received
  ROS_INFO("i:  %d", i);
  int size = received_ROIs.size();
  ROS_INFO("ROI size: %d", size);
  //CARE if the plan is not finished the state doesnt return succeded so the execution blocks
  if ((i == 0 && new_roi_received) || (i < received_ROIs.size() && ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED))
  {
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.header.frame_id = "map";
    //if is in vertical position
    if(received_ROIs.at(i)->size_x > received_ROIs.at(i)->size_y)
    {
      goal.target_pose.pose.position.x = received_ROIs.at(i)->center.x;
      goal.target_pose.pose.position.y = received_ROIs.at(i)->center.y - 1;
      goal.target_pose.pose.orientation.w = 0.707;
      goal.target_pose.pose.orientation.z = 0.707;
    }
    else
    {
      goal.target_pose.pose.position.x = received_ROIs.at(i)->center.x - 1;
      goal.target_pose.pose.position.y = received_ROIs.at(i)->center.y;
      goal.target_pose.pose.orientation.w = 1;
    }
    std::string type2 = received_ROIs.at(i)->type;
    ROS_INFO("Moving to type: %s", type2.c_str());
    ROS_INFO("Pos x: %f", received_ROIs.at(i)->center.x);
    ROS_INFO("Pos y: %f", received_ROIs.at(i)->center.y);
    ac.sendGoal(goal);
    i++;
  }

}
