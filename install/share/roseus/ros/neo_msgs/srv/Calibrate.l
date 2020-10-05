;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::Calibrate)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'Calibrate (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::CALIBRATE")
  (make-package "NEO_MSGS::CALIBRATE"))
(unless (find-package "NEO_MSGS::CALIBRATEREQUEST")
  (make-package "NEO_MSGS::CALIBRATEREQUEST"))
(unless (find-package "NEO_MSGS::CALIBRATERESPONSE")
  (make-package "NEO_MSGS::CALIBRATERESPONSE"))

(in-package "ROS")





(defclass neo_msgs::CalibrateRequest
  :super ros::object
  :slots ())

(defmethod neo_msgs::CalibrateRequest
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

(defclass neo_msgs::CalibrateResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::CalibrateResponse
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

(defclass neo_msgs::Calibrate
  :super ros::object
  :slots ())

(setf (get neo_msgs::Calibrate :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::Calibrate :datatype-) "neo_msgs/Calibrate")
(setf (get neo_msgs::Calibrate :request) neo_msgs::CalibrateRequest)
(setf (get neo_msgs::Calibrate :response) neo_msgs::CalibrateResponse)

(defmethod neo_msgs::CalibrateRequest
  (:response () (instance neo_msgs::CalibrateResponse :init)))

(setf (get neo_msgs::CalibrateRequest :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::CalibrateRequest :datatype-) "neo_msgs/CalibrateRequest")
(setf (get neo_msgs::CalibrateRequest :definition-)
      "---
int32 event
")

(setf (get neo_msgs::CalibrateResponse :md5sum-) "b2a9c605bb7a420089b02c6063322298")
(setf (get neo_msgs::CalibrateResponse :datatype-) "neo_msgs/CalibrateResponse")
(setf (get neo_msgs::CalibrateResponse :definition-)
      "---
int32 event
")



(provide :neo_msgs/Calibrate "b2a9c605bb7a420089b02c6063322298")


