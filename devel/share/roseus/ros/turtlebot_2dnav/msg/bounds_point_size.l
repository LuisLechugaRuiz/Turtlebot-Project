;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::bounds_point_size)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'bounds_point_size (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::BOUNDS_POINT_SIZE")
  (make-package "TURTLEBOT_2DNAV::BOUNDS_POINT_SIZE"))

(in-package "ROS")
;;//! \htmlinclude bounds_point_size.msg.html


(defclass turtlebot_2dnav::bounds_point_size
  :super ros::object
  :slots (_points_size _red_zones_active ))

(defmethod turtlebot_2dnav::bounds_point_size
  (:init
   (&key
    ((:points_size __points_size) (make-array 0 :initial-element 0 :element-type :integer))
    ((:red_zones_active __red_zones_active) nil)
    )
   (send-super :init)
   (setq _points_size __points_size)
   (setq _red_zones_active __red_zones_active)
   self)
  (:points_size
   (&optional __points_size)
   (if __points_size (setq _points_size __points_size)) _points_size)
  (:red_zones_active
   (&optional __red_zones_active)
   (if __red_zones_active (setq _red_zones_active __red_zones_active)) _red_zones_active)
  (:serialization-length
   ()
   (+
    ;; int32[] _points_size
    (* 4    (length _points_size)) 4
    ;; bool _red_zones_active
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32[] _points_size
     (write-long (length _points_size) s)
     (dotimes (i (length _points_size))
       (write-long (elt _points_size i) s)
       )
     ;; bool _red_zones_active
       (if _red_zones_active (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32[] _points_size
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _points_size (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _points_size i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; bool _red_zones_active
     (setq _red_zones_active (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get turtlebot_2dnav::bounds_point_size :md5sum-) "2760f00cd3ace23bdfe186aae6abbb4b")
(setf (get turtlebot_2dnav::bounds_point_size :datatype-) "turtlebot_2dnav/bounds_point_size")
(setf (get turtlebot_2dnav::bounds_point_size :definition-)
      "int32[] points_size
bool red_zones_active

")



(provide :turtlebot_2dnav/bounds_point_size "2760f00cd3ace23bdfe186aae6abbb4b")


