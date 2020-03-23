;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::returnCost)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'returnCost (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::RETURNCOST")
  (make-package "TURTLEBOT_2DNAV::RETURNCOST"))
(unless (find-package "TURTLEBOT_2DNAV::RETURNCOSTREQUEST")
  (make-package "TURTLEBOT_2DNAV::RETURNCOSTREQUEST"))
(unless (find-package "TURTLEBOT_2DNAV::RETURNCOSTRESPONSE")
  (make-package "TURTLEBOT_2DNAV::RETURNCOSTRESPONSE"))

(in-package "ROS")

(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))




(defclass turtlebot_2dnav::returnCostRequest
  :super ros::object
  :slots (_start _goal ))

(defmethod turtlebot_2dnav::returnCostRequest
  (:init
   (&key
    ((:start __start) (instance geometry_msgs::PoseStamped :init))
    ((:goal __goal) (instance geometry_msgs::PoseStamped :init))
    )
   (send-super :init)
   (setq _start __start)
   (setq _goal __goal)
   self)
  (:start
   (&rest __start)
   (if (keywordp (car __start))
       (send* _start __start)
     (progn
       (if __start (setq _start (car __start)))
       _start)))
  (:goal
   (&rest __goal)
   (if (keywordp (car __goal))
       (send* _goal __goal)
     (progn
       (if __goal (setq _goal (car __goal)))
       _goal)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/PoseStamped _start
    (send _start :serialization-length)
    ;; geometry_msgs/PoseStamped _goal
    (send _goal :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/PoseStamped _start
       (send _start :serialize s)
     ;; geometry_msgs/PoseStamped _goal
       (send _goal :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/PoseStamped _start
     (send _start :deserialize buf ptr-) (incf ptr- (send _start :serialization-length))
   ;; geometry_msgs/PoseStamped _goal
     (send _goal :deserialize buf ptr-) (incf ptr- (send _goal :serialization-length))
   ;;
   self)
  )

(defclass turtlebot_2dnav::returnCostResponse
  :super ros::object
  :slots (_cost ))

(defmethod turtlebot_2dnav::returnCostResponse
  (:init
   (&key
    ((:cost __cost) 0)
    )
   (send-super :init)
   (setq _cost (round __cost))
   self)
  (:cost
   (&optional __cost)
   (if __cost (setq _cost __cost)) _cost)
  (:serialization-length
   ()
   (+
    ;; int64 _cost
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _cost
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _cost (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _cost) (= (length (_cost . bv)) 2)) ;; bignum
              (write-long (ash (elt (_cost . bv) 0) 0) s)
              (write-long (ash (elt (_cost . bv) 1) -1) s))
             ((and (class _cost) (= (length (_cost . bv)) 1)) ;; big1
              (write-long (elt (_cost . bv) 0) s)
              (write-long (if (>= _cost 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _cost s)(write-long (if (>= _cost 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _cost
#+(or :alpha :irix6 :x86_64)
      (setf _cost (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _cost (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass turtlebot_2dnav::returnCost
  :super ros::object
  :slots ())

(setf (get turtlebot_2dnav::returnCost :md5sum-) "f0ab08f6ab3861462bec12fbd2aae873")
(setf (get turtlebot_2dnav::returnCost :datatype-) "turtlebot_2dnav/returnCost")
(setf (get turtlebot_2dnav::returnCost :request) turtlebot_2dnav::returnCostRequest)
(setf (get turtlebot_2dnav::returnCost :response) turtlebot_2dnav::returnCostResponse)

(defmethod turtlebot_2dnav::returnCostRequest
  (:response () (instance turtlebot_2dnav::returnCostResponse :init)))

(setf (get turtlebot_2dnav::returnCostRequest :md5sum-) "f0ab08f6ab3861462bec12fbd2aae873")
(setf (get turtlebot_2dnav::returnCostRequest :datatype-) "turtlebot_2dnav/returnCostRequest")
(setf (get turtlebot_2dnav::returnCostRequest :definition-)
      "geometry_msgs/PoseStamped start

geometry_msgs/PoseStamped goal


================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

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
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---

int64 cost

")

(setf (get turtlebot_2dnav::returnCostResponse :md5sum-) "f0ab08f6ab3861462bec12fbd2aae873")
(setf (get turtlebot_2dnav::returnCostResponse :datatype-) "turtlebot_2dnav/returnCostResponse")
(setf (get turtlebot_2dnav::returnCostResponse :definition-)
      "geometry_msgs/PoseStamped start

geometry_msgs/PoseStamped goal


================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

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
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---

int64 cost

")



(provide :turtlebot_2dnav/returnCost "f0ab08f6ab3861462bec12fbd2aae873")


