#include <data.h>

data::data(geometry_msgs::PoseStamped New_Pose_)
{
  center.x = New_Pose_.pose.position.x;
  center.y = New_Pose_.pose.position.y;
  //Make size_y bigger than size_x so we go frontly to the frontier
  size_x = 0.2;
  size_y = 1.0;
}

data::data(turtlebot_2dnav::ROI ROI_)
{
  updateData(ROI_);
}

void data::updateData(turtlebot_2dnav::ROI updatedROI)
{
  center.x = updatedROI.center.x;
  center.y = updatedROI.center.y;
  type   = updatedROI.type;
  size_x = updatedROI.size_x;
  size_y = updatedROI.size_y;
  index  = updatedROI.index;
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


float data::get_size_x()
{
  return size_x;
}

float data::get_size_y()
{
  return size_y;
}

person::person(turtlebot_2dnav::ROI ROI, double initial_distance_) : data::data(ROI)
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
