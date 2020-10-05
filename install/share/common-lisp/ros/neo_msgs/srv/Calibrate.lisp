; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude Calibrate-request.msg.html

(cl:defclass <Calibrate-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Calibrate-request (<Calibrate-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Calibrate-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Calibrate-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Calibrate-request> is deprecated: use neo_msgs-srv:Calibrate-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Calibrate-request>) ostream)
  "Serializes a message object of type '<Calibrate-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Calibrate-request>) istream)
  "Deserializes a message object of type '<Calibrate-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Calibrate-request>)))
  "Returns string type for a service object of type '<Calibrate-request>"
  "neo_msgs/CalibrateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Calibrate-request)))
  "Returns string type for a service object of type 'Calibrate-request"
  "neo_msgs/CalibrateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Calibrate-request>)))
  "Returns md5sum for a message object of type '<Calibrate-request>"
  "b2a9c605bb7a420089b02c6063322298")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Calibrate-request)))
  "Returns md5sum for a message object of type 'Calibrate-request"
  "b2a9c605bb7a420089b02c6063322298")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Calibrate-request>)))
  "Returns full string definition for message of type '<Calibrate-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Calibrate-request)))
  "Returns full string definition for message of type 'Calibrate-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Calibrate-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Calibrate-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Calibrate-request
))
;//! \htmlinclude Calibrate-response.msg.html

(cl:defclass <Calibrate-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0))
)

(cl:defclass Calibrate-response (<Calibrate-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Calibrate-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Calibrate-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Calibrate-response> is deprecated: use neo_msgs-srv:Calibrate-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <Calibrate-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Calibrate-response>) ostream)
  "Serializes a message object of type '<Calibrate-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Calibrate-response>) istream)
  "Deserializes a message object of type '<Calibrate-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Calibrate-response>)))
  "Returns string type for a service object of type '<Calibrate-response>"
  "neo_msgs/CalibrateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Calibrate-response)))
  "Returns string type for a service object of type 'Calibrate-response"
  "neo_msgs/CalibrateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Calibrate-response>)))
  "Returns md5sum for a message object of type '<Calibrate-response>"
  "b2a9c605bb7a420089b02c6063322298")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Calibrate-response)))
  "Returns md5sum for a message object of type 'Calibrate-response"
  "b2a9c605bb7a420089b02c6063322298")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Calibrate-response>)))
  "Returns full string definition for message of type '<Calibrate-response>"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Calibrate-response)))
  "Returns full string definition for message of type 'Calibrate-response"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Calibrate-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Calibrate-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Calibrate-response
    (cl:cons ':event (event msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Calibrate)))
  'Calibrate-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Calibrate)))
  'Calibrate-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Calibrate)))
  "Returns string type for a service object of type '<Calibrate>"
  "neo_msgs/Calibrate")