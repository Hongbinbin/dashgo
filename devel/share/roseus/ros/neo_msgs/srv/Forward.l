;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::Forward)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'Forward (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::FORWARD")
  (make-package "NEO_MSGS::FORWARD"))
(unless (find-package "NEO_MSGS::FORWARDREQUEST")
  (make-package "NEO_MSGS::FORWARDREQUEST"))
(unless (find-package "NEO_MSGS::FORWARDRESPONSE")
  (make-package "NEO_MSGS::FORWARDRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::ForwardRequest
  :super ros::object
  :slots (_angles ))

(defmethod neo_msgs::ForwardRequest
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

(defclass neo_msgs::ForwardResponse
  :super ros::object
  :slots (_event _pose ))

(defmethod neo_msgs::ForwardResponse
  (:init
   (&key
    ((:event __event) 0)
    ((:pose __pose) (instance neo_msgs::EndPose :init))
    )
   (send-super :init)
   (setq _event (round __event))
   (setq _pose __pose)
   self)
  (:event
   (&optional __event)
   (if __event (setq _event __event)) _event)
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
    ;; int32 _event
    4
    ;; neo_msgs/EndPose _pose
    (send _pose :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _event
       (write-long _event s)
     ;; neo_msgs/EndPose _pose
       (send _pose :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _event
     (setq _event (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; neo_msgs/EndPose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;;
   self)
  )

(defclass neo_msgs::Forward
  :super ros::object
  :slots ())

(setf (get neo_msgs::Forward :md5sum-) "56fbdb4f932ad85907ae86d07f710cb2")
(setf (get neo_msgs::Forward :datatype-) "neo_msgs/Forward")
(setf (get neo_msgs::Forward :request) neo_msgs::ForwardRequest)
(setf (get neo_msgs::Forward :response) neo_msgs::ForwardResponse)

(defmethod neo_msgs::ForwardRequest
  (:response () (instance neo_msgs::ForwardResponse :init)))

(setf (get neo_msgs::ForwardRequest :md5sum-) "56fbdb4f932ad85907ae86d07f710cb2")
(setf (get neo_msgs::ForwardRequest :datatype-) "neo_msgs/ForwardRequest")
(setf (get neo_msgs::ForwardRequest :definition-)
      "float64[] angles
---
int32 event
EndPose pose

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
")

(setf (get neo_msgs::ForwardResponse :md5sum-) "56fbdb4f932ad85907ae86d07f710cb2")
(setf (get neo_msgs::ForwardResponse :datatype-) "neo_msgs/ForwardResponse")
(setf (get neo_msgs::ForwardResponse :definition-)
      "float64[] angles
---
int32 event
EndPose pose

================================================================================
MSG: neo_msgs/EndPose
float64 x
float64 y
float64 z
float64 Rx
float64 Ry
")



(provide :neo_msgs/Forward "56fbdb4f932ad85907ae86d07f710cb2")


