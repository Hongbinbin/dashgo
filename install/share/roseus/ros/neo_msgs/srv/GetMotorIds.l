;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::GetMotorIds)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'GetMotorIds (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::GETMOTORIDS")
  (make-package "NEO_MSGS::GETMOTORIDS"))
(unless (find-package "NEO_MSGS::GETMOTORIDSREQUEST")
  (make-package "NEO_MSGS::GETMOTORIDSREQUEST"))
(unless (find-package "NEO_MSGS::GETMOTORIDSRESPONSE")
  (make-package "NEO_MSGS::GETMOTORIDSRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::GetMotorIdsRequest
  :super ros::object
  :slots ())

(defmethod neo_msgs::GetMotorIdsRequest
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

(defclass neo_msgs::GetMotorIdsResponse
  :super ros::object
  :slots (_event _motor_ids ))

(defmethod neo_msgs::GetMotorIdsResponse
  (:init
   (&key
    ((:event __event) 0)
    ((:motor_ids __motor_ids) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _event (round __event))
   (setq _motor_ids __motor_ids)
   self)
  (:event
   (&optional __event)
   (if __event (setq _event __event)) _event)
  (:motor_ids
   (&optional __motor_ids)
   (if __motor_ids (setq _motor_ids __motor_ids)) _motor_ids)
  (:serialization-length
   ()
   (+
    ;; int32 _event
    4
    ;; int32[] _motor_ids
    (* 4    (length _motor_ids)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _event
       (write-long _event s)
     ;; int32[] _motor_ids
     (write-long (length _motor_ids) s)
     (dotimes (i (length _motor_ids))
       (write-long (elt _motor_ids i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _event
     (setq _event (sys::peek buf ptr- :integer)) (incf ptr- 4)
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

(defclass neo_msgs::GetMotorIds
  :super ros::object
  :slots ())

(setf (get neo_msgs::GetMotorIds :md5sum-) "da45074f03ccd6c00fa83c029210839d")
(setf (get neo_msgs::GetMotorIds :datatype-) "neo_msgs/GetMotorIds")
(setf (get neo_msgs::GetMotorIds :request) neo_msgs::GetMotorIdsRequest)
(setf (get neo_msgs::GetMotorIds :response) neo_msgs::GetMotorIdsResponse)

(defmethod neo_msgs::GetMotorIdsRequest
  (:response () (instance neo_msgs::GetMotorIdsResponse :init)))

(setf (get neo_msgs::GetMotorIdsRequest :md5sum-) "da45074f03ccd6c00fa83c029210839d")
(setf (get neo_msgs::GetMotorIdsRequest :datatype-) "neo_msgs/GetMotorIdsRequest")
(setf (get neo_msgs::GetMotorIdsRequest :definition-)
      "---
int32 event
int32[] motor_ids
")

(setf (get neo_msgs::GetMotorIdsResponse :md5sum-) "da45074f03ccd6c00fa83c029210839d")
(setf (get neo_msgs::GetMotorIdsResponse :datatype-) "neo_msgs/GetMotorIdsResponse")
(setf (get neo_msgs::GetMotorIdsResponse :definition-)
      "---
int32 event
int32[] motor_ids
")



(provide :neo_msgs/GetMotorIds "da45074f03ccd6c00fa83c029210839d")


