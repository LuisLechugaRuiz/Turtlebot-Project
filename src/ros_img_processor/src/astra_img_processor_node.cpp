#include "astra_img_processor_node.h"

//OpenCV
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

//pcl
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>

//msgs
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>
#include <ros_img_processor/camera_POI_msg.h>

//std
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>

//Constructor

AstraImgProcessorNode::AstraImgProcessorNode () : nh_(ros::this_node::getName()), img_tp_(nh_) //¿?
{
	//loop rate [hz]
	rate_=10;
	
	//set publishers
	image_pub_ = img_tp_.advertise("image_out",100); 
	camera_POI_ = nh_.advertise <ros_img_processor::camera_POI_msg>("camera_POI", 1);

	//set subscribers
	depth_subs_ = nh_.subscribe("/camera/depth/image_raw", 1, &AstraImgProcessorNode::depthCallback, this);
	camera_info_subs_ = nh_.subscribe("/camera/rgb/camera_info", 100, &AstraImgProcessorNode::cameraInfoCallback, this);
}

void AstraImgProcessorNode::process()
{
	//check if there is a new image
	if( cv_img_ptr_in_!= nullptr)
	{ 
		//define variables
		std::vector<cv::Mat> contours, color;
		cv::Rect rectangle;
		std::vector<cv::String> identify ={"R","E","P"};
		pcl::PointXYZ pointleft;
		pcl::PointXYZ pointright;
		cv::Mat hsv_image, blue_mask, red_mask, red_mask1, red_mask2, green_mask;

		//copy the input image to the out one
		cv_img_out_.image = cv_img_ptr_in_->image;
			
		//Convert RGB image to HSV
		 cv::cvtColor(cv_img_ptr_in_->image, hsv_image, CV_BGR2HSV); 
		
		//Red color mask HSV
		cv::inRange(hsv_image, cv::Scalar(0, 70, 50), cv::Scalar(10, 255, 255), red_mask1);
      		cv::inRange(hsv_image, cv::Scalar(170, 70, 50), cv::Scalar(180, 255, 255), red_mask2);
      		red_mask = red_mask1 | red_mask2;
		color.push_back(red_mask);

		//Green color mask HSV
		cv::inRange(hsv_image, cv::Scalar(40, 100, 100), cv::Scalar(80, 255, 255), green_mask);
      		color.push_back(green_mask);

		//Blue color mask HSV
		cv::inRange(hsv_image,cv::Scalar(120,0,0),cv::Scalar(179,255,255),blue_mask);
      		color.push_back(blue_mask);


		//For each mask find and draw contours (rectangles)
		for(int i=0; i<3;i++)
		{
			cv::findContours(color[i], contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
			cv::drawContours(cv_img_out_.image, contours, -1, (0,0,0), 5);
			
			//Check if contours.size give back only an int or a vector.
        		for(int j = 0; j < contours.size(); j++)
			{
				rectangle = cv::boundingRect(contours[j]);
				
				sensor_msgs::Image depth;
				
				//find the center of the rectangle
				cv::Point rectanglecenter;
          			rectanglecenter.x = rectangle.x + rectangle.width/2;
          			rectanglecenter.y = rectangle.y + rectangle.height/2;				
				
				//Find depth to control points
				/*pointleft = depth.at(rectangle.x + 10, rectangle.y + rectangle.height/2);
          			pointright = depth.at(rectangle.x + rectangle.width - 10, rectangle.y + rectangle.height/2);*/
				
				pointleft.z = depth.data[rectangle.x + 10, rectangle.y + rectangle.height/2];
          			pointright.z = depth.data[rectangle.x + rectangle.width - 10, rectangle.y + rectangle.height/2];
				ROS_INFO_STREAM(pointleft.z);
				ROS_INFO_STREAM(pointright.z);

				//text with data
          			cv::putText(cv_img_out_.image, identify[i], rectanglecenter, CV_FONT_HERSHEY_DUPLEX, 2, (0,255,0), 10);
				
				//check if it is a complete rectangle
				if (std::isnan(pointleft.x) || std::isnan(pointleft.y) || std::isnan(pointright.x) || std::isnan(pointright.y));
				else{
					//we keep the point POI
					std::string id = identify[i];
					ros_img_processor::camera_POI_msg POI;
					
					//Fill data in Camera_POI_msg
          				 POI.Header.frame_id = "camera";
            				//is wrong, must save the time when the process start ¿?
            				POI.Header.stamp = arriveTime;
            				POI.type = id;
           			    	POI.pointleft.x = pointleft.x;
            				POI.pointleft.y = pointleft.y;
            				POI.pointleft.z = pointleft.z;
            				POI.pointright.x = pointright.x;
            				POI.pointright.y = pointright.y;
            				POI.pointright.z = pointright.z;
            				camera_POI_.publish(POI);
				}
			}
		}

	}
        // reset input image
	cv_img_ptr_in_=nullptr;
}

//Destructor
AstraImgProcessorNode::~AstraImgProcessorNode()
{
    //
}


void AstraImgProcessorNode::publishImage()
{
	//check that there is info
	if( !cv_img_out_.image.data ) return;

   	cv_img_out_.header.seq ++;
    	cv_img_out_.header.stamp = ros::Time::now();
    	cv_img_out_.header.frame_id = "camera";
    	cv_img_out_.encoding = sensor_msgs::image_encodings::BGR8;
    	image_pub_.publish(cv_img_out_.toImageMsg());

}

void AstraImgProcessorNode::depthCallback(const sensor_msgs::ImageConstPtr & _msg)
{
    try
    {
        img_encoding_ = _msg->encoding;//get image encodings
        cv_img_ptr_in_ = cv_bridge::toCvCopy(_msg, _msg->encoding);//get image
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("RosImgProcessorNode::image_callback(): cv_bridge exception: %s", e.what());
        return;
    }
}
void AstraImgProcessorNode::cameraInfoCallback(const sensor_msgs::CameraInfo & _msg)
{
	matrixK_  << _msg.K[0],_msg.K[1],_msg.K[2],
                 _msg.K[3],_msg.K[4],_msg.K[5],
                 _msg.K[6],_msg.K[7],_msg.K[8];
}

