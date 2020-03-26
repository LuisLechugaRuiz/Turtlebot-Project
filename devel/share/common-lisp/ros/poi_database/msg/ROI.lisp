; Auto-generated. Do not edit!


(cl:in-package poi_database-msg)


;//! \htmlinclude ROI.msg.html

(cl:defclass <ROI> (roslisp-msg-protocol:ros-message)
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
   (center
    :reader center
    :initarg :center
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (size_x
    :reader size_x
    :initarg :size_x
    :type cl:float
    :initform 0.0)
   (size_y
    :reader size_y
    :initarg :size_y
    :type cl:float
    :initform 0.0)
   (index
    :reader index
    :initarg :index
    :type cl:fixnum
    :initform 0)
   (isnew
    :reader isnew
    :initarg :isnew
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ROI (<ROI>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ROI>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ROI)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name poi_database-msg:<ROI> is deprecated: use poi_database-msg:ROI instead.")))

(cl:ensure-generic-function 'Header-val :lambda-list '(m))
(cl:defmethod Header-val ((m <ROI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader poi_database-msg:Header-val is deprecated.  Use poi_database-msg:Header instead.")
  (Header m))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <ROI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader poi_database-msg:type-val is deprecated.  Use poi_database-msg:type instead.")
  (type m))

(cl:ensure-generic-function 'center-val :lambda-list '(m))
(cl:defmethod center-val ((m <ROI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader poi_database-msg:center-val is deprecated.  Use poi_database-msg:center instead.")
  (center m))

(cl:ensure-generic-function 'size_x-val :lambda-list '(m))
(cl:defmethod size_x-val ((m <ROI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader poi_database-msg:size_x-val is deprecated.  Use poi_database-msg:size_x instead.")
  (size_x m))

(cl:ensure-generic-function 'size_y-val :lambda-list '(m))
(cl:defmethod size_y-val ((m <ROI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader poi_database-msg:size_y-val is deprecated.  Use poi_database-msg:size_y instead.")
  (size_y m))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <ROI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader poi_database-msg:index-val is deprecated.  Use poi_database-msg:index instead.")
  (index m))

(cl:ensure-generic-function 'isnew-val :lambda-list '(m))
(cl:defmethod isnew-val ((m <ROI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader poi_database-msg:isnew-val is deprecated.  Use poi_database-msg:isnew instead.")
  (isnew m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ROI>) ostream)
  "Serializes a message object of type '<ROI>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'type))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'center) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'size_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'size_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'index)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isnew) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ROI>) istream)
  "Deserializes a message object of type '<ROI>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'center) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'size_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'size_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'index)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'isnew) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ROI>)))
  "Returns string type for a message object of type '<ROI>"
  "poi_database/ROI")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ROI)))
  "Returns string type for a message object of type 'ROI"
  "poi_database/ROI")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ROI>)))
  "Returns md5sum for a message object of type '<ROI>"
  "fe6aa07fdbecd8b2e91005f5ecf70714")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ROI)))
  "Returns md5sum for a message object of type 'ROI"
  "fe6aa07fdbecd8b2e91005f5ecf70714")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ROI>)))
  "Returns full string definition for message of type '<ROI>"
  (cl:format cl:nil "Header Header~%string type~%geometry_msgs/Point center~%float32 size_x~%float32 size_y~%uint8 index~%bool isnew~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ROI)))
  "Returns full string definition for message of type 'ROI"
  (cl:format cl:nil "Header Header~%string type~%geometry_msgs/Point center~%float32 size_x~%float32 size_y~%uint8 index~%bool isnew~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ROI>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Header))
     4 (cl:length (cl:slot-value msg 'type))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'center))
     4
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ROI>))
  "Converts a ROS message object to a list"
  (cl:list 'ROI
    (cl:cons ':Header (Header msg))
    (cl:cons ':type (type msg))
    (cl:cons ':center (center msg))
    (cl:cons ':size_x (size_x msg))
    (cl:cons ':size_y (size_y msg))
    (cl:cons ':index (index msg))
    (cl:cons ':isnew (isnew msg))
))
