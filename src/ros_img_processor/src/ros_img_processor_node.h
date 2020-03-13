#ifndef ros_img_processor_node_H
#define ros_img_processor_node_H

//std C++
#include <iostream>

//Eigen
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

//ROS headers for image I/O
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CameraInfo.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>


class RosImgProcessorNode
{
    protected:
        //ros node handle
        ros::NodeHandle nh_;

        //image transport
        image_transport::ImageTransport img_tp_;

        // subscribers to the image and camera info topics
        ros::Subscriber cloud_subs_;
        ros::Subscriber camera_info_subs_;

        //publishers
        image_transport::Publisher image_pub_;
        ros::Publisher camera_POI;

        //Time of pcl arrive
        ros::Time arriveTime;

        //pointer to received (in) and published (out) images
        cv_bridge::CvImagePtr cv_img_ptr_in_;
        cv_bridge::CvImage cv_img_out_;

        sensor_msgs::ImagePtr image;
        pcl::PointCloud<pcl::PointXYZ> depth;

    		//Camera matrix
    		Eigen::Matrix3d matrixK_;

        //wished process rate, [hz]
        double rate_;

    protected:
        // callbacks
        void cloudCallback(const sensor_msgs::PointCloud2ConstPtr & _msg);
        void cameraInfoCallback(const sensor_msgs::CameraInfo & _msg);

    public:
        // Constructor
        RosImgProcessorNode();

        // Destructor
        ~RosImgProcessorNode();

        // Process input image
        void process();

        // Publish output image
        void publishImage();

 		// Returns rate_
        double getRate() const;
};
#endif
