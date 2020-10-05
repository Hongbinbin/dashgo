;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::EndPose)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'EndPose (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::ENDPOSE")
  (make-package "NEO_MSGS::ENDPOSE"))

(in-package "ROS")
;;//! \htmlinclude EndPose.msg.html


(defclass neo_msgs::EndPose
  :super ros::object
  :slots (_x _y _z _Rx _Ry _Rz ))

(defmethod neo_msgs::EndPose
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:Rx __Rx) 0.0)
    ((:Ry __Ry) 0.0)
    ((:Rz __Rz) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _Rx (float __Rx))
   (setq _Ry (float __Ry))
   (setq _Rz (float __Rz))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:Rx
   (&optional __Rx)
   (if __Rx (setq _Rx __Rx)) _Rx)
  (:Ry
   (&optional __Ry)
   (if __Ry (setq _Ry __Ry)) _Ry)
  (:Rz
   (&optional __Rz)
   (if __Rz (setq _Rz __Rz)) _Rz)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ;; float64 _Rx
    8
    ;; float64 _Ry
    8
    ;; float64 _Rz
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Rx
       (sys::poke _Rx (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Ry
       (sys::poke _Ry (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Rz
       (sys::poke _Rz (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Rx
     (setq _Rx (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Ry
     (setq _Ry (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Rz
     (setq _Rz (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get neo_msgs::EndPose :md5sum-) "9f62dbed28d2c842e4baf60dcb12c05c")
(setf (get neo_msgs::EndPose :datatype-) "neo_msgs/EndPose")
(setf (get neo_msgs::EndPose :definition-)
      "float64 x
float64 y
float64 z
float64 Rx
float64 Ry
float64 Rz
")



(provide :neo_msgs/EndPose "9f62dbed28d2c842e4baf60dcb12c05c")


