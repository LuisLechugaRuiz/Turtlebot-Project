; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-msg)


;//! \htmlinclude frontier.msg.html

(cl:defclass <frontier> (roslisp-msg-protocol:ros-message)
  ((goal
    :reader goal
    :initarg :goal
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped))
   (frontiers_count
    :reader frontiers_count
    :initarg :frontiers_count
    :type cl:fixnum
    :initform 0))
)

(cl:defclass frontier (<frontier>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <frontier>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'frontier)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-msg:<frontier> is deprecated: use turtlebot_2dnav-msg:frontier instead.")))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <frontier>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:goal-val is deprecated.  Use turtlebot_2dnav-msg:goal instead.")
  (goal m))

(cl:ensure-generic-function 'frontiers_count-val :lambda-list '(m))
(cl:defmethod frontiers_count-val ((m <frontier>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:frontiers_count-val is deprecated.  Use turtlebot_2dnav-msg:frontiers_count instead.")
  (frontiers_count m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <frontier>) ostream)
  "Serializes a message object of type '<frontier>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'frontiers_count)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <frontier>) istream)
  "Deserializes a message object of type '<frontier>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'frontiers_count)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<frontier>)))
  "Returns string type for a message object of type '<frontier>"
  "turtlebot_2dnav/frontier")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'frontier)))
  "Returns string type for a message object of type 'frontier"
  "turtlebot_2dnav/frontier")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<frontier>)))
  "Returns md5sum for a message object of type '<frontier>"
  "72fa4e2f921957ecbe666961f3773de7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'frontier)))
  "Returns md5sum for a message object of type 'frontier"
  "72fa4e2f921957ecbe666961f3773de7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<frontier>)))
  "Returns full string definition for message of type '<frontier>"
  (cl:format cl:nil "geometry_msgs/PoseStamped goal~%uint8 frontiers_count~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'frontier)))
  "Returns full string definition for message of type 'frontier"
  (cl:format cl:nil "geometry_msgs/PoseStamped goal~%uint8 frontiers_count~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <frontier>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <frontier>))
  "Converts a ROS message object to a list"
  (cl:list 'frontier
    (cl:cons ':goal (goal msg))
    (cl:cons ':frontiers_count (frontiers_count msg))
))
