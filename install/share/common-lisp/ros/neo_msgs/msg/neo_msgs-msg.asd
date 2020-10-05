
(cl:in-package :asdf)

(defsystem "neo_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "EndPose" :depends-on ("_package_EndPose"))
    (:file "_package_EndPose" :depends-on ("_package"))
    (:file "JointAngles" :depends-on ("_package_JointAngles"))
    (:file "_package_JointAngles" :depends-on ("_package"))
    (:file "JointCurrent" :depends-on ("_package_JointCurrent"))
    (:file "_package_JointCurrent" :depends-on ("_package"))
    (:file "JointVelocity" :depends-on ("_package_JointVelocity"))
    (:file "_package_JointVelocity" :depends-on ("_package"))
  ))