;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::Inverse)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'Inverse (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::INVERSE")
  (make-package "NEO_MSGS::INVERSE"))
(unless (find-package "NEO_MSGS::INVERSEREQUEST")
  (make-package "NEO_MSGS::INVERSEREQUEST"))
(unless (find-package "NEO_MSGS::INVERSERESPONSE")
  (make-package "NEO_MSGS::INVERSERESPONSE"))

(in-package "ROS")





(defclass neo_msgs::InverseRequest
  :super ros::object
  :slots (_pose ))

(defmethod neo_msgs::InverseRequest
  (:init
   (&key
    ((:pose __pose) (instance neo_msgs::EndPose :init))
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
    ;; neo_msgs/EndPose _pose
    (send _pose :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; neo_msgs/EndPose _pose
       (send _pose :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; neo_msgs/EndPose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;;
   self)
  )

(defclass neo_msgs::InverseResponse
  :super ros::object
  :slots (_event _angles ))

(defmethod neo_msgs::InverseResponse
  (:init
   (&key
    ((:event __event) 0)
    ((:angles __angles) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _event (round __event))
   (setq _angles __angles)
   self)
  (:event
   (&optional __event)
   (if __event (setq _event __event)) _event)
  (:angles
   (&optional __angles)
   (if __angles (setq _angles __angles)) _angles)
  (:serialization-length
   ()
   (+
    ;; int32 _event
    4
    ;; float64[] _angles
    (* 8    (length _angles)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _event
       (write-long _event s)
     ;; float64[] _angles
     (write-long (length _angles) s)
     (dotimes (i (length _angles))
       (sys::poke (elt _angles i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _event
     (setq _event (sys::peek buf ptr- :integer)) (incf ptr- 4)
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

(defclass neo_msgs::Inverse
  :super ros::object
  :slots ())

(setf (get neo_msgs::Inverse :md5sum-) "a7f6d41d0e750d2b5bb2a289caba9efe")
(setf (get neo_msgs::Inverse :datatype-) "neo_msgs/Inverse")
(setf (get neo_msgs::Inverse :request) neo_msgs::InverseRequest)
(setf (get neo_msgs::Inverse :response) neo_msgs::InverseResponse)

(defmethod neo_msgs::InverseRequest
  (:response () (instance neo_msgs::InverseResponse :init)))

(setf (get neo_msgs::InverseRequest :md5sum-) "a7f6d41d0e750d2b5bb2a289caba9efe")
(setf (get neo_msgs::InverseRequest :datatype-) "neo_msgs/InverseRequest")
(setf (get neo_msgs::InverseRequest :definition-)
      "EndPose pose

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
---
int32 event
float64[] angles
")

(setf (get neo_msgs::InverseResponse :md5sum-) "a7f6d41d0e750d2b5bb2a289caba9efe")
(setf (get neo_msgs::InverseResponse :datatype-) "neo_msgs/InverseResponse")
(setf (get neo_msgs::InverseResponse :definition-)
      "EndPose pose

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
---
int32 event
float64[] angles
")



(provide :neo_msgs/Inverse "a7f6d41d0e750d2b5bb2a289caba9efe")


