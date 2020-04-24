//ros dependencies
#include "astra_img_processor_node.h"

//node main
int main(int argc, char **argv)
{
      //init ros
      ros::init(argc, argv, "astra_img_processor");

      //create ros wrapper object
      AstraImgProcessorNode imgp;


      ros::Duration(1).sleep();
      
      //set node loop rate
      ros::Rate loopRate(imgp.getRate());

      //node loop
      while ( ros::ok() )
      {
            //execute pending callbacks
            ros::spinOnce();

            //do things
            imgp.process();

            //publish things
            imgp.publishImage();

            //relax to fit output rate
            loopRate.sleep();
      }

      //exit program
      return 0;
}
