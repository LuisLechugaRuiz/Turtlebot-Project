#include <decision_maker.h>


Decision::Decision():
  nh(ros::this_node::getName()),
  acMove("move_base", true),
  acGreedy("explore_greedy", true)
{
  ROI_sub = n.subscribe("database/ROI", 1, &Decision::ROI_callBack, this);
  cost_client = n.serviceClient<turtlebot_2dnav::returnCost>("move_base/GlobalPlanner/return_cost");
  nh.param("number_of_persons", number_of_persons, 6);
  nh.param("total_time_min", total_time_min, 25);
  nh.param("total_time_sec", total_time_sec, 30);
  nh.param("points_exit", points_exit, 5);
  nh.param("points_person", points_person, 3);
  nh.param("points_danger", points_person, 2);
  nh.param("points_person_rescued_half_time", points_person_rescued_half_time, 5);
  nh.param("points_person_rescued_full_time", points_person_rescued_full_time, 3);
  nh.param("initial_cost", initial_cost, 10000000);
  nh.param("rescued_cost", rescued_cost, 100000000);
  nh.param("riskymode", riskymode, false);
  total_time = total_time_min * 60 + total_time_sec;
  time_inic = ros::Time::now();
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
  acGreedy.sendGoal(greedy, boost::bind(&Decision::getGreedyresult, this, _1, _2),NULL, NULL);
}


void Decision::getGreedyresult(const actionlib::SimpleClientGoalState& state,
                               const explore_lite::greedyResultConstPtr& result)
{
  if (greedy.greedy == false)
  {
    if (state == actionlib::SimpleClientGoalState::SUCCEEDED)
    {

      bestFrontier = result->frontier;
      number_of_frontiers = result->number_of_frontiers;
    }
  }
  else number_of_frontiers = 1000;
}


//lets try to make a risky movement:
  // If we arrived to the exit before the 1/4 total_time lets try to compare person / frontier
  // Get the number of frontiers and number of persons not found
  // Divide them (probability of find a person behind each frontier) Person / frontier
  // Then divide the cost of the closer frontier by this number (make the cost higher);
  // If frontier cost < person go to explore controlled!
bool Decision::isFrontier_worth(int iteration)
{
  bool isWorth = false;
  //make harder to be worth after each iteration
  iteration = iteration*5;
  data frontier_(bestFrontier);
  float probability = (number_of_persons - persons_rescued) / number_of_frontiers;
  //to get the cost here we override goal pose which is dangerous.
  ROS_INFO("Number of frontiers: %d", number_of_frontiers);
  setGoalPose(frontier_);
  float cost_prob = getCost()/probability;
  if(iteration > 0) cost_prob = cost_prob * iteration;
  ROS_INFO("COST PROB FRONTIER %f", cost_prob);
  ROS_INFO("COST PERSON %d", database_p[0].cost);
  if(cost_prob < database_p[0].cost) isWorth = true;
  return isWorth;
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

bool Decision::takeRisk(bool riskymode)
{
  bool risky;
  //Already found the exit
  if (database_e.size() > 0 && riskymode && ((time_exit_found.sec - time_inic.sec) < total_time/4))
  {
    ROS_INFO("Min: %d", (time_exit_found.sec - time_inic.sec) / 60);
    ROS_INFO("segundos: %d", (time_exit_found.sec - time_inic.sec) % 60);
    risky = true;
  }
  else risky =false;

  return risky;
}

//Five states:
// searching_exit   -> Initially it would just look for the exit (moving greedy)
// rescuing         -> If we found a person and we are not carrying anyone start rescuing
// exploring        -> In case we want to run risky_mode go to the nearest frontier in case is worth it
// searching_person -> In case we already rescued anyone on the list search persons again and if one is found return to rescue state
// finished         -> If all the persons have been rescued then finish
bool Decision::process()
{
  switch(_state)
  {
    case _searching_exit:
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
          setGreedyAction(false);
          _state = _rescuing;
          _direction = _person;
        }
      }
      else if (database_p.size() > 0)
      {
        ROS_INFO("State 1: GOING TO RESCUE NEAREST PERSON");
        setGreedyAction(false);
        time_exit_found = ros::Time::now();
        _state = _rescuing;
      }
      else
      {
        ROS_INFO("State 2: GOING GREEDY SEARCHING PERSON");
        time_exit_found = ros::Time::now();
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
              setGreedyAction(false);
              //Recalculate the costs and reorder the database_p
              findNearestPerson();
              setGoalPose(database_p.at(0));
              if(database_p.at(0).get_rescued() == false)
              {
                //Already found the exit
                if (takeRisk(riskymode) && isFrontier_worth(exploring_iteration)) _state = _exploring;
                else
                {
                  _direction = _person;
                  ROS_INFO("Direction: Person");
                }
              }
              else
              {
                ROS_INFO("State 2: GOING GREEDY SEARCHING PERSON");
                setGreedyAction(true);
                _state = _searching_person;
              }
            }
            else _state = _finished;
          break;

          case _person:
            setGoalPose(database_p.at(0));
            callMoveAction();
            isMoving = true;
            _direction = _exit;
            ROS_INFO("Direction: Exit");
          break;

          case _exit:
            carrying_person = true;
            if (database_e.size() == 0) _state = _searching_exit;
            else
            {
              setGoalPose(database_e[0]);
              callMoveAction();
              //update the rescued bool of the person
              database_p.at(0).set_rescued();
              database_p.at(0).updateData(rescued_cost);
              isMoving = true;
              persons_rescued++;
              _direction = _wait;
            }
          }
        }
    break;


    case _exploring:
      if(!isMoving)
      {
        persons_found = database_p.size();
        ROS_INFO("EXPLORING");
        data frontier(bestFrontier);
        setGoalPose(frontier);
        callMoveAction();
        isMoving = true;
        exploring_iteration++;
        _state = _rescuing;
        _direction = _wait;
        ROS_INFO("Direction: Fontier");
      }

      if (persons_found < database_p.size() || database_p[0].cost < getCost() )
      {
        ROS_INFO("OVERRIDE!");
        //OVERRIDE THE MOVE_BASE ACTION!
        isMoving = false;
        _state = _rescuing;
        _direction = _wait;
      }

    break;

    case _searching_person:
      if (database_p.size() > persons_rescued)
      {
        ROS_INFO("State 1: GOING TO RESCUE NEAREST PERSON");
        _state = _rescuing;
        setGreedyAction(false);
      }
    break;

    case _finished:
      ROS_INFO("congratulations! you saved the world ;P");
      return true;
    break;
  }
  return false;
}
