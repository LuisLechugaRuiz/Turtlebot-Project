#include <decision_maker.h>


Decision::Decision():
  nh(ros::this_node::getName()),
  acMove("move_base", true)
{

  nh.param("number_of_persons", number_of_persons, 6);
  nh.param("total_time_min", total_time_min, 25);
  nh.param("total_time_sec", total_time_sec, 30);
  nh.param("points_exit", points_exit, 5);
  nh.param("points_person", points_person, 3);
  nh.param("points_danger", points_person, 2);
  nh.param("points_person_rescued_half_time", points_person_rescued_half_time, 5);
  nh.param("points_person_rescued_full_time", points_person_rescued_full_time, 3);
  nh.param("initial_distance", initial_distance, 10000.00);
  nh.param("rescued_distance", rescued_distance, 100000.00);
  nh.param("riskymode", riskymode, false);
  nh.param("dist_x_update_frontier", dist_x_update_frontier, 1.0);
  nh.param("dist_y_update_frontier", dist_y_update_frontier, 1.0);

  total_time = total_time_min * 60 + total_time_sec;
  time_inic = ros::Time::now();
  NewFrontier.pose.position.x = 0;
  NewFrontier.pose.position.y = 0;
  plan_client = n.serviceClient<nav_msgs::GetPlan>("move_base/GlobalPlanner/make_plan");
  ROI_sub = n.subscribe("database/ROI", 1, &Decision::ROI_callBack, this);
  frontiers_sub = n.subscribe("explore/frontier", 100, &Decision::Frontier_callBack, this);

  //starting bestfrontier and Newfrontier in different places.
  bestFrontier.pose.position.x = 1000;
  bestFrontier.pose.position.y = 1000;
  NewFrontier.pose.position.x = 0;
  NewFrontier.pose.position.y = 0;
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
        person New_Person(New_ROI, initial_distance);
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


void Decision::Frontier_callBack(turtlebot_2dnav::frontier frontier)
{
  if(!first_frontier_received)
  {
    first_frontier_received = true;
    //initiale bestFrontier
    bestFrontier = NewFrontier;
  }
  NewFrontier = frontier.goal;
  number_of_frontiers = frontier.frontiers_count;
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


//lets try to make a risky movement:
  // If we arrived to the exit before the 1/4 total_time lets try to compare person / frontier
  // Get the number of frontiers and number of persons not found
  // Divide them (probability of find a person behind each frontier) Person / frontier
  // Then divide the cost of the closer frontier by this number (make the cost higher);
  // If frontier cost < person go to explore controlled!
bool Decision::isFrontier_worth(int iteration)
{
  ROS_INFO("ITERATION: %d", iteration);
  bool isWorth = false;
  //make harder to be worth after each iteration
  iteration = iteration*5;
  data frontier_(bestFrontier);
  double distance_prob = getDistanceProb(frontier_);
  if(iteration > 0)
  {
    distance_prob = distance_prob * iteration;
    ROS_INFO("INSIDE");
  }
  ROS_INFO("distance prob2: %f", distance_prob);
  if(distance_prob > 0 && distance_prob < database_p[0].distance)
  {
    isWorth = true;
    ROS_INFO("ISWORTH!");
  }
  return isWorth;
}

double Decision::getDistanceProb(data Frontier)
{
  double probability = (double)(number_of_persons - persons_rescued) / (double)number_of_frontiers;
  ROS_INFO("probability: %f", probability);
  //to get the cost here we override goal pose which is dangerous.
  setGoalPose(Frontier);
  auto Frontier_path = getPlan();
  double distance_frontier = getDistance(Frontier_path);
  distance_frontier = distance_frontier/probability;
  ROS_INFO("distance prob1: %f", distance_frontier);
  return distance_frontier;
}


nav_msgs::Path Decision::getPlan()
{
  plan_request.request.start = actualPose;
  plan_request.request.goal = goalPose;
  plan_request.request.tolerance = tolerance;
  plan_client.call(plan_request);
  return plan_request.response.plan;
}

static bool sortbydistance(const person &a, const person &b)
{
    return (a.distance < b.distance);
}


void Decision::findNearestPerson()
{
  persons_found = database_p.size();
  getActualPose();
  for(auto& person_ : database_p)
  {
    //Only update the cost if the person is not rescued, else the cost will be standar
    if(person_.get_rescued() == false)
    {
      setGoalPose(person_);
      auto New_path = getPlan();
      person_.updateData( getDistance(New_path) );
    }
  }
  std::sort(database_p.begin(), database_p.end(), sortbydistance);
  double distance = database_p[0].distance;
  ROS_INFO("distance: %f", distance);
}


void Decision::callMoveAction()
{
  goal.target_pose = goalPose;
  acMove.sendGoal(goal, boost::bind(&Decision::moving_done_Callback, this, _1));
}

bool Decision::takeRisk(bool riskymode)
{
  bool risky;
  time_now = ros::Time::now();
  //Already found the exit
  if (database_e.size() > 0 && riskymode && ((time_now.sec - time_now.sec) < total_time/4))
  {
    ROS_INFO("Min: %d", (time_now.sec - time_inic.sec) / 60);
    ROS_INFO("segundos: %d", (time_now.sec - time_inic.sec) % 60);
    risky = true;
  }
  else risky = false;

  return risky;
}

void Decision::updateFrontier()
{
  bestFrontier = NewFrontier;
  setGoalPose(bestFrontier);
  callMoveAction();
  isMoving = true;
  ROS_INFO("New Frontier");
}

void Decision::explore()
{
  //IF PATH DIES NEED TO SEND IT AGAIN!
  //check if same frontier!
  if (sameFrontier(bestFrontier.pose.position, NewFrontier.pose.position))
  {
    if (number_of_frontiers == 0) ROS_INFO("No frontiers!");
    if (!isMoving) ROS_INFO ("Waiting New Frontier");
  }
  else
  {
    getActualPose();
    if (!isMoving || (actualPose.pose.position.x - bestFrontier.pose.position.x) < dist_x_update_frontier
                  || (actualPose.pose.position.x -bestFrontier.pose.position.y) < dist_y_update_frontier)   updateFrontier();
    else if(CostSecondLower(actualPose.pose, bestFrontier.pose.position, NewFrontier.pose.position))
    {
      updateFrontier();
      ROS_INFO ("Calculated New");
    }
  }
}


//Five states:

// searching_exit   -> Initially it would just look for the exit (moving greedy)
// rescuing         -> If we found a person and we are not carrying anyone start rescuing
  // The states (directions)
    //Wait   -> take decision to where to go depending on different factors
    //Person -> moving to the closer person
    //Exit   -> carrying a person to the exit
// exploring        -> In case we want to run risky_mode go to the nearest frontier in case is worth it
// searching_person -> In case we already rescued anyone on the list search persons again and if one is found return to rescue state
// finished         -> If all the persons have been rescued then finish

bool Decision::process()
{
  //Wait to start exploring
  if (!first_frontier_received) return false;
  switch(_state)
  {
    case _searching_exit:
      if (database_e.size() == 0)
      {
        if(!isMoving) ROS_INFO("State 0: GOING GREEDY SEARCHING EXIT");
        if(database_p.size() > 0 && !carrying_person)
        {
          ROS_INFO("State 1: GOING TO RESCUE NEAREST PERSON");
          _state = _rescuing;
          _direction = _person;
        }
        else explore();
      }
      else if (database_p.size() > 0)
      {
        _state = _rescuing;
        isMoving = false;
      }
      else
      {
        ROS_INFO("State 2: GOING GREEDY SEARCHING PERSON");
        _state = _searching_person;
      }
    break;

    case _rescuing:
      if(!isMoving)
      {
        switch (_direction)
        {
          case _wait:
            carrying_person = false;
            if(persons_rescued != number_of_persons)
            {
              //Recalculate the costs and reorder the database_p
              findNearestPerson();
              if(database_p.at(0).get_rescued() == false)
              {
                //Already found the exit
                if (takeRisk(riskymode) && isFrontier_worth(exploring_iteration))
                {
                  _state = _exploring;
                  _exploration_mode = _starting;
                }
                else _direction = _person;
              }
              else
              {
                ROS_INFO("State 2: GOING GREEDY SEARCHING PERSON");
                _state = _searching_person;
              }
            }
            else _state = _finished;
          break;


          case _person:
            ROS_INFO("Direction: Person");
            setGoalPose(database_p.at(0));
            callMoveAction();
            isMoving = true;
            _direction = _exit;
          break;


          case _exit:
            ROS_INFO("Direction: Exit");
            carrying_person = true;
            if (!isMoving)
            {
              if (database_e.size() == 0) _state = _searching_exit;
              else
              {
                setGoalPose(database_e[0]);
                callMoveAction();
                //update the rescued bool of the person
                database_p.at(0).set_rescued();
                database_p.at(0).updateData(rescued_distance);
                isMoving = true;
                persons_rescued++;
                _direction = _wait;
              }
            }
          break;
        }
      }
    break;


    case _exploring:

      switch (_exploration_mode)
      {
        case _starting:
          if(!isMoving)
          {
            ROS_INFO("EXPLORING");
            isMoving = true;
            exploring_iteration++;
            _exploration_mode = _moving;
            ROS_INFO("Direction: Fontier");
          }
        break;

        case _moving:
          //check if new persons found during the way!
          if (persons_found < database_p.size())
          {
            findNearestPerson();
            if (!isFrontier_worth(exploring_iteration))
            {
              _state = _rescuing;;
              _direction = _person;
              //OVERRIDE THE MOVE_BASE ACTION!
              isMoving = false;
            }
          }
          if (!isMoving) _exploration_mode = _stopped;
          else explore();
        break;

        case _stopped:
        _state = _rescuing;
        _direction = _wait;
        break;
      }
    break;

    case _searching_person:
      if (database_p.size() > persons_rescued)
      {
        ROS_INFO("State 1: GOING TO RESCUE NEAREST PERSON");
        _state = _rescuing;
      }
      else explore();
    break;

    case _finished:
      ROS_INFO("congratulations! you saved the world ;P");
      return true;
    break;
  }
  return false;
}
