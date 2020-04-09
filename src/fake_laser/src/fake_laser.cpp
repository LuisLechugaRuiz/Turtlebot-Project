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
}

void fake_laser::boundsCallback(turtlebot_2dnav::fake_bound bound)
{
  //Get the number of points of the last bound
  int first_index, index_left, index_right;

  if(bound.index == 0) first_index = 0;
  else first_index = bounds[bound.index - 1];

  //check if need to resize
  if(bound.resize) deleteBound( first_index, bounds[bound.index], bound.index);

  index_left = insertPoints(bound.pointleftmin, bound.pointleftmax, first_index, bound.isvertical, bound.exit);

  //update first_index for the right points
  first_index += index_left;

  index_right = insertPoints(bound.pointrightmin, bound.pointrightmax, first_index, bound.isvertical, bound.exit);

  int last_index = first_index + index_right;

  //insert the new numbers of point in the bounds vector
  bounds.insert( bounds.begin() + bound.index, last_index );
  p_size.points_size.insert( p_size.points_size.begin() + bound.index, last_index );

  //if resized update the bounds vector
  if(bound.resize) updateBoundlist(bound.index, last_index);
}

int fake_laser::insertPoints(geometry_msgs::Point pmin, geometry_msgs::Point pmax, int points_index, bool vertical, bool exitbool)
{
  float size;
  if(vertical) size = abs(pmax.x - pmin.x);
  else size = abs(pmax.y - pmin.y);
  int index = size / (resolution/2);

  geometry_msgs::Point point = pmin;
  for (int i = 0; i < index; i++)
  {
    pcl::PointXYZ newPoint;
    newPoint.x = point.x;
    newPoint.y = point.y;
    newPoint.z = 0.2;

    if(exitbool) exitCloud.points.push_back( newPoint );
    Cloud.points.insert( Cloud.points.begin() + points_index, newPoint );
    points_index++;
    if (vertical) point.x += (resolution/2);
    else point.y += (resolution/2);
  }
  return index;
}


void fake_laser::deleteBound(int first_index, int last_index, int bound_index)
{
    int dif_index = last_index - first_index;
    //clear points of cloud
    Cloud.points.erase(Cloud.points.begin() + first_index, Cloud.points.begin() + last_index);
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
  for (int i = vector_index + 1; i < bounds.size(); i++)
  {
    bounds[i] += total_new_points;
    p_size.points_size[i] += total_new_points;
  }
}


bool fake_laser::active_service(turtlebot_2dnav::fakeLaser::Request &req,
                            turtlebot_2dnav::fakeLaser::Response &res)
{
  ON = req.active;
  res.received = true;
  return true;
}

void fake_laser::PublishCloud()
{
  //broadcaster.sendTransform(
  //tf::StampedTransform( tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, 0.2)),
  //                      ros::Time(0),"map", "fakelaser"));
  // publish point cloud
  if(ON)
  {
    p_size.red_zones_active = true;
    Cloud.header.stamp = ros::Time::now().sec;
    laser_pub.publish(Cloud.makeShared());
  }
  else
  {
    p_size.red_zones_active = false;
    exitCloud.header.stamp = ros::Time::now().sec;
    laser_pub.publish(exitCloud.makeShared());
  }
  bounds_list_pub.publish(p_size);
}
