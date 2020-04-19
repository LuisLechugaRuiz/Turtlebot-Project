
(cl:in-package :asdf)

(defsystem "costmap_2d-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "clearCostmap" :depends-on ("_package_clearCostmap"))
    (:file "_package_clearCostmap" :depends-on ("_package"))
  ))