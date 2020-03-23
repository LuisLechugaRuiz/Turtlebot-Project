; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-srv)


;//! \htmlinclude returnCost-request.msg.html

(cl:defclass <returnCost-request> (roslisp-msg-protocol:ros-message)
  ((start
    :reader start
    :initarg :start
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped))
   (goal
    :reader goal
    :initarg :goal
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped)))
)

(cl:defclass returnCost-request (<returnCost-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <returnCost-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'returnCost-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<returnCost-request> is deprecated: use turtlebot_2dnav-srv:returnCost-request instead.")))

(cl:ensure-generic-function 'start-val :lambda-list '(m))
(cl:defmethod start-val ((m <returnCost-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:start-val is deprecated.  Use turtlebot_2dnav-srv:start instead.")
  (start m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <returnCost-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:goal-val is deprecated.  Use turtlebot_2dnav-srv:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <returnCost-request>) ostream)
  "Serializes a message object of type '<returnCost-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'start) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <returnCost-request>) istream)
  "Deserializes a message object of type '<returnCost-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'start) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<returnCost-request>)))
  "Returns string type for a service object of type '<returnCost-request>"
  "turtlebot_2dnav/returnCostRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'returnCost-request)))
  "Returns string type for a service object of type 'returnCost-request"
  "turtlebot_2dnav/returnCostRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<returnCost-request>)))
  "Returns md5sum for a message object of type '<returnCost-request>"
  "f0ab08f6ab3861462bec12fbd2aae873")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'returnCost-request)))
  "Returns md5sum for a message object of type 'returnCost-request"
  "f0ab08f6ab3861462bec12fbd2aae873")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<returnCost-request>)))
  "Returns full string definition for message of type '<returnCost-request>"
  (cl:format cl:nil "geometry_msgs/PoseStamped start~%~%geometry_msgs/PoseStamped goal~%~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'returnCost-request)))
  "Returns full string definition for message of type 'returnCost-request"
  (cl:format cl:nil "geometry_msgs/PoseStamped start~%~%geometry_msgs/PoseStamped goal~%~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <returnCost-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'start))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <returnCost-request>))
  "Converts a ROS message object to a list"
  (cl:list 'returnCost-request
    (cl:cons ':start (start msg))
    (cl:cons ':goal (goal msg))
))
;//! \htmlinclude returnCost-response.msg.html

(cl:defclass <returnCost-response> (roslisp-msg-protocol:ros-message)
  ((cost
    :reader cost
    :initarg :cost
    :type cl:integer
    :initform 0))
)

(cl:defclass returnCost-response (<returnCost-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <returnCost-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'returnCost-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<returnCost-response> is deprecated: use turtlebot_2dnav-srv:returnCost-response instead.")))

(cl:ensure-generic-function 'cost-val :lambda-list '(m))
(cl:defmethod cost-val ((m <returnCost-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:cost-val is deprecated.  Use turtlebot_2dnav-srv:cost instead.")
  (cost m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <returnCost-response>) ostream)
  "Serializes a message object of type '<returnCost-response>"
  (cl:let* ((signed (cl:slot-value msg 'cost)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <returnCost-response>) istream)
  "Deserializes a message object of type '<returnCost-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cost) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<returnCost-response>)))
  "Returns string type for a service object of type '<returnCost-response>"
  "turtlebot_2dnav/returnCostResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'returnCost-response)))
  "Returns string type for a service object of type 'returnCost-response"
  "turtlebot_2dnav/returnCostResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<returnCost-response>)))
  "Returns md5sum for a message object of type '<returnCost-response>"
  "f0ab08f6ab3861462bec12fbd2aae873")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'returnCost-response)))
  "Returns md5sum for a message object of type 'returnCost-response"
  "f0ab08f6ab3861462bec12fbd2aae873")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<returnCost-response>)))
  "Returns full string definition for message of type '<returnCost-response>"
  (cl:format cl:nil "~%int64 cost~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'returnCost-response)))
  "Returns full string definition for message of type 'returnCost-response"
  (cl:format cl:nil "~%int64 cost~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <returnCost-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <returnCost-response>))
  "Converts a ROS message object to a list"
  (cl:list 'returnCost-response
    (cl:cons ':cost (cost msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'returnCost)))
  'returnCost-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'returnCost)))
  'returnCost-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'returnCost)))
  "Returns string type for a service object of type '<returnCost>"
  "turtlebot_2dnav/returnCost")