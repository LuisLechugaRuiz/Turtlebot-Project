#include <data.h>

data::data(geometry_msgs::PoseStamped New_Pose)
{
  center.x = New_Pose.pose.position.x;
  center.y = New_Pose.pose.position.y;
  //Make size_y bigger than size_x so we go frontly to the frontier
  size_x = 0.2;
  size_y = 1.0;
}

data::data(turtlebot_2dnav::ROI ROI_)
{
  updateDataROI(ROI_);
}

void data::updateDataROI(turtlebot_2dnav::ROI ROI_)
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

int data::get_index()
{
  return index;
}

person::person(turtlebot_2dnav::ROI ROI_, double initial_distance_) : data::data(ROI_)
{
  updateData(initial_distance_);
  updateData(false);
}


void person::updateData(double New_Distance)
{
  distance = New_Distance;
}

void person::updateData(bool rescued_)
{
  rescued = rescued_;
}


void person::updateData(geometry_msgs::Pose New_Pose)
{
  center = New_Pose.position;
}

double person::get_distance()
{
  return distance;
}

bool person::get_rescued()
{
  return rescued;
}

void person::set_rescued()
{
  updateData(true);
}