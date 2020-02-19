;; Auto-generated. Do not edit!


(when (boundp 'openni2_camera::GetSerial)
  (if (not (find-package "OPENNI2_CAMERA"))
    (make-package "OPENNI2_CAMERA"))
  (shadow 'GetSerial (find-package "OPENNI2_CAMERA")))
(unless (find-package "OPENNI2_CAMERA::GETSERIAL")
  (make-package "OPENNI2_CAMERA::GETSERIAL"))
(unless (find-package "OPENNI2_CAMERA::GETSERIALREQUEST")
  (make-package "OPENNI2_CAMERA::GETSERIALREQUEST"))
(unless (find-package "OPENNI2_CAMERA::GETSERIALRESPONSE")
  (make-package "OPENNI2_CAMERA::GETSERIALRESPONSE"))

(in-package "ROS")





(defclass openni2_camera::GetSerialRequest
  :super ros::object
  :slots ())

(defmethod openni2_camera::GetSerialRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass openni2_camera::GetSerialResponse
  :super ros::object
  :slots (_serial ))

(defmethod openni2_camera::GetSerialResponse
  (:init
   (&key
    ((:serial __serial) "")
    )
   (send-super :init)
   (setq _serial (string __serial))
   self)
  (:serial
   (&optional __serial)
   (if __serial (setq _serial __serial)) _serial)
  (:serialization-length
   ()
   (+
    ;; string _serial
    4 (length _serial)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _serial
       (write-long (length _serial) s) (princ _serial s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _serial
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _serial (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass openni2_camera::GetSerial
  :super ros::object
  :slots ())

(setf (get openni2_camera::GetSerial :md5sum-) "fca40cf463282a80db4e2037c8a61741")
(setf (get openni2_camera::GetSerial :datatype-) "openni2_camera/GetSerial")
(setf (get openni2_camera::GetSerial :request) openni2_camera::GetSerialRequest)
(setf (get openni2_camera::GetSerial :response) openni2_camera::GetSerialResponse)

(defmethod openni2_camera::GetSerialRequest
  (:response () (instance openni2_camera::GetSerialResponse :init)))

(setf (get openni2_camera::GetSerialRequest :md5sum-) "fca40cf463282a80db4e2037c8a61741")
(setf (get openni2_camera::GetSerialRequest :datatype-) "openni2_camera/GetSerialRequest")
(setf (get openni2_camera::GetSerialRequest :definition-)
      "---
string serial

")

(setf (get openni2_camera::GetSerialResponse :md5sum-) "fca40cf463282a80db4e2037c8a61741")
(setf (get openni2_camera::GetSerialResponse :datatype-) "openni2_camera/GetSerialResponse")
(setf (get openni2_camera::GetSerialResponse :definition-)
      "---
string serial

")



(provide :openni2_camera/GetSerial "fca40cf463282a80db4e2037c8a61741")


