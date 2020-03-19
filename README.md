
# Turtlebot Project
## Description:

This project is part of the Master in Robotics of the UVIC - Eurecat.

The framework used is ROS (Melodic), Gazebo as simulator and RVIZ as visualizator.

The purpose is to simulate a rescue task using a mobile robot in an unknown interior zone, where external technologies like GPS fails.

A fixed number of persons are located in unknow positions, the maze has one exit and some risks which needs to be avoided when the robot is carrying a person. 

The objective is to take all the persons out in the minimum time, the robot can only carry one person at the same time. The persons that the robot take out before the half time give double of points. 

Walls of differents colors are placed inside of the maze to ease the perception task:

![#1589F0](https://placehold.it/100/1589F0/ffffff/?text=PERS)  ![#1589F0](https://placehold.it/100/f03c15/ffffff/?text=RISK)
![#008000](https://placehold.it/100/008000/ffffff/?text=EXIT)  

## Distribution

### Hardware
The robot is a Kobuki based on a turtlebot2. The main difference with the standar turtlebots is the use of a LiDAR (in our case the RPLidar 360º). RPLiDAR URDF -> (https://github.com/LuisLechugaRuiz/Turtlebot-Project/blob/master/src/turtlebot_2dnav/sensors/rplidar.urdf.xacro)

#### Dependency 

The URDF of the RPLiDAR depends on http://wiki.ros.org/hector_sensors_description.
The packages http://wiki.ros.org/kobuki, http://wiki.ros.org/kobuki_desktop and http://wiki.ros.org/kobuki_msgs for the real and simulated base. 

### Mapping

In order to localizate and track the robot an SLAM technique based on gmapping has been implemented. Some modifications have been done to construct the map with the LiDAR information.

#### Dependency 

One of the main packages is http://wiki.ros.org/turtlebot_navigation which contains gmapping and a lot of different techinques to localizate and navigate based on a turtlebot.


### Navigation

This

### Exploration

### Image Processor

### Database

### Decision Maker

