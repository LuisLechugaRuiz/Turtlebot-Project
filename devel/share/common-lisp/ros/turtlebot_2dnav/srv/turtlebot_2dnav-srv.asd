
(cl:in-package :asdf)

(defsystem "turtlebot_2dnav-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :turtlebot_2dnav-msg
)
  :components ((:file "_package")
    (:file "CarryingPerson" :depends-on ("_package_CarryingPerson"))
    (:file "_package_CarryingPerson" :depends-on ("_package"))
    (:file "askNewFrontier" :depends-on ("_package_askNewFrontier"))
    (:file "_package_askNewFrontier" :depends-on ("_package"))
    (:file "fakeLaser" :depends-on ("_package_fakeLaser"))
    (:file "_package_fakeLaser" :depends-on ("_package"))
    (:file "fakeObstacles" :depends-on ("_package_fakeObstacles"))
    (:file "_package_fakeObstacles" :depends-on ("_package"))
    (:file "recalculateBound" :depends-on ("_package_recalculateBound"))
    (:file "_package_recalculateBound" :depends-on ("_package"))
    (:file "restrictCostmap" :depends-on ("_package_restrictCostmap"))
    (:file "_package_restrictCostmap" :depends-on ("_package"))
  ))