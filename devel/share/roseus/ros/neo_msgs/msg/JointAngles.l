;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::JointAngles)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'JointAngles (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::JOINTANGLES")
  (make-package "NEO_MSGS::JOINTANGLES"))

(in-package "ROS")
;;//! \htmlinclude JointAngles.msg.html


(defclass neo_msgs::JointAngles
  :super ros::object
  :slots (_angles ))

(defmethod neo_msgs::JointAngles
  (:init
   (&key
    ((:angles __angles) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _angles __angles)
   self)
  (:angles
   (&optional __angles)
   (if __angles (setq _angles __angles)) _angles)
  (:serialization-length
   ()
   (+
    ;; float64[] _angles
    (* 8    (length _angles)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64[] _angles
     (write-long (length _angles) s)
     (dotimes (i (length _angles))
       (sys::poke (elt _angles i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64[] _angles
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _angles (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _angles i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get neo_msgs::JointAngles :md5sum-) "b7ca77b9da2dfe623a276e10b570d2df")
(setf (get neo_msgs::JointAngles :datatype-) "neo_msgs/JointAngles")
(setf (get neo_msgs::JointAngles :definition-)
      "float64[] angles
")



(provide :neo_msgs/JointAngles "b7ca77b9da2dfe623a276e10b570d2df")


