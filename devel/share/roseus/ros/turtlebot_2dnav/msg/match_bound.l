;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::match_bound)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'match_bound (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::MATCH_BOUND")
  (make-package "TURTLEBOT_2DNAV::MATCH_BOUND"))

(in-package "ROS")
;;//! \htmlinclude match_bound.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass turtlebot_2dnav::match_bound
  :super ros::object
  :slots (_pointright _pointleft _pointcenter _matched _index _color ))

(defmethod turtlebot_2dnav::match_bound
  (:init
   (&key
    ((:pointright __pointright) (instance geometry_msgs::Point :init))
    ((:pointleft __pointleft) (instance geometry_msgs::Point :init))
    ((:pointcenter __pointcenter) (instance geometry_msgs::Point :init))
    ((:matched __matched) nil)
    ((:index __index) 0)
    ((:color __color) 0)
    )
   (send-super :init)
   (setq _pointright __pointright)
   (setq _pointleft __pointleft)
   (setq _pointcenter __pointcenter)
   (setq _matched __matched)
   (setq _index (round __index))
   (setq _color (round __color))
   self)
  (:pointright
   (&rest __pointright)
   (if (keywordp (car __pointright))
       (send* _pointright __pointright)
     (progn
       (if __pointright (setq _pointright (car __pointright)))
       _pointright)))
  (:pointleft
   (&rest __pointleft)
   (if (keywordp (car __pointleft))
       (send* _pointleft __pointleft)
     (progn
       (if __pointleft (setq _pointleft (car __pointleft)))
       _pointleft)))
  (:pointcenter
   (&rest __pointcenter)
   (if (keywordp (car __pointcenter))
       (send* _pointcenter __pointcenter)
     (progn
       (if __pointcenter (setq _pointcenter (car __pointcenter)))
       _pointcenter)))
  (:matched
   (&optional __matched)
   (if __matched (setq _matched __matched)) _matched)
  (:index
   (&optional __index)
   (if __index (setq _index __index)) _index)
  (:color
   (&optional __color)
   (if __color (setq _color __color)) _color)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _pointright
    (send _pointright :serialization-length)
    ;; geometry_msgs/Point _pointleft
    (send _pointleft :serialization-length)
    ;; geometry_msgs/Point _pointcenter
    (send _pointcenter :serialization-length)
    ;; bool _matched
    1
    ;; int32 _index
    4
    ;; int32 _color
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _pointright
       (send _pointright :serialize s)
     ;; geometry_msgs/Point _pointleft
       (send _pointleft :serialize s)
     ;; geometry_msgs/Point _pointcenter
       (send _pointcenter :serialize s)
     ;; bool _matched
       (if _matched (write-byte -1 s) (write-byte 0 s))
     ;; int32 _index
       (write-long _index s)
     ;; int32 _color
       (write-long _color s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _pointright
     (send _pointright :deserialize buf ptr-) (incf ptr- (send _pointright :serialization-length))
   ;; geometry_msgs/Point _pointleft
     (send _pointleft :deserialize buf ptr-) (incf ptr- (send _pointleft :serialization-length))
   ;; geometry_msgs/Point _pointcenter
     (send _pointcenter :deserialize buf ptr-) (incf ptr- (send _pointcenter :serialization-length))
   ;; bool _matched
     (setq _matched (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _index
     (setq _index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _color
     (setq _color (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get turtlebot_2dnav::match_bound :md5sum-) "c25fb2723cbd0da8861846f432114884")
(setf (get turtlebot_2dnav::match_bound :datatype-) "turtlebot_2dnav/match_bound")
(setf (get turtlebot_2dnav::match_bound :definition-)
      "geometry_msgs/Point pointright
geometry_msgs/Point pointleft
geometry_msgs/Point pointcenter
bool matched
int32 index
int32 color

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :turtlebot_2dnav/match_bound "c25fb2723cbd0da8861846f432114884")


