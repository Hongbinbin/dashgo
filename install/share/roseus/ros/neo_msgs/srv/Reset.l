;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::Reset)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'Reset (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::RESET")
  (make-package "NEO_MSGS::RESET"))
(unless (find-package "NEO_MSGS::RESETREQUEST")
  (make-package "NEO_MSGS::RESETREQUEST"))
(unless (find-package "NEO_MSGS::RESETRESPONSE")
  (make-package "NEO_MSGS::RESETRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::ResetRequest
  :super ros::object
  :slots ())

(defmethod neo_msgs::ResetRequest
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

(defclass neo_msgs::ResetResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::ResetResponse
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

(defclass neo_msgs::Reset
  :super ros::object
  :slots ())

(setf (get neo_msgs::Reset :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::Reset :datatype-) "neo_msgs/Reset")
(setf (get neo_msgs::Reset :request) neo_msgs::ResetRequest)
(setf (get neo_msgs::Reset :response) neo_msgs::ResetResponse)

(defmethod neo_msgs::ResetRequest
  (:response () (instance neo_msgs::ResetResponse :init)))

(setf (get neo_msgs::ResetRequest :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::ResetRequest :datatype-) "neo_msgs/ResetRequest")
(setf (get neo_msgs::ResetRequest :definition-)
      "---
int32 event
")

(setf (get neo_msgs::ResetResponse :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::ResetResponse :datatype-) "neo_msgs/ResetResponse")
(setf (get neo_msgs::ResetResponse :definition-)
      "---
int32 event
")



(provide :neo_msgs/Reset "b2a9c605bb7a420089b02c6063322298")


