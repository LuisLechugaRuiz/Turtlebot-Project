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
      //received_ROIs.push_back(&database_ptr->at(index_ptr));
      //Now we got a pointer to the ith of database_p and a inital cost inside of the vector in a pair!
      if(type == "P"){
        cost_p_not_rescued.push_back(std::make_pair(database_ptr->at(index_ptr), initial_cost));
      }
    }

    //else if(!ROI_isEmpty(received_ROIs.at(New_ROI.index)))
    //{
    //  ROS_INFO("DENTRO");
    //  std::string _type = received_ROIs.at(New_ROI.index)->type;
    //  ROS_INFO("Modifying ROI type: %s", _type.c_str());
    //  ROS_INFO("Antes centro x: %f", received_ROIs.at(New_ROI.index)->center.x);
    //  ROS_INFO("Antes centro y: %f", received_ROIs.at(New_ROI.index)->center.y);
    //  received_ROIs.at(New_ROI.index)->size_x = New_ROI.size_x;
    //  received_ROIs.at(New_ROI.index)->size_y = New_ROI.size_y;
    //  received_ROIs.at(New_ROI.index)->center = New_ROI.center;
    //  ROS_INFO("Ahora centro x: %f", received_ROIs.at(New_ROI.index)->center.x);
    //  ROS_INFO("Ahora centro y: %f", received_ROIs.at(New_ROI.index)->center.y);
    //}
}

//This is the only function that sets isMoving to false
void Decision::moving_done_Callback(const actionlib::SimpleClientGoalState& state)
{
    if (state == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
      ROS_INFO("Goal reached");
      isMoving = false;
    }
}

//WORKING GOOD
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

void Decision::setGoalPose(poi_database::ROI ROI)
{
  //. o ->? pasando como referencia es un pointer o simplemente el objeto?
  goalPose.header.stamp = ros::Time::now();
  goalPose.header.frame_id = "map";
  if(ROI.size_x > ROI.size_y)
  {
    goalPose.pose.position.x = ROI.center.x;
    goalPose.pose.position.y = ROI.center.y - 1;
    goalPose.pose.orientation.z = 0.707;
    goalPose.pose.orientation.w = 0.707;
  }
  else{
    goalPose.pose.position.x = ROI.center.x - 1;
    goalPose.pose.position.y = ROI.center.y;
    goalPose.pose.orientation.w = 1;
  }
}

void Decision::setGreedyAction(bool state)
{
  greedy.greedy = state;
  acGreedy.sendGoal(greedy);
}

int Decision::getCost()
{
  cost_request.request.start = actualPose;
  cost_request.request.goal = goalPose;
  cost_client.call(cost_request);
  return cost_request.response.cost;
}

bool Decision::sortbysec(const std::pair<poi_database::ROI,int> &a, const std::pair<poi_database::ROI,int> &b)
{
    return (a.second < b.second);
}

void Decision::findNearestPerson()
{
  getActualPose();
  for(auto& pair_p_cost : cost_p_not_rescued)
  {
    setGoalPose(pair_p_cost.first);
    pair_p_cost.second = getCost();
    ROS_INFO("Dist x = %f", pair_p_cost.first.center.x - actualPose.pose.position.x);
    ROS_INFO("Dist y = %f", pair_p_cost.first.center.y - actualPose.pose.position.y);
    ROS_INFO("Cost = %d", pair_p_cost.second);
  }
  std::sort(cost_p_not_rescued.begin(), cost_p_not_rescued.end(), sortbysec);
  persons_not_rescued = cost_p_not_rescued.size();
}

void Decision::callMoveAction()
{
  goal.target_pose = goalPose;
  acMove.sendGoal(goal, boost::bind(&Decision::moving_done_Callback, this, _1));
}

bool Decision::ROI_isEmpty(poi_database::ROI* ROI)
{
  ROS_INFO("Checking if empty");
  return (ROI->size_x == 1000);
}


void Decision::process()
{
//Three states:
// searching_exit   -> Initially it would just look for the exit (moving greedy)
// rescuing         -> Once we found it start rescuing persons if there is anynone in the vector (cost_p_not_rescued)
// searching_person -> In case we already rescued anyone on the list search persons again and if one is found return to rescue state
// finished         -> If all the persons have been rescued then finish
  switch(_state)
  {
    case _state_searching_exit:
      if (database_e.size() == 0)
      {
        if(!greedy.greedy)
        {
          ROS_INFO("State 0: GOING GREEDY SEARCHING EXIT");
          setGreedyAction(true);
        }
      }
      else if (cost_p_not_rescued.size() > 0)
      {
        ROS_INFO("State 1: GOING TO RESCUE NEAREST PERSON");
        _state = _state_rescuing;
        setGreedyAction(false);
      }
      else
      {
        _state = _state_searching_person;
      }
    break;

    case _state_rescuing:
      //move to the person
      if (!isMoving && !isgoing_to_person)
      {
        //check if finished
        if(persons_rescued != number_of_persons)
        {
          //check if there is any person to rescue in the queue
          if(cost_p_not_rescued.size() > 0)
          {
            ROS_INFO("RESCUING!");
            ROS_INFO("PERSONS TO RESCUE: %d", persons_not_rescued);
            //Recalculate as new routes could be seen and cost modified
            findNearestPerson();
            setGoalPose(cost_p_not_rescued[0].first);
            ROS_INFO("ROI center MENOR x = %f", cost_p_not_rescued[0].first.center.x);
            ROS_INFO("ROI center MENOR y = %f", cost_p_not_rescued[0].first.center.y);
            ROS_INFO("Cost = %d", cost_p_not_rescued[0].second);
            callMoveAction();
            isMoving = true;
            isgoing_to_person = true;
          }
          else
          {
            ROS_INFO("State 2: GOING GREEDY SEARCHING PERSON");
            _state = _state_searching_person;
            setGreedyAction(true);
          }
        }
        else _state = _state_finished;
      }
      //if not moving and was going to the person we already reached the goal!
      else if (!isMoving && isgoing_to_person)
      {
        setGoalPose(database_e[0]);
        callMoveAction();
        //set at NULL the person at database_p
        //cost_p_not_rescued.at(0).first.size_x = 1000;
        //erase the person rescued
        cost_p_not_rescued.erase(cost_p_not_rescued.begin());
        persons_not_rescued--;
        persons_rescued++;
        isMoving = true;
        isgoing_to_person = false;
      }
    break;

    case _state_searching_person:
      if (cost_p_not_rescued.size() > 0)
      {
        _state = _state_rescuing;
        setGreedyAction(false);
      }
    break;

    case _state_finished:
      ROS_INFO("congratulations, you are a f**** beast");
      ros::Duration(10).sleep();
    break;
  }
}
