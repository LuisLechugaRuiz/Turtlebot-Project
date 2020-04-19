; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-srv)


;//! \htmlinclude recalculateBound-request.msg.html

(cl:defclass <recalculateBound-request> (roslisp-msg-protocol:ros-message)
  ((recalculate
    :reader recalculate
    :initarg :recalculate
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass recalculateBound-request (<recalculateBound-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <recalculateBound-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'recalculateBound-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<recalculateBound-request> is deprecated: use turtlebot_2dnav-srv:recalculateBound-request instead.")))

(cl:ensure-generic-function 'recalculate-val :lambda-list '(m))
(cl:defmethod recalculate-val ((m <recalculateBound-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:recalculate-val is deprecated.  Use turtlebot_2dnav-srv:recalculate instead.")
  (recalculate m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <recalculateBound-request>) ostream)
  "Serializes a message object of type '<recalculateBound-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'recalculate) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <recalculateBound-request>) istream)
  "Deserializes a message object of type '<recalculateBound-request>"
    (cl:setf (cl:slot-value msg 'recalculate) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<recalculateBound-request>)))
  "Returns string type for a service object of type '<recalculateBound-request>"
  "turtlebot_2dnav/recalculateBoundRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'recalculateBound-request)))
  "Returns string type for a service object of type 'recalculateBound-request"
  "turtlebot_2dnav/recalculateBoundRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<recalculateBound-request>)))
  "Returns md5sum for a message object of type '<recalculateBound-request>"
  "ccb08b87036c8a7862161f690fdb0a11")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'recalculateBound-request)))
  "Returns md5sum for a message object of type 'recalculateBound-request"
  "ccb08b87036c8a7862161f690fdb0a11")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<recalculateBound-request>)))
  "Returns full string definition for message of type '<recalculateBound-request>"
  (cl:format cl:nil "bool recalculate~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'recalculateBound-request)))
  "Returns full string definition for message of type 'recalculateBound-request"
  (cl:format cl:nil "bool recalculate~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <recalculateBound-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <recalculateBound-request>))
  "Converts a ROS message object to a list"
  (cl:list 'recalculateBound-request
    (cl:cons ':recalculate (recalculate msg))
))
;//! \htmlinclude recalculateBound-response.msg.html

(cl:defclass <recalculateBound-response> (roslisp-msg-protocol:ros-message)
  ((received
    :reader received
    :initarg :received
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass recalculateBound-response (<recalculateBound-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <recalculateBound-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'recalculateBound-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<recalculateBound-response> is deprecated: use turtlebot_2dnav-srv:recalculateBound-response instead.")))

(cl:ensure-generic-function 'received-val :lambda-list '(m))
(cl:defmethod received-val ((m <recalculateBound-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:received-val is deprecated.  Use turtlebot_2dnav-srv:received instead.")
  (received m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <recalculateBound-response>) ostream)
  "Serializes a message object of type '<recalculateBound-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'received) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <recalculateBound-response>) istream)
  "Deserializes a message object of type '<recalculateBound-response>"
    (cl:setf (cl:slot-value msg 'received) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<recalculateBound-response>)))
  "Returns string type for a service object of type '<recalculateBound-response>"
  "turtlebot_2dnav/recalculateBoundResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'recalculateBound-response)))
  "Returns string type for a service object of type 'recalculateBound-response"
  "turtlebot_2dnav/recalculateBoundResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<recalculateBound-response>)))
  "Returns md5sum for a message object of type '<recalculateBound-response>"
  "ccb08b87036c8a7862161f690fdb0a11")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'recalculateBound-response)))
  "Returns md5sum for a message object of type 'recalculateBound-response"
  "ccb08b87036c8a7862161f690fdb0a11")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<recalculateBound-response>)))
  "Returns full string definition for message of type '<recalculateBound-response>"
  (cl:format cl:nil "bool received~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'recalculateBound-response)))
  "Returns full string definition for message of type 'recalculateBound-response"
  (cl:format cl:nil "bool received~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <recalculateBound-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <recalculateBound-response>))
  "Converts a ROS message object to a list"
  (cl:list 'recalculateBound-response
    (cl:cons ':received (received msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'recalculateBound)))
  'recalculateBound-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'recalculateBound)))
  'recalculateBound-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'recalculateBound)))
  "Returns string type for a service object of type '<recalculateBound>"
  "turtlebot_2dnav/recalculateBound")