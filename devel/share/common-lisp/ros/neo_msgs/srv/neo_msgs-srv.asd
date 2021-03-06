
(cl:in-package :asdf)

(defsystem "neo_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :neo_msgs-msg
)
  :components ((:file "_package")
    (:file "Calibrate" :depends-on ("_package_Calibrate"))
    (:file "_package_Calibrate" :depends-on ("_package"))
    (:file "Forward" :depends-on ("_package_Forward"))
    (:file "_package_Forward" :depends-on ("_package"))
    (:file "GetInput" :depends-on ("_package_GetInput"))
    (:file "_package_GetInput" :depends-on ("_package"))
    (:file "GetMotorIds" :depends-on ("_package_GetMotorIds"))
    (:file "_package_GetMotorIds" :depends-on ("_package"))
    (:file "Hold" :depends-on ("_package_Hold"))
    (:file "_package_Hold" :depends-on ("_package"))
    (:file "Inverse" :depends-on ("_package_Inverse"))
    (:file "_package_Inverse" :depends-on ("_package"))
    (:file "MoveJ" :depends-on ("_package_MoveJ"))
    (:file "_package_MoveJ" :depends-on ("_package"))
    (:file "MoveL" :depends-on ("_package_MoveL"))
    (:file "_package_MoveL" :depends-on ("_package"))
    (:file "MoveP" :depends-on ("_package_MoveP"))
    (:file "_package_MoveP" :depends-on ("_package"))
    (:file "MoveToAngles" :depends-on ("_package_MoveToAngles"))
    (:file "_package_MoveToAngles" :depends-on ("_package"))
    (:file "MoveToPose" :depends-on ("_package_MoveToPose"))
    (:file "_package_MoveToPose" :depends-on ("_package"))
    (:file "Recover" :depends-on ("_package_Recover"))
    (:file "_package_Recover" :depends-on ("_package"))
    (:file "Release" :depends-on ("_package_Release"))
    (:file "_package_Release" :depends-on ("_package"))
    (:file "Reset" :depends-on ("_package_Reset"))
    (:file "_package_Reset" :depends-on ("_package"))
    (:file "SetEOATAction" :depends-on ("_package_SetEOATAction"))
    (:file "_package_SetEOATAction" :depends-on ("_package"))
    (:file "SetOutput" :depends-on ("_package_SetOutput"))
    (:file "_package_SetOutput" :depends-on ("_package"))
    (:file "Stop" :depends-on ("_package_Stop"))
    (:file "_package_Stop" :depends-on ("_package"))
  ))