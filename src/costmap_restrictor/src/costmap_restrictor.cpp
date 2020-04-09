#include <costmap_restrictor.h>

CostmapRes::CostmapRes() :
  nh(ros::this_node::getName())
  {
  std::string costmap_topic;
  std::string footprint_topic;
  nh.param("costmap_topic", costmap_topic, std::string("costmap"));
  restrict_server = nh.advertiseService("restrict", &CostmapRes::RestrictService, this);
  costmap_sub_ = n.subscribe(costmap_topic, 1000, &CostmapRes::ProcessCostmap, this);
  bound_pub = nh.advertise<turtlebot_2dnav::fake_bound>("fake_bound", 10);
}

void CostmapRes::ProcessCostmap(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
  size_in_cells_x = msg->info.width;
  size_in_cells_y = msg->info.height;
  resolution = msg->info.resolution;
  origin_x = msg->info.origin.position.x;
  origin_y = msg->info.origin.position.y;
  if(queue.size() > 0)
  {
    if(queue[0].vertical)
    {
      index_left = getIndex( MapToCostmap(queue[0].point_left_max) );
      pleft = queue[0].point_left_max;
      index_right = getIndex( MapToCostmap(queue[0].point_right_min) );
      pright = queue[0].point_right_min;
    }
    else
    {
      index_left = getIndex( MapToCostmap(queue[0].point_left_min) );
      pleft = queue[0].point_left_min;
      index_right = getIndex( MapToCostmap(queue[0].point_right_max) );
      pright = queue[0].point_right_max;
    }
    value = msg->data[index_left];
    int count = 0;
    geometry_msgs::Point costmap_coords = MapToCostmap(pleft);

    //FIND THE OBSTACLE IN COSTMAP!
    //findCloserObstacle();
    //int count = 0;
    while (value != LETHAL_OBSTACLE && value != INSCRIBED_OBSTACLE && count < 10)
    {
        count++;
        if(queue[0].vertical) costmap_coords.y++;
        else costmap_coords.x++;
        index_left = getIndex(costmap_coords);
        value = msg->data[index_left];
    }


    //IF NOT FOUND TRY THE ANOTHER WAY
    if (count == 10)
    {
      //ROS_INFO("obstacle not found1");
      count = 0;
      costmap_coords = MapToCostmap(pleft);
      while (value != LETHAL_OBSTACLE && value != INSCRIBED_OBSTACLE && count < 10)
      {
          count++;
          if(queue[0].vertical) costmap_coords.y--;
          else costmap_coords.x--;
          index_left = getIndex(costmap_coords);
          value = msg->data[index_left];
          //ROS_INFO("value: %c", value);
          //if (count == 10) ROS_INFO("obstacle not found2");
      }
    }

    //FIND LEFT LIMIT
    if (count < 10)
    {
      count = 0;
      while ((value == LETHAL_OBSTACLE || value == INSCRIBED_OBSTACLE) && count < 15)
      {
        count++;
        if(queue[0].vertical) costmap_coords.x--;
        else costmap_coords.y++;
        index_left = getIndex(costmap_coords);
        value = msg->data[index_left];
        //ROS_INFO("value: %c", value);
      }
    }
    else
    {
      value = msg->data[index_left];
      costmap_coords = MapToCostmap(pleft);
    }



    //save the count for the right limit!
    auto _count = count;
    auto _costmap_coords = costmap_coords;

    count = 0;
    //FIND CLOSER OBSTACLE (TO THE LEFT) TO CLOSE THE WAY.
    while (value != LETHAL_OBSTACLE && value != INSCRIBED_OBSTACLE && count < 30)
    {
      count++;
      if(queue[0].vertical) costmap_coords.x--;
      else costmap_coords.y++;
      index_left = getIndex(costmap_coords);
      value = msg->data[index_left];
      //ROS_INFO("value: %c", value);
    }

    if (count == 30) queue[0].recalculateleft = true;
    else queue[0].recalculateleft = false;

    if(queue[0].vertical) queue[0].point_left_min = CostmapToMap( indexToCostmap(index_left) );
    else
    {
      queue[0].point_left_max = CostmapToMap( indexToCostmap(index_left) );
      //ROS_INFO("left point x: %f", queue[0].point_left_max.x);
      //ROS_INFO("left point y: %f", queue[0].point_left_max.y);
    }

    //FIND RIGHT LIMIT
    if (_count < 10)
    {
      count = 0;
      costmap_coords = _costmap_coords;
      while ((value == LETHAL_OBSTACLE || value == INSCRIBED_OBSTACLE) && count < 30)
      {
        count++;
        if(queue[0].vertical) costmap_coords.x++;
        else costmap_coords.y--;
        index_right = getIndex(costmap_coords);
        value = msg->data[index_right];
        //ROS_INFO("value: %c", value);
      }
    }

    else
    {
      value = msg->data[index_right];
      costmap_coords = MapToCostmap(pright);
    }

    //FIND CLOSER OBSTACLE (TO THE RIGHT) TO CLOSE THE WAY.
    count = 0;
    while (value != LETHAL_OBSTACLE && value != INSCRIBED_OBSTACLE && count < 30)
    {
      count++;
      if(queue[0].vertical) costmap_coords.x++;
      else costmap_coords.y--;
      index_left = getIndex(costmap_coords);
      value = msg->data[index_right];
    }

    if (count == 30) queue[0].recalculateright = true;
    else queue[0].recalculateright = false;

    if(queue[0].vertical) queue[0].point_right_max = CostmapToMap( indexToCostmap(index_right) );
    else
    {
      queue[0].point_right_min = CostmapToMap( indexToCostmap(index_right) );
      //ROS_INFO("right point x: %f", queue[0].point_right_min.x);
      //ROS_INFO("right point y: %f", queue[0].point_right_min.y);
    }
    //IF FIRST PROCESS
    if (queue[0].index  == -1)
    {
      queue[0].index = index;
      bound_.resize = false;
      index++;
    }
    else bound_.resize = true;

    bound_.index = queue[0].index;

    bound_.pointleftmin = queue[0].point_left_min;
    bound_.pointleftmax = queue[0].point_left_max;
    bound_.pointrightmin = queue[0].point_right_min;
    bound_.pointrightmax = queue[0].point_right_max;

    if (!queue[0].recalculateleft && !queue[0].recalculateright) queue.erase( queue.begin() );
    else
    {
      std::rotate(queue.begin(), queue.begin() + 1, queue.end());
      queue[0].count++;
    }
    bound_.isvertical = queue[0].vertical;
    bound_pub.publish(bound_);
  }
}

bool CostmapRes::RestrictService(turtlebot_2dnav::restrictCostmap::Request &req,
                                        turtlebot_2dnav::restrictCostmap::Response &res)
{
  //ROS_INFO("RECEIVED!");
  bound_.exit = req.exit;
  if(req.isvertical)
  {
    restringed_zone.vertical = true;
    restringed_zone.point_left_max = req.leftPoint;
    restringed_zone.point_right_min = req.rightPoint;
  }
  else
  {
    restringed_zone.vertical = false;
    restringed_zone.point_left_min = req.leftPoint;
    restringed_zone.point_right_max = req.rightPoint;
  }
  queue.insert(queue.begin(),restringed_zone);
  res.received = true;
  return res.received;
}


//void CostmapRes::findCloserObstacle()
//{

//}

geometry_msgs::Point CostmapRes::MapToCostmap(geometry_msgs::Point point)
{
  geometry_msgs::Point costmap_point;
  costmap_point.x = (point.x - origin_x) / resolution;
  costmap_point.y = (point.y - origin_y) / resolution;
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
