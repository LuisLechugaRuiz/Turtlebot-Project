#include <turtlebot_2dnav/ROI.h>
#include <geometry_msgs/PoseStamped.h>

class data
{
  public:
    data(turtlebot_2dnav::ROI ROI_);

    data(geometry_msgs::PoseStamped New_Pose);

    void updateDataROI(turtlebot_2dnav::ROI ROI_);

    bool data_index_equal_to(int index_);

    float get_center_x ();

    float get_center_y ();

    bool is_vertical();

    int get_index();

  protected:
    geometry_msgs::Point center;
    float size_x;
    float size_y;
    std::string type;
    int index;
};

class person : public data
{
  public:
    person(turtlebot_2dnav::ROI ROI_, double initial_distance_);

    void updateData(double New_Distance);

    void updateData(bool rescued_);

    void updateData(geometry_msgs::Pose New_Pose);

    void set_rescued();

    bool get_rescued();

    double get_distance();

    double distance;
  private:

    bool rescued;
};
