;; Auto-generated. Do not edit!


(when (boundp 'web_monitor2::sendGoalPose)
  (if (not (find-package "WEB_MONITOR2"))
    (make-package "WEB_MONITOR2"))
  (shadow 'sendGoalPose (find-package "WEB_MONITOR2")))
(unless (find-package "WEB_MONITOR2::SENDGOALPOSE")
  (make-package "WEB_MONITOR2::SENDGOALPOSE"))
(unless (find-package "WEB_MONITOR2::SENDGOALPOSEREQUEST")
  (make-package "WEB_MONITOR2::SENDGOALPOSEREQUEST"))
(unless (find-package "WEB_MONITOR2::SENDGOALPOSERESPONSE")
  (make-package "WEB_MONITOR2::SENDGOALPOSERESPONSE"))

(in-package "ROS")

(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))




(defclass web_monitor2::sendGoalPoseRequest
  :super ros::object
  :slots (_pose ))

(defmethod web_monitor2::sendGoalPoseRequest
  (:init
   (&key
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    )
   (send-super :init)
   (setq _pose __pose)
   self)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;;
   self)
  )

(defclass web_monitor2::sendGoalPoseResponse
  :super ros::object
  :slots (_status ))

(defmethod web_monitor2::sendGoalPoseResponse
  (:init
   (&key
    ((:status __status) 0)
    )
   (send-super :init)
   (setq _status (round __status))
   self)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:serialization-length
   ()
   (+
    ;; int64 _status
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _status
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _status (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _status) (= (length (_status . bv)) 2)) ;; bignum
              (write-long (ash (elt (_status . bv) 0) 0) s)
              (write-long (ash (elt (_status . bv) 1) -1) s))
             ((and (class _status) (= (length (_status . bv)) 1)) ;; big1
              (write-long (elt (_status . bv) 0) s)
              (write-long (if (>= _status 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _status s)(write-long (if (>= _status 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _status
#+(or :alpha :irix6 :x86_64)
      (setf _status (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _status (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass web_monitor2::sendGoalPose
  :super ros::object
  :slots ())

(setf (get web_monitor2::sendGoalPose :md5sum-) "cd2c26734e978127e0e9c0f2b353125a")
(setf (get web_monitor2::sendGoalPose :datatype-) "web_monitor2/sendGoalPose")
(setf (get web_monitor2::sendGoalPose :request) web_monitor2::sendGoalPoseRequest)
(setf (get web_monitor2::sendGoalPose :response) web_monitor2::sendGoalPoseResponse)

(defmethod web_monitor2::sendGoalPoseRequest
  (:response () (instance web_monitor2::sendGoalPoseResponse :init)))

(setf (get web_monitor2::sendGoalPoseRequest :md5sum-) "cd2c26734e978127e0e9c0f2b353125a")
(setf (get web_monitor2::sendGoalPoseRequest :datatype-) "web_monitor2/sendGoalPoseRequest")
(setf (get web_monitor2::sendGoalPoseRequest :definition-)
      "geometry_msgs/Pose pose

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---
int64 status

")

(setf (get web_monitor2::sendGoalPoseResponse :md5sum-) "cd2c26734e978127e0e9c0f2b353125a")
(setf (get web_monitor2::sendGoalPoseResponse :datatype-) "web_monitor2/sendGoalPoseResponse")
(setf (get web_monitor2::sendGoalPoseResponse :definition-)
      "geometry_msgs/Pose pose

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---
int64 status

")



(provide :web_monitor2/sendGoalPose "cd2c26734e978127e0e9c0f2b353125a")


