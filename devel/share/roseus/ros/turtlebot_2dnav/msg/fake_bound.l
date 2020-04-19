;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::fake_bound)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'fake_bound (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::FAKE_BOUND")
  (make-package "TURTLEBOT_2DNAV::FAKE_BOUND"))

(in-package "ROS")
;;//! \htmlinclude fake_bound.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass turtlebot_2dnav::fake_bound
  :super ros::object
  :slots (_pointleftmin _pointleftmax _pointrightmin _pointrightmax _isvertical _index _resize _exit ))

(defmethod turtlebot_2dnav::fake_bound
  (:init
   (&key
    ((:pointleftmin __pointleftmin) (instance geometry_msgs::Point :init))
    ((:pointleftmax __pointleftmax) (instance geometry_msgs::Point :init))
    ((:pointrightmin __pointrightmin) (instance geometry_msgs::Point :init))
    ((:pointrightmax __pointrightmax) (instance geometry_msgs::Point :init))
    ((:isvertical __isvertical) nil)
    ((:index __index) 0)
    ((:resize __resize) nil)
    ((:exit __exit) nil)
    )
   (send-super :init)
   (setq _pointleftmin __pointleftmin)
   (setq _pointleftmax __pointleftmax)
   (setq _pointrightmin __pointrightmin)
   (setq _pointrightmax __pointrightmax)
   (setq _isvertical __isvertical)
   (setq _index (round __index))
   (setq _resize __resize)
   (setq _exit __exit)
   self)
  (:pointleftmin
   (&rest __pointleftmin)
   (if (keywordp (car __pointleftmin))
       (send* _pointleftmin __pointleftmin)
     (progn
       (if __pointleftmin (setq _pointleftmin (car __pointleftmin)))
       _pointleftmin)))
  (:pointleftmax
   (&rest __pointleftmax)
   (if (keywordp (car __pointleftmax))
       (send* _pointleftmax __pointleftmax)
     (progn
       (if __pointleftmax (setq _pointleftmax (car __pointleftmax)))
       _pointleftmax)))
  (:pointrightmin
   (&rest __pointrightmin)
   (if (keywordp (car __pointrightmin))
       (send* _pointrightmin __pointrightmin)
     (progn
       (if __pointrightmin (setq _pointrightmin (car __pointrightmin)))
       _pointrightmin)))
  (:pointrightmax
   (&rest __pointrightmax)
   (if (keywordp (car __pointrightmax))
       (send* _pointrightmax __pointrightmax)
     (progn
       (if __pointrightmax (setq _pointrightmax (car __pointrightmax)))
       _pointrightmax)))
  (:isvertical
   (&optional __isvertical)
   (if __isvertical (setq _isvertical __isvertical)) _isvertical)
  (:index
   (&optional __index)
   (if __index (setq _index __index)) _index)
  (:resize
   (&optional __resize)
   (if __resize (setq _resize __resize)) _resize)
  (:exit
   (&optional __exit)
   (if __exit (setq _exit __exit)) _exit)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _pointleftmin
    (send _pointleftmin :serialization-length)
    ;; geometry_msgs/Point _pointleftmax
    (send _pointleftmax :serialization-length)
    ;; geometry_msgs/Point _pointrightmin
    (send _pointrightmin :serialization-length)
    ;; geometry_msgs/Point _pointrightmax
    (send _pointrightmax :serialization-length)
    ;; bool _isvertical
    1
    ;; uint8 _index
    1
    ;; bool _resize
    1
    ;; bool _exit
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _pointleftmin
       (send _pointleftmin :serialize s)
     ;; geometry_msgs/Point _pointleftmax
       (send _pointleftmax :serialize s)
     ;; geometry_msgs/Point _pointrightmin
       (send _pointrightmin :serialize s)
     ;; geometry_msgs/Point _pointrightmax
       (send _pointrightmax :serialize s)
     ;; bool _isvertical
       (if _isvertical (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _index
       (write-byte _index s)
     ;; bool _resize
       (if _resize (write-byte -1 s) (write-byte 0 s))
     ;; bool _exit
       (if _exit (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _pointleftmin
     (send _pointleftmin :deserialize buf ptr-) (incf ptr- (send _pointleftmin :serialization-length))
   ;; geometry_msgs/Point _pointleftmax
     (send _pointleftmax :deserialize buf ptr-) (incf ptr- (send _pointleftmax :serialization-length))
   ;; geometry_msgs/Point _pointrightmin
     (send _pointrightmin :deserialize buf ptr-) (incf ptr- (send _pointrightmin :serialization-length))
   ;; geometry_msgs/Point _pointrightmax
     (send _pointrightmax :deserialize buf ptr-) (incf ptr- (send _pointrightmax :serialization-length))
   ;; bool _isvertical
     (setq _isvertical (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _index
     (setq _index (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _resize
     (setq _resize (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _exit
     (setq _exit (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get turtlebot_2dnav::fake_bound :md5sum-) "d1c2e5bd63abef51265cdf5e8668cf43")
(setf (get turtlebot_2dnav::fake_bound :datatype-) "turtlebot_2dnav/fake_bound")
(setf (get turtlebot_2dnav::fake_bound :definition-)
      "geometry_msgs/Point pointleftmin
geometry_msgs/Point pointleftmax
geometry_msgs/Point pointrightmin
geometry_msgs/Point pointrightmax
bool isvertical
uint8 index
bool resize
bool exit

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :turtlebot_2dnav/fake_bound "d1c2e5bd63abef51265cdf5e8668cf43")


