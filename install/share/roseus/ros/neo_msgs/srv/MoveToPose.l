;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::MoveToPose)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'MoveToPose (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::MOVETOPOSE")
  (make-package "NEO_MSGS::MOVETOPOSE"))
(unless (find-package "NEO_MSGS::MOVETOPOSEREQUEST")
  (make-package "NEO_MSGS::MOVETOPOSEREQUEST"))
(unless (find-package "NEO_MSGS::MOVETOPOSERESPONSE")
  (make-package "NEO_MSGS::MOVETOPOSERESPONSE"))

(in-package "ROS")





(defclass neo_msgs::MoveToPoseRequest
  :super ros::object
  :slots (_pose _velocity _acceleration _relative _block ))

(defmethod neo_msgs::MoveToPoseRequest
  (:init
   (&key
    ((:pose __pose) (instance neo_msgs::EndPose :init))
    ((:velocity __velocity) 0.0)
    ((:acceleration __acceleration) 0.0)
    ((:relative __relative) nil)
    ((:block __block) nil)
    )
   (send-super :init)
   (setq _pose __pose)
   (setq _velocity (float __velocity))
   (setq _acceleration (float __acceleration))
   (setq _relative __relative)
   (setq _block __block)
   self)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:acceleration
   (&optional __acceleration)
   (if __acceleration (setq _acceleration __acceleration)) _acceleration)
  (:relative
   (&optional __relative)
   (if __relative (setq _relative __relative)) _relative)
  (:block
   (&optional __block)
   (if __block (setq _block __block)) _block)
  (:serialization-length
   ()
   (+
    ;; neo_msgs/EndPose _pose
    (send _pose :serialization-length)
    ;; float32 _velocity
    4
    ;; float32 _acceleration
    4
    ;; bool _relative
    1
    ;; bool _block
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; neo_msgs/EndPose _pose
       (send _pose :serialize s)
     ;; float32 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _acceleration
       (sys::poke _acceleration (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _relative
       (if _relative (write-byte -1 s) (write-byte 0 s))
     ;; bool _block
       (if _block (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; neo_msgs/EndPose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;; float32 _velocity
     (setq _velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _acceleration
     (setq _acceleration (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _relative
     (setq _relative (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _block
     (setq _block (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass neo_msgs::MoveToPoseResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::MoveToPoseResponse
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

(defclass neo_msgs::MoveToPose
  :super ros::object
  :slots ())

(setf (get neo_msgs::MoveToPose :md5sum-) "550b9435c70b6cfbf9422fec504e8a70")
(setf (get neo_msgs::MoveToPose :datatype-) "neo_msgs/MoveToPose")
(setf (get neo_msgs::MoveToPose :request) neo_msgs::MoveToPoseRequest)
(setf (get neo_msgs::MoveToPose :response) neo_msgs::MoveToPoseResponse)

(defmethod neo_msgs::MoveToPoseRequest
  (:response () (instance neo_msgs::MoveToPoseResponse :init)))

(setf (get neo_msgs::MoveToPoseRequest :md5sum-) "550b9435c70b6cfbf9422fec504e8a70")
(setf (get neo_msgs::MoveToPoseRequest :datatype-) "neo_msgs/MoveToPoseRequest")
(setf (get neo_msgs::MoveToPoseRequest :definition-)
      "EndPose pose
float32 velocity
float32 acceleration
bool relative
bool block

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

(setf (get neo_msgs::MoveToPoseResponse :md5sum-) "550b9435c70b6cfbf9422fec504e8a70")
(setf (get neo_msgs::MoveToPoseResponse :datatype-) "neo_msgs/MoveToPoseResponse")
(setf (get neo_msgs::MoveToPoseResponse :definition-)
      "EndPose pose
float32 velocity
float32 acceleration
bool relative
bool block

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



(provide :neo_msgs/MoveToPose "550b9435c70b6cfbf9422fec504e8a70")


