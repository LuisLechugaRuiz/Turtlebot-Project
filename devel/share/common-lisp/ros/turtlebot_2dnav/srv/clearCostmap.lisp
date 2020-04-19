; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-srv)


;//! \htmlinclude clearCostmap-request.msg.html

(cl:defclass <clearCostmap-request> (roslisp-msg-protocol:ros-message)
  ((clear
    :reader clear
    :initarg :clear
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass clearCostmap-request (<clearCostmap-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <clearCostmap-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'clearCostmap-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<clearCostmap-request> is deprecated: use turtlebot_2dnav-srv:clearCostmap-request instead.")))

(cl:ensure-generic-function 'clear-val :lambda-list '(m))
(cl:defmethod clear-val ((m <clearCostmap-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:clear-val is deprecated.  Use turtlebot_2dnav-srv:clear instead.")
  (clear m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <clearCostmap-request>) ostream)
  "Serializes a message object of type '<clearCostmap-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'clear) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <clearCostmap-request>) istream)
  "Deserializes a message object of type '<clearCostmap-request>"
    (cl:setf (cl:slot-value msg 'clear) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<clearCostmap-request>)))
  "Returns string type for a service object of type '<clearCostmap-request>"
  "turtlebot_2dnav/clearCostmapRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'clearCostmap-request)))
  "Returns string type for a service object of type 'clearCostmap-request"
  "turtlebot_2dnav/clearCostmapRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<clearCostmap-request>)))
  "Returns md5sum for a message object of type '<clearCostmap-request>"
  "6f1cadb125ab62799a65523a8282332f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'clearCostmap-request)))
  "Returns md5sum for a message object of type 'clearCostmap-request"
  "6f1cadb125ab62799a65523a8282332f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<clearCostmap-request>)))
  "Returns full string definition for message of type '<clearCostmap-request>"
  (cl:format cl:nil "bool clear~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'clearCostmap-request)))
  "Returns full string definition for message of type 'clearCostmap-request"
  (cl:format cl:nil "bool clear~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <clearCostmap-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <clearCostmap-request>))
  "Converts a ROS message object to a list"
  (cl:list 'clearCostmap-request
    (cl:cons ':clear (clear msg))
))
;//! \htmlinclude clearCostmap-response.msg.html

(cl:defclass <clearCostmap-response> (roslisp-msg-protocol:ros-message)
  ((received
    :reader received
    :initarg :received
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass clearCostmap-response (<clearCostmap-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <clearCostmap-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'clearCostmap-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<clearCostmap-response> is deprecated: use turtlebot_2dnav-srv:clearCostmap-response instead.")))

(cl:ensure-generic-function 'received-val :lambda-list '(m))
(cl:defmethod received-val ((m <clearCostmap-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:received-val is deprecated.  Use turtlebot_2dnav-srv:received instead.")
  (received m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <clearCostmap-response>) ostream)
  "Serializes a message object of type '<clearCostmap-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'received) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <clearCostmap-response>) istream)
  "Deserializes a message object of type '<clearCostmap-response>"
    (cl:setf (cl:slot-value msg 'received) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<clearCostmap-response>)))
  "Returns string type for a service object of type '<clearCostmap-response>"
  "turtlebot_2dnav/clearCostmapResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'clearCostmap-response)))
  "Returns string type for a service object of type 'clearCostmap-response"
  "turtlebot_2dnav/clearCostmapResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<clearCostmap-response>)))
  "Returns md5sum for a message object of type '<clearCostmap-response>"
  "6f1cadb125ab62799a65523a8282332f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'clearCostmap-response)))
  "Returns md5sum for a message object of type 'clearCostmap-response"
  "6f1cadb125ab62799a65523a8282332f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<clearCostmap-response>)))
  "Returns full string definition for message of type '<clearCostmap-response>"
  (cl:format cl:nil "bool received~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'clearCostmap-response)))
  "Returns full string definition for message of type 'clearCostmap-response"
  (cl:format cl:nil "bool received~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <clearCostmap-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <clearCostmap-response>))
  "Converts a ROS message object to a list"
  (cl:list 'clearCostmap-response
    (cl:cons ':received (received msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'clearCostmap)))
  'clearCostmap-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'clearCostmap)))
  'clearCostmap-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'clearCostmap)))
  "Returns string type for a service object of type '<clearCostmap>"
  "turtlebot_2dnav/clearCostmap")