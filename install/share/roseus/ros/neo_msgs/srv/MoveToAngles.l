;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::MoveToAngles)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'MoveToAngles (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::MOVETOANGLES")
  (make-package "NEO_MSGS::MOVETOANGLES"))
(unless (find-package "NEO_MSGS::MOVETOANGLESREQUEST")
  (make-package "NEO_MSGS::MOVETOANGLESREQUEST"))
(unless (find-package "NEO_MSGS::MOVETOANGLESRESPONSE")
  (make-package "NEO_MSGS::MOVETOANGLESRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::MoveToAnglesRequest
  :super ros::object
  :slots (_motor_ids _angles _velocity _acceleration _relative _block ))

(defmethod neo_msgs::MoveToAnglesRequest
  (:init
   (&key
    ((:motor_ids __motor_ids) (make-array 0 :initial-element 0 :element-type :integer))
    ((:angles __angles) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:velocity __velocity) 0.0)
    ((:acceleration __acceleration) 0.0)
    ((:relative __relative) nil)
    ((:block __block) nil)
    )
   (send-super :init)
   (setq _motor_ids __motor_ids)
   (setq _angles __angles)
   (setq _velocity (float __velocity))
   (setq _acceleration (float __acceleration))
   (setq _relative __relative)
   (setq _block __block)
   self)
  (:motor_ids
   (&optional __motor_ids)
   (if __motor_ids (setq _motor_ids __motor_ids)) _motor_ids)
  (:angles
   (&optional __angles)
   (if __angles (setq _angles __angles)) _angles)
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
    ;; int32[] _motor_ids
    (* 4    (length _motor_ids)) 4
    ;; float64[] _angles
    (* 8    (length _angles)) 4
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
     ;; int32[] _motor_ids
     (write-long (length _motor_ids) s)
     (dotimes (i (length _motor_ids))
       (write-long (elt _motor_ids i) s)
       )
     ;; float64[] _angles
     (write-long (length _angles) s)
     (dotimes (i (length _angles))
       (sys::poke (elt _angles i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
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
   ;; int32[] _motor_ids
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _motor_ids (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _motor_ids i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; float64[] _angles
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _angles (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _angles i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
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

(defclass neo_msgs::MoveToAnglesResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::MoveToAnglesResponse
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

(defclass neo_msgs::MoveToAngles
  :super ros::object
  :slots ())

(setf (get neo_msgs::MoveToAngles :md5sum-) "df013f5f4546b148508f366c4f2a3858")
(setf (get neo_msgs::MoveToAngles :datatype-) "neo_msgs/MoveToAngles")
(setf (get neo_msgs::MoveToAngles :request) neo_msgs::MoveToAnglesRequest)
(setf (get neo_msgs::MoveToAngles :response) neo_msgs::MoveToAnglesResponse)

(defmethod neo_msgs::MoveToAnglesRequest
  (:response () (instance neo_msgs::MoveToAnglesResponse :init)))

(setf (get neo_msgs::MoveToAnglesRequest :md5sum-) "df013f5f4546b148508f366c4f2a3858")
(setf (get neo_msgs::MoveToAnglesRequest :datatype-) "neo_msgs/MoveToAnglesRequest")
(setf (get neo_msgs::MoveToAnglesRequest :definition-)
      "int32[] motor_ids
float64[] angles
float32 velocity
float32 acceleration
bool relative
bool block
---
int32 event
")

(setf (get neo_msgs::MoveToAnglesResponse :md5sum-) "df013f5f4546b148508f366c4f2a3858")
(setf (get neo_msgs::MoveToAnglesResponse :datatype-) "neo_msgs/MoveToAnglesResponse")
(setf (get neo_msgs::MoveToAnglesResponse :definition-)
      "int32[] motor_ids
float64[] angles
float32 velocity
float32 acceleration
bool relative
bool block
---
int32 event
")



(provide :neo_msgs/MoveToAngles "df013f5f4546b148508f366c4f2a3858")


