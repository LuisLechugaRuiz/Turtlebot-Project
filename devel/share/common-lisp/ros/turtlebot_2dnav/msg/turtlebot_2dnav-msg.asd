
(cl:in-package :asdf)

(defsystem "turtlebot_2dnav-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ROI" :depends-on ("_package_ROI"))
    (:file "_package_ROI" :depends-on ("_package"))
    (:file "bounds_point_size" :depends-on ("_package_bounds_point_size"))
    (:file "_package_bounds_point_size" :depends-on ("_package"))
    (:file "fake_bound" :depends-on ("_package_fake_bound"))
    (:file "_package_fake_bound" :depends-on ("_package"))
    (:file "frontier" :depends-on ("_package_frontier"))
    (:file "_package_frontier" :depends-on ("_package"))
    (:file "match_bound" :depends-on ("_package_match_bound"))
    (:file "_package_match_bound" :depends-on ("_package"))
  ))