;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::Recover)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'Recover (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::RECOVER")
  (make-package "NEO_MSGS::RECOVER"))
(unless (find-package "NEO_MSGS::RECOVERREQUEST")
  (make-package "NEO_MSGS::RECOVERREQUEST"))
(unless (find-package "NEO_MSGS::RECOVERRESPONSE")
  (make-package "NEO_MSGS::RECOVERRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::RecoverRequest
  :super ros::object
  :slots ())

(defmethod neo_msgs::RecoverRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass neo_msgs::RecoverResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::RecoverResponse
  (:init
   (&key
    ((:event __event) 0)
    )
   (send-super :init)
   (setq _event (round __event))
   self)
  (:event
   (&optional __event)
   (if __event (setq _event __event)) _event)
  (:serialization-length
   ()
   (+
    ;; int32 _event
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _event
       (write-long _event s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _event
     (setq _event (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass neo_msgs::Recover
  :super ros::object
  :slots ())

(setf (get neo_msgs::Recover :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::Recover :datatype-) "neo_msgs/Recover")
(setf (get neo_msgs::Recover :request) neo_msgs::RecoverRequest)
(setf (get neo_msgs::Recover :response) neo_msgs::RecoverResponse)

(defmethod neo_msgs::RecoverRequest
  (:response () (instance neo_msgs::RecoverResponse :init)))

(setf (get neo_msgs::RecoverRequest :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::RecoverRequest :datatype-) "neo_msgs/RecoverRequest")
(setf (get neo_msgs::RecoverRequest :definition-)
      "---
int32 event
")

(setf (get neo_msgs::RecoverResponse :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::RecoverResponse :datatype-) "neo_msgs/RecoverResponse")
(setf (get neo_msgs::RecoverResponse :definition-)
      "---
int32 event
")



(provide :neo_msgs/Recover "b2a9c605bb7a420089b02c6063322298")


