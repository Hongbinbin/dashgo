;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::GetInput)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'GetInput (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::GETINPUT")
  (make-package "NEO_MSGS::GETINPUT"))
(unless (find-package "NEO_MSGS::GETINPUTREQUEST")
  (make-package "NEO_MSGS::GETINPUTREQUEST"))
(unless (find-package "NEO_MSGS::GETINPUTRESPONSE")
  (make-package "NEO_MSGS::GETINPUTRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::GetInputRequest
  :super ros::object
  :slots (_motor_ids ))

(defmethod neo_msgs::GetInputRequest
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

(defclass neo_msgs::GetInputResponse
  :super ros::object
  :slots (_event _signal ))

(defmethod neo_msgs::GetInputResponse
  (:init
   (&key
    ((:event __event) 0)
    ((:signal __signal) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _event (round __event))
   (setq _signal __signal)
   self)
  (:event
   (&optional __event)
   (if __event (setq _event __event)) _event)
  (:signal
   (&optional __signal)
   (if __signal (setq _signal __signal)) _signal)
  (:serialization-length
   ()
   (+
    ;; int32 _event
    4
    ;; int32[] _signal
    (* 4    (length _signal)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _event
       (write-long _event s)
     ;; int32[] _signal
     (write-long (length _signal) s)
     (dotimes (i (length _signal))
       (write-long (elt _signal i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _event
     (setq _event (sys::peek buf ptr- :integer)) (incf ptr- 4)
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

(defclass neo_msgs::GetInput
  :super ros::object
  :slots ())

(setf (get neo_msgs::GetInput :md5sum-) "151f6f423f75ecb8922ac2bfb5b2965f")
(setf (get neo_msgs::GetInput :datatype-) "neo_msgs/GetInput")
(setf (get neo_msgs::GetInput :request) neo_msgs::GetInputRequest)
(setf (get neo_msgs::GetInput :response) neo_msgs::GetInputResponse)

(defmethod neo_msgs::GetInputRequest
  (:response () (instance neo_msgs::GetInputResponse :init)))

(setf (get neo_msgs::GetInputRequest :md5sum-) "151f6f423f75ecb8922ac2bfb5b2965f")
(setf (get neo_msgs::GetInputRequest :datatype-) "neo_msgs/GetInputRequest")
(setf (get neo_msgs::GetInputRequest :definition-)
      "int32[] motor_ids
---
int32 event
int32[] signal
")

(setf (get neo_msgs::GetInputResponse :md5sum-) "151f6f423f75ecb8922ac2bfb5b2965f")
(setf (get neo_msgs::GetInputResponse :datatype-) "neo_msgs/GetInputResponse")
(setf (get neo_msgs::GetInputResponse :definition-)
      "int32[] motor_ids
---
int32 event
int32[] signal
")



(provide :neo_msgs/GetInput "151f6f423f75ecb8922ac2bfb5b2965f")


