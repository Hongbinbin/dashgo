; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude Inverse-request.msg.html

(cl:defclass <Inverse-request> (roslisp-msg-protocol:ros-message)
  ((pose
    :reader pose
    :initarg :pose
    :type neo_msgs-msg:EndPose
    :initform (cl:make-instance 'neo_msgs-msg:EndPose)))
)

(cl:defclass Inverse-request (<Inverse-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Inverse-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Inverse-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Inverse-request> is deprecated: use neo_msgs-srv:Inverse-request instead.")))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <Inverse-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:pose-val is deprecated.  Use neo_msgs-srv:pose instead.")
  (pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Inverse-request>) ostream)
  "Serializes a message object of type '<Inverse-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Inverse-request>) istream)
  "Deserializes a message object of type '<Inverse-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Inverse-request>)))
  "Returns string type for a service object of type '<Inverse-request>"
  "neo_msgs/InverseRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Inverse-request)))
  "Returns string type for a service object of type 'Inverse-request"
  "neo_msgs/InverseRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Inverse-request>)))
  "Returns md5sum for a message object of type '<Inverse-request>"
  "a7f6d41d0e750d2b5bb2a289caba9efe")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Inverse-request)))
  "Returns md5sum for a message object of type 'Inverse-request"
  "a7f6d41d0e750d2b5bb2a289caba9efe")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Inverse-request>)))
  "Returns full string definition for message of type '<Inverse-request>"
  (cl:format cl:nil "EndPose pose~%~%================================================================================~%MSG: neo_msgs/EndPose~%float64 x~%float64 y~%float64 z~%float64 Rx~%float64 Ry~%float64 Rz~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Inverse-request)))
  "Returns full string definition for message of type 'Inverse-request"
  (cl:format cl:nil "EndPose pose~%~%================================================================================~%MSG: neo_msgs/EndPose~%float64 x~%float64 y~%float64 z~%float64 Rx~%float64 Ry~%float64 Rz~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Inverse-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Inverse-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Inverse-request
    (cl:cons ':pose (pose msg))
))
;//! \htmlinclude Inverse-response.msg.html

(cl:defclass <Inverse-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0)
   (angles
    :reader angles
    :initarg :angles
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass Inverse-response (<Inverse-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Inverse-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Inverse-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Inverse-response> is deprecated: use neo_msgs-srv:Inverse-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <Inverse-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))

(cl:ensure-generic-function 'angles-val :lambda-list '(m))
(cl:defmethod angles-val ((m <Inverse-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:angles-val is deprecated.  Use neo_msgs-srv:angles instead.")
  (angles m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Inverse-response>) ostream)
  "Serializes a message object of type '<Inverse-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'angles))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'angles))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Inverse-response>) istream)
  "Deserializes a message object of type '<Inverse-response>"
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
  (cl:setf (cl:slot-value msg 'angles) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'angles)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Inverse-response>)))
  "Returns string type for a service object of type '<Inverse-response>"
  "neo_msgs/InverseResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Inverse-response)))
  "Returns string type for a service object of type 'Inverse-response"
  "neo_msgs/InverseResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Inverse-response>)))
  "Returns md5sum for a message object of type '<Inverse-response>"
  "a7f6d41d0e750d2b5bb2a289caba9efe")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Inverse-response)))
  "Returns md5sum for a message object of type 'Inverse-response"
  "a7f6d41d0e750d2b5bb2a289caba9efe")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Inverse-response>)))
  "Returns full string definition for message of type '<Inverse-response>"
  (cl:format cl:nil "int32 event~%float64[] angles~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Inverse-response)))
  "Returns full string definition for message of type 'Inverse-response"
  (cl:format cl:nil "int32 event~%float64[] angles~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Inverse-response>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'angles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Inverse-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Inverse-response
    (cl:cons ':event (event msg))
    (cl:cons ':angles (angles msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Inverse)))
  'Inverse-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Inverse)))
  'Inverse-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Inverse)))
  "Returns string type for a service object of type '<Inverse>"
  "neo_msgs/Inverse")