
(cl:in-package :asdf)

(defsystem "poi_database-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ROI" :depends-on ("_package_ROI"))
    (:file "_package_ROI" :depends-on ("_package"))
  ))