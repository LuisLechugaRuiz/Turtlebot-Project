;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_msgs::SetFollowState)
  (if (not (find-package "TURTLEBOT_MSGS"))
    (make-package "TURTLEBOT_MSGS"))
  (shadow 'SetFollowState (find-package "TURTLEBOT_MSGS")))
(unless (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATE")
  (make-package "TURTLEBOT_MSGS::SETFOLLOWSTATE"))
(unless (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATEREQUEST")
  (make-package "TURTLEBOT_MSGS::SETFOLLOWSTATEREQUEST"))
(unless (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATERESPONSE")
  (make-package "TURTLEBOT_MSGS::SETFOLLOWSTATERESPONSE"))

(in-package "ROS")





(intern "*STOPPED*" (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATEREQUEST"))
(shadow '*STOPPED* (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATEREQUEST"))
(defconstant turtlebot_msgs::SetFollowStateRequest::*STOPPED* 0)
(intern "*FOLLOW*" (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATEREQUEST"))
(shadow '*FOLLOW* (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATEREQUEST"))
(defconstant turtlebot_msgs::SetFollowStateRequest::*FOLLOW* 1)
(defclass turtlebot_msgs::SetFollowStateRequest
  :super ros::object
  :slots (_state ))

(defmethod turtlebot_msgs::SetFollowStateRequest
  (:init
   (&key
    ((:state __state) 0)
    )
   (send-super :init)
   (setq _state (round __state))
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:serialization-length
   ()
   (+
    ;; uint8 _state
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _state
       (write-byte _state s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _state
     (setq _state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(intern "*OK*" (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATERESPONSE"))
(shadow '*OK* (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATERESPONSE"))
(defconstant turtlebot_msgs::SetFollowStateResponse::*OK* 0)
(intern "*ERROR*" (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATERESPONSE"))
(shadow '*ERROR* (find-package "TURTLEBOT_MSGS::SETFOLLOWSTATERESPONSE"))
(defconstant turtlebot_msgs::SetFollowStateResponse::*ERROR* 1)
(defclass turtlebot_msgs::SetFollowStateResponse
  :super ros::object
  :slots (_result ))

(defmethod turtlebot_msgs::SetFollowStateResponse
  (:init
   (&key
    ((:result __result) 0)
    )
   (send-super :init)
   (setq _result (round __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; uint8 _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _result
       (write-byte _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _result
     (setq _result (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass turtlebot_msgs::SetFollowState
  :super ros::object
  :slots ())

(setf (get turtlebot_msgs::SetFollowState :md5sum-) "6095eaec0ed61c547340fdc2200c8372")
(setf (get turtlebot_msgs::SetFollowState :datatype-) "turtlebot_msgs/SetFollowState")
(setf (get turtlebot_msgs::SetFollowState :request) turtlebot_msgs::SetFollowStateRequest)
(setf (get turtlebot_msgs::SetFollowState :response) turtlebot_msgs::SetFollowStateResponse)

(defmethod turtlebot_msgs::SetFollowStateRequest
  (:response () (instance turtlebot_msgs::SetFollowStateResponse :init)))

(setf (get turtlebot_msgs::SetFollowStateRequest :md5sum-) "6095eaec0ed61c547340fdc2200c8372")
(setf (get turtlebot_msgs::SetFollowStateRequest :datatype-) "turtlebot_msgs/SetFollowStateRequest")
(setf (get turtlebot_msgs::SetFollowStateRequest :definition-)
      "uint8 STOPPED = 0
uint8 FOLLOW  = 1


uint8 state

---

uint8 OK    = 0
uint8 ERROR = 1

uint8 result

")

(setf (get turtlebot_msgs::SetFollowStateResponse :md5sum-) "6095eaec0ed61c547340fdc2200c8372")
(setf (get turtlebot_msgs::SetFollowStateResponse :datatype-) "turtlebot_msgs/SetFollowStateResponse")
(setf (get turtlebot_msgs::SetFollowStateResponse :definition-)
      "uint8 STOPPED = 0
uint8 FOLLOW  = 1


uint8 state

---

uint8 OK    = 0
uint8 ERROR = 1

uint8 result

")



(provide :turtlebot_msgs/SetFollowState "6095eaec0ed61c547340fdc2200c8372")


