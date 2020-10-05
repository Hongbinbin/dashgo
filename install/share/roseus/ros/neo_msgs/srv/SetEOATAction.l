;; Auto-generated. Do not edit!


(when (boundp 'neo_msgs::SetEOATAction)
  (if (not (find-package "NEO_MSGS"))
    (make-package "NEO_MSGS"))
  (shadow 'SetEOATAction (find-package "NEO_MSGS")))
(unless (find-package "NEO_MSGS::SETEOATACTION")
  (make-package "NEO_MSGS::SETEOATACTION"))
(unless (find-package "NEO_MSGS::SETEOATACTIONREQUEST")
  (make-package "NEO_MSGS::SETEOATACTIONREQUEST"))
(unless (find-package "NEO_MSGS::SETEOATACTIONRESPONSE")
  (make-package "NEO_MSGS::SETEOATACTIONRESPONSE"))

(in-package "ROS")





(defclass neo_msgs::SetEOATActionRequest
  :super ros::object
  :slots (_name _action ))

(defmethod neo_msgs::SetEOATActionRequest
  (:init
   (&key
    ((:name __name) "")
    ((:action __action) "")
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _action (string __action))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:action
   (&optional __action)
   (if __action (setq _action __action)) _action)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; string _action
    4 (length _action)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; string _action
       (write-long (length _action) s) (princ _action s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _action
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _action (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass neo_msgs::SetEOATActionResponse
  :super ros::object
  :slots (_event ))

(defmethod neo_msgs::SetEOATActionResponse
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

(defclass neo_msgs::SetEOATAction
  :super ros::object
  :slots ())

(setf (get neo_msgs::SetEOATAction :md5sum-) "f9a82cb332c3449f5a7f012529c9367e")
(setf (get neo_msgs::SetEOATAction :datatype-) "neo_msgs/SetEOATAction")
(setf (get neo_msgs::SetEOATAction :request) neo_msgs::SetEOATActionRequest)
(setf (get neo_msgs::SetEOATAction :response) neo_msgs::SetEOATActionResponse)

(defmethod neo_msgs::SetEOATActionRequest
  (:response () (instance neo_msgs::SetEOATActionResponse :init)))

(setf (get neo_msgs::SetEOATActionRequest :md5sum-) "f9a82cb332c3449f5a7f012529c9367e")
(setf (get neo_msgs::SetEOATActionRequest :datatype-) "neo_msgs/SetEOATActionRequest")
(setf (get neo_msgs::SetEOATActionRequest :definition-)
      "string name
string action
---
int32 event
")

(setf (get neo_msgs::SetEOATActionResponse :md5sum-) "f9a82cb332c3449f5a7f012529c9367e")
(setf (get neo_msgs::SetEOATActionResponse :datatype-) "neo_msgs/SetEOATActionResponse")
(setf (get neo_msgs::SetEOATActionResponse :definition-)
      "string name
string action
---
int32 event
")



(provide :neo_msgs/SetEOATAction "f9a82cb332c3449f5a7f012529c9367e")


