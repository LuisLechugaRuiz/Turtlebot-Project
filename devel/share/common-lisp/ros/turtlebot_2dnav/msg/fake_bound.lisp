; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-msg)


;//! \htmlinclude fake_bound.msg.html

(cl:defclass <fake_bound> (roslisp-msg-protocol:ros-message)
  ((pointleftmin
    :reader pointleftmin
    :initarg :pointleftmin
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (pointleftmax
    :reader pointleftmax
    :initarg :pointleftmax
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (pointrightmin
    :reader pointrightmin
    :initarg :pointrightmin
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (pointrightmax
    :reader pointrightmax
    :initarg :pointrightmax
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (isvertical
    :reader isvertical
    :initarg :isvertical
    :type cl:boolean
    :initform cl:nil)
   (index
    :reader index
    :initarg :index
    :type cl:fixnum
    :initform 0)
   (resize
    :reader resize
    :initarg :resize
    :type cl:boolean
    :initform cl:nil)
   (exit
    :reader exit
    :initarg :exit
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass fake_bound (<fake_bound>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <fake_bound>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'fake_bound)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-msg:<fake_bound> is deprecated: use turtlebot_2dnav-msg:fake_bound instead.")))

(cl:ensure-generic-function 'pointleftmin-val :lambda-list '(m))
(cl:defmethod pointleftmin-val ((m <fake_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:pointleftmin-val is deprecated.  Use turtlebot_2dnav-msg:pointleftmin instead.")
  (pointleftmin m))

(cl:ensure-generic-function 'pointleftmax-val :lambda-list '(m))
(cl:defmethod pointleftmax-val ((m <fake_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:pointleftmax-val is deprecated.  Use turtlebot_2dnav-msg:pointleftmax instead.")
  (pointleftmax m))

(cl:ensure-generic-function 'pointrightmin-val :lambda-list '(m))
(cl:defmethod pointrightmin-val ((m <fake_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:pointrightmin-val is deprecated.  Use turtlebot_2dnav-msg:pointrightmin instead.")
  (pointrightmin m))

(cl:ensure-generic-function 'pointrightmax-val :lambda-list '(m))
(cl:defmethod pointrightmax-val ((m <fake_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:pointrightmax-val is deprecated.  Use turtlebot_2dnav-msg:pointrightmax instead.")
  (pointrightmax m))

(cl:ensure-generic-function 'isvertical-val :lambda-list '(m))
(cl:defmethod isvertical-val ((m <fake_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:isvertical-val is deprecated.  Use turtlebot_2dnav-msg:isvertical instead.")
  (isvertical m))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <fake_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:index-val is deprecated.  Use turtlebot_2dnav-msg:index instead.")
  (index m))

(cl:ensure-generic-function 'resize-val :lambda-list '(m))
(cl:defmethod resize-val ((m <fake_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:resize-val is deprecated.  Use turtlebot_2dnav-msg:resize instead.")
  (resize m))

(cl:ensure-generic-function 'exit-val :lambda-list '(m))
(cl:defmethod exit-val ((m <fake_bound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:exit-val is deprecated.  Use turtlebot_2dnav-msg:exit instead.")
  (exit m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <fake_bound>) ostream)
  "Serializes a message object of type '<fake_bound>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointleftmin) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointleftmax) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointrightmin) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointrightmax) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isvertical) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'index)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'resize) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'exit) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <fake_bound>) istream)
  "Deserializes a message object of type '<fake_bound>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointleftmin) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointleftmax) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointrightmin) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointrightmax) istream)
    (cl:setf (cl:slot-value msg 'isvertical) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'index)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'resize) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'exit) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<fake_bound>)))
  "Returns string type for a message object of type '<fake_bound>"
  "turtlebot_2dnav/fake_bound")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'fake_bound)))
  "Returns string type for a message object of type 'fake_bound"
  "turtlebot_2dnav/fake_bound")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<fake_bound>)))
  "Returns md5sum for a message object of type '<fake_bound>"
  "d1c2e5bd63abef51265cdf5e8668cf43")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'fake_bound)))
  "Returns md5sum for a message object of type 'fake_bound"
  "d1c2e5bd63abef51265cdf5e8668cf43")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<fake_bound>)))
  "Returns full string definition for message of type '<fake_bound>"
  (cl:format cl:nil "geometry_msgs/Point pointleftmin~%geometry_msgs/Point pointleftmax~%geometry_msgs/Point pointrightmin~%geometry_msgs/Point pointrightmax~%bool isvertical~%uint8 index~%bool resize~%bool exit~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'fake_bound)))
  "Returns full string definition for message of type 'fake_bound"
  (cl:format cl:nil "geometry_msgs/Point pointleftmin~%geometry_msgs/Point pointleftmax~%geometry_msgs/Point pointrightmin~%geometry_msgs/Point pointrightmax~%bool isvertical~%uint8 index~%bool resize~%bool exit~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <fake_bound>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointleftmin))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointleftmax))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointrightmin))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointrightmax))
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <fake_bound>))
  "Converts a ROS message object to a list"
  (cl:list 'fake_bound
    (cl:cons ':pointleftmin (pointleftmin msg))
    (cl:cons ':pointleftmax (pointleftmax msg))
    (cl:cons ':pointrightmin (pointrightmin msg))
    (cl:cons ':pointrightmax (pointrightmax msg))
    (cl:cons ':isvertical (isvertical msg))
    (cl:cons ':index (index msg))
    (cl:cons ':resize (resize msg))
    (cl:cons ':exit (exit msg))
))
