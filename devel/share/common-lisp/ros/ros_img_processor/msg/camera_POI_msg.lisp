; Auto-generated. Do not edit!


(cl:in-package ros_img_processor-msg)


;//! \htmlinclude camera_POI_msg.msg.html

(cl:defclass <camera_POI_msg> (roslisp-msg-protocol:ros-message)
  ((Header
    :reader Header
    :initarg :Header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (type
    :reader type
    :initarg :type
    :type cl:string
    :initform "")
   (pointleft
    :reader pointleft
    :initarg :pointleft
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (pointright
    :reader pointright
    :initarg :pointright
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass camera_POI_msg (<camera_POI_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <camera_POI_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'camera_POI_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_img_processor-msg:<camera_POI_msg> is deprecated: use ros_img_processor-msg:camera_POI_msg instead.")))

(cl:ensure-generic-function 'Header-val :lambda-list '(m))
(cl:defmethod Header-val ((m <camera_POI_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_img_processor-msg:Header-val is deprecated.  Use ros_img_processor-msg:Header instead.")
  (Header m))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <camera_POI_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_img_processor-msg:type-val is deprecated.  Use ros_img_processor-msg:type instead.")
  (type m))

(cl:ensure-generic-function 'pointleft-val :lambda-list '(m))
(cl:defmethod pointleft-val ((m <camera_POI_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_img_processor-msg:pointleft-val is deprecated.  Use ros_img_processor-msg:pointleft instead.")
  (pointleft m))

(cl:ensure-generic-function 'pointright-val :lambda-list '(m))
(cl:defmethod pointright-val ((m <camera_POI_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_img_processor-msg:pointright-val is deprecated.  Use ros_img_processor-msg:pointright instead.")
  (pointright m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <camera_POI_msg>) ostream)
  "Serializes a message object of type '<camera_POI_msg>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'type))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointleft) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointright) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <camera_POI_msg>) istream)
  "Deserializes a message object of type '<camera_POI_msg>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointleft) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointright) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<camera_POI_msg>)))
  "Returns string type for a message object of type '<camera_POI_msg>"
  "ros_img_processor/camera_POI_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'camera_POI_msg)))
  "Returns string type for a message object of type 'camera_POI_msg"
  "ros_img_processor/camera_POI_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<camera_POI_msg>)))
  "Returns md5sum for a message object of type '<camera_POI_msg>"
  "3889b5518a505b6dff84d0f699e8b734")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'camera_POI_msg)))
  "Returns md5sum for a message object of type 'camera_POI_msg"
  "3889b5518a505b6dff84d0f699e8b734")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<camera_POI_msg>)))
  "Returns full string definition for message of type '<camera_POI_msg>"
  (cl:format cl:nil "Header Header~%string type~%geometry_msgs/Point pointleft~%geometry_msgs/Point pointright~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'camera_POI_msg)))
  "Returns full string definition for message of type 'camera_POI_msg"
  (cl:format cl:nil "Header Header~%string type~%geometry_msgs/Point pointleft~%geometry_msgs/Point pointright~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <camera_POI_msg>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Header))
     4 (cl:length (cl:slot-value msg 'type))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointleft))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointright))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <camera_POI_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'camera_POI_msg
    (cl:cons ':Header (Header msg))
    (cl:cons ':type (type msg))
    (cl:cons ':pointleft (pointleft msg))
    (cl:cons ':pointright (pointright msg))
))
