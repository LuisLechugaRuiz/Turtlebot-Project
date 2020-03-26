;; Auto-generated. Do not edit!


(when (boundp 'ros_img_processor::camera_POI_msg)
  (if (not (find-package "ROS_IMG_PROCESSOR"))
    (make-package "ROS_IMG_PROCESSOR"))
  (shadow 'camera_POI_msg (find-package "ROS_IMG_PROCESSOR")))
(unless (find-package "ROS_IMG_PROCESSOR::CAMERA_POI_MSG")
  (make-package "ROS_IMG_PROCESSOR::CAMERA_POI_MSG"))

(in-package "ROS")
;;//! \htmlinclude camera_POI_msg.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ros_img_processor::camera_POI_msg
  :super ros::object
  :slots (_Header _type _pointleft _pointright ))

(defmethod ros_img_processor::camera_POI_msg
  (:init
   (&key
    ((:Header __Header) (instance std_msgs::Header :init))
    ((:type __type) "")
    ((:pointleft __pointleft) (instance geometry_msgs::Point :init))
    ((:pointright __pointright) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _Header __Header)
   (setq _type (string __type))
   (setq _pointleft __pointleft)
   (setq _pointright __pointright)
   self)
  (:Header
   (&rest __Header)
   (if (keywordp (car __Header))
       (send* _Header __Header)
     (progn
       (if __Header (setq _Header (car __Header)))
       _Header)))
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:pointleft
   (&rest __pointleft)
   (if (keywordp (car __pointleft))
       (send* _pointleft __pointleft)
     (progn
       (if __pointleft (setq _pointleft (car __pointleft)))
       _pointleft)))
  (:pointright
   (&rest __pointright)
   (if (keywordp (car __pointright))
       (send* _pointright __pointright)
     (progn
       (if __pointright (setq _pointright (car __pointright)))
       _pointright)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _Header
    (send _Header :serialization-length)
    ;; string _type
    4 (length _type)
    ;; geometry_msgs/Point _pointleft
    (send _pointleft :serialization-length)
    ;; geometry_msgs/Point _pointright
    (send _pointright :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _Header
       (send _Header :serialize s)
     ;; string _type
       (write-long (length _type) s) (princ _type s)
     ;; geometry_msgs/Point _pointleft
       (send _pointleft :serialize s)
     ;; geometry_msgs/Point _pointright
       (send _pointright :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _Header
     (send _Header :deserialize buf ptr-) (incf ptr- (send _Header :serialization-length))
   ;; string _type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; geometry_msgs/Point _pointleft
     (send _pointleft :deserialize buf ptr-) (incf ptr- (send _pointleft :serialization-length))
   ;; geometry_msgs/Point _pointright
     (send _pointright :deserialize buf ptr-) (incf ptr- (send _pointright :serialization-length))
   ;;
   self)
  )

(setf (get ros_img_processor::camera_POI_msg :md5sum-) "3889b5518a505b6dff84d0f699e8b734")
(setf (get ros_img_processor::camera_POI_msg :datatype-) "ros_img_processor/camera_POI_msg")
(setf (get ros_img_processor::camera_POI_msg :definition-)
      "Header Header
string type
geometry_msgs/Point pointleft
geometry_msgs/Point pointright

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :ros_img_processor/camera_POI_msg "3889b5518a505b6dff84d0f699e8b734")


