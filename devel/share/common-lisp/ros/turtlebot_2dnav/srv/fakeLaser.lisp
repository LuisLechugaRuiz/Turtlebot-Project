; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-srv)


;//! \htmlinclude fakeLaser-request.msg.html

(cl:defclass <fakeLaser-request> (roslisp-msg-protocol:ros-message)
  ((active
    :reader active
    :initarg :active
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass fakeLaser-request (<fakeLaser-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <fakeLaser-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'fakeLaser-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<fakeLaser-request> is deprecated: use turtlebot_2dnav-srv:fakeLaser-request instead.")))

(cl:ensure-generic-function 'active-val :lambda-list '(m))
(cl:defmethod active-val ((m <fakeLaser-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:active-val is deprecated.  Use turtlebot_2dnav-srv:active instead.")
  (active m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <fakeLaser-request>) ostream)
  "Serializes a message object of type '<fakeLaser-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'active) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <fakeLaser-request>) istream)
  "Deserializes a message object of type '<fakeLaser-request>"
    (cl:setf (cl:slot-value msg 'active) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<fakeLaser-request>)))
  "Returns string type for a service object of type '<fakeLaser-request>"
  "turtlebot_2dnav/fakeLaserRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'fakeLaser-request)))
  "Returns string type for a service object of type 'fakeLaser-request"
  "turtlebot_2dnav/fakeLaserRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<fakeLaser-request>)))
  "Returns md5sum for a message object of type '<fakeLaser-request>"
  "313460372e25eee11ab9126733a5d19c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'fakeLaser-request)))
  "Returns md5sum for a message object of type 'fakeLaser-request"
  "313460372e25eee11ab9126733a5d19c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<fakeLaser-request>)))
  "Returns full string definition for message of type '<fakeLaser-request>"
  (cl:format cl:nil "bool active~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'fakeLaser-request)))
  "Returns full string definition for message of type 'fakeLaser-request"
  (cl:format cl:nil "bool active~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <fakeLaser-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <fakeLaser-request>))
  "Converts a ROS message object to a list"
  (cl:list 'fakeLaser-request
    (cl:cons ':active (active msg))
))
;//! \htmlinclude fakeLaser-response.msg.html

(cl:defclass <fakeLaser-response> (roslisp-msg-protocol:ros-message)
  ((received
    :reader received
    :initarg :received
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass fakeLaser-response (<fakeLaser-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <fakeLaser-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'fakeLaser-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<fakeLaser-response> is deprecated: use turtlebot_2dnav-srv:fakeLaser-response instead.")))

(cl:ensure-generic-function 'received-val :lambda-list '(m))
(cl:defmethod received-val ((m <fakeLaser-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:received-val is deprecated.  Use turtlebot_2dnav-srv:received instead.")
  (received m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <fakeLaser-response>) ostream)
  "Serializes a message object of type '<fakeLaser-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'received) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <fakeLaser-response>) istream)
  "Deserializes a message object of type '<fakeLaser-response>"
    (cl:setf (cl:slot-value msg 'received) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<fakeLaser-response>)))
  "Returns string type for a service object of type '<fakeLaser-response>"
  "turtlebot_2dnav/fakeLaserResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'fakeLaser-response)))
  "Returns string type for a service object of type 'fakeLaser-response"
  "turtlebot_2dnav/fakeLaserResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<fakeLaser-response>)))
  "Returns md5sum for a message object of type '<fakeLaser-response>"
  "313460372e25eee11ab9126733a5d19c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'fakeLaser-response)))
  "Returns md5sum for a message object of type 'fakeLaser-response"
  "313460372e25eee11ab9126733a5d19c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<fakeLaser-response>)))
  "Returns full string definition for message of type '<fakeLaser-response>"
  (cl:format cl:nil "bool received~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'fakeLaser-response)))
  "Returns full string definition for message of type 'fakeLaser-response"
  (cl:format cl:nil "bool received~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <fakeLaser-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <fakeLaser-response>))
  "Converts a ROS message object to a list"
  (cl:list 'fakeLaser-response
    (cl:cons ':received (received msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'fakeLaser)))
  'fakeLaser-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'fakeLaser)))
  'fakeLaser-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'fakeLaser)))
  "Returns string type for a service object of type '<fakeLaser>"
  "turtlebot_2dnav/fakeLaser")