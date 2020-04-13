#include <fake_laser.h>

int main(int argc, char **argv)
{
    // setup ros for this node and get handle to ros system
    ros::init(argc, argv, "fake_laser");

    fake_laser fakeLaser;
    ros::Rate loopRate(10);
    while ( ros::ok() )
    {
        ros::spinOnce();

        fakeLaser.Processqueue();
        
        fakeLaser.PublishCloud();

        // pause for loop delay
        loopRate.sleep();
    }

    return 0;
}
