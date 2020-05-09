#include <costmap_restrictor.h>

CostmapRes::CostmapRes() :
  nh(ros::this_node::getName())
  {
    std::string costmap_topic;
    std::string footprint_topic;

    nh.param("costmap_topic", costmap_topic, std::string("costmap"));
    nh.param("resolution", resolution, 0.095);
    nh.param("max_count_findPerpendicularObstacle", max_count_findPerpendicularObstacle, 3);
    nh.param("max_count_findParalelObstacle", max_count_findParalelObstacle, 10);
    nh.param("max_count_findLimits", max_count_findLimits, 15);
    nh.param("min_count_size", min_count_size, 12);
    nh.param("max_count_size", max_count_size, 16);
    nh.param("max_match_count", max_match_count, 50);
    nh.param("max_recalculate_count", max_recalculate_count, 10);

    restrict_server = nh.advertiseService("restrict", &CostmapRes::RestrictService, this);
    recalculate_server = nh.advertiseService("recalculate", &CostmapRes::RecalculateService, this);
    costmap_sub_ = n.subscribe(costmap_topic, 1000, &CostmapRes::ProcessCostmap, this);
    fake_bound_pub = nh.advertise<turtlebot_2dnav::fake_bound>("fake_bound", 10);
    match_bound_pub = nh.advertise<turtlebot_2dnav::match_bound>("match_bound", 10);
}


void CostmapRes::ProcessCostmap(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
  size_in_cells_x = msg->info.width;
  size_in_cells_y = msg->info.height;
  resolution = msg->info.resolution;
  origin_x = msg->info.origin.position.x;
  origin_y = msg->info.origin.position.y;

  //TO BE DECIDED
  //if (canRecalculate)
  //{
  //  if (recalculatequeue.size() > 0)
  //  {
  //    resetBound( recalculatequeue[0] );
  //    matchqueue.insert( matchqueue.begin(), recalculatequeue[0] );
  //    recalculatequeue.erase( recalculatequeue.begin() );
  //  }
  //}

  //In case of resize (because a recalculate dont publish just match again!)
  if(matchqueue.size() > 0)
  {
    //ROS_INFO("MATCHING!");
    if( matchBound(matchqueue[0], msg) )
    {
      //ROS_INFO("BOUND MATCHED");
      if(!matchqueue[0].recalculate)
      {
        turtlebot_2dnav::match_bound matched_bound_;
        matched_bound_.matched = true;
        if(matchqueue[0].vertical)
        {
          matched_bound_.pointleft = matchqueue[0].point_left_max;
          matched_bound_.pointright = matchqueue[0].point_right_min;
        }
        else
        {
          matched_bound_.pointleft = matchqueue[0].point_left_min;
          matched_bound_.pointright = matchqueue[0].point_right_max;
        }
        matched_bound_.pointcenter = matchqueue[0].center_point;
        matched_bound_.index = matchqueue[0].database_index;
        matched_bound_.color = matchqueue[0].color;
        match_bound_pub.publish(matched_bound_);
        recalculate_database_index(matchqueue[0].database_index, matchqueue[0].color);
        //ROS_INFO("BOUND COLOR: %d", matchqueue[0].color);
        //PUBLISH TO DATABASE!
      }
      if(matchqueue[0].restriction) queue.push_back(matchqueue[0]);
      matchqueue.erase( matchqueue.begin() );
    }
    else if(matchqueue[0].match_count < max_match_count)
    {
      if(matchqueue[0].match_count >= max_match_count/2)
      {
        //ROS_INFO("looking for a new center");
        matchqueue[0].center_LETHAL = 2;
      }
      matchqueue[0].match_count++;
      //send it to the last!
      std::rotate(matchqueue.begin(), matchqueue.begin() + 1, matchqueue.end());
    }
    else
    {
      if(!matchqueue[0].recalculate)
      {
      turtlebot_2dnav::match_bound not_matched_bound_;
      not_matched_bound_.matched = false;
      not_matched_bound_.pointcenter = matchqueue[0].center_point;
      not_matched_bound_.pointleft = matchqueue[0].center_point;
      not_matched_bound_.pointright = matchqueue[0].center_point;
      not_matched_bound_.index = matchqueue[0].database_index;
      not_matched_bound_.color = matchqueue[0].color;
      match_bound_pub.publish(not_matched_bound_);
      recalculate_database_index(matchqueue[0].database_index, matchqueue[0].color);
      //ROS_INFO ("bound not matched, erasing matchqueue");
      }
      matchqueue.erase( matchqueue.begin() );
    }
  }

  if(queue.size() > 0)
  {

    //findInCostmap parameters:
        // - obstacle/limit
        // - costmap ptr
        // - costmap coords
        // - max_count in the loop
        // - perpendicular / paralel
        // - left / right

    //CHECK IF NEED TO RECALCULATE
    //Two cases:
    if (queue[0].count > max_recalculate_count && !queue[0].exit)
    {
        recalculatequeue.push_back( queue[0] );
        queue.erase( queue.begin() );
        ROS_INFO("Sending to recalculate queue");
        return;
    }

    else
    {
      //save a copy of last bounds limit to check if any update
      geometry_msgs::Point l_min = queue[0].point_left_min;
      geometry_msgs::Point l_max = queue[0].point_left_max;
      geometry_msgs::Point r_min = queue[0].point_right_min;
      geometry_msgs::Point r_max = queue[0].point_right_max;

      int count = 0;
      geometry_msgs::Point costmap_coords;
      //FIND THE CLOSER OBSTACLE IN LEFT DIRECTION
      if(queue[0].recalculateleft)
      {
        if (queue[0].vertical)
        {
          if(queue[0].laser_index != -1) costmap_coords = MapToCostmap(queue[0].point_left_min);
          //IF IS A RESIZE START COUNTING FROM THE LIMIT
          else costmap_coords = MapToCostmap(queue[0].point_left_max);
        }
        else
        {
          if(queue[0].laser_index != -1) costmap_coords = MapToCostmap(queue[0].point_left_max);
          else costmap_coords = MapToCostmap(queue[0].point_left_min);
        }
        count = findInCostmap(queue[0], true, msg, costmap_coords, max_count_findParalelObstacle, false, true);
        if ( count < max_count_findParalelObstacle && !unknown_limit)
        {
          queue[0].recalculateleft = false;
          //ROS_INFO("NO NEED TO RECALCULATE LEFT");
        }
      }

      //FIND THE CLOSER OBSTACLE IN RIGHT DIRECTION
      if(queue[0].recalculateright)
      {
        if (queue[0].vertical)
        {
          if(queue[0].laser_index != -1) costmap_coords = MapToCostmap(queue[0].point_right_max);
          else costmap_coords = MapToCostmap(queue[0].point_right_min);
        }
        else
        {
          if(queue[0].laser_index != -1) costmap_coords = MapToCostmap(queue[0].point_right_min);
          else costmap_coords = MapToCostmap(queue[0].point_right_max);
        }
        count = findInCostmap(queue[0], true, msg, costmap_coords, max_count_findParalelObstacle, false, false);
        if ( count < max_count_findParalelObstacle && !unknown_limit)
        {
          queue[0].recalculateright = false;
          //ROS_INFO("NO NEED TO RECALCULATE RIGHT");
        }
      }

      bound_.index = queue[0].laser_index;
      bound_.isvertical = queue[0].vertical;
      bound_.exit = queue[0].exit;

      //IF FIRST PROCESS
      if (queue[0].laser_index  == -1)
      {
        queue[0].laser_index = laser_index;
        bound_.index = queue[0].laser_index;
        bound_.resize = false;
        if(!queue[0].exit)
        {
          for(int i = 0; i <10; i++)
          {
            if ( queue[0].vertical )
            {
              if(queue[0].point_right_max.x - queue[0].point_right_min.x > 1)
              {
                bound_.pointrightmax.x = queue[0].point_right_min.x + 1;
              }
              else
              {
                bound_.pointrightmax.x = queue[0].point_right_max.x;
              }
              if(queue[0].point_left_max.x - queue[0].point_left_min.x > 1)
              {
                bound_.pointleftmin.x = queue[0].point_left_max.x - 1;
              }
              else
              {
                bound_.pointleftmin.x = queue[0].point_left_min.x;
              }
              bound_.pointrightmin.x = queue[0].point_left_max.x;
              bound_.pointleftmax.x = queue[0].point_right_min.x;

              bound_.pointrightmax.y =  queue[0].point_right_min.y - 1 + 0.2 * i;
              bound_.pointrightmin.y =  queue[0].point_right_min.y - 1 + 0.2 * i;
              bound_.pointleftmax.y =  queue[0].point_right_min.y - 1 + 0.2 * i;
              bound_.pointleftmin.y=  queue[0].point_right_min.y - 1 + 0.2 * i;
            }
            else
            {
              if(queue[0].point_right_max.y - queue[0].point_right_min.y > 1)
              {
                bound_.pointrightmin.y = queue[0].point_right_max.y - 1;
              }
              else
              {
                bound_.pointrightmin.y = queue[0].point_right_min.y;
              }
              if(queue[0].point_left_max.y - queue[0].point_left_min.y > 1)
              {
                bound_.pointleftmax.y = queue[0].point_left_min.y + 1;
              }
              else
              {
                bound_.pointleftmax.y = queue[0].point_left_max.y;
              }
              bound_.pointrightmax.y = queue[0].point_right_max.y;
              bound_.pointleftmin.y = queue[0].point_right_min.y;

              bound_.pointrightmax.x =  queue[0].point_right_min.x - 1 + 0.2 * i;
              bound_.pointrightmin.x =  queue[0].point_right_min.x - 1 + 0.2 * i;
              bound_.pointleftmax.x =  queue[0].point_right_min.x - 1 + 0.2 * i;
              bound_.pointleftmin.x=  queue[0].point_right_min.x - 1 + 0.2 * i;
            }
            fake_bound_pub.publish(bound_);
            laser_index++;
          }
        }
        else
        {
          bound_.pointrightmax = queue[0].point_right_max;
          bound_.pointrightmin = queue[0].point_right_min;
          bound_.pointleftmax = queue[0].point_left_max;
          bound_.pointleftmin = queue[0].point_left_min;
          fake_bound_pub.publish(bound_);
          laser_index++;
        }

      }

      //IF ANY UPDATE ON ONE SIDES (and not first time) PUBLISH
      else if( needUpdate(queue[0], l_min, l_max, r_min, r_max) )
      {
        //ROS_INFO("PUBLISHING UPDATE!");
        bound_.resize = true;
        fake_bound_pub.publish(bound_);
      }
      queue[0].count++;
      if (queue[0].recalculateleft || queue[0].recalculateright) std::rotate(queue.begin(), queue.begin() + 1, queue.end());
      else
      {
        queue.erase( queue.begin() );
        //ROS_INFO("good bound, deleted from queue");
      }
    }
  }
}


bool CostmapRes::RestrictService(turtlebot_2dnav::restrictCostmap::Request &req,
                                        turtlebot_2dnav::restrictCostmap::Response &res)
{
  New_Bound.exit = req.exit;
  New_Bound.vertical = req.isvertical;
  New_Bound.center_point = req.Point;
  New_Bound.database_index = req.index;
  New_Bound.restriction = req.restrict;
  New_Bound.color = req.color;

  matchqueue.push_back(New_Bound);
  //check that we sent as exit the correct bound inserting it at the begin
  res.received = true;
  return res.received;
}


int CostmapRes::findInCostmap(CostmapRes::Bound &_bound, bool obstacle,
                              const nav_msgs::OccupancyGrid::ConstPtr& msg,
                              geometry_msgs::Point costmap_coords, int max_count,
                              bool perpendicular, bool positiveDirection)
{
  //ROS_INFO("IN OBSTACLES");
  int count = 0;
  int acum = 0;
  unknown_limit = false;

  auto index_ = getIndex( costmap_coords );
  auto value = msg->data[index_];

  //in this case positive direction means (left and up)
  if (positiveDirection) acum = 1;
  else acum = -1;


  //FIND OBSTACLE (PERPENDICULAR)
  if(obstacle)
  {

    int center_count;
    if(value == LETHAL_OBSTACLE) center_count = 1;
    else center_count = 0;

    if (perpendicular)
    {
      while (_bound.center_LETHAL != center_count && count < max_count)
      {
        count++;
        if(_bound.vertical) costmap_coords.y += acum;
        else costmap_coords.x += acum;
        index_ = getIndex(costmap_coords);
        value = msg->data[index_];
        if(value == LETHAL_OBSTACLE) center_count++;
      }
      if (count < max_count) _bound.center_point = CostmapToMap( indexToCostmap(index_) );
    }

    //NOW FINDING THE CLOSER OBSTACLE AT PARALEL DIRECTION
    else
    {
      while (value != LETHAL_OBSTACLE && value != -1 && count < max_count)
      {
        count++;
        if(_bound.vertical) costmap_coords.x -= acum;
        else costmap_coords.y += acum;
        index_ = getIndex(costmap_coords);
        value = msg->data[index_];
      }
      if (value == -1)
      {
        unknown_limit = true;
        geometry_msgs::Point unkP = CostmapToMap( indexToCostmap(index_) );
      }
      //UPDATE THE LIMIT OF THE OBSTACLE FOUND
      if (positiveDirection)
      {
        if (_bound.vertical) _bound.point_left_min = CostmapToMap( indexToCostmap(index_) );
        else _bound.point_left_max = CostmapToMap( indexToCostmap(index_) );
      }
      else
      {
        if (_bound.vertical) _bound.point_right_max = CostmapToMap( indexToCostmap(index_) );
        else _bound.point_right_min = CostmapToMap( indexToCostmap(index_) );
      }
    }
  }

  //FIND LIMIT (PARALEL)
  else
  {
    while (value == LETHAL_OBSTACLE && count < max_count)
    {
      count++;
      if(_bound.vertical) costmap_coords.x -= acum;
      else costmap_coords.y += acum;
      index_ = getIndex(costmap_coords);
      value = msg->data[index_];
    }
    //ROS_INFO("size paralel: %d", count);


    //UPDATE THE LIMIT OF THE OBSTACLE FOUND
    if (positiveDirection)
    {
      if (_bound.vertical) _bound.point_left_max = CostmapToMap( indexToCostmap(index_) );
      else _bound.point_left_min = CostmapToMap( indexToCostmap(index_) );
    }
    else
    {
      if (_bound.vertical) _bound.point_right_min = CostmapToMap( indexToCostmap(index_) );
      else _bound.point_right_max = CostmapToMap( indexToCostmap(index_) );
    }
  }
  return count;
}

//Need to test corners!
bool CostmapRes::matchBound(CostmapRes::Bound &_bound, const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
  int count = 0;
  bool matched = false;
  geometry_msgs::Point costmap_coords = MapToCostmap(_bound.center_point);

  //try in the perpendicular positive direction
  count = findInCostmap(_bound, true, msg, costmap_coords, max_count_findPerpendicularObstacle, true, true);
  if( count == max_count_findPerpendicularObstacle) count = findInCostmap(_bound, true, msg, costmap_coords, max_count_findPerpendicularObstacle, true, false);
  //if center found reset the costmap_coords and calculate limits
  if( count < max_count_findPerpendicularObstacle)
  {

    costmap_coords = MapToCostmap(_bound.center_point);
    geometry_msgs::Point Limit;
    _bound.center_found = true;
    //ROS_INFO("CENTER FOUND");
    //FIND LIMITS OF THE SELECTED OBSTACLE
    //left limit
    _bound.size_count += findInCostmap(_bound, false, msg, costmap_coords, max_count_findLimits, false, true);
    //check if corner?
    bool left_corner;
    if(_bound.vertical)
    {
      Limit = MapToCostmap(_bound.point_left_max);
      Limit.x += 1;
      left_corner = checkifCorner(_bound, Limit, msg, true, 4);
      //try the other direction
      if (!left_corner) left_corner = checkifCorner(_bound, Limit, msg, false, 4);
    }
    else
    {
      Limit = MapToCostmap(_bound.point_left_min);
      Limit.x -= 1;
      left_corner = checkifCorner(_bound, Limit, msg, true, 4);
      if (!left_corner) left_corner = checkifCorner(_bound, Limit, msg, false, 4);
    }
    //IF IS A CORNER DONT NEED TO RECALCULATE LIMITS!
    if (left_corner)
    {
      //ROS_INFO("IS LEFT CORNER!");
      _bound.recalculateleft = false;
      if(_bound.vertical) _bound.point_left_min = _bound.point_left_max;
      else _bound.point_left_max = _bound.point_left_min;
    }

    //right limit
    _bound.size_count += findInCostmap(_bound, false, msg, costmap_coords, max_count_findLimits, false, false);

    //Check if corner?
    bool right_corner;

    if(_bound.vertical)
    {
      Limit = MapToCostmap(_bound.point_right_min);
      //shift to left to get the last cell of the bound
      Limit.y -= 1;
      right_corner = checkifCorner(_bound, Limit, msg, true, 4);
      //try the other direction
      if (!right_corner) left_corner = checkifCorner(_bound, Limit, msg, false, 4);
    }
    else
    {
      Limit = MapToCostmap(_bound.point_right_max);
      //shift to left to get the last cell of the bound
      Limit.y += 1;
      right_corner = checkifCorner(_bound, Limit, msg, true, 4);
      if (!right_corner) right_corner = checkifCorner(_bound, Limit, msg, false, 4);
    }
    //IF IS A CORNER DONT NEED TO RECALCULATE LIMITS!
    if (right_corner)
    {
      //ROS_INFO("IS RIGHT CORNER!");
      _bound.recalculateright = false;
      if(_bound.vertical) _bound.point_right_max = _bound.point_right_min;
      else _bound.point_right_min = _bound.point_right_max;
    }
  }
//  else ROS_INFO("CENTER NOT FOUND");

  //ROS_INFO("bound size: %d", _bound.size_count);
  if(_bound.center_found)
  {
    if (_bound.size_count >= min_count_size && _bound.size_count < max_count_size)
    {
      matched = true;
      //ROS_INFO("size: %d", _bound.size_count);
      //if bound matched recalculate the center based on the limits!
      //ROS_INFO("Last center x: %f", _bound.center_point.x);
      //ROS_INFO("Last center y: %f", _bound.center_point.y);
      if(_bound.vertical) _bound.center_point.x = (_bound.point_right_min.x + _bound.point_left_max.x) / 2;
      else _bound.center_point.y = (_bound.point_left_min.y + _bound.point_right_max.y) / 2;
      //ROS_INFO("New center x: %f", _bound.center_point.x);
      //ROS_INFO("New center y: %f", _bound.center_point.y);
    }
    else
    {
      //ROS_INFO("LIMITS NOT MATCHED YET");
      _bound.size_count = 0;
    }
  }

  return matched;
}

void CostmapRes::resetBound(CostmapRes::Bound &actual_bound)
{
  ROS_INFO("RESETING BOUND");
  actual_bound.count = 0;
  actual_bound.recalculate = true;
  actual_bound.recalculateleft = true;
  actual_bound.recalculateright = true;
  if(actual_bound.vertical)
  {
    actual_bound.point_right_max = actual_bound.point_right_min;
    actual_bound.point_right_max.x++;
    actual_bound.point_left_min = actual_bound.point_left_max;
    actual_bound.point_left_min.x--;
  }
  else
  {
    actual_bound.point_right_min = actual_bound.point_right_max;
    actual_bound.point_right_min.y--;
    actual_bound.point_left_max = actual_bound.point_left_min;
    actual_bound.point_left_max.y++;
  }
  //SEND THE INITIAL SIZE OF THE BOUND TO FAKE LASER
  ROS_INFO("Laser Index Reset: %d", actual_bound.laser_index);
  bound_.index = actual_bound.laser_index;
  bound_.pointleftmin = actual_bound.point_left_min;
  bound_.pointleftmax = actual_bound.point_left_max;
  bound_.pointrightmin = actual_bound.point_right_min;
  bound_.pointrightmax = actual_bound.point_right_max;
  bound_.isvertical = actual_bound.vertical;
  bound_.exit = actual_bound.exit;
  if(bound_.exit) ROS_INFO ("Fail, can not reset the exit right now");
  bound_.resize = true;
  fake_bound_pub.publish(bound_);
}

bool CostmapRes::checkifCorner(CostmapRes::Bound &_bound, geometry_msgs::Point costmap_coords,
                               const nav_msgs::OccupancyGrid::ConstPtr& msg, bool positiveDirection,
                               int n_points)
{
  //SAME AS IN FIND IN COSTMAP BUT NOT MODIFYING POINTS ONLY CHECKING
  int count = 0;
  int acum = 0;
  if (positiveDirection) acum = 1;
  else acum = -1;
  auto index_ = getIndex( costmap_coords );
  auto value = msg->data[index_];
  bool corner = false;

  while (value == LETHAL_OBSTACLE && count < n_points)
  {
    count++;
    if(_bound.vertical) costmap_coords.y += acum;
    else costmap_coords.x += acum;
    index_ = getIndex(costmap_coords);
    value = msg->data[index_];
    //ROS_INFO("value corner: %c", value);
  }
  if (count == n_points) corner = true;
  return corner;
}


void CostmapRes::recalculate_database_index(int data_index, int data_color)
{
  for (auto data_bound : matchqueue)
  {
    //resize because an erase on database candidates!
    if (data_bound.color == data_color && data_bound.database_index > data_index)
    data_bound.database_index--;
  }
}

bool CostmapRes::RecalculateService (turtlebot_2dnav::recalculateBound::Request &req,
                                     turtlebot_2dnav::recalculateBound::Response &res)
{
  canRecalculate = req.recalculate;
  res.received = true;
  return true;
}


bool CostmapRes::needUpdate(CostmapRes::Bound &_bound,geometry_msgs::Point l_min,
                            geometry_msgs::Point l_max, geometry_msgs::Point r_min,
                            geometry_msgs::Point r_max)
{
  bool equalleft = ( (isEqual(l_min, _bound.point_left_min)) && (isEqual(l_max, _bound.point_left_max)) );
  bool equalright = ( (isEqual(r_min, _bound.point_right_min)) && (isEqual(r_max, _bound.point_right_max)) );
  return ( !(equalleft && equalright) );
}

bool CostmapRes::isEqual(geometry_msgs::Point p1, geometry_msgs::Point p2)
{
  return ( (p1.x == p2.x) && (p1.y == p2.y) );
}

geometry_msgs::Point CostmapRes::MapToCostmap(geometry_msgs::Point point)
{
  geometry_msgs::Point costmap_point;
  costmap_point.x = (int)((point.x - origin_x) / resolution);
  costmap_point.y = (int)((point.y - origin_y) / resolution);
  return costmap_point;
}

unsigned int CostmapRes::getIndex(geometry_msgs::Point point)
{
  unsigned int mx = (unsigned int) point.x;
  unsigned int my = (unsigned int) point.y;
  unsigned int index = my * size_in_cells_x + mx;
  return index;
}

geometry_msgs::Point CostmapRes::indexToCostmap(unsigned int index)
{
  geometry_msgs::Point costmap_coord;
  costmap_coord.y = index / size_in_cells_x;
  costmap_coord.x = index - (costmap_coord.y * size_in_cells_x);
  return costmap_coord;
}

geometry_msgs::Point CostmapRes::CostmapToMap(geometry_msgs::Point point)
{
  geometry_msgs::Point map_point;
  map_point.x = origin_x + (point.x + 0.5) * resolution;
  map_point.y = origin_y + (point.y + 0.5) * resolution;
  return map_point;
}
