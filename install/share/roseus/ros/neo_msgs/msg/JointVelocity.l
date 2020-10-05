;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::JointVelocity)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'JointVelocity (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::JOINTVELOCITY")
  (make-package "NEO_MSGS::JOINTVELOCITY"))

(in-package "ROS")
;;//! \htmlinclude JointVelocity.msg.html


(defclass neo_msgs::JointVelocity
  :super ros::object
  :slots (_velocity ))

(defmethod neo_msgs::JointVelocity
  (:init
   (&key
    ((:velocity __velocity) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _velocity __velocity)
   self)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:serialization-length
   ()
   (+
    ;; float64[] _velocity
    (* 8    (length _velocity)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _velocity
     (write-long (length _velocity) s)
     (dotimes (i (length _velocity))
       (sys::poke (elt _velocity i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _velocity
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _velocity (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _velocity i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get neo_msgs::JointVelocity :md5sum-) "241a0480799a6297b297c9f6e498fe3c")
(setf (get neo_msgs::JointVelocity :datatype-) "neo_msgs/JointVelocity")
(setf (get neo_msgs::JointVelocity :definition-)
      "float64[] velocity
")



(provide :neo_msgs/JointVelocity "241a0480799a6297b297c9f6e498fe3c")


