; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude Release-request.msg.html

(cl:defclass <Release-request> (roslisp-msg-protocol:ros-message)
  ((motor_ids
    :reader motor_ids
    :initarg :motor_ids
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass Release-request (<Release-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Release-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Release-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Release-request> is deprecated: use neo_msgs-srv:Release-request instead.")))

(cl:ensure-generic-function 'motor_ids-val :lambda-list '(m))
(cl:defmethod motor_ids-val ((m <Release-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:motor_ids-val is deprecated.  Use neo_msgs-srv:motor_ids instead.")
  (motor_ids m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Release-request>) ostream)
  "Serializes a message object of type '<Release-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Release-request>) istream)
  "Deserializes a message object of type '<Release-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Release-request>)))
  "Returns string type for a service object of type '<Release-request>"
  "neo_msgs/ReleaseRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Release-request)))
  "Returns string type for a service object of type 'Release-request"
  "neo_msgs/ReleaseRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Release-request>)))
  "Returns md5sum for a message object of type '<Release-request>"
  "1e3ab015e243c7706c372ab529619c93")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Release-request)))
  "Returns md5sum for a message object of type 'Release-request"
  "1e3ab015e243c7706c372ab529619c93")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Release-request>)))
  "Returns full string definition for message of type '<Release-request>"
  (cl:format cl:nil "int32[] motor_ids~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Release-request)))
  "Returns full string definition for message of type 'Release-request"
  (cl:format cl:nil "int32[] motor_ids~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Release-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'motor_ids) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Release-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Release-request
    (cl:cons ':motor_ids (motor_ids msg))
))
;//! \htmlinclude Release-response.msg.html

(cl:defclass <Release-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0))
)

(cl:defclass Release-response (<Release-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Release-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Release-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Release-response> is deprecated: use neo_msgs-srv:Release-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <Release-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Release-response>) ostream)
  "Serializes a message object of type '<Release-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Release-response>) istream)
  "Deserializes a message object of type '<Release-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Release-response>)))
  "Returns string type for a service object of type '<Release-response>"
  "neo_msgs/ReleaseResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Release-response)))
  "Returns string type for a service object of type 'Release-response"
  "neo_msgs/ReleaseResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Release-response>)))
  "Returns md5sum for a message object of type '<Release-response>"
  "1e3ab015e243c7706c372ab529619c93")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Release-response)))
  "Returns md5sum for a message object of type 'Release-response"
  "1e3ab015e243c7706c372ab529619c93")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Release-response>)))
  "Returns full string definition for message of type '<Release-response>"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Release-response)))
  "Returns full string definition for message of type 'Release-response"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Release-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Release-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Release-response
    (cl:cons ':event (event msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Release)))
  'Release-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Release)))
  'Release-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Release)))
  "Returns string type for a service object of type '<Release>"
  "neo_msgs/Release")