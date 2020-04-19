;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::CarryingPerson)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'CarryingPerson (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::CARRYINGPERSON")
  (make-package "TURTLEBOT_2DNAV::CARRYINGPERSON"))
(unless (find-package "TURTLEBOT_2DNAV::CARRYINGPERSONREQUEST")
  (make-package "TURTLEBOT_2DNAV::CARRYINGPERSONREQUEST"))
(unless (find-package "TURTLEBOT_2DNAV::CARRYINGPERSONRESPONSE")
  (make-package "TURTLEBOT_2DNAV::CARRYINGPERSONRESPONSE"))

(in-package "ROS")





(defclass turtlebot_2dnav::CarryingPersonRequest
  :super ros::object
  :slots (_person ))

(defmethod turtlebot_2dnav::CarryingPersonRequest
  (:init
   (&key
    ((:person __person) (instance turtlebot_2dnav::ROI :init))
    )
   (send-super :init)
   (setq _person __person)
   self)
  (:person
   (&rest __person)
   (if (keywordp (car __person))
       (send* _person __person)
     (progn
       (if __person (setq _person (car __person)))
       _person)))
  (:serialization-length
   ()
   (+
    ;; turtlebot_2dnav/ROI _person
    (send _person :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; turtlebot_2dnav/ROI _person
       (send _person :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; turtlebot_2dnav/ROI _person
     (send _person :deserialize buf ptr-) (incf ptr- (send _person :serialization-length))
   ;;
   self)
  )

(defclass turtlebot_2dnav::CarryingPersonResponse
  :super ros::object
  :slots (_received ))

(defmethod turtlebot_2dnav::CarryingPersonResponse
  (:init
   (&key
    ((:received __received) nil)
    )
   (send-super :init)
   (setq _received __received)
   self)
  (:received
   (&optional __received)
   (if __received (setq _received __received)) _received)
  (:serialization-length
   ()
   (+
    ;; bool _received
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _received
       (if _received (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _received
     (setq _received (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass turtlebot_2dnav::CarryingPerson
  :super ros::object
  :slots ())

(setf (get turtlebot_2dnav::CarryingPerson :md5sum-) "483ed3a7747788a7b78a207bdc605ba1")
(setf (get turtlebot_2dnav::CarryingPerson :datatype-) "turtlebot_2dnav/CarryingPerson")
(setf (get turtlebot_2dnav::CarryingPerson :request) turtlebot_2dnav::CarryingPersonRequest)
(setf (get turtlebot_2dnav::CarryingPerson :response) turtlebot_2dnav::CarryingPersonResponse)

(defmethod turtlebot_2dnav::CarryingPersonRequest
  (:response () (instance turtlebot_2dnav::CarryingPersonResponse :init)))

(setf (get turtlebot_2dnav::CarryingPersonRequest :md5sum-) "483ed3a7747788a7b78a207bdc605ba1")
(setf (get turtlebot_2dnav::CarryingPersonRequest :datatype-) "turtlebot_2dnav/CarryingPersonRequest")
(setf (get turtlebot_2dnav::CarryingPersonRequest :definition-)
      "turtlebot_2dnav/ROI person


================================================================================
MSG: turtlebot_2dnav/ROI
Header Header
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
---

bool received

")

(setf (get turtlebot_2dnav::CarryingPersonResponse :md5sum-) "483ed3a7747788a7b78a207bdc605ba1")
(setf (get turtlebot_2dnav::CarryingPersonResponse :datatype-) "turtlebot_2dnav/CarryingPersonResponse")
(setf (get turtlebot_2dnav::CarryingPersonResponse :definition-)
      "turtlebot_2dnav/ROI person


================================================================================
MSG: turtlebot_2dnav/ROI
Header Header
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
---

bool received

")



(provide :turtlebot_2dnav/CarryingPerson "483ed3a7747788a7b78a207bdc605ba1")


