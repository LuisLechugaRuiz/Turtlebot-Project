;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::frontier)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'frontier (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::FRONTIER")
  (make-package "TURTLEBOT_2DNAV::FRONTIER"))

(in-package "ROS")
;;//! \htmlinclude frontier.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass turtlebot_2dnav::frontier
  :super ros::object
  :slots (_goal _frontiers_count ))

(defmethod turtlebot_2dnav::frontier
  (:init
   (&key
    ((:goal __goal) (instance geometry_msgs::PoseStamped :init))
    ((:frontiers_count __frontiers_count) 0)
    )
   (send-super :init)
   (setq _goal __goal)
   (setq _frontiers_count (round __frontiers_count))
   self)
  (:goal
   (&rest __goal)
   (if (keywordp (car __goal))
       (send* _goal __goal)
     (progn
       (if __goal (setq _goal (car __goal)))
       _goal)))
  (:frontiers_count
   (&optional __frontiers_count)
   (if __frontiers_count (setq _frontiers_count __frontiers_count)) _frontiers_count)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/PoseStamped _goal
    (send _goal :serialization-length)
    ;; uint8 _frontiers_count
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/PoseStamped _goal
       (send _goal :serialize s)
     ;; uint8 _frontiers_count
       (write-byte _frontiers_count s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/PoseStamped _goal
     (send _goal :deserialize buf ptr-) (incf ptr- (send _goal :serialization-length))
   ;; uint8 _frontiers_count
     (setq _frontiers_count (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get turtlebot_2dnav::frontier :md5sum-) "72fa4e2f921957ecbe666961f3773de7")
(setf (get turtlebot_2dnav::frontier :datatype-) "turtlebot_2dnav/frontier")
(setf (get turtlebot_2dnav::frontier :definition-)
      "geometry_msgs/PoseStamped goal
uint8 frontiers_count

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

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
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :turtlebot_2dnav/frontier "72fa4e2f921957ecbe666961f3773de7")


