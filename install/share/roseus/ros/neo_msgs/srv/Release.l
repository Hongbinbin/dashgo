;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::Release)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'Release (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::RELEASE")
  (make-package "NEO_MSGS::RELEASE"))
(unless (find-package "NEO_MSGS::RELEASEREQUEST")
  (make-package "NEO_MSGS::RELEASEREQUEST"))
(unless (find-package "NEO_MSGS::RELEASERESPONSE")
  (make-package "NEO_MSGS::RELEASERESPONSE"))

(in-package "ROS")





(defclass neo_msgs::ReleaseRequest
  :super ros::object
  :slots (_motor_ids ))

(defmethod neo_msgs::ReleaseRequest
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

(defclass neo_msgs::ReleaseResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::ReleaseResponse
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

(defclass neo_msgs::Release
  :super ros::object
  :slots ())

(setf (get neo_msgs::Release :md5sum-) "1e3ab015e243c7706c372ab529619c93")
(setf (get neo_msgs::Release :datatype-) "neo_msgs/Release")
(setf (get neo_msgs::Release :request) neo_msgs::ReleaseRequest)
(setf (get neo_msgs::Release :response) neo_msgs::ReleaseResponse)

(defmethod neo_msgs::ReleaseRequest
  (:response () (instance neo_msgs::ReleaseResponse :init)))

(setf (get neo_msgs::ReleaseRequest :md5sum-) "1e3ab015e243c7706c372ab529619c93")
(setf (get neo_msgs::ReleaseRequest :datatype-) "neo_msgs/ReleaseRequest")
(setf (get neo_msgs::ReleaseRequest :definition-)
      "int32[] motor_ids
---
int32 event
")

(setf (get neo_msgs::ReleaseResponse :md5sum-) "1e3ab015e243c7706c372ab529619c93")
(setf (get neo_msgs::ReleaseResponse :datatype-) "neo_msgs/ReleaseResponse")
(setf (get neo_msgs::ReleaseResponse :definition-)
      "int32[] motor_ids
---
int32 event
")



(provide :neo_msgs/Release "1e3ab015e243c7706c372ab529619c93")


