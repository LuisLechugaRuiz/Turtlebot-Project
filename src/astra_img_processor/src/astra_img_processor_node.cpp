#include "astra_img_processor_node.h"

//OpenCV
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/rgbd.hpp>
//image
#include <image_geometry/pinhole_camera_model.h>
#include <sensor_msgs/image_encodings.h>
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

AstraImgProcessorNode::AstraImgProcessorNode () : 
	nh_(ros::this_node::getName()), 
	img_tp_(nh_) 
{
	//loop rate [hz]
	rate_ = 10;
	
	//set publishers
        image_pub_ = img_tp_.advertise("image_out", 100);
	camera_POI = nh_.advertise<ros_img_processor::camera_POI_msg>("camera_POI", 1);

	//set subscribers
	image_info_subs_ = img_tp_.subscribeCamera ("image_in", 1, &AstraImgProcessorNode::imageCallback,this);
	depth_info_subs_ = img_tp_.subscribeCamera ("image_depth_in", 1, &AstraImgProcessorNode::depthCallback,this);
}

//Destructor
AstraImgProcessorNode::~AstraImgProcessorNode()
{
    //
}

void AstraImgProcessorNode::process()
{
	//define variables
        
	std::vector<cv::Mat> contours, color;
	cv::Rect rectangle;
	std::vector<cv::String> identify ={"R","E","P"};
	cv::Point3d pointleft;
	cv::Point3d pointright;
	cv::Mat hsv_image, blue_mask, red_mask, red_mask1, red_mask2, green_mask;
	cv::Point2d uv_left;
	cv::Point2d uv_right;
	
    	//check if new image is there
   		 if ( cv_img_ptr_in_ != nullptr )
   		 {
  
			//copy the input image to the out one
			cv_img_out_.image = cv_img_ptr_in_->image;
		
			//Convert RGB image to HSV
		 	cv::cvtColor(cv_img_out_.image, hsv_image, CV_BGR2HSV); 
		
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
				
					//find the center of the rectangle
					cv::Point rectanglecenter;
          				rectanglecenter.x = rectangle.x + rectangle.width/2;
          				rectanglecenter.y = rectangle.y + rectangle.height/2;				

					//Find point XYZ of control points
					uv_left = cv::Point2d(rectangle.x + 10,rectanglecenter.y);
                               		uv_right = cv::Point2d(rectangle.x + rectangle.width - 10,rectanglecenter.y);
					
					//pixel u,v to point (x/z,y/z,1) in camera_frame 
					pointleft = cam_model_image_.projectPixelTo3dRay(uv_left);
					pointright = cam_model_image_.projectPixelTo3dRay(uv_right);
					
					//depth in pixel u,v
					pointleft.z = depth.at<float>(uv_left);
					pointright.z = depth.at<float>(uv_right);
					
					// point (x,y)
					/*pointleft.x = pointleft.x * pointleft.z;
					pointright.x = pointright.x * pointright.z;
					pointleft.y = pointleft.y * pointleft.z;
					pointright.y = pointright.y * pointright.z;*/

/*
					int pxy[2]={2,2};
					pxy[0,0]=pointleft.x;
					pxy[0,1]=pointleft.y;
					pxy[1,0]=pointright.x;
					pxy[1,1]=pointright.y;

					int points3d[2]={3,3};
                              		int pxyz[2]={3,3};
					pxyz = cv::rgbd::depthTo3dSparse(cv_img_ptr_depth_->image,  cam_model_depth_.K_, pxy, points3d);*/

					//text with data
          				cv::putText(cv_img_out_.image, identify[i], rectanglecenter, CV_FONT_HERSHEY_DUPLEX, 2, (0,255,0), 10);
				
					//check if it is a complete rectangle
					if(std::isnan(pointleft.x) || std::isnan(pointleft.y)
            					|| std::isnan(pointright.x) || std::isnan(pointright.y));
         				else{
						//we keep the point PO
            					std::string id = identify[i];
            					ros_img_processor::camera_POI_msg POI;
						//Fill data in Camera_POI_msg
            					POI.Header.frame_id = "camera";
           					//is wrong, must save the time when the process start
            					POI.Header.stamp = arriveTime;
           					POI.type = id;
            					POI.pointleft.x = pointleft.x;
            					POI.pointleft.y = pointleft.y;
           					POI.pointleft.z = pointleft.z;
            					POI.pointright.x = pointright.x;
            					POI.pointright.y = pointright.y;
            					POI.pointright.z = pointright.z;
            					camera_POI.publish(POI);
          				}	
			
				}	

			}
        	}
		// reset input image
		cv_img_ptr_in_=nullptr;
}


void AstraImgProcessorNode::publishImage()
{
	//check that there is info
	if( !cv_img_out_.image.data ) return;

    cv_img_out_.header.seq ++;
    cv_img_out_.header.stamp = ros::Time::now();
    cv_img_out_.header.frame_id = "camera";
    cv_img_out_.encoding = img_encoding_;
    image_pub_.publish(cv_img_out_.toImageMsg());

}

double AstraImgProcessorNode::getRate() const
{
    return rate_;
}

void AstraImgProcessorNode::imageCallback(const sensor_msgs::ImageConstPtr& image_msg, 
					  const sensor_msgs::CameraInfoConstPtr& info_msg)
{
   
    try
    {
      img_encoding_ = image_msg->encoding;//get image encodings
      cv_img_ptr_in_ = cv_bridge::toCvCopy(image_msg,img_encoding_);//get image
      image = cv_img_ptr_in_->image;
      arriveTime = ros::Time::now();
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("AstraImgProcessorNode::image_callback(): cv_bridge exception: %s", e.what());
        return;
    }
   
   //camera info 
   cam_model_image_.fromCameraInfo(info_msg);


}

void AstraImgProcessorNode::depthCallback(const sensor_msgs::ImageConstPtr& depth_msg, 
					  const sensor_msgs::CameraInfoConstPtr& infod_msg)
{
   
    try
    {
      cv_img_ptr_depth_ = cv_bridge::toCvCopy(depth_msg,depth_msg->encoding);//get image
      depth = cv_img_ptr_depth_->image;
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("AstraImgProcessorNode::image_callback(): cv_bridge exception: %s", e.what());
        return;
    }
   
   //camera info 
   cam_model_depth_.fromCameraInfo(infod_msg);


}



