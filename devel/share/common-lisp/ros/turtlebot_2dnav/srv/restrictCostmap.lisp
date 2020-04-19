; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-srv)


;//! \htmlinclude restrictCostmap-request.msg.html

(cl:defclass <restrictCostmap-request> (roslisp-msg-protocol:ros-message)
  ((Point
    :reader Point
    :initarg :Point
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (index
    :reader index
    :initarg :index
    :type cl:integer
    :initform 0)
   (color
    :reader color
    :initarg :color
    :type cl:integer
    :initform 0)
   (restrict
    :reader restrict
    :initarg :restrict
    :type cl:boolean
    :initform cl:nil)
   (isvertical
    :reader isvertical
    :initarg :isvertical
    :type cl:boolean
    :initform cl:nil)
   (exit
    :reader exit
    :initarg :exit
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass restrictCostmap-request (<restrictCostmap-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <restrictCostmap-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'restrictCostmap-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<restrictCostmap-request> is deprecated: use turtlebot_2dnav-srv:restrictCostmap-request instead.")))

(cl:ensure-generic-function 'Point-val :lambda-list '(m))
(cl:defmethod Point-val ((m <restrictCostmap-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:Point-val is deprecated.  Use turtlebot_2dnav-srv:Point instead.")
  (Point m))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <restrictCostmap-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:index-val is deprecated.  Use turtlebot_2dnav-srv:index instead.")
  (index m))

(cl:ensure-generic-function 'color-val :lambda-list '(m))
(cl:defmethod color-val ((m <restrictCostmap-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:color-val is deprecated.  Use turtlebot_2dnav-srv:color instead.")
  (color m))

(cl:ensure-generic-function 'restrict-val :lambda-list '(m))
(cl:defmethod restrict-val ((m <restrictCostmap-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:restrict-val is deprecated.  Use turtlebot_2dnav-srv:restrict instead.")
  (restrict m))

(cl:ensure-generic-function 'isvertical-val :lambda-list '(m))
(cl:defmethod isvertical-val ((m <restrictCostmap-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:isvertical-val is deprecated.  Use turtlebot_2dnav-srv:isvertical instead.")
  (isvertical m))

(cl:ensure-generic-function 'exit-val :lambda-list '(m))
(cl:defmethod exit-val ((m <restrictCostmap-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:exit-val is deprecated.  Use turtlebot_2dnav-srv:exit instead.")
  (exit m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <restrictCostmap-request>) ostream)
  "Serializes a message object of type '<restrictCostmap-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Point) ostream)
  (cl:let* ((signed (cl:slot-value msg 'index)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'color)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'restrict) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isvertical) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'exit) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <restrictCostmap-request>) istream)
  "Deserializes a message object of type '<restrictCostmap-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Point) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'index) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'color) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'restrict) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'isvertical) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'exit) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<restrictCostmap-request>)))
  "Returns string type for a service object of type '<restrictCostmap-request>"
  "turtlebot_2dnav/restrictCostmapRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'restrictCostmap-request)))
  "Returns string type for a service object of type 'restrictCostmap-request"
  "turtlebot_2dnav/restrictCostmapRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<restrictCostmap-request>)))
  "Returns md5sum for a message object of type '<restrictCostmap-request>"
  "ca045509d540aafaf4518df5620d8993")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'restrictCostmap-request)))
  "Returns md5sum for a message object of type 'restrictCostmap-request"
  "ca045509d540aafaf4518df5620d8993")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<restrictCostmap-request>)))
  "Returns full string definition for message of type '<restrictCostmap-request>"
  (cl:format cl:nil "geometry_msgs/Point Point~%int32 index~%int32 color~%bool restrict~%bool isvertical~%bool exit~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'restrictCostmap-request)))
  "Returns full string definition for message of type 'restrictCostmap-request"
  (cl:format cl:nil "geometry_msgs/Point Point~%int32 index~%int32 color~%bool restrict~%bool isvertical~%bool exit~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <restrictCostmap-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Point))
     4
     4
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <restrictCostmap-request>))
  "Converts a ROS message object to a list"
  (cl:list 'restrictCostmap-request
    (cl:cons ':Point (Point msg))
    (cl:cons ':index (index msg))
    (cl:cons ':color (color msg))
    (cl:cons ':restrict (restrict msg))
    (cl:cons ':isvertical (isvertical msg))
    (cl:cons ':exit (exit msg))
))
;//! \htmlinclude restrictCostmap-response.msg.html

(cl:defclass <restrictCostmap-response> (roslisp-msg-protocol:ros-message)
  ((received
    :reader received
    :initarg :received
    :type cl:boolean
    :initform cl:nil)
   (NewCenter
    :reader NewCenter
    :initarg :NewCenter
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass restrictCostmap-response (<restrictCostmap-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <restrictCostmap-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'restrictCostmap-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<restrictCostmap-response> is deprecated: use turtlebot_2dnav-srv:restrictCostmap-response instead.")))

(cl:ensure-generic-function 'received-val :lambda-list '(m))
(cl:defmethod received-val ((m <restrictCostmap-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:received-val is deprecated.  Use turtlebot_2dnav-srv:received instead.")
  (received m))

(cl:ensure-generic-function 'NewCenter-val :lambda-list '(m))
(cl:defmethod NewCenter-val ((m <restrictCostmap-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:NewCenter-val is deprecated.  Use turtlebot_2dnav-srv:NewCenter instead.")
  (NewCenter m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <restrictCostmap-response>) ostream)
  "Serializes a message object of type '<restrictCostmap-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'received) 1 0)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'NewCenter) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <restrictCostmap-response>) istream)
  "Deserializes a message object of type '<restrictCostmap-response>"
    (cl:setf (cl:slot-value msg 'received) (cl:not (cl:zerop (cl:read-byte istream))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'NewCenter) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<restrictCostmap-response>)))
  "Returns string type for a service object of type '<restrictCostmap-response>"
  "turtlebot_2dnav/restrictCostmapResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'restrictCostmap-response)))
  "Returns string type for a service object of type 'restrictCostmap-response"
  "turtlebot_2dnav/restrictCostmapResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<restrictCostmap-response>)))
  "Returns md5sum for a message object of type '<restrictCostmap-response>"
  "ca045509d540aafaf4518df5620d8993")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'restrictCostmap-response)))
  "Returns md5sum for a message object of type 'restrictCostmap-response"
  "ca045509d540aafaf4518df5620d8993")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<restrictCostmap-response>)))
  "Returns full string definition for message of type '<restrictCostmap-response>"
  (cl:format cl:nil "bool received~%geometry_msgs/Point NewCenter~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'restrictCostmap-response)))
  "Returns full string definition for message of type 'restrictCostmap-response"
  (cl:format cl:nil "bool received~%geometry_msgs/Point NewCenter~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <restrictCostmap-response>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'NewCenter))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <restrictCostmap-response>))
  "Converts a ROS message object to a list"
  (cl:list 'restrictCostmap-response
    (cl:cons ':received (received msg))
    (cl:cons ':NewCenter (NewCenter msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'restrictCostmap)))
  'restrictCostmap-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'restrictCostmap)))
  'restrictCostmap-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'restrictCostmap)))
  "Returns string type for a service object of type '<restrictCostmap>"
  "turtlebot_2dnav/restrictCostmap")