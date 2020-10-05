; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude Recover-request.msg.html

(cl:defclass <Recover-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Recover-request (<Recover-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Recover-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Recover-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Recover-request> is deprecated: use neo_msgs-srv:Recover-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Recover-request>) ostream)
  "Serializes a message object of type '<Recover-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Recover-request>) istream)
  "Deserializes a message object of type '<Recover-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Recover-request>)))
  "Returns string type for a service object of type '<Recover-request>"
  "neo_msgs/RecoverRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Recover-request)))
  "Returns string type for a service object of type 'Recover-request"
  "neo_msgs/RecoverRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Recover-request>)))
  "Returns md5sum for a message object of type '<Recover-request>"
  "b2a9c605bb7a420089b02c6063322298")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Recover-request)))
  "Returns md5sum for a message object of type 'Recover-request"
  "b2a9c605bb7a420089b02c6063322298")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Recover-request>)))
  "Returns full string definition for message of type '<Recover-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Recover-request)))
  "Returns full string definition for message of type 'Recover-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Recover-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Recover-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Recover-request
))
;//! \htmlinclude Recover-response.msg.html

(cl:defclass <Recover-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0))
)

(cl:defclass Recover-response (<Recover-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Recover-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Recover-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Recover-response> is deprecated: use neo_msgs-srv:Recover-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <Recover-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Recover-response>) ostream)
  "Serializes a message object of type '<Recover-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Recover-response>) istream)
  "Deserializes a message object of type '<Recover-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Recover-response>)))
  "Returns string type for a service object of type '<Recover-response>"
  "neo_msgs/RecoverResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Recover-response)))
  "Returns string type for a service object of type 'Recover-response"
  "neo_msgs/RecoverResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Recover-response>)))
  "Returns md5sum for a message object of type '<Recover-response>"
  "b2a9c605bb7a420089b02c6063322298")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Recover-response)))
  "Returns md5sum for a message object of type 'Recover-response"
  "b2a9c605bb7a420089b02c6063322298")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Recover-response>)))
  "Returns full string definition for message of type '<Recover-response>"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Recover-response)))
  "Returns full string definition for message of type 'Recover-response"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Recover-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Recover-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Recover-response
    (cl:cons ':event (event msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Recover)))
  'Recover-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Recover)))
  'Recover-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Recover)))
  "Returns string type for a service object of type '<Recover>"
  "neo_msgs/Recover")