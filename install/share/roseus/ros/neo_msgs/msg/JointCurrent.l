;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::JointCurrent)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'JointCurrent (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::JOINTCURRENT")
  (make-package "NEO_MSGS::JOINTCURRENT"))

(in-package "ROS")
;;//! \htmlinclude JointCurrent.msg.html


(defclass neo_msgs::JointCurrent
  :super ros::object
  :slots (_current ))

(defmethod neo_msgs::JointCurrent
  (:init
   (&key
    ((:current __current) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _current __current)
   self)
  (:current
   (&optional __current)
   (if __current (setq _current __current)) _current)
  (:serialization-length
   ()
   (+
    ;; float64[] _current
    (* 8    (length _current)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _current
     (write-long (length _current) s)
     (dotimes (i (length _current))
       (sys::poke (elt _current i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _current
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _current (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _current i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get neo_msgs::JointCurrent :md5sum-) "1634c573362b3eca9589d81d03b20094")
(setf (get neo_msgs::JointCurrent :datatype-) "neo_msgs/JointCurrent")
(setf (get neo_msgs::JointCurrent :definition-)
      "float64[] current
")



(provide :neo_msgs/JointCurrent "1634c573362b3eca9589d81d03b20094")


