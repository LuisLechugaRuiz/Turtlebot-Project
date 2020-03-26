
(cl:in-package :asdf)

(defsystem "ros_img_processor-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "camera_POI_msg" :depends-on ("_package_camera_POI_msg"))
    (:file "_package_camera_POI_msg" :depends-on ("_package"))
  ))