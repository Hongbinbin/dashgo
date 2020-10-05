;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::Stop)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'Stop (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::STOP")
  (make-package "NEO_MSGS::STOP"))
(unless (find-package "NEO_MSGS::STOPREQUEST")
  (make-package "NEO_MSGS::STOPREQUEST"))
(unless (find-package "NEO_MSGS::STOPRESPONSE")
  (make-package "NEO_MSGS::STOPRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::StopRequest
  :super ros::object
  :slots ())

(defmethod neo_msgs::StopRequest
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

(defclass neo_msgs::StopResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::StopResponse
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

(defclass neo_msgs::Stop
  :super ros::object
  :slots ())

(setf (get neo_msgs::Stop :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::Stop :datatype-) "neo_msgs/Stop")
(setf (get neo_msgs::Stop :request) neo_msgs::StopRequest)
(setf (get neo_msgs::Stop :response) neo_msgs::StopResponse)

(defmethod neo_msgs::StopRequest
  (:response () (instance neo_msgs::StopResponse :init)))

(setf (get neo_msgs::StopRequest :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::StopRequest :datatype-) "neo_msgs/StopRequest")
(setf (get neo_msgs::StopRequest :definition-)
      "---
int32 event
")

(setf (get neo_msgs::StopResponse :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::StopResponse :datatype-) "neo_msgs/StopResponse")
(setf (get neo_msgs::StopResponse :definition-)
      "---
int32 event
")



(provide :neo_msgs/Stop "b2a9c605bb7a420089b02c6063322298")


