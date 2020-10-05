;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::SetOutput)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'SetOutput (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::SETOUTPUT")
  (make-package "NEO_MSGS::SETOUTPUT"))
(unless (find-package "NEO_MSGS::SETOUTPUTREQUEST")
  (make-package "NEO_MSGS::SETOUTPUTREQUEST"))
(unless (find-package "NEO_MSGS::SETOUTPUTRESPONSE")
  (make-package "NEO_MSGS::SETOUTPUTRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::SetOutputRequest
  :super ros::object
  :slots (_motor_ids _signal ))

(defmethod neo_msgs::SetOutputRequest
  (:init
   (&key
    ((:motor_ids __motor_ids) (make-array 0 :initial-element 0 :element-type :integer))
    ((:signal __signal) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _motor_ids __motor_ids)
   (setq _signal __signal)
   self)
  (:motor_ids
   (&optional __motor_ids)
   (if __motor_ids (setq _motor_ids __motor_ids)) _motor_ids)
  (:signal
   (&optional __signal)
   (if __signal (setq _signal __signal)) _signal)
  (:serialization-length
   ()
   (+
    ;; int32[] _motor_ids
    (* 4    (length _motor_ids)) 4
    ;; int32[] _signal
    (* 4    (length _signal)) 4
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
     ;; int32[] _signal
     (write-long (length _signal) s)
     (dotimes (i (length _signal))
       (write-long (elt _signal i) s)
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
   ;; int32[] _signal
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _signal (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _signal i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(defclass neo_msgs::SetOutputResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::SetOutputResponse
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

(defclass neo_msgs::SetOutput
  :super ros::object
  :slots ())

(setf (get neo_msgs::SetOutput :md5sum-) "1373bfb415f821cd86d00baf749212d2")
(setf (get neo_msgs::SetOutput :datatype-) "neo_msgs/SetOutput")
(setf (get neo_msgs::SetOutput :request) neo_msgs::SetOutputRequest)
(setf (get neo_msgs::SetOutput :response) neo_msgs::SetOutputResponse)

(defmethod neo_msgs::SetOutputRequest
  (:response () (instance neo_msgs::SetOutputResponse :init)))

(setf (get neo_msgs::SetOutputRequest :md5sum-) "1373bfb415f821cd86d00baf749212d2")
(setf (get neo_msgs::SetOutputRequest :datatype-) "neo_msgs/SetOutputRequest")
(setf (get neo_msgs::SetOutputRequest :definition-)
      "int32[] motor_ids
int32[] signal
---
int32 event
")

(setf (get neo_msgs::SetOutputResponse :md5sum-) "1373bfb415f821cd86d00baf749212d2")
(setf (get neo_msgs::SetOutputResponse :datatype-) "neo_msgs/SetOutputResponse")
(setf (get neo_msgs::SetOutputResponse :definition-)
      "int32[] motor_ids
int32[] signal
---
int32 event
")



(provide :neo_msgs/SetOutput "1373bfb415f821cd86d00baf749212d2")


