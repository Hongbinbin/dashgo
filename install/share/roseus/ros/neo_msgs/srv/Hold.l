;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::Hold)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'Hold (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::HOLD")
  (make-package "NEO_MSGS::HOLD"))
(unless (find-package "NEO_MSGS::HOLDREQUEST")
  (make-package "NEO_MSGS::HOLDREQUEST"))
(unless (find-package "NEO_MSGS::HOLDRESPONSE")
  (make-package "NEO_MSGS::HOLDRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::HoldRequest
  :super ros::object
  :slots (_motor_ids ))

(defmethod neo_msgs::HoldRequest
  (:init
   (&key
    ((:motor_ids __motor_ids) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _motor_ids __motor_ids)
   self)
  (:motor_ids
   (&optional __motor_ids)
   (if __motor_ids (setq _motor_ids __motor_ids)) _motor_ids)
  (:serialization-length
   ()
   (+
    ;; int32[] _motor_ids
    (* 4    (length _motor_ids)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32[] _motor_ids
     (write-long (length _motor_ids) s)
     (dotimes (i (length _motor_ids))
       (write-long (elt _motor_ids i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32[] _motor_ids
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _motor_ids (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _motor_ids i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(defclass neo_msgs::HoldResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::HoldResponse
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

(defclass neo_msgs::Hold
  :super ros::object
  :slots ())

(setf (get neo_msgs::Hold :md5sum-) "1e3ab015e243c7706c372ab529619c93")
(setf (get neo_msgs::Hold :datatype-) "neo_msgs/Hold")
(setf (get neo_msgs::Hold :request) neo_msgs::HoldRequest)
(setf (get neo_msgs::Hold :response) neo_msgs::HoldResponse)

(defmethod neo_msgs::HoldRequest
  (:response () (instance neo_msgs::HoldResponse :init)))

(setf (get neo_msgs::HoldRequest :md5sum-) "1e3ab015e243c7706c372ab529619c93")
(setf (get neo_msgs::HoldRequest :datatype-) "neo_msgs/HoldRequest")
(setf (get neo_msgs::HoldRequest :definition-)
      "int32[] motor_ids
---
int32 event
")

(setf (get neo_msgs::HoldResponse :md5sum-) "1e3ab015e243c7706c372ab529619c93")
(setf (get neo_msgs::HoldResponse :datatype-) "neo_msgs/HoldResponse")
(setf (get neo_msgs::HoldResponse :definition-)
      "int32[] motor_ids
---
int32 event
")



(provide :neo_msgs/Hold "1e3ab015e243c7706c372ab529619c93")


