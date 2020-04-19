; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-srv)


;//! \htmlinclude CarryingPerson-request.msg.html

(cl:defclass <CarryingPerson-request> (roslisp-msg-protocol:ros-message)
  ((person
    :reader person
    :initarg :person
    :type turtlebot_2dnav-msg:ROI
    :initform (cl:make-instance 'turtlebot_2dnav-msg:ROI)))
)

(cl:defclass CarryingPerson-request (<CarryingPerson-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CarryingPerson-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CarryingPerson-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<CarryingPerson-request> is deprecated: use turtlebot_2dnav-srv:CarryingPerson-request instead.")))

(cl:ensure-generic-function 'person-val :lambda-list '(m))
(cl:defmethod person-val ((m <CarryingPerson-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:person-val is deprecated.  Use turtlebot_2dnav-srv:person instead.")
  (person m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CarryingPerson-request>) ostream)
  "Serializes a message object of type '<CarryingPerson-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'person) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CarryingPerson-request>) istream)
  "Deserializes a message object of type '<CarryingPerson-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'person) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CarryingPerson-request>)))
  "Returns string type for a service object of type '<CarryingPerson-request>"
  "turtlebot_2dnav/CarryingPersonRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CarryingPerson-request)))
  "Returns string type for a service object of type 'CarryingPerson-request"
  "turtlebot_2dnav/CarryingPersonRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CarryingPerson-request>)))
  "Returns md5sum for a message object of type '<CarryingPerson-request>"
  "483ed3a7747788a7b78a207bdc605ba1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CarryingPerson-request)))
  "Returns md5sum for a message object of type 'CarryingPerson-request"
  "483ed3a7747788a7b78a207bdc605ba1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CarryingPerson-request>)))
  "Returns full string definition for message of type '<CarryingPerson-request>"
  (cl:format cl:nil "turtlebot_2dnav/ROI person~%~%~%================================================================================~%MSG: turtlebot_2dnav/ROI~%Header Header~%string type~%geometry_msgs/Point center~%float32 size_x~%float32 size_y~%uint8 index~%bool isnew~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CarryingPerson-request)))
  "Returns full string definition for message of type 'CarryingPerson-request"
  (cl:format cl:nil "turtlebot_2dnav/ROI person~%~%~%================================================================================~%MSG: turtlebot_2dnav/ROI~%Header Header~%string type~%geometry_msgs/Point center~%float32 size_x~%float32 size_y~%uint8 index~%bool isnew~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CarryingPerson-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'person))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CarryingPerson-request>))
  "Converts a ROS message object to a list"
  (cl:list 'CarryingPerson-request
    (cl:cons ':person (person msg))
))
;//! \htmlinclude CarryingPerson-response.msg.html

(cl:defclass <CarryingPerson-response> (roslisp-msg-protocol:ros-message)
  ((received
    :reader received
    :initarg :received
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass CarryingPerson-response (<CarryingPerson-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CarryingPerson-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CarryingPerson-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<CarryingPerson-response> is deprecated: use turtlebot_2dnav-srv:CarryingPerson-response instead.")))

(cl:ensure-generic-function 'received-val :lambda-list '(m))
(cl:defmethod received-val ((m <CarryingPerson-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:received-val is deprecated.  Use turtlebot_2dnav-srv:received instead.")
  (received m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CarryingPerson-response>) ostream)
  "Serializes a message object of type '<CarryingPerson-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'received) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CarryingPerson-response>) istream)
  "Deserializes a message object of type '<CarryingPerson-response>"
    (cl:setf (cl:slot-value msg 'received) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CarryingPerson-response>)))
  "Returns string type for a service object of type '<CarryingPerson-response>"
  "turtlebot_2dnav/CarryingPersonResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CarryingPerson-response)))
  "Returns string type for a service object of type 'CarryingPerson-response"
  "turtlebot_2dnav/CarryingPersonResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CarryingPerson-response>)))
  "Returns md5sum for a message object of type '<CarryingPerson-response>"
  "483ed3a7747788a7b78a207bdc605ba1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CarryingPerson-response)))
  "Returns md5sum for a message object of type 'CarryingPerson-response"
  "483ed3a7747788a7b78a207bdc605ba1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CarryingPerson-response>)))
  "Returns full string definition for message of type '<CarryingPerson-response>"
  (cl:format cl:nil "~%bool received~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CarryingPerson-response)))
  "Returns full string definition for message of type 'CarryingPerson-response"
  (cl:format cl:nil "~%bool received~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CarryingPerson-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CarryingPerson-response>))
  "Converts a ROS message object to a list"
  (cl:list 'CarryingPerson-response
    (cl:cons ':received (received msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'CarryingPerson)))
  'CarryingPerson-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'CarryingPerson)))
  'CarryingPerson-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CarryingPerson)))
  "Returns string type for a service object of type '<CarryingPerson>"
  "turtlebot_2dnav/CarryingPerson")