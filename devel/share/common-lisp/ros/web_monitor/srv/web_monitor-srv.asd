
(cl:in-package :asdf)

(defsystem "web_monitor-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "sendGoalPose" :depends-on ("_package_sendGoalPose"))
    (:file "_package_sendGoalPose" :depends-on ("_package"))
  ))