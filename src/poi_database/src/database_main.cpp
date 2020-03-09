//ros dependencies
#include "database.h"

//node main
int main(int argc, char **argv)
{
      ros::init(argc, argv, "POI_database_node");

      Database Database_POI;

      ros::Rate loopRate(10);

      while ( ros::ok() )
      {
            //execute pending callbacks
            ros::spinOnce();

            //Transform from camera
            Database_POI.process();

            Database_POI.PublishMarkers();

            //relax to fit output rate
            loopRate.sleep();
      }

      //exit program
      return 0;
}
