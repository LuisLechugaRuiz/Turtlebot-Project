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
  nh.param("fastupdate_x_dist", fastupdate_x_dist, 1.0);
  nh.param("fastupdate_y_dist", fastupdate_y_dist, 1.0);

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
    //Maybe make a template for person/data ?
    if(New_ROI.isnew)
    {
      if(type == "P")
      {
        person Person(New_ROI, initial_distance);
        database_p.push_back(Person);
        New_Person = true;
      }
      if(type == "R")
      {
        data New_data(New_ROI);
        database_r.push_back(New_data);
      }
      if(type == "E")
      {
        data New_data(New_ROI);
        database_e.push_back(New_data);
        if (!exit_found) exit_found = true;
        else ROS_INFO ("2 exits found!?");
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
      if(type == "R"){
        for(data data_r_ : database_r)
        {
          if(data_r_.data_index_equal_to(New_ROI.index)) data_r_.updateData(New_ROI);
        }
      }
      if(type == "E"){
        for(data data_e_ : database_e)
        {
          if(data_e_.data_index_equal_to(New_ROI.index)) data_e_.updateData(New_ROI);
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
      if(_state == _exploring) frontierTargetReached = true;
      if(_state == _waiting) rescuedTargetReached = true;
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


geometry_msgs::PoseStamped Decision::setPose(data target_goal)
{
  geometry_msgs::PoseStamped goal;
  goal.header.stamp = ros::Time::now();
  goal.header.frame_id = "map";
  if(target_goal.is_vertical())
  {
    goal.pose.position.x = target_goal.get_center_x();
    goal.pose.position.y = target_goal.get_center_y() - 1;
    goal.pose.orientation.z = 0.707;
    goal.pose.orientation.w = 0.707;
  }
  else
  {
    goal.pose.position.x = target_goal.get_center_x() - 1;
    goal.pose.position.y = target_goal.get_center_y();
    goal.pose.orientation.w = 1;
  }
  return goal;
}


//lets try to make a risky movement:
  // If we arrived to the exit before the 1/4 total_time lets try to compare person / frontier
  // Get the number of frontiers and number of persons not found
  // Divide them (probability of find a person behind each frontier) Person / frontier
  // Then divide the cost of the closer frontier by this number (make the cost higher);
  // If frontier cost < person go to explore controlled!
bool Decision::isFrontier_worth(int iteration, geometry_msgs::PoseStamped inic_pose)
{
  ROS_INFO("ITERATION: %d", iteration);
  bool isWorth = false;
  //make harder to be worth after each iteration
  iteration = iteration*5;
  data frontier_(bestFrontier);
  double distance_prob = getDistanceProb(frontier_, inic_pose);
  if( iteration > 0 ) distance_prob = distance_prob * iteration;
  ROS_INFO("INSIDE");
  ROS_INFO("distance prob2: %f", distance_prob);
  if(distance_prob > 0 && distance_prob < database_p[0].distance)
  {
    isWorth = true;
    ROS_INFO("ISWORTH!");
  }
  return isWorth;
}

double Decision::getDistanceProb(data Frontier, geometry_msgs::PoseStamped inic_pose)
{
  double probability = (double)(number_of_persons - persons_rescued) / (double)number_of_frontiers;
  ROS_INFO("probability: %f", probability);
  //to get the cost here we override goal pose which is dangerous.
  auto Frontier_path = getPlan(inic_pose, setPose(Frontier) );
  double distance_frontier = getDistance(Frontier_path);
  distance_frontier = distance_frontier/probability;
  ROS_INFO("distance prob1: %f", distance_frontier);
  return distance_frontier;
}


nav_msgs::Path Decision::getPlan(geometry_msgs::PoseStamped inic, geometry_msgs::PoseStamped goal)
{
  plan_request.request.start = inic;
  plan_request.request.goal = goal ;
  plan_request.request.tolerance = tolerance;
  plan_client.call(plan_request);
  return plan_request.response.plan;
}

static bool sortbydistance(const person &a, const person &b)
{
    return (a.distance < b.distance);
}


void Decision::findNearestPerson(geometry_msgs::PoseStamped inic_pose)
{
  persons_found = database_p.size();
  for(auto& person_ : database_p)
  {
    //Only update the cost if the person is not rescued, else the cost will be standar
    if(person_.get_rescued() == false)
    {
      auto New_path = getPlan( inic_pose, setPose(person_) );
      person_.updateData( getDistance(New_path) );
    }
  }
  std::sort(database_p.begin(), database_p.end(), sortbydistance);
  double distance = database_p[0].distance;
  ROS_INFO("distance: %f", distance);
}


void Decision::callMoveAction( geometry_msgs::PoseStamped goalPose )
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


void Decision::updatePersonsbyDistance()
{
  std::sort(database_p.begin(), database_p.end(), sortbydistance);
}

void Decision::updateFrontier()
{
  bestFrontier = NewFrontier;
  data Frontier(bestFrontier);
  callMoveAction(  setPose(Frontier) );
  frontierTargetReached = false;
  explore_override = false;
  calculatedNew = false;
  //ROS_INFO("New Frontier");
  //ROS_INFO("Pos x: %f", bestFrontier.pose.position.x);
  //ROS_INFO("Pos y: %f", bestFrontier.pose.position.y);
}

bool Decision::fastUpdateFrontier()
{
  bool update = false;
  if( ((actualPose.pose.position.x - bestFrontier.pose.position.x) < dist_x_update_frontier)
  || ((actualPose.pose.position.x -bestFrontier.pose.position.y) < dist_y_update_frontier) )
  {
    if ( ((NewFrontier.pose.position.x - bestFrontier.pose.position.x) < fastupdate_x_dist)
    || ((NewFrontier.pose.position.y - bestFrontier.pose.position.y) < fastupdate_y_dist) )
    {
      update = true;
    }
  }
  return update;
}

void Decision::explore()
{

  // IF PATH DIES NEED TO SEND IT AGAIN!

  if (number_of_frontiers == 0) ROS_INFO("No frontiers!");
  //if is the same frontier and has not been overrided dont publish nothing just wait!
  else if (sameFrontier(bestFrontier.pose.position, NewFrontier.pose.position) && !explore_override);
  else
  {
    getActualPose();
    if (explore_override)
    {
      updateFrontier();
      return;
    }
    if (frontierTargetReached || fastUpdateFrontier()) updateFrontier();

    else if(CostSecondLower(actualPose.pose, bestFrontier.pose.position, NewFrontier.pose.position) && !calculatedNew)
    {
      updateFrontier();
      calculatedNew = true;
      ROS_INFO ("Calculated New");
    }
  }
}


bool Decision::checkIfFrontierWorth(geometry_msgs::PoseStamped inic)
{
  bool isworth = false;
  if (takeRisk(riskymode) && isFrontier_worth(exploring_iteration, inic))
  {
    exploring_iteration++;
    frontierTargetReached = false;
    isworth = true;
    ROS_INFO("GOING TO INTERESTING FRONTIER!");
  }
  return isworth;
}
//Two main states:

//EXPLORING
  //3 different posibilities:
    //Searching exit
    //Searching persons
    //Risky Mode *future implementation*

//RESCUING
  //2 different directions:
    //Person
    //Exit

//WATIING
 //3 diferent states:
  //Waiting direction_Person
  //Waiting direction_Exit
  //Calculating next target!

bool Decision::process()
{

  //Wait to start exploring
  if (!first_frontier_received) return false;

  switch(_state)
  {
    case _exploring:

        //We should always carry a Person if not carrying and a new_person is detected! (riskymode need something)
        if(!carrying_person && New_Person)
        {
          _state = _rescuing;
          break;
        }

        switch(_exploration_mode)
        {
          case _searching_exit:
            if (exit_found)
            {
              if (New_Person) _state = _rescuing;
              else _exploration_mode = _searching_person;
            }
            else explore();
          break;

          case _searching_person:
            explore();
          break;

          //in this case we will check again (in waiting) after the interesting frontier is reached!
          case _exploring_frontier:
            frontierTargetReached = true;
            explore();
            _state = _waiting;
          break;
        }
    break;

    //We only enter to set the goal!
    case _rescuing:
        ROS_INFO("State: Rescuing");
        rescuedTargetReached = false;
        //If we want to explore again we should send the last frontier even if is the SAME!
        explore_override = true;
        _state = _waiting;
        switch (_direction)
        {
          case _person:
            ROS_INFO("Direction: Person");
            callMoveAction( setPose(database_p.at(0)) );

            //if we are going to a person send it to the end of the list so if we find during the way another one we can recalculate!
            database_p.at(0).set_rescued();
            database_p.at(0).updateData(rescued_distance);

            //update the new person to rescue!
            updatePersonsbyDistance();
          break;

          case _exit:
            ROS_INFO("Direction: Exit");
            callMoveAction( setPose(database_e[0]) );
          break;
        }
    break;

    case _waiting:

      if (rescuedTargetReached)
      {
        switch (_direction)
        {
          case _person:
            carrying_person = true;
            ROS_INFO("CARRYING PERSON");
            _direction = _exit;
            //do we know the exit?
            if (exit_found) _state = _rescuing;
            else _state = _exploring;
          break;

          case _exit:
            carrying_person = false;
            persons_rescued++;
            ROS_INFO("LEFT AT EXIT. PERSON: %d", persons_rescued);
            _direction = _person;
            _state = _decided_state;
          break;
        }
      }

      //if we are moving use this time to calculate the next route
      //Only if we already now the exit and we can calculate distances!
      else if (exit_found)
      {
        if(persons_rescued != number_of_persons)
        {
          if (!database_p[0].get_rescued())
          {
          //Calculate decision if New_Person = true or we are riskymode and the last frontier reached!
            if (New_Person || (riskymode && frontierTargetReached))
            {
              //New_Person processed!
              New_Person = false;
              //case we are exploring_frontier!
              if ( exploring_iteration > 0 )
              {
                getActualPose();
                findNearestPerson( actualPose );
                if (checkIfFrontierWorth(actualPose))
                {
                  _decided_state = _exploring;
                  _exploration_mode = _exploring_frontier;
                }
              }
              else
              {
                findNearestPerson( setPose(database_e[0]) );
                if (checkIfFrontierWorth( setPose(database_e[0]) ))
                {
                  _decided_state = _exploring;
                  _exploration_mode = _exploring_frontier;
                }
                else _decided_state = _rescuing;
              }
            }
          }
          else
          {
            ROS_INFO("GOING GREEDY: SEARCHING PERSON");
            _state = _exploring;
            _exploration_mode = _searching_person;
          }
        }
        else
        {
          ROS_INFO("congratulations! you saved the world ;P");
          return true;
        }
      }
  break;
  }
}
