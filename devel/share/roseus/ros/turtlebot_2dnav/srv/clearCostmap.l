;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::clearCostmap)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'clearCostmap (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::CLEARCOSTMAP")
  (make-package "TURTLEBOT_2DNAV::CLEARCOSTMAP"))
(unless (find-package "TURTLEBOT_2DNAV::CLEARCOSTMAPREQUEST")
  (make-package "TURTLEBOT_2DNAV::CLEARCOSTMAPREQUEST"))
(unless (find-package "TURTLEBOT_2DNAV::CLEARCOSTMAPRESPONSE")
  (make-package "TURTLEBOT_2DNAV::CLEARCOSTMAPRESPONSE"))

(in-package "ROS")





(defclass turtlebot_2dnav::clearCostmapRequest
  :super ros::object
  :slots (_clear ))

(defmethod turtlebot_2dnav::clearCostmapRequest
  (:init
   (&key
    ((:clear __clear) nil)
    )
   (send-super :init)
   (setq _clear __clear)
   self)
  (:clear
   (&optional __clear)
   (if __clear (setq _clear __clear)) _clear)
  (:serialization-length
   ()
   (+
    ;; bool _clear
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _clear
       (if _clear (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _clear
     (setq _clear (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass turtlebot_2dnav::clearCostmapResponse
  :super ros::object
  :slots (_received ))

(defmethod turtlebot_2dnav::clearCostmapResponse
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

(defclass turtlebot_2dnav::clearCostmap
  :super ros::object
  :slots ())

(setf (get turtlebot_2dnav::clearCostmap :md5sum-) "6f1cadb125ab62799a65523a8282332f")
(setf (get turtlebot_2dnav::clearCostmap :datatype-) "turtlebot_2dnav/clearCostmap")
(setf (get turtlebot_2dnav::clearCostmap :request) turtlebot_2dnav::clearCostmapRequest)
(setf (get turtlebot_2dnav::clearCostmap :response) turtlebot_2dnav::clearCostmapResponse)

(defmethod turtlebot_2dnav::clearCostmapRequest
  (:response () (instance turtlebot_2dnav::clearCostmapResponse :init)))

(setf (get turtlebot_2dnav::clearCostmapRequest :md5sum-) "6f1cadb125ab62799a65523a8282332f")
(setf (get turtlebot_2dnav::clearCostmapRequest :datatype-) "turtlebot_2dnav/clearCostmapRequest")
(setf (get turtlebot_2dnav::clearCostmapRequest :definition-)
      "bool clear
---
bool received

")

(setf (get turtlebot_2dnav::clearCostmapResponse :md5sum-) "6f1cadb125ab62799a65523a8282332f")
(setf (get turtlebot_2dnav::clearCostmapResponse :datatype-) "turtlebot_2dnav/clearCostmapResponse")
(setf (get turtlebot_2dnav::clearCostmapResponse :definition-)
      "bool clear
---
bool received

")



(provide :turtlebot_2dnav/clearCostmap "6f1cadb125ab62799a65523a8282332f")


