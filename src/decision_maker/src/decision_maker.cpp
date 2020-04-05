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

  total_time = total_time_min * 60 + total_time_sec;
  time_inic = ros::Time::now();
  NewFrontier.pose.position.x = 0;
  NewFrontier.pose.position.y = 0;
  plan_client = n.serviceClient<nav_msgs::GetPlan>("move_base/GlobalPlanner/make_plan");
  carrying_person_client = n.serviceClient<turtlebot_2dnav::CarryingPerson>("database/CarryingPerson");
  ROI_sub = n.subscribe("database/ROI", 1, &Decision::ROI_callBack, this);
  frontiers_sub = n.subscribe("explore/frontier", 100, &Decision::Frontier_callBack, this);
  marker_carrying_person_pub = nh.advertise<visualization_msgs::Marker>("visualization_markers_carrying_person", 10);

  //starting bestfrontier and Newfrontier in different places.
  bestFrontier.pose.position.x = 1000;
  bestFrontier.pose.position.y = 1000;
  NewFrontier.pose.position.x = 0;
  NewFrontier.pose.position.y = 0;

}

void Decision::ROI_callBack(turtlebot_2dnav::ROI New_ROI)
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
  geometry_msgs::PoseStamped goal_pose;
  goal_pose.header.stamp = ros::Time::now();
  goal_pose.header.frame_id = "map";
  if(target_goal.is_vertical())
  {
    goal_pose.pose.position.x = target_goal.get_center_x();
    goal_pose.pose.position.y = target_goal.get_center_y() - 1;
    goal_pose.pose.orientation.z = 0.707;
    goal_pose.pose.orientation.w = 0.707;
  }
  else
  {
    goal_pose.pose.position.x = target_goal.get_center_x() - 1;
    goal_pose.pose.position.y = target_goal.get_center_y();
    goal_pose.pose.orientation.w = 1;
  }
  return goal_pose;
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
  if (database_e.size() > 0 && riskymode && ((time_now.sec - time_inic.sec) < total_time/4))
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
    updateFrontier();
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



void Decision::inicMarkerCarryingPerson()
{

  marker_carrying_person.color.r = 0.0;
  marker_carrying_person.color.g = 0.0;
  marker_carrying_person.color.b = 1.0;
  marker_carrying_person.color.a = 1.0;
  marker_carrying_person.scale.x = 0.2;
  marker_carrying_person.scale.y = 0.2;
  marker_carrying_person.scale.z = 0.2;
  marker_carrying_person.pose.orientation.w = 1;
  marker_carrying_person.type = visualization_msgs::Marker::SPHERE_LIST;

  geometry_msgs::PoseStamped person_map;
  person_map = getBehindPose();
  geometry_msgs::Point point_map_person;
  point_map_person.x = person_map.pose.position.x;
  point_map_person.y = person_map.pose.position.y;
  point_map_person.z = 0.15;

  marker_carrying_person.points.push_back(point_map_person);

}

void Decision::updateMarker()
{

  geometry_msgs::PoseStamped person_map;
  person_map = getBehindPose();
  geometry_msgs::Point point_map_person;
  point_map_person.x = person_map.pose.position.x;
  point_map_person.y = person_map.pose.position.y;
  point_map_person.z = 0.15;
  marker_carrying_person.points[persons_rescued] = point_map_person;

  marker_carrying_person.header.frame_id = "map";
  marker_carrying_person.header.stamp = ros::Time::now();
  marker_carrying_person_pub.publish(marker_carrying_person);
}

geometry_msgs::PoseStamped Decision::getBehindPose()
{
  geometry_msgs::PoseStamped carrying_person;
  geometry_msgs::PoseStamped person_point_map;

  carrying_person.header.stamp = ros::Time(0);
  carrying_person.header.frame_id = "/base_link";
  carrying_person.pose.position.x = -0.5;
  carrying_person.pose.position.y = 0;
  carrying_person.pose.position.z = 0;
  carrying_person.pose.orientation.x = 0;
  carrying_person.pose.orientation.y = 0;
  carrying_person.pose.orientation.z = 0;
  carrying_person.pose.orientation.w = 1;

  tf::StampedTransform transform;
  try{
    listener.lookupTransform("/map","/base_link", ros::Time(0), transform);
  }
  catch (tf::TransformException &ex) {
    ROS_ERROR("%s",ex.what());
  }

  geometry_msgs::TransformStamped stampedTransform;
  tf::transformStampedTFToMsg(transform, stampedTransform);
  tf2::doTransform(carrying_person, person_point_map, stampedTransform);
  return person_point_map;
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
        if(!carrying_person && New_Person && (exploring_iteration == 0) )
        {
          //Process the New_Person and decide where to go!
          getActualPose();
          findNearestPerson( actualPose );
          _state = _rescuing;
          break;
        }

        if (carrying_person) updateMarker();

        switch(_exploration_mode)
        {
          case _searching_exit:
            if (exit_found)
            {
              exitPosition = setPose( database_e[0] );
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
        frontierTargetReached = false;
        //If we want to explore again we should send the last frontier even if is the SAME!
        explore_override = true;
        _state = _waiting;
        switch (_direction)
        {
          case _person:
            ROS_INFO("Direction: Person");
            bestPerson = setPose(database_p[0]);
            callMoveAction( bestPerson );
          break;

          case _exit:
            ROS_INFO("Direction: Exit");
            callMoveAction( exitPosition );
          break;
        }
    break;

    case _waiting:

      if (carrying_person) updateMarker();

      switch (_waiting_decisions)
      {
        case _continous_decisions:

          if (exit_found)
          {
            //Calculate decision if New_Person = true or we are riskymode and the last frontier reached!
            if (New_Person)
            {
              findNearestPerson( exitPosition );
              if (checkIfFrontierWorth( exitPosition ))
              {
                _decided_state = _exploring;
                _exploration_mode = _exploring_frontier;
              }
              else _decided_state = _rescuing;
              //New_Person processed!
              New_Person = false;
            }
          }

          //should be planned AFTER the exit is reached!!!
          if(exploring_iteration > 0 && frontierTargetReached)
          //case we are exploring_frontier!
          {
            ROS_INFO("INSIDE2");
            getActualPose();
            findNearestPerson( actualPose );
            if (checkIfFrontierWorth(actualPose))
            {
              _state = _exploring;
              _exploration_mode = _exploring_frontier;
            }
            else
            {
              _state = _rescuing;
              _direction = _person;
            }
          }

          if (rescuedTargetReached) _waiting_decisions = _static_decisions;

        break;

        case _static_decisions:
          if(persons_rescued != number_of_persons)
          {
            if(database_p[0].get_rescued())
            {
              _decided_state = _exploring;
              _exploration_mode = _searching_person;
            }
          }

          _waiting_decisions = _send_decision;
        break;

        case _send_decision:
          _waiting_decisions = _continous_decisions;
          rescuedTargetReached = false;
          frontierTargetReached = false;

          switch (_direction)
          {
            case _person:
            carrying_person = true;

            ROS_INFO("CARRYING PERSON");

            carrying_ROI.index = database_p[0].get_index();
            carrying_.request.person = carrying_ROI;
            carrying_person_client.call(carrying_);

            inicMarkerCarryingPerson();

            _direction = _exit;
            //if we are going to a person send it to the end of the list so if we find during the way another one we can recalculate!
            database_p[0].set_rescued();
            database_p[0].updateData(rescued_distance);
            //update the new person to rescue!
            updatePersonsbyDistance();
            //do we know the exit?
            if (exit_found) _state = _rescuing;
            else _state = _exploring;
          break;

          case _exit:
            carrying_person = false;
            persons_rescued++;
            ROS_INFO("LEFT AT EXIT. PERSON: %d", (persons_rescued+1));
            if(persons_rescued != number_of_persons)
            {
              _direction = _person;
              if(riskymode)
              {
                getActualPose();
                findNearestPerson( actualPose );
                if (checkIfFrontierWorth(actualPose))
                {
                  _state = _exploring;
                  _exploration_mode = _exploring_frontier;
                }
                else _state = _decided_state;
              }
              else _state = _decided_state;
            }
            else
            {
              ROS_INFO("congratulations! you saved the world ;P");
              return true;
            }
          break;
          }
        break;
      }
    break;
  }
}
