; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude GetMotorIds-request.msg.html

(cl:defclass <GetMotorIds-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass GetMotorIds-request (<GetMotorIds-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetMotorIds-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetMotorIds-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<GetMotorIds-request> is deprecated: use neo_msgs-srv:GetMotorIds-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetMotorIds-request>) ostream)
  "Serializes a message object of type '<GetMotorIds-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetMotorIds-request>) istream)
  "Deserializes a message object of type '<GetMotorIds-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetMotorIds-request>)))
  "Returns string type for a service object of type '<GetMotorIds-request>"
  "neo_msgs/GetMotorIdsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetMotorIds-request)))
  "Returns string type for a service object of type 'GetMotorIds-request"
  "neo_msgs/GetMotorIdsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetMotorIds-request>)))
  "Returns md5sum for a message object of type '<GetMotorIds-request>"
  "da45074f03ccd6c00fa83c029210839d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetMotorIds-request)))
  "Returns md5sum for a message object of type 'GetMotorIds-request"
  "da45074f03ccd6c00fa83c029210839d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetMotorIds-request>)))
  "Returns full string definition for message of type '<GetMotorIds-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetMotorIds-request)))
  "Returns full string definition for message of type 'GetMotorIds-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetMotorIds-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetMotorIds-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetMotorIds-request
))
;//! \htmlinclude GetMotorIds-response.msg.html

(cl:defclass <GetMotorIds-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0)
   (motor_ids
    :reader motor_ids
    :initarg :motor_ids
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass GetMotorIds-response (<GetMotorIds-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetMotorIds-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetMotorIds-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<GetMotorIds-response> is deprecated: use neo_msgs-srv:GetMotorIds-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <GetMotorIds-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))

(cl:ensure-generic-function 'motor_ids-val :lambda-list '(m))
(cl:defmethod motor_ids-val ((m <GetMotorIds-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:motor_ids-val is deprecated.  Use neo_msgs-srv:motor_ids instead.")
  (motor_ids m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetMotorIds-response>) ostream)
  "Serializes a message object of type '<GetMotorIds-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'motor_ids))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'motor_ids))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetMotorIds-response>) istream)
  "Deserializes a message object of type '<GetMotorIds-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'motor_ids) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'motor_ids)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetMotorIds-response>)))
  "Returns string type for a service object of type '<GetMotorIds-response>"
  "neo_msgs/GetMotorIdsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetMotorIds-response)))
  "Returns string type for a service object of type 'GetMotorIds-response"
  "neo_msgs/GetMotorIdsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetMotorIds-response>)))
  "Returns md5sum for a message object of type '<GetMotorIds-response>"
  "da45074f03ccd6c00fa83c029210839d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetMotorIds-response)))
  "Returns md5sum for a message object of type 'GetMotorIds-response"
  "da45074f03ccd6c00fa83c029210839d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetMotorIds-response>)))
  "Returns full string definition for message of type '<GetMotorIds-response>"
  (cl:format cl:nil "int32 event~%int32[] motor_ids~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetMotorIds-response)))
  "Returns full string definition for message of type 'GetMotorIds-response"
  (cl:format cl:nil "int32 event~%int32[] motor_ids~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetMotorIds-response>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'motor_ids) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetMotorIds-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetMotorIds-response
    (cl:cons ':event (event msg))
    (cl:cons ':motor_ids (motor_ids msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetMotorIds)))
  'GetMotorIds-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetMotorIds)))
  'GetMotorIds-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetMotorIds)))
  "Returns string type for a service object of type '<GetMotorIds>"
  "neo_msgs/GetMotorIds")