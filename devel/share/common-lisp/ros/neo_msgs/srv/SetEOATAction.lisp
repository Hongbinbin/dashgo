; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude SetEOATAction-request.msg.html

(cl:defclass <SetEOATAction-request> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (action
    :reader action
    :initarg :action
    :type cl:string
    :initform ""))
)

(cl:defclass SetEOATAction-request (<SetEOATAction-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetEOATAction-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetEOATAction-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<SetEOATAction-request> is deprecated: use neo_msgs-srv:SetEOATAction-request instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <SetEOATAction-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:name-val is deprecated.  Use neo_msgs-srv:name instead.")
  (name m))

(cl:ensure-generic-function 'action-val :lambda-list '(m))
(cl:defmethod action-val ((m <SetEOATAction-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:action-val is deprecated.  Use neo_msgs-srv:action instead.")
  (action m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetEOATAction-request>) ostream)
  "Serializes a message object of type '<SetEOATAction-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'action))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'action))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetEOATAction-request>) istream)
  "Deserializes a message object of type '<SetEOATAction-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'action) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'action) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetEOATAction-request>)))
  "Returns string type for a service object of type '<SetEOATAction-request>"
  "neo_msgs/SetEOATActionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetEOATAction-request)))
  "Returns string type for a service object of type 'SetEOATAction-request"
  "neo_msgs/SetEOATActionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetEOATAction-request>)))
  "Returns md5sum for a message object of type '<SetEOATAction-request>"
  "f9a82cb332c3449f5a7f012529c9367e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetEOATAction-request)))
  "Returns md5sum for a message object of type 'SetEOATAction-request"
  "f9a82cb332c3449f5a7f012529c9367e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetEOATAction-request>)))
  "Returns full string definition for message of type '<SetEOATAction-request>"
  (cl:format cl:nil "string name~%string action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetEOATAction-request)))
  "Returns full string definition for message of type 'SetEOATAction-request"
  (cl:format cl:nil "string name~%string action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetEOATAction-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     4 (cl:length (cl:slot-value msg 'action))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetEOATAction-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetEOATAction-request
    (cl:cons ':name (name msg))
    (cl:cons ':action (action msg))
))
;//! \htmlinclude SetEOATAction-response.msg.html

(cl:defclass <SetEOATAction-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0))
)

(cl:defclass SetEOATAction-response (<SetEOATAction-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetEOATAction-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetEOATAction-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<SetEOATAction-response> is deprecated: use neo_msgs-srv:SetEOATAction-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <SetEOATAction-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetEOATAction-response>) ostream)
  "Serializes a message object of type '<SetEOATAction-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetEOATAction-response>) istream)
  "Deserializes a message object of type '<SetEOATAction-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetEOATAction-response>)))
  "Returns string type for a service object of type '<SetEOATAction-response>"
  "neo_msgs/SetEOATActionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetEOATAction-response)))
  "Returns string type for a service object of type 'SetEOATAction-response"
  "neo_msgs/SetEOATActionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetEOATAction-response>)))
  "Returns md5sum for a message object of type '<SetEOATAction-response>"
  "f9a82cb332c3449f5a7f012529c9367e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetEOATAction-response)))
  "Returns md5sum for a message object of type 'SetEOATAction-response"
  "f9a82cb332c3449f5a7f012529c9367e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetEOATAction-response>)))
  "Returns full string definition for message of type '<SetEOATAction-response>"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetEOATAction-response)))
  "Returns full string definition for message of type 'SetEOATAction-response"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetEOATAction-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetEOATAction-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetEOATAction-response
    (cl:cons ':event (event msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetEOATAction)))
  'SetEOATAction-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetEOATAction)))
  'SetEOATAction-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetEOATAction)))
  "Returns string type for a service object of type '<SetEOATAction>"
  "neo_msgs/SetEOATAction")