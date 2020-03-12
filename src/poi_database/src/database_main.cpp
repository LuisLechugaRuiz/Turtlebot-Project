//ros dependencies
#include "database.h"

//node main
int main(int argc, char **argv)
{
      ros::init(argc, argv, "POI_database_node");

      DatabaseNode  Database_ROI;

      //should be similar to ros_img_processor and camera (for a future optimization maybe)
      ros::Rate loopRate(10);

      while ( ros::ok() )
      {
            //execute pending callbacks
            ros::spinOnce();

            //Transform from camera
            Database_ROI.process();

            Database_ROI.PublishMarkers();

            loopRate.sleep();
      }

      //exit program
      return 0;
}
