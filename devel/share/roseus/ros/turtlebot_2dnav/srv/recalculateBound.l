;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::recalculateBound)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'recalculateBound (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::RECALCULATEBOUND")
  (make-package "TURTLEBOT_2DNAV::RECALCULATEBOUND"))
(unless (find-package "TURTLEBOT_2DNAV::RECALCULATEBOUNDREQUEST")
  (make-package "TURTLEBOT_2DNAV::RECALCULATEBOUNDREQUEST"))
(unless (find-package "TURTLEBOT_2DNAV::RECALCULATEBOUNDRESPONSE")
  (make-package "TURTLEBOT_2DNAV::RECALCULATEBOUNDRESPONSE"))

(in-package "ROS")





(defclass turtlebot_2dnav::recalculateBoundRequest
  :super ros::object
  :slots (_recalculate ))

(defmethod turtlebot_2dnav::recalculateBoundRequest
  (:init
   (&key
    ((:recalculate __recalculate) nil)
    )
   (send-super :init)
   (setq _recalculate __recalculate)
   self)
  (:recalculate
   (&optional __recalculate)
   (if __recalculate (setq _recalculate __recalculate)) _recalculate)
  (:serialization-length
   ()
   (+
    ;; bool _recalculate
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _recalculate
       (if _recalculate (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _recalculate
     (setq _recalculate (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass turtlebot_2dnav::recalculateBoundResponse
  :super ros::object
  :slots (_received ))

(defmethod turtlebot_2dnav::recalculateBoundResponse
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

(defclass turtlebot_2dnav::recalculateBound
  :super ros::object
  :slots ())

(setf (get turtlebot_2dnav::recalculateBound :md5sum-) "ccb08b87036c8a7862161f690fdb0a11")
(setf (get turtlebot_2dnav::recalculateBound :datatype-) "turtlebot_2dnav/recalculateBound")
(setf (get turtlebot_2dnav::recalculateBound :request) turtlebot_2dnav::recalculateBoundRequest)
(setf (get turtlebot_2dnav::recalculateBound :response) turtlebot_2dnav::recalculateBoundResponse)

(defmethod turtlebot_2dnav::recalculateBoundRequest
  (:response () (instance turtlebot_2dnav::recalculateBoundResponse :init)))

(setf (get turtlebot_2dnav::recalculateBoundRequest :md5sum-) "ccb08b87036c8a7862161f690fdb0a11")
(setf (get turtlebot_2dnav::recalculateBoundRequest :datatype-) "turtlebot_2dnav/recalculateBoundRequest")
(setf (get turtlebot_2dnav::recalculateBoundRequest :definition-)
      "bool recalculate
---
bool received

")

(setf (get turtlebot_2dnav::recalculateBoundResponse :md5sum-) "ccb08b87036c8a7862161f690fdb0a11")
(setf (get turtlebot_2dnav::recalculateBoundResponse :datatype-) "turtlebot_2dnav/recalculateBoundResponse")
(setf (get turtlebot_2dnav::recalculateBoundResponse :definition-)
      "bool recalculate
---
bool received

")



(provide :turtlebot_2dnav/recalculateBound "ccb08b87036c8a7862161f690fdb0a11")


