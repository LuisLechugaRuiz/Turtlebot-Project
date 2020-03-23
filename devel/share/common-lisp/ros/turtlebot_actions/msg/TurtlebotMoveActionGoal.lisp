; Auto-generated. Do not edit!


(cl:in-package turtlebot_actions-msg)


;//! \htmlinclude TurtlebotMoveActionGoal.msg.html

(cl:defclass <TurtlebotMoveActionGoal> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (goal_id
    :reader goal_id
    :initarg :goal_id
    :type actionlib_msgs-msg:GoalID
    :initform (cl:make-instance 'actionlib_msgs-msg:GoalID))
   (goal
    :reader goal
    :initarg :goal
    :type turtlebot_actions-msg:TurtlebotMoveGoal
    :initform (cl:make-instance 'turtlebot_actions-msg:TurtlebotMoveGoal)))
)

(cl:defclass TurtlebotMoveActionGoal (<TurtlebotMoveActionGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TurtlebotMoveActionGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TurtlebotMoveActionGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_actions-msg:<TurtlebotMoveActionGoal> is deprecated: use turtlebot_actions-msg:TurtlebotMoveActionGoal instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <TurtlebotMoveActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:header-val is deprecated.  Use turtlebot_actions-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'goal_id-val :lambda-list '(m))
(cl:defmethod goal_id-val ((m <TurtlebotMoveActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:goal_id-val is deprecated.  Use turtlebot_actions-msg:goal_id instead.")
  (goal_id m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <TurtlebotMoveActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:goal-val is deprecated.  Use turtlebot_actions-msg:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TurtlebotMoveActionGoal>) ostream)
  "Serializes a message object of type '<TurtlebotMoveActionGoal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal_id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TurtlebotMoveActionGoal>) istream)
  "Deserializes a message object of type '<TurtlebotMoveActionGoal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal_id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TurtlebotMoveActionGoal>)))
  "Returns string type for a message object of type '<TurtlebotMoveActionGoal>"
  "turtlebot_actions/TurtlebotMoveActionGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TurtlebotMoveActionGoal)))
  "Returns string type for a message object of type 'TurtlebotMoveActionGoal"
  "turtlebot_actions/TurtlebotMoveActionGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TurtlebotMoveActionGoal>)))
  "Returns md5sum for a message object of type '<TurtlebotMoveActionGoal>"
  "7e462cf7fe57fc76afd36fde5d415bc1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TurtlebotMoveActionGoal)))
  "Returns md5sum for a message object of type 'TurtlebotMoveActionGoal"
  "7e462cf7fe57fc76afd36fde5d415bc1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TurtlebotMoveActionGoal>)))
  "Returns full string definition for message of type '<TurtlebotMoveActionGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%TurtlebotMoveGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: turtlebot_actions/TurtlebotMoveGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%float32 turn_distance     # in radians, ccw = +, cw = -~%float32 forward_distance  # in meters, forward = +, backward = -~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TurtlebotMoveActionGoal)))
  "Returns full string definition for message of type 'TurtlebotMoveActionGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%TurtlebotMoveGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: turtlebot_actions/TurtlebotMoveGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%float32 turn_distance     # in radians, ccw = +, cw = -~%float32 forward_distance  # in meters, forward = +, backward = -~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TurtlebotMoveActionGoal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal_id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TurtlebotMoveActionGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'TurtlebotMoveActionGoal
    (cl:cons ':header (header msg))
    (cl:cons ':goal_id (goal_id msg))
    (cl:cons ':goal (goal msg))
))
