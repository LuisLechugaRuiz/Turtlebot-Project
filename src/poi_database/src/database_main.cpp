//ros dependencies
#include "database.h"

//node main
int main(int argc, char **argv)
{
      ros::init(argc, argv, "POI_database");

      DatabaseNode  Database_ROI;

      ros::Duration(1).sleep();

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
