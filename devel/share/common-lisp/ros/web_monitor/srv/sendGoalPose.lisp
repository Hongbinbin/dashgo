; Auto-generated. Do not edit!


(cl:in-package web_monitor-srv)


;//! \htmlinclude sendGoalPose-request.msg.html

(cl:defclass <sendGoalPose-request> (roslisp-msg-protocol:ros-message)
  ((pose
    :reader pose
    :initarg :pose
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass sendGoalPose-request (<sendGoalPose-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <sendGoalPose-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'sendGoalPose-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name web_monitor-srv:<sendGoalPose-request> is deprecated: use web_monitor-srv:sendGoalPose-request instead.")))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <sendGoalPose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader web_monitor-srv:pose-val is deprecated.  Use web_monitor-srv:pose instead.")
  (pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <sendGoalPose-request>) ostream)
  "Serializes a message object of type '<sendGoalPose-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <sendGoalPose-request>) istream)
  "Deserializes a message object of type '<sendGoalPose-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<sendGoalPose-request>)))
  "Returns string type for a service object of type '<sendGoalPose-request>"
  "web_monitor/sendGoalPoseRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'sendGoalPose-request)))
  "Returns string type for a service object of type 'sendGoalPose-request"
  "web_monitor/sendGoalPoseRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<sendGoalPose-request>)))
  "Returns md5sum for a message object of type '<sendGoalPose-request>"
  "cd2c26734e978127e0e9c0f2b353125a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'sendGoalPose-request)))
  "Returns md5sum for a message object of type 'sendGoalPose-request"
  "cd2c26734e978127e0e9c0f2b353125a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<sendGoalPose-request>)))
  "Returns full string definition for message of type '<sendGoalPose-request>"
  (cl:format cl:nil "geometry_msgs/Pose pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'sendGoalPose-request)))
  "Returns full string definition for message of type 'sendGoalPose-request"
  (cl:format cl:nil "geometry_msgs/Pose pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <sendGoalPose-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <sendGoalPose-request>))
  "Converts a ROS message object to a list"
  (cl:list 'sendGoalPose-request
    (cl:cons ':pose (pose msg))
))
;//! \htmlinclude sendGoalPose-response.msg.html

(cl:defclass <sendGoalPose-response> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type cl:integer
    :initform 0))
)

(cl:defclass sendGoalPose-response (<sendGoalPose-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <sendGoalPose-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'sendGoalPose-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name web_monitor-srv:<sendGoalPose-response> is deprecated: use web_monitor-srv:sendGoalPose-response instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <sendGoalPose-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader web_monitor-srv:status-val is deprecated.  Use web_monitor-srv:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <sendGoalPose-response>) ostream)
  "Serializes a message object of type '<sendGoalPose-response>"
  (cl:let* ((signed (cl:slot-value msg 'status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <sendGoalPose-response>) istream)
  "Deserializes a message object of type '<sendGoalPose-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<sendGoalPose-response>)))
  "Returns string type for a service object of type '<sendGoalPose-response>"
  "web_monitor/sendGoalPoseResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'sendGoalPose-response)))
  "Returns string type for a service object of type 'sendGoalPose-response"
  "web_monitor/sendGoalPoseResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<sendGoalPose-response>)))
  "Returns md5sum for a message object of type '<sendGoalPose-response>"
  "cd2c26734e978127e0e9c0f2b353125a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'sendGoalPose-response)))
  "Returns md5sum for a message object of type 'sendGoalPose-response"
  "cd2c26734e978127e0e9c0f2b353125a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<sendGoalPose-response>)))
  "Returns full string definition for message of type '<sendGoalPose-response>"
  (cl:format cl:nil "int64 status~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'sendGoalPose-response)))
  "Returns full string definition for message of type 'sendGoalPose-response"
  (cl:format cl:nil "int64 status~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <sendGoalPose-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <sendGoalPose-response>))
  "Converts a ROS message object to a list"
  (cl:list 'sendGoalPose-response
    (cl:cons ':status (status msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'sendGoalPose)))
  'sendGoalPose-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'sendGoalPose)))
  'sendGoalPose-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'sendGoalPose)))
  "Returns string type for a service object of type '<sendGoalPose>"
  "web_monitor/sendGoalPose")