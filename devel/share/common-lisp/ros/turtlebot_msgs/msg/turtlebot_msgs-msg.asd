
(cl:in-package :asdf)

(defsystem "turtlebot_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "PanoramaImg" :depends-on ("_package_PanoramaImg"))
    (:file "_package_PanoramaImg" :depends-on ("_package"))
  ))