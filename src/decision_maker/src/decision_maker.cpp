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
    type = New_ROI.type;
    if(type == "R") data_ptr = &database_r;
    if(type == "E") data_ptr = &database_e;

    if(New_ROI.isnew)
    {
      if(type == "P")
      {
        person New_Person(New_ROI, initial_cost);
        database_p.push_back(New_Person);
      }
      else
      {
        data New_data(New_ROI);
        data_ptr->push_back(New_data);
      }
    }

    else
    {
      if(type == "P"){
        for(data data_p_ : database_p)
        {
          if(data_p_.data_index_equal_to(New_ROI.index)) data_p_.updateData(New_ROI);
        }
      }
      else
      {
        for(auto& data_ : *data_ptr)
        {
          if(data_.data_index_equal_to(New_ROI.index)) data_.updateData(New_ROI);
        }
      }
    }
  }

//This is the only function that sets isMoving to false
void Decision::moving_done_Callback(const actionlib::SimpleClientGoalState& state)
{
    if (state == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
      isMoving = false;
      if(carrying_person) ROS_INFO("LEFT AT EXIT. PERSON: %d", persons_rescued);
      else ROS_INFO("CARRYING PERSON");
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


void Decision::setGoalPose(data target_goal)
{
  goalPose.header.stamp = ros::Time::now();
  goalPose.header.frame_id = "map";
  if(target_goal.is_vertical())
  {
    goalPose.pose.position.x = target_goal.get_center_x();
    goalPose.pose.position.y = target_goal.get_center_y() - 1;
    goalPose.pose.orientation.z = 0.707;
    goalPose.pose.orientation.w = 0.707;
  }
  else
  {
    goalPose.pose.position.x = target_goal.get_center_x() - 1;
    goalPose.pose.position.y = target_goal.get_center_y();
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

static bool sortbycost(const person &a, const person &b)
{
    return (a.cost < b.cost);
}

void Decision::findNearestPerson()
{
  getActualPose();
  for(auto& person_ : database_p)
  {
    //Only update the cost if the person is not rescued, else the cost will be standar
    if(person_.get_rescued() == false)
    {
      setGoalPose(person_);
      person_.updateData(getCost());
    }
  }
  std::sort(database_p.begin(), database_p.end(), sortbycost);
}

void Decision::callMoveAction()
{
  goal.target_pose = goalPose;
  acMove.sendGoal(goal, boost::bind(&Decision::moving_done_Callback, this, _1));
}

data::data(poi_database::ROI ROI_)
{
  updateData(ROI_);
}

person::person(poi_database::ROI ROI_, int initial_cost_) : data::data(ROI_)
{
  updateData(initial_cost_);
  updateData(false);
}

void data::updateData(poi_database::ROI ROI_)
{
  center = ROI_.center;
  type   = ROI_.type;
  size_x = ROI_.size_x;
  size_y = ROI_.size_y;
  index  = ROI_.index;
}

bool data::data_index_equal_to(int index_)
{
  return (index == index_);
}

bool data::is_vertical()
{
  return (size_x > size_y);
}

float data::get_center_x()
{
  return center.x;
}

float data::get_center_y()
{
  return center.y;
}

void person::updateData(int New_cost)
{
  cost = New_cost;
}

void person::updateData(bool rescued_)
{
  rescued = rescued_;
}

int person::get_cost()
{
  return cost;
}

bool person::get_rescued()
{
  return rescued;
}

void person::set_rescued()
{
  updateData(true);
}

bool Decision::process()
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
        if(database_p.size() > 0 && !carrying_person)
        {
          ROS_INFO("State 1: GOING TO RESCUE NEAREST PERSON");
          _state = _state_rescuing;
          setGreedyAction(false);
        }
      }
      else if (database_p.size() > 0)
      {
        ROS_INFO("State 1: GOING TO RESCUE NEAREST PERSON");
        _state = _state_rescuing;
        setGreedyAction(false);
      }
      else
      {
        ROS_INFO("State 1: GOING GREEDY SEARCHING PERSON");
        _state = _state_searching_person;
      }
    break;

    case _state_rescuing:
      //move to the person
      if (!isMoving && !isgoing_to_person)
      {
        if(persons_rescued != number_of_persons)
        {
          //Recalculate the costs and reorder the database_p
          findNearestPerson();
          //If the nearest person is rescued all the persons allocated are (as the rescued person cost = rescued_cost which is so high)
          if(database_p.at(0).get_rescued() == false)
          {
            //ROS_INFO("PERSONS TO RESCUE: %d", not_rescued_persons.size());
            //Recalculate as new routes could be seen and cost modified
            setGoalPose(database_p.at(0));
            callMoveAction();
            isMoving = true;
            isgoing_to_person = true;
            carrying_person = false;
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
        //Next time we enter isgoing_to_person = true and moving = false so we will go directly to the exit!
        //Probably is worth to add the posibility that while we are on the way to some person we find another and take him out!
        if (database_e.size() == 0)
        {
          carrying_person = true;
          _state = _state_searching_exit;
        }
        else
        {
          isMoving = true;
          isgoing_to_person = false;
          carrying_person = true;
          setGoalPose(database_e[0]);
          callMoveAction();
          //update the rescued bool of the person
          database_p.at(0).set_rescued();
          database_p.at(0).updateData(rescued_cost);
          persons_rescued++;
        }
      }
    break;

    case _state_searching_person:
      if (database_p.size() > persons_rescued)
      {
        _state = _state_rescuing;
        setGreedyAction(false);
      }
    break;

    case _state_finished:
      ROS_INFO("congratulations, you are a f**** beast");
      return true;
    break;
  }
  return false;
}
