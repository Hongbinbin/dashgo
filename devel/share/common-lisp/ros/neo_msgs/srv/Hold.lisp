; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude Hold-request.msg.html

(cl:defclass <Hold-request> (roslisp-msg-protocol:ros-message)
  ((motor_ids
    :reader motor_ids
    :initarg :motor_ids
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass Hold-request (<Hold-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Hold-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Hold-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Hold-request> is deprecated: use neo_msgs-srv:Hold-request instead.")))

(cl:ensure-generic-function 'motor_ids-val :lambda-list '(m))
(cl:defmethod motor_ids-val ((m <Hold-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:motor_ids-val is deprecated.  Use neo_msgs-srv:motor_ids instead.")
  (motor_ids m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Hold-request>) ostream)
  "Serializes a message object of type '<Hold-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Hold-request>) istream)
  "Deserializes a message object of type '<Hold-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Hold-request>)))
  "Returns string type for a service object of type '<Hold-request>"
  "neo_msgs/HoldRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Hold-request)))
  "Returns string type for a service object of type 'Hold-request"
  "neo_msgs/HoldRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Hold-request>)))
  "Returns md5sum for a message object of type '<Hold-request>"
  "1e3ab015e243c7706c372ab529619c93")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Hold-request)))
  "Returns md5sum for a message object of type 'Hold-request"
  "1e3ab015e243c7706c372ab529619c93")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Hold-request>)))
  "Returns full string definition for message of type '<Hold-request>"
  (cl:format cl:nil "int32[] motor_ids~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Hold-request)))
  "Returns full string definition for message of type 'Hold-request"
  (cl:format cl:nil "int32[] motor_ids~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Hold-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'motor_ids) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Hold-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Hold-request
    (cl:cons ':motor_ids (motor_ids msg))
))
;//! \htmlinclude Hold-response.msg.html

(cl:defclass <Hold-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0))
)

(cl:defclass Hold-response (<Hold-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Hold-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Hold-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Hold-response> is deprecated: use neo_msgs-srv:Hold-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <Hold-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Hold-response>) ostream)
  "Serializes a message object of type '<Hold-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Hold-response>) istream)
  "Deserializes a message object of type '<Hold-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Hold-response>)))
  "Returns string type for a service object of type '<Hold-response>"
  "neo_msgs/HoldResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Hold-response)))
  "Returns string type for a service object of type 'Hold-response"
  "neo_msgs/HoldResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Hold-response>)))
  "Returns md5sum for a message object of type '<Hold-response>"
  "1e3ab015e243c7706c372ab529619c93")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Hold-response)))
  "Returns md5sum for a message object of type 'Hold-response"
  "1e3ab015e243c7706c372ab529619c93")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Hold-response>)))
  "Returns full string definition for message of type '<Hold-response>"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Hold-response)))
  "Returns full string definition for message of type 'Hold-response"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Hold-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Hold-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Hold-response
    (cl:cons ':event (event msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Hold)))
  'Hold-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Hold)))
  'Hold-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Hold)))
  "Returns string type for a service object of type '<Hold>"
  "neo_msgs/Hold")