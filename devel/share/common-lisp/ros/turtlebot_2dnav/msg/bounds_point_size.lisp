; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-msg)


;//! \htmlinclude bounds_point_size.msg.html

(cl:defclass <bounds_point_size> (roslisp-msg-protocol:ros-message)
  ((points_size
    :reader points_size
    :initarg :points_size
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (red_zones_active
    :reader red_zones_active
    :initarg :red_zones_active
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass bounds_point_size (<bounds_point_size>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <bounds_point_size>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'bounds_point_size)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-msg:<bounds_point_size> is deprecated: use turtlebot_2dnav-msg:bounds_point_size instead.")))

(cl:ensure-generic-function 'points_size-val :lambda-list '(m))
(cl:defmethod points_size-val ((m <bounds_point_size>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:points_size-val is deprecated.  Use turtlebot_2dnav-msg:points_size instead.")
  (points_size m))

(cl:ensure-generic-function 'red_zones_active-val :lambda-list '(m))
(cl:defmethod red_zones_active-val ((m <bounds_point_size>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-msg:red_zones_active-val is deprecated.  Use turtlebot_2dnav-msg:red_zones_active instead.")
  (red_zones_active m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <bounds_point_size>) ostream)
  "Serializes a message object of type '<bounds_point_size>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'points_size))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'points_size))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'red_zones_active) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <bounds_point_size>) istream)
  "Deserializes a message object of type '<bounds_point_size>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'points_size) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'points_size)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
    (cl:setf (cl:slot-value msg 'red_zones_active) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<bounds_point_size>)))
  "Returns string type for a message object of type '<bounds_point_size>"
  "turtlebot_2dnav/bounds_point_size")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'bounds_point_size)))
  "Returns string type for a message object of type 'bounds_point_size"
  "turtlebot_2dnav/bounds_point_size")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<bounds_point_size>)))
  "Returns md5sum for a message object of type '<bounds_point_size>"
  "2760f00cd3ace23bdfe186aae6abbb4b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'bounds_point_size)))
  "Returns md5sum for a message object of type 'bounds_point_size"
  "2760f00cd3ace23bdfe186aae6abbb4b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<bounds_point_size>)))
  "Returns full string definition for message of type '<bounds_point_size>"
  (cl:format cl:nil "int32[] points_size~%bool red_zones_active~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'bounds_point_size)))
  "Returns full string definition for message of type 'bounds_point_size"
  (cl:format cl:nil "int32[] points_size~%bool red_zones_active~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <bounds_point_size>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'points_size) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <bounds_point_size>))
  "Converts a ROS message object to a list"
  (cl:list 'bounds_point_size
    (cl:cons ':points_size (points_size msg))
    (cl:cons ':red_zones_active (red_zones_active msg))
))
