;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::fakeLaser)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'fakeLaser (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::FAKELASER")
  (make-package "TURTLEBOT_2DNAV::FAKELASER"))
(unless (find-package "TURTLEBOT_2DNAV::FAKELASERREQUEST")
  (make-package "TURTLEBOT_2DNAV::FAKELASERREQUEST"))
(unless (find-package "TURTLEBOT_2DNAV::FAKELASERRESPONSE")
  (make-package "TURTLEBOT_2DNAV::FAKELASERRESPONSE"))

(in-package "ROS")





(defclass turtlebot_2dnav::fakeLaserRequest
  :super ros::object
  :slots (_active ))

(defmethod turtlebot_2dnav::fakeLaserRequest
  (:init
   (&key
    ((:active __active) nil)
    )
   (send-super :init)
   (setq _active __active)
   self)
  (:active
   (&optional __active)
   (if __active (setq _active __active)) _active)
  (:serialization-length
   ()
   (+
    ;; bool _active
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _active
       (if _active (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _active
     (setq _active (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass turtlebot_2dnav::fakeLaserResponse
  :super ros::object
  :slots (_received ))

(defmethod turtlebot_2dnav::fakeLaserResponse
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

(defclass turtlebot_2dnav::fakeLaser
  :super ros::object
  :slots ())

(setf (get turtlebot_2dnav::fakeLaser :md5sum-) "313460372e25eee11ab9126733a5d19c")
(setf (get turtlebot_2dnav::fakeLaser :datatype-) "turtlebot_2dnav/fakeLaser")
(setf (get turtlebot_2dnav::fakeLaser :request) turtlebot_2dnav::fakeLaserRequest)
(setf (get turtlebot_2dnav::fakeLaser :response) turtlebot_2dnav::fakeLaserResponse)

(defmethod turtlebot_2dnav::fakeLaserRequest
  (:response () (instance turtlebot_2dnav::fakeLaserResponse :init)))

(setf (get turtlebot_2dnav::fakeLaserRequest :md5sum-) "313460372e25eee11ab9126733a5d19c")
(setf (get turtlebot_2dnav::fakeLaserRequest :datatype-) "turtlebot_2dnav/fakeLaserRequest")
(setf (get turtlebot_2dnav::fakeLaserRequest :definition-)
      "bool active
---
bool received

")

(setf (get turtlebot_2dnav::fakeLaserResponse :md5sum-) "313460372e25eee11ab9126733a5d19c")
(setf (get turtlebot_2dnav::fakeLaserResponse :datatype-) "turtlebot_2dnav/fakeLaserResponse")
(setf (get turtlebot_2dnav::fakeLaserResponse :definition-)
      "bool active
---
bool received

")



(provide :turtlebot_2dnav/fakeLaser "313460372e25eee11ab9126733a5d19c")


