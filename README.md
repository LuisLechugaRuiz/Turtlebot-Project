
# Turtlebot Project

![Example](https://github.com/LuisLechugaRuiz/Turtlebot-Project/blob/master/images/Screenshot%20from%202020-03-26%2021-55-58.png) 

This project is part of the Master in Robotics of the UVIC - Eurecat.

## Description:

The framework used is ROS (Melodic), Gazebo as simulator and RVIZ as visualizator.

The purpose is to simulate a rescue task using a mobile robot in an unknown interior zone, where external technologies like GPS fails.

A fixed number of persons are located in unknow positions, the maze has one exit and some risks which needs to be avoided when the robot is carrying a person. 

The objective is to take all the persons out in the minimum time, the robot can only carry one person at the same time. When the robot save a person before half time it is awarded with double number of points. 

Walls of differents colors are placed inside of the maze to ease the perception task:

![#1589F0](https://placehold.it/100/1589F0/ffffff/?text=PERS)  ![#1589F0](https://placehold.it/100/f03c15/ffffff/?text=RISK)
![#008000](https://placehold.it/100/008000/ffffff/?text=EXIT)  

## Distribution

### Hardware
The robot is a Kobuki based on a turtlebot2. The main difference with the standard turtlebots is the use of a LIDAR (in our case the RPLidar 360º https://github.com/LuisLechugaRuiz/Turtlebot-Project/blob/master/src/turtlebot_2dnav/sensors/rplidar.urdf.xacro)

### Mapping

In order to localizate and track the robot an SLAM technique based on gmapping has been implemented. Some modifications have been done to construct the map with the LIDAR information. 

### Navigation

The navigation stack is the biggest component of the project, the move_base node has been configured setting the parameters to work with our robot configuration (as the standard parameters of turtlebot are configured to receive information from the camera instead of the LIDAR). The parameters configuration is stored at the folder: https://github.com/LuisLechugaRuiz/Turtlebot-Project/tree/master/src/turtlebot_2dnav/param.

The global planner selected is the standard GlobalPlanner and the local planner is the Dynamic Window Approach (DWA) which use pluggins to avoid obstacle and smooth the plan.

### Exploration

The robot starts in an unknown position on the map and doesn't have any info about where is the exit, to explore the map efficiently a greedy exploration algorithm has been implemented and modified with an extra funcionality to control if the explore node publish goals or just serve information about unknown zones (frontiers).

The greedy exploration algorithm can be found at: http://wiki.ros.org/explore_lite

The modified version of this algorithm is located at: https://github.com/LuisLechugaRuiz/Turtlebot-Project/tree/master/src/m-explore

### Image Processor

In order to find regions of interest a node who process the camera information has been implemented using OpenCV.

The camera is an Orbec Astra Depth Camera which provides depth information of each pixel in addition to the rgb image.

This node publish two points (the limits) of each region of interest in the robot frame.

### Database

The points published by the Image Processor are referenced by the robot frame to locate them in the map this node makes the transformations (receiving the info submitted by the tf tree) from the "base-link" frame to "map" frame.

The image processor node publish information of each region of interest everytime the camera sees them. This information is affected by the robot movement, if the robot is rotating the depth image and the rgb are desynchronized sometimes and the regions are projected in another wall. To filter the received points and allocate a precised position in the map to each region this node uses a filter algorithm based on candidates which are updated dynamically and ascend to "database" if they accomplish some stricts requirements. 

### Decision Maker

All the previous nodes provides powerful funcionalities, this node is connected to most of them and determine when to use each of this funcionality.

A State Machine with 3 differents states (with different actions depending on the status of different variables) is used to control the purpose of the robot at each instant:

- Searching Exit: The robots start to make the map and doesn't know where is the exit yet, it will explore greedly until a person or the exit is found.

- Rescuing Person: In case the robot is not carrying any person and has located at least one it will carry the nearest person to the exit (if the exit is in an unknow position it comes back to searching exit state).

- Searching Person: When the exit is known and the robot has rescued all the persons that has seen during the exploration it start to explore greedly searching new persons and will return to rescuing person state once it founds one of them.

When the robot has rescued all the person this node stops and return the time spent during the rescue task.


## Dependencies


- The URDF of the RPLiDAR depends on http://wiki.ros.org/hector_sensors_description.

- The packages http://wiki.ros.org/kobuki, http://wiki.ros.org/kobuki_desktop and http://wiki.ros.org/kobuki_msgs for the real and simulated base.

- One of the main packages is http://wiki.ros.org/turtlebot_navigation which contains gmapping and a lot of different techinques to localizate and navigate based on a turtlebot. This node has been modify to include a funcionality at the Global Planner which provides the cost to reach a specific coordinates on the map, this modification is stored at: https://github.com/LuisLechugaRuiz/Turtlebot-Project/tree/master/src/navigation. 

- The eurecat_grobotics_project includes the map to realize the simulation.

