;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::MoveP)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'MoveP (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::MOVEP")
  (make-package "NEO_MSGS::MOVEP"))
(unless (find-package "NEO_MSGS::MOVEPREQUEST")
  (make-package "NEO_MSGS::MOVEPREQUEST"))
(unless (find-package "NEO_MSGS::MOVEPRESPONSE")
  (make-package "NEO_MSGS::MOVEPRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::MovePRequest
  :super ros::object
  :slots (_points _velocity _acceleration _interval _close ))

(defmethod neo_msgs::MovePRequest
  (:init
   (&key
    ((:points __points) (let (r) (dotimes (i 0) (push (instance neo_msgs::EndPose :init) r)) r))
    ((:velocity __velocity) 0.0)
    ((:acceleration __acceleration) 0.0)
    ((:interval __interval) 0.0)
    ((:close __close) nil)
    )
   (send-super :init)
   (setq _points __points)
   (setq _velocity (float __velocity))
   (setq _acceleration (float __acceleration))
   (setq _interval (float __interval))
   (setq _close __close)
   self)
  (:points
   (&rest __points)
   (if (keywordp (car __points))
       (send* _points __points)
     (progn
       (if __points (setq _points (car __points)))
       _points)))
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:acceleration
   (&optional __acceleration)
   (if __acceleration (setq _acceleration __acceleration)) _acceleration)
  (:interval
   (&optional __interval)
   (if __interval (setq _interval __interval)) _interval)
  (:close
   (&optional __close)
   (if __close (setq _close __close)) _close)
  (:serialization-length
   ()
   (+
    ;; neo_msgs/EndPose[] _points
    (apply #'+ (send-all _points :serialization-length)) 4
    ;; float32 _velocity
    4
    ;; float32 _acceleration
    4
    ;; float32 _interval
    4
    ;; bool _close
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; neo_msgs/EndPose[] _points
     (write-long (length _points) s)
     (dolist (elem _points)
       (send elem :serialize s)
       )
     ;; float32 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _acceleration
       (sys::poke _acceleration (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _interval
       (sys::poke _interval (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _close
       (if _close (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; neo_msgs/EndPose[] _points
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _points (let (r) (dotimes (i n) (push (instance neo_msgs::EndPose :init) r)) r))
     (dolist (elem- _points)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; float32 _velocity
     (setq _velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _acceleration
     (setq _acceleration (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _interval
     (setq _interval (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _close
     (setq _close (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass neo_msgs::MovePResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::MovePResponse
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

(defclass neo_msgs::MoveP
  :super ros::object
  :slots ())

(setf (get neo_msgs::MoveP :md5sum-) "c94ebec1f5e856eae9ca23929e46a5f8")
(setf (get neo_msgs::MoveP :datatype-) "neo_msgs/MoveP")
(setf (get neo_msgs::MoveP :request) neo_msgs::MovePRequest)
(setf (get neo_msgs::MoveP :response) neo_msgs::MovePResponse)

(defmethod neo_msgs::MovePRequest
  (:response () (instance neo_msgs::MovePResponse :init)))

(setf (get neo_msgs::MovePRequest :md5sum-) "c94ebec1f5e856eae9ca23929e46a5f8")
(setf (get neo_msgs::MovePRequest :datatype-) "neo_msgs/MovePRequest")
(setf (get neo_msgs::MovePRequest :definition-)
      "EndPose[] points
float32 velocity
float32 acceleration
float32 interval
bool close

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
---
int32 event
")

(setf (get neo_msgs::MovePResponse :md5sum-) "c94ebec1f5e856eae9ca23929e46a5f8")
(setf (get neo_msgs::MovePResponse :datatype-) "neo_msgs/MovePResponse")
(setf (get neo_msgs::MovePResponse :definition-)
      "EndPose[] points
float32 velocity
float32 acceleration
float32 interval
bool close

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
---
int32 event
")



(provide :neo_msgs/MoveP "c94ebec1f5e856eae9ca23929e46a5f8")

