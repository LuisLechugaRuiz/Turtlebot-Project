;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_2dnav::askNewFrontier)
  (if (not (find-package "TURTLEBOT_2DNAV"))
    (make-package "TURTLEBOT_2DNAV"))
  (shadow 'askNewFrontier (find-package "TURTLEBOT_2DNAV")))
(unless (find-package "TURTLEBOT_2DNAV::ASKNEWFRONTIER")
  (make-package "TURTLEBOT_2DNAV::ASKNEWFRONTIER"))
(unless (find-package "TURTLEBOT_2DNAV::ASKNEWFRONTIERREQUEST")
  (make-package "TURTLEBOT_2DNAV::ASKNEWFRONTIERREQUEST"))
(unless (find-package "TURTLEBOT_2DNAV::ASKNEWFRONTIERRESPONSE")
  (make-package "TURTLEBOT_2DNAV::ASKNEWFRONTIERRESPONSE"))

(in-package "ROS")





(defclass turtlebot_2dnav::askNewFrontierRequest
  :super ros::object
  :slots (_addBlacklist _clearBlacklist ))

(defmethod turtlebot_2dnav::askNewFrontierRequest
  (:init
   (&key
    ((:addBlacklist __addBlacklist) nil)
    ((:clearBlacklist __clearBlacklist) nil)
    )
   (send-super :init)
   (setq _addBlacklist __addBlacklist)
   (setq _clearBlacklist __clearBlacklist)
   self)
  (:addBlacklist
   (&optional __addBlacklist)
   (if __addBlacklist (setq _addBlacklist __addBlacklist)) _addBlacklist)
  (:clearBlacklist
   (&optional __clearBlacklist)
   (if __clearBlacklist (setq _clearBlacklist __clearBlacklist)) _clearBlacklist)
  (:serialization-length
   ()
   (+
    ;; bool _addBlacklist
    1
    ;; bool _clearBlacklist
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _addBlacklist
       (if _addBlacklist (write-byte -1 s) (write-byte 0 s))
     ;; bool _clearBlacklist
       (if _clearBlacklist (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _addBlacklist
     (setq _addBlacklist (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _clearBlacklist
     (setq _clearBlacklist (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass turtlebot_2dnav::askNewFrontierResponse
  :super ros::object
  :slots (_done ))

(defmethod turtlebot_2dnav::askNewFrontierResponse
  (:init
   (&key
    ((:done __done) nil)
    )
   (send-super :init)
   (setq _done __done)
   self)
  (:done
   (&optional __done)
   (if __done (setq _done __done)) _done)
  (:serialization-length
   ()
   (+
    ;; bool _done
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _done
       (if _done (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _done
     (setq _done (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass turtlebot_2dnav::askNewFrontier
  :super ros::object
  :slots ())

(setf (get turtlebot_2dnav::askNewFrontier :md5sum-) "1218c344901f1bfc2f1bcf338db224b8")
(setf (get turtlebot_2dnav::askNewFrontier :datatype-) "turtlebot_2dnav/askNewFrontier")
(setf (get turtlebot_2dnav::askNewFrontier :request) turtlebot_2dnav::askNewFrontierRequest)
(setf (get turtlebot_2dnav::askNewFrontier :response) turtlebot_2dnav::askNewFrontierResponse)

(defmethod turtlebot_2dnav::askNewFrontierRequest
  (:response () (instance turtlebot_2dnav::askNewFrontierResponse :init)))

(setf (get turtlebot_2dnav::askNewFrontierRequest :md5sum-) "1218c344901f1bfc2f1bcf338db224b8")
(setf (get turtlebot_2dnav::askNewFrontierRequest :datatype-) "turtlebot_2dnav/askNewFrontierRequest")
(setf (get turtlebot_2dnav::askNewFrontierRequest :definition-)
      "bool addBlacklist
bool clearBlacklist
---
bool done

")

(setf (get turtlebot_2dnav::askNewFrontierResponse :md5sum-) "1218c344901f1bfc2f1bcf338db224b8")
(setf (get turtlebot_2dnav::askNewFrontierResponse :datatype-) "turtlebot_2dnav/askNewFrontierResponse")
(setf (get turtlebot_2dnav::askNewFrontierResponse :definition-)
      "bool addBlacklist
bool clearBlacklist
---
bool done

")



(provide :turtlebot_2dnav/askNewFrontier "1218c344901f1bfc2f1bcf338db224b8")


