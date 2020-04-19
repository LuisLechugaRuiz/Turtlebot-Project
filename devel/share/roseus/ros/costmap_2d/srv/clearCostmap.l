;; Auto-generated. Do not edit!


(when (boundp 'costmap_2d::clearCostmap)
  (if (not (find-package "COSTMAP_2D"))
    (make-package "COSTMAP_2D"))
  (shadow 'clearCostmap (find-package "COSTMAP_2D")))
(unless (find-package "COSTMAP_2D::CLEARCOSTMAP")
  (make-package "COSTMAP_2D::CLEARCOSTMAP"))
(unless (find-package "COSTMAP_2D::CLEARCOSTMAPREQUEST")
  (make-package "COSTMAP_2D::CLEARCOSTMAPREQUEST"))
(unless (find-package "COSTMAP_2D::CLEARCOSTMAPRESPONSE")
  (make-package "COSTMAP_2D::CLEARCOSTMAPRESPONSE"))

(in-package "ROS")





(defclass costmap_2d::clearCostmapRequest
  :super ros::object
  :slots (_clear ))

(defmethod costmap_2d::clearCostmapRequest
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

(defclass costmap_2d::clearCostmapResponse
  :super ros::object
  :slots (_received ))

(defmethod costmap_2d::clearCostmapResponse
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

(defclass costmap_2d::clearCostmap
  :super ros::object
  :slots ())

(setf (get costmap_2d::clearCostmap :md5sum-) "6f1cadb125ab62799a65523a8282332f")
(setf (get costmap_2d::clearCostmap :datatype-) "costmap_2d/clearCostmap")
(setf (get costmap_2d::clearCostmap :request) costmap_2d::clearCostmapRequest)
(setf (get costmap_2d::clearCostmap :response) costmap_2d::clearCostmapResponse)

(defmethod costmap_2d::clearCostmapRequest
  (:response () (instance costmap_2d::clearCostmapResponse :init)))

(setf (get costmap_2d::clearCostmapRequest :md5sum-) "6f1cadb125ab62799a65523a8282332f")
(setf (get costmap_2d::clearCostmapRequest :datatype-) "costmap_2d/clearCostmapRequest")
(setf (get costmap_2d::clearCostmapRequest :definition-)
      "bool clear
---
bool received

")

(setf (get costmap_2d::clearCostmapResponse :md5sum-) "6f1cadb125ab62799a65523a8282332f")
(setf (get costmap_2d::clearCostmapResponse :datatype-) "costmap_2d/clearCostmapResponse")
(setf (get costmap_2d::clearCostmapResponse :definition-)
      "bool clear
---
bool received

")



(provide :costmap_2d/clearCostmap "6f1cadb125ab62799a65523a8282332f")


