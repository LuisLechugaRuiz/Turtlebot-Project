#include <fake_laser.h>

fake_laser::fake_laser() :
  nh(ros::this_node::getName())
{
  laser_pub = nh.advertise<pcl::PointCloud<pcl::PointXYZ>>("cloud",1000);
  bounds_sub = n.subscribe("costmap_restrictor/fake_bound", 100, &fake_laser::boundsCallback, this);
  Cloud.header.frame_id = "map";
  exitCloud.header.frame_id = "map";
  active_srv = nh.advertiseService("active", &fake_laser::active_service, this);
  bounds_list_pub = nh.advertise<turtlebot_2dnav::bounds_point_size>("bound_list", 1);
  markers_pub = nh.advertise<visualization_msgs::Marker>("visualization_markers",10);
}

void fake_laser::boundsCallback(turtlebot_2dnav::fake_bound bound)
{
  queue.push_back(bound);
}

void fake_laser::Processqueue()
{
  if(queue.size() > 0)
  {
    bool exitbool = false;

    if(queue[0].exit) index_exit = queue[0].index;
    //check here (in case of new or resize exit)
    if(queue[0].index == index_exit) exitbool = true;

    //Get the number of points of the last bound
    int first_index, index_left, index_right;

    if(queue[0].index == 0) first_index = 0;
    else first_index = bounds[queue[0].index - 1];

    //check if need to resize
    //if(queue[0].resize) deleteBound( first_index, bounds[queue[0].index], queue[0].index, exitbool);


    index_left = insertPoints(queue[0].pointleftmin, queue[0].pointleftmax, first_index, queue[0].isvertical, true, exitbool);

    //update first_index for the right points
    first_index += index_left;

    index_right = insertPoints(queue[0].pointrightmin, queue[0].pointrightmax, first_index, queue[0].isvertical, false, exitbool);

    int last_index = first_index + index_right;

    //insert the new numbers of point in the bounds vector
    bounds.insert( bounds.begin() + queue[0].index, last_index );
    p_size.points_size.insert( p_size.points_size.begin() + queue[0].index, last_index );
    updateMarker(queue[0].index, exitbool, queue[0].resize, queue[0].pointleftmin, queue[0].pointleftmax, queue[0].pointrightmin, queue[0].pointrightmax);


    //if resized update the bounds vector
    //f(queue[0].resize) updateBoundlist(queue[0].index, last_index);

    queue.erase( queue.begin() );
  }
}


int fake_laser::insertPoints(geometry_msgs::Point pmin, geometry_msgs::Point pmax, int points_index, bool vertical, bool left, bool exitbool)
{
  float size;
  geometry_msgs::Point point;
  //0.3 to avoid inflating the cell which the costmap restrictor is studying. (need check)
  if(vertical)
  {
    size = pmax.x - pmin.x - 0.3;
    if (size < 0) size = 0;
    if(left) point = pmax;
    else point = pmin;
  }
  else
  {
    size = pmax.y - pmin.y - 0.3;
    if (size < 0) size = 0;
    if(left) point = pmin;
    else point = pmax;
  }
  int index = size / (resolution/2);
  for (int i = 0; i < index; i++)
  {
    pcl::PointXYZ newPoint;
    newPoint.x = point.x;
    newPoint.y = point.y;
    newPoint.z = 0.2;

    if(exitbool) exitCloud.points.push_back( newPoint );
    Cloud.points.insert( Cloud.points.begin() + points_index, newPoint );
    points_index++;
    if (vertical)
    {
      if(left) point.x -= (resolution/2);
      else point.x += (resolution/2);
    }
    else
    {
      if(left) point.y += (resolution/2);
      else point.y -= (resolution/2);
    }
  }
  //ROS_INFO("inserted");
  return index;
}


void fake_laser::deleteBound(int first_index, int last_index, int bound_index, bool exitbool)
{

    int dif_index = last_index - first_index;
    //clear points of cloud
    Cloud.points.erase(Cloud.points.begin() + first_index, Cloud.points.begin() + last_index);
    //ROS_INFO("DELETING POINTS: %d", dif_index);
    if (exitbool)
    {
      exitCloud.points.erase(exitCloud.points.begin(), exitCloud.points.begin() + dif_index);
      //ROS_INFO("deleting points: %d", dif_index);
    }

    if (bound_index < bounds.size() - 1)
    {
      for(int j = bound_index + 1; j < bounds.size(); j++)
      {
        bounds[j] -= dif_index;
        p_size.points_size[j] -= dif_index;
      }
    }
    //clear the vector which contains the size of each bound
    bounds.erase(bounds.begin() + bound_index);
    p_size.points_size.erase(p_size.points_size.begin() + bound_index);
}

void fake_laser::updateBoundlist( int vector_index, int total_new_points)
{
  //ROS_INFO("UPDATING POINTS: %d", total_new_points);
  for (int i = vector_index + 1; i < bounds.size(); i++)
  {
    bounds[i] += total_new_points;
    p_size.points_size[i] += total_new_points;
  }
}

void fake_laser::updateMarker(int bound_index, bool exitbool, bool resize,
                              geometry_msgs::Point pointleftmin_,
                              geometry_msgs::Point pointleftmax_,
                              geometry_msgs::Point pointrightmin_,
                              geometry_msgs::Point pointrightmax_)
{
  update_marker = true;
  markers.color.r = 0.0;
  markers.color.g = 0.0;
  markers.color.b = 0.0;
  markers.color.a = 1.0;
  markers.scale.x = 1.0;
  //insert 4 times the same color (first and last point of the bound)
  //ROS_INFO("UPDATED");
  if(resize)
  {
    markers_points[4*bound_index] =  pointleftmin_;
    markers_points[4*bound_index + 1] = pointleftmax_;
    markers_points[4*bound_index + 2] = pointrightmin_;
    markers_points[4*bound_index + 3] = pointrightmax_;
  }
  else
  {
    markers_points.insert(markers_points.begin() + 4*bound_index, pointleftmin_);
    markers_points.insert(markers_points.begin() + 4*bound_index + 1, pointleftmax_);
    markers_points.insert(markers_points.begin() + 4*bound_index + 2, pointrightmin_);
    markers_points.insert(markers_points.begin() + 4*bound_index + 3, pointrightmax_);
  }
  if(exitbool)
  {
    update_exit = true;
    markers_exit.clear();
    markers_exit.push_back(pointleftmin_);
    markers_exit.push_back(pointleftmax_);
    markers_exit.push_back(pointrightmin_);
    markers_exit.push_back(pointrightmax_);
  }
  markers.header.frame_id = "map";
  markers.pose.orientation.w = 1.0;
  markers.scale.x = 0.2;
  markers.type = visualization_msgs::Marker::LINE_LIST;
}

bool fake_laser::active_service(turtlebot_2dnav::fakeLaser::Request &req,
                            turtlebot_2dnav::fakeLaser::Response &res)
{
  ON = req.active;
  res.received = true;
  if(!ON)
  {
    markers.points.clear();
    markers.colors.clear();
    if(update_exit)
    {
      markers.points.insert(markers.points.begin(), markers_exit.begin(), markers_exit.end());
      markers.colors.insert(markers.colors.begin(), 4, markers.color);
      markers.header.frame_id = "map";
      markers.header.stamp = ros::Time::now();
    }
    markers_pub.publish(markers);
  }
  else update_marker = true;
  return true;
}

void fake_laser::PublishCloud()
{
  // publish point cloud
  if(ON)
  {
    p_size.red_zones_active = true;
    Cloud.header.stamp = ros::Time::now().sec;
    laser_pub.publish(Cloud.makeShared());
    if(update_marker)
    {
      markers.points.clear();
      markers.colors.clear();
      markers.points.insert(markers.points.begin(), markers_points.begin(), markers_points.end());
      markers.colors.insert(markers.colors.begin(), markers_points.size(), markers.color);
      markers.header.frame_id = "map";
      markers.header.stamp = ros::Time::now();
      markers_pub.publish(markers);
      update_marker = false;
    }
  }
  else
  {
    p_size.red_zones_active = false;
    exitCloud.header.stamp = ros::Time::now().sec;
    laser_pub.publish(exitCloud.makeShared());
  }
  bounds_list_pub.publish(p_size);
}
