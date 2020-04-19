; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-msg)


;//! \htmlinclude match_bound.msg.html

(cl:defclass <match_bound> (roslisp-msg-protocol:ros-message)
  ((pointright
    :reader pointright
    :initarg :pointright
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (pointleft
    :reader pointleft
    :initarg :pointleft
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (pointcenter
    :reader pointcenter
    :initarg :pointcenter
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (matched
    :reader matched
    :initarg :matched
    :type cl:boolean
    :initform cl:nil)
   (index
    :reader index
    :initarg :index
    :type cl:integer
    :initform 0)
   (color
    :reader color
    :initarg :color
    :type cl:integer
    :initform 0))
)

(cl:defclass match_bound (<match_bound>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <match_bound>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'match_bound)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-msg:<match_bound> is deprecated: use turtlebot_2dnav-msg:match_bound instead.")))

(cl:ensure-generic-function 'pointright-val :lambda-list '(m))
(cl:defmethod pointright-val ((m <match_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:pointright-val is deprecated.  Use turtlebot_2dnav-msg:pointright instead.")
  (pointright m))

(cl:ensure-generic-function 'pointleft-val :lambda-list '(m))
(cl:defmethod pointleft-val ((m <match_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:pointleft-val is deprecated.  Use turtlebot_2dnav-msg:pointleft instead.")
  (pointleft m))

(cl:ensure-generic-function 'pointcenter-val :lambda-list '(m))
(cl:defmethod pointcenter-val ((m <match_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:pointcenter-val is deprecated.  Use turtlebot_2dnav-msg:pointcenter instead.")
  (pointcenter m))

(cl:ensure-generic-function 'matched-val :lambda-list '(m))
(cl:defmethod matched-val ((m <match_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:matched-val is deprecated.  Use turtlebot_2dnav-msg:matched instead.")
  (matched m))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <match_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:index-val is deprecated.  Use turtlebot_2dnav-msg:index instead.")
  (index m))

(cl:ensure-generic-function 'color-val :lambda-list '(m))
(cl:defmethod color-val ((m <match_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:color-val is deprecated.  Use turtlebot_2dnav-msg:color instead.")
  (color m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <match_bound>) ostream)
  "Serializes a message object of type '<match_bound>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointright) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointleft) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointcenter) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'matched) 1 0)) ostream)
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
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <match_bound>) istream)
  "Deserializes a message object of type '<match_bound>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointright) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointleft) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointcenter) istream)
    (cl:setf (cl:slot-value msg 'matched) (cl:not (cl:zerop (cl:read-byte istream))))
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<match_bound>)))
  "Returns string type for a message object of type '<match_bound>"
  "turtlebot_2dnav/match_bound")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'match_bound)))
  "Returns string type for a message object of type 'match_bound"
  "turtlebot_2dnav/match_bound")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<match_bound>)))
  "Returns md5sum for a message object of type '<match_bound>"
  "c25fb2723cbd0da8861846f432114884")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'match_bound)))
  "Returns md5sum for a message object of type 'match_bound"
  "c25fb2723cbd0da8861846f432114884")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<match_bound>)))
  "Returns full string definition for message of type '<match_bound>"
  (cl:format cl:nil "geometry_msgs/Point pointright~%geometry_msgs/Point pointleft~%geometry_msgs/Point pointcenter~%bool matched~%int32 index~%int32 color~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'match_bound)))
  "Returns full string definition for message of type 'match_bound"
  (cl:format cl:nil "geometry_msgs/Point pointright~%geometry_msgs/Point pointleft~%geometry_msgs/Point pointcenter~%bool matched~%int32 index~%int32 color~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <match_bound>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointright))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointleft))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointcenter))
     1
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <match_bound>))
  "Converts a ROS message object to a list"
  (cl:list 'match_bound
    (cl:cons ':pointright (pointright msg))
    (cl:cons ':pointleft (pointleft msg))
    (cl:cons ':pointcenter (pointcenter msg))
    (cl:cons ':matched (matched msg))
    (cl:cons ':index (index msg))
    (cl:cons ':color (color msg))
))
