;; Auto-generated. Do not edit!


(when (boundp 'poi_database::ROI)
  (if (not (find-package "POI_DATABASE"))
    (make-package "POI_DATABASE"))
  (shadow 'ROI (find-package "POI_DATABASE")))
(unless (find-package "POI_DATABASE::ROI")
  (make-package "POI_DATABASE::ROI"))

(in-package "ROS")
;;//! \htmlinclude ROI.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass poi_database::ROI
  :super ros::object
  :slots (_Header _type _center _size_x _size_y _index _isnew ))

(defmethod poi_database::ROI
  (:init
   (&key
    ((:Header __Header) (instance std_msgs::Header :init))
    ((:type __type) "")
    ((:center __center) (instance geometry_msgs::Point :init))
    ((:size_x __size_x) 0.0)
    ((:size_y __size_y) 0.0)
    ((:index __index) 0)
    ((:isnew __isnew) nil)
    )
   (send-super :init)
   (setq _Header __Header)
   (setq _type (string __type))
   (setq _center __center)
   (setq _size_x (float __size_x))
   (setq _size_y (float __size_y))
   (setq _index (round __index))
   (setq _isnew __isnew)
   self)
  (:Header
   (&rest __Header)
   (if (keywordp (car __Header))
       (send* _Header __Header)
     (progn
       (if __Header (setq _Header (car __Header)))
       _Header)))
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:center
   (&rest __center)
   (if (keywordp (car __center))
       (send* _center __center)
     (progn
       (if __center (setq _center (car __center)))
       _center)))
  (:size_x
   (&optional __size_x)
   (if __size_x (setq _size_x __size_x)) _size_x)
  (:size_y
   (&optional __size_y)
   (if __size_y (setq _size_y __size_y)) _size_y)
  (:index
   (&optional __index)
   (if __index (setq _index __index)) _index)
  (:isnew
   (&optional __isnew)
   (if __isnew (setq _isnew __isnew)) _isnew)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _Header
    (send _Header :serialization-length)
    ;; string _type
    4 (length _type)
    ;; geometry_msgs/Point _center
    (send _center :serialization-length)
    ;; float32 _size_x
    4
    ;; float32 _size_y
    4
    ;; uint8 _index
    1
    ;; bool _isnew
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _Header
       (send _Header :serialize s)
     ;; string _type
       (write-long (length _type) s) (princ _type s)
     ;; geometry_msgs/Point _center
       (send _center :serialize s)
     ;; float32 _size_x
       (sys::poke _size_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _size_y
       (sys::poke _size_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _index
       (write-byte _index s)
     ;; bool _isnew
       (if _isnew (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _Header
     (send _Header :deserialize buf ptr-) (incf ptr- (send _Header :serialization-length))
   ;; string _type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; geometry_msgs/Point _center
     (send _center :deserialize buf ptr-) (incf ptr- (send _center :serialization-length))
   ;; float32 _size_x
     (setq _size_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _size_y
     (setq _size_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _index
     (setq _index (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _isnew
     (setq _isnew (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get poi_database::ROI :md5sum-) "fe6aa07fdbecd8b2e91005f5ecf70714")
(setf (get poi_database::ROI :datatype-) "poi_database/ROI")
(setf (get poi_database::ROI :definition-)
      "Header Header
string type
geometry_msgs/Point center
float32 size_x
float32 size_y
uint8 index
bool isnew

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :poi_database/ROI "fe6aa07fdbecd8b2e91005f5ecf70714")


