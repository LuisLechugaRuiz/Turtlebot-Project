#ifndef astra_img_processor_node_H
#define astra_img_processor_node_H

//std C++
#include <iostream>

//Eigen
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

//ROS headers for image I/O
#include <image_transport/image_transport.h>
#include <image_geometry/pinhole_camera_model.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CameraInfo.h>
#include <visualization_msgs/Marker.h>

class AstraImgProcessorNode
{
    protected:
        //ros node handle
        ros::NodeHandle nh_;

        //image transport
        image_transport::ImageTransport img_tp_;

        // Subscribers 
	image_transport::CameraSubscriber image_info_subs_;
	image_transport::CameraSubscriber depth_info_subs_;
        
	//publishers
        image_transport::Publisher image_pub_;
        ros::Publisher camera_POI;

        //Time of image arrive
        ros::Time arriveTime;

        //pointer to received (in) and published (out) images
        cv_bridge::CvImagePtr cv_img_ptr_in_;
	cv_bridge::CvImagePtr cv_img_ptr_depth_;
        cv_bridge::CvImage cv_img_out_;
	cv::Mat image;
	cv::Mat depth;

	//Camera Model
        image_geometry::PinholeCameraModel cam_model_image_;
	image_geometry::PinholeCameraModel cam_model_depth_;
	
	//image encoding label
        std::string img_encoding_;

        //wished process rate, [hz]
        double rate_;

    protected:
        // callbacks
	void imageCallback(const sensor_msgs::ImageConstPtr& image_msg, const sensor_msgs::CameraInfoConstPtr& info_msg);
	void depthCallback(const sensor_msgs::ImageConstPtr& depth_msg, const sensor_msgs::CameraInfoConstPtr& infod_msg);

		
   
    public:
        // Constructor
        AstraImgProcessorNode();

        // Destructor
        ~AstraImgProcessorNode();

        // Process input image
        void process();

        // Publish output image
        void publishImage();

 	// Returns rate_
        double getRate() const;
};
#endif

