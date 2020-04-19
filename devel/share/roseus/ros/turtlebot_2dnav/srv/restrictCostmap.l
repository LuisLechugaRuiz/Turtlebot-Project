;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::restrictCostmap)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'restrictCostmap (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::RESTRICTCOSTMAP")
  (make-package "TURTLEBOT_2DNAV::RESTRICTCOSTMAP"))
(unless (find-package "TURTLEBOT_2DNAV::RESTRICTCOSTMAPREQUEST")
  (make-package "TURTLEBOT_2DNAV::RESTRICTCOSTMAPREQUEST"))
(unless (find-package "TURTLEBOT_2DNAV::RESTRICTCOSTMAPRESPONSE")
  (make-package "TURTLEBOT_2DNAV::RESTRICTCOSTMAPRESPONSE"))

(in-package "ROS")

(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass turtlebot_2dnav::restrictCostmapRequest
  :super ros::object
  :slots (_Point _index _color _restrict _isvertical _exit ))

(defmethod turtlebot_2dnav::restrictCostmapRequest
  (:init
   (&key
    ((:Point __Point) (instance geometry_msgs::Point :init))
    ((:index __index) 0)
    ((:color __color) 0)
    ((:restrict __restrict) nil)
    ((:isvertical __isvertical) nil)
    ((:exit __exit) nil)
    )
   (send-super :init)
   (setq _Point __Point)
   (setq _index (round __index))
   (setq _color (round __color))
   (setq _restrict __restrict)
   (setq _isvertical __isvertical)
   (setq _exit __exit)
   self)
  (:Point
   (&rest __Point)
   (if (keywordp (car __Point))
       (send* _Point __Point)
     (progn
       (if __Point (setq _Point (car __Point)))
       _Point)))
  (:index
   (&optional __index)
   (if __index (setq _index __index)) _index)
  (:color
   (&optional __color)
   (if __color (setq _color __color)) _color)
  (:restrict
   (&optional __restrict)
   (if __restrict (setq _restrict __restrict)) _restrict)
  (:isvertical
   (&optional __isvertical)
   (if __isvertical (setq _isvertical __isvertical)) _isvertical)
  (:exit
   (&optional __exit)
   (if __exit (setq _exit __exit)) _exit)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _Point
    (send _Point :serialization-length)
    ;; int32 _index
    4
    ;; int32 _color
    4
    ;; bool _restrict
    1
    ;; bool _isvertical
    1
    ;; bool _exit
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _Point
       (send _Point :serialize s)
     ;; int32 _index
       (write-long _index s)
     ;; int32 _color
       (write-long _color s)
     ;; bool _restrict
       (if _restrict (write-byte -1 s) (write-byte 0 s))
     ;; bool _isvertical
       (if _isvertical (write-byte -1 s) (write-byte 0 s))
     ;; bool _exit
       (if _exit (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _Point
     (send _Point :deserialize buf ptr-) (incf ptr- (send _Point :serialization-length))
   ;; int32 _index
     (setq _index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _color
     (setq _color (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _restrict
     (setq _restrict (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _isvertical
     (setq _isvertical (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _exit
     (setq _exit (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass turtlebot_2dnav::restrictCostmapResponse
  :super ros::object
  :slots (_received _NewCenter ))

(defmethod turtlebot_2dnav::restrictCostmapResponse
  (:init
   (&key
    ((:received __received) nil)
    ((:NewCenter __NewCenter) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _received __received)
   (setq _NewCenter __NewCenter)
   self)
  (:received
   (&optional __received)
   (if __received (setq _received __received)) _received)
  (:NewCenter
   (&rest __NewCenter)
   (if (keywordp (car __NewCenter))
       (send* _NewCenter __NewCenter)
     (progn
       (if __NewCenter (setq _NewCenter (car __NewCenter)))
       _NewCenter)))
  (:serialization-length
   ()
   (+
    ;; bool _received
    1
    ;; geometry_msgs/Point _NewCenter
    (send _NewCenter :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _received
       (if _received (write-byte -1 s) (write-byte 0 s))
     ;; geometry_msgs/Point _NewCenter
       (send _NewCenter :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _received
     (setq _received (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; geometry_msgs/Point _NewCenter
     (send _NewCenter :deserialize buf ptr-) (incf ptr- (send _NewCenter :serialization-length))
   ;;
   self)
  )

(defclass turtlebot_2dnav::restrictCostmap
  :super ros::object
  :slots ())

(setf (get turtlebot_2dnav::restrictCostmap :md5sum-) "ca045509d540aafaf4518df5620d8993")
(setf (get turtlebot_2dnav::restrictCostmap :datatype-) "turtlebot_2dnav/restrictCostmap")
(setf (get turtlebot_2dnav::restrictCostmap :request) turtlebot_2dnav::restrictCostmapRequest)
(setf (get turtlebot_2dnav::restrictCostmap :response) turtlebot_2dnav::restrictCostmapResponse)

(defmethod turtlebot_2dnav::restrictCostmapRequest
  (:response () (instance turtlebot_2dnav::restrictCostmapResponse :init)))

(setf (get turtlebot_2dnav::restrictCostmapRequest :md5sum-) "ca045509d540aafaf4518df5620d8993")
(setf (get turtlebot_2dnav::restrictCostmapRequest :datatype-) "turtlebot_2dnav/restrictCostmapRequest")
(setf (get turtlebot_2dnav::restrictCostmapRequest :definition-)
      "geometry_msgs/Point Point
int32 index
int32 color
bool restrict
bool isvertical
bool exit

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
---
bool received
geometry_msgs/Point NewCenter


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
")

(setf (get turtlebot_2dnav::restrictCostmapResponse :md5sum-) "ca045509d540aafaf4518df5620d8993")
(setf (get turtlebot_2dnav::restrictCostmapResponse :datatype-) "turtlebot_2dnav/restrictCostmapResponse")
(setf (get turtlebot_2dnav::restrictCostmapResponse :definition-)
      "geometry_msgs/Point Point
int32 index
int32 color
bool restrict
bool isvertical
bool exit

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
---
bool received
geometry_msgs/Point NewCenter


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
")



(provide :turtlebot_2dnav/restrictCostmap "ca045509d540aafaf4518df5620d8993")


