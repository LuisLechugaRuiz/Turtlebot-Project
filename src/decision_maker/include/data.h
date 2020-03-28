#include <poi_database/ROI.h>
#include <geometry_msgs/PoseStamped.h>

class data
{
  public:
    data(poi_database::ROI ROI_);

    data(geometry_msgs::PoseStamped New_Pose);

    void updateData(poi_database::ROI ROI_);

    bool data_index_equal_to(int index_);

    float get_center_x ();

    float get_center_y ();

    bool is_vertical();

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
    person(poi_database::ROI ROI_, int initial_cost);

    void updateData(int New_Cost);

    void updateData(bool rescued_);

    void set_rescued();

    bool get_rescued();

    int get_cost();

    int cost;
  private:

    bool rescued;
};
