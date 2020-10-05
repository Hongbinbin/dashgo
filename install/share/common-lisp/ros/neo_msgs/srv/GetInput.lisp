; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude GetInput-request.msg.html

(cl:defclass <GetInput-request> (roslisp-msg-protocol:ros-message)
  ((motor_ids
    :reader motor_ids
    :initarg :motor_ids
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass GetInput-request (<GetInput-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetInput-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetInput-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<GetInput-request> is deprecated: use neo_msgs-srv:GetInput-request instead.")))

(cl:ensure-generic-function 'motor_ids-val :lambda-list '(m))
(cl:defmethod motor_ids-val ((m <GetInput-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:motor_ids-val is deprecated.  Use neo_msgs-srv:motor_ids instead.")
  (motor_ids m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetInput-request>) ostream)
  "Serializes a message object of type '<GetInput-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetInput-request>) istream)
  "Deserializes a message object of type '<GetInput-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetInput-request>)))
  "Returns string type for a service object of type '<GetInput-request>"
  "neo_msgs/GetInputRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetInput-request)))
  "Returns string type for a service object of type 'GetInput-request"
  "neo_msgs/GetInputRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetInput-request>)))
  "Returns md5sum for a message object of type '<GetInput-request>"
  "151f6f423f75ecb8922ac2bfb5b2965f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetInput-request)))
  "Returns md5sum for a message object of type 'GetInput-request"
  "151f6f423f75ecb8922ac2bfb5b2965f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetInput-request>)))
  "Returns full string definition for message of type '<GetInput-request>"
  (cl:format cl:nil "int32[] motor_ids~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetInput-request)))
  "Returns full string definition for message of type 'GetInput-request"
  (cl:format cl:nil "int32[] motor_ids~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetInput-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'motor_ids) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetInput-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetInput-request
    (cl:cons ':motor_ids (motor_ids msg))
))
;//! \htmlinclude GetInput-response.msg.html

(cl:defclass <GetInput-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0)
   (signal
    :reader signal
    :initarg :signal
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass GetInput-response (<GetInput-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetInput-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetInput-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<GetInput-response> is deprecated: use neo_msgs-srv:GetInput-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <GetInput-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))

(cl:ensure-generic-function 'signal-val :lambda-list '(m))
(cl:defmethod signal-val ((m <GetInput-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:signal-val is deprecated.  Use neo_msgs-srv:signal instead.")
  (signal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetInput-response>) ostream)
  "Serializes a message object of type '<GetInput-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'signal))))
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
   (cl:slot-value msg 'signal))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetInput-response>) istream)
  "Deserializes a message object of type '<GetInput-response>"
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
  (cl:setf (cl:slot-value msg 'signal) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'signal)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetInput-response>)))
  "Returns string type for a service object of type '<GetInput-response>"
  "neo_msgs/GetInputResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetInput-response)))
  "Returns string type for a service object of type 'GetInput-response"
  "neo_msgs/GetInputResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetInput-response>)))
  "Returns md5sum for a message object of type '<GetInput-response>"
  "151f6f423f75ecb8922ac2bfb5b2965f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetInput-response)))
  "Returns md5sum for a message object of type 'GetInput-response"
  "151f6f423f75ecb8922ac2bfb5b2965f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetInput-response>)))
  "Returns full string definition for message of type '<GetInput-response>"
  (cl:format cl:nil "int32 event~%int32[] signal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetInput-response)))
  "Returns full string definition for message of type 'GetInput-response"
  (cl:format cl:nil "int32 event~%int32[] signal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetInput-response>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'signal) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetInput-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetInput-response
    (cl:cons ':event (event msg))
    (cl:cons ':signal (signal msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetInput)))
  'GetInput-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetInput)))
  'GetInput-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetInput)))
  "Returns string type for a service object of type '<GetInput>"
  "neo_msgs/GetInput")