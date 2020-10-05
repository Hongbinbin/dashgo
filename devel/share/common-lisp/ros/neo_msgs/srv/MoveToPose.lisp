; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude MoveToPose-request.msg.html

(cl:defclass <MoveToPose-request> (roslisp-msg-protocol:ros-message)
  ((pose
    :reader pose
    :initarg :pose
    :type neo_msgs-msg:EndPose
    :initform (cl:make-instance 'neo_msgs-msg:EndPose))
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0)
   (acceleration
    :reader acceleration
    :initarg :acceleration
    :type cl:float
    :initform 0.0)
   (relative
    :reader relative
    :initarg :relative
    :type cl:boolean
    :initform cl:nil)
   (block
    :reader block
    :initarg :block
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass MoveToPose-request (<MoveToPose-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveToPose-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveToPose-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<MoveToPose-request> is deprecated: use neo_msgs-srv:MoveToPose-request instead.")))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <MoveToPose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:pose-val is deprecated.  Use neo_msgs-srv:pose instead.")
  (pose m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <MoveToPose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:velocity-val is deprecated.  Use neo_msgs-srv:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'acceleration-val :lambda-list '(m))
(cl:defmethod acceleration-val ((m <MoveToPose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:acceleration-val is deprecated.  Use neo_msgs-srv:acceleration instead.")
  (acceleration m))

(cl:ensure-generic-function 'relative-val :lambda-list '(m))
(cl:defmethod relative-val ((m <MoveToPose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:relative-val is deprecated.  Use neo_msgs-srv:relative instead.")
  (relative m))

(cl:ensure-generic-function 'block-val :lambda-list '(m))
(cl:defmethod block-val ((m <MoveToPose-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:block-val is deprecated.  Use neo_msgs-srv:block instead.")
  (block m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveToPose-request>) ostream)
  "Serializes a message object of type '<MoveToPose-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acceleration))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'relative) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'block) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveToPose-request>) istream)
  "Deserializes a message object of type '<MoveToPose-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acceleration) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'relative) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'block) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveToPose-request>)))
  "Returns string type for a service object of type '<MoveToPose-request>"
  "neo_msgs/MoveToPoseRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveToPose-request)))
  "Returns string type for a service object of type 'MoveToPose-request"
  "neo_msgs/MoveToPoseRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveToPose-request>)))
  "Returns md5sum for a message object of type '<MoveToPose-request>"
  "550b9435c70b6cfbf9422fec504e8a70")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveToPose-request)))
  "Returns md5sum for a message object of type 'MoveToPose-request"
  "550b9435c70b6cfbf9422fec504e8a70")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveToPose-request>)))
  "Returns full string definition for message of type '<MoveToPose-request>"
  (cl:format cl:nil "EndPose pose~%float32 velocity~%float32 acceleration~%bool relative~%bool block~%~%================================================================================~%MSG: neo_msgs/EndPose~%float64 x~%float64 y~%float64 z~%float64 Rx~%float64 Ry~%float64 Rz~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveToPose-request)))
  "Returns full string definition for message of type 'MoveToPose-request"
  (cl:format cl:nil "EndPose pose~%float32 velocity~%float32 acceleration~%bool relative~%bool block~%~%================================================================================~%MSG: neo_msgs/EndPose~%float64 x~%float64 y~%float64 z~%float64 Rx~%float64 Ry~%float64 Rz~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveToPose-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
     4
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveToPose-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveToPose-request
    (cl:cons ':pose (pose msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':acceleration (acceleration msg))
    (cl:cons ':relative (relative msg))
    (cl:cons ':block (block msg))
))
;//! \htmlinclude MoveToPose-response.msg.html

(cl:defclass <MoveToPose-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0))
)

(cl:defclass MoveToPose-response (<MoveToPose-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveToPose-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveToPose-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<MoveToPose-response> is deprecated: use neo_msgs-srv:MoveToPose-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <MoveToPose-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveToPose-response>) ostream)
  "Serializes a message object of type '<MoveToPose-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveToPose-response>) istream)
  "Deserializes a message object of type '<MoveToPose-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveToPose-response>)))
  "Returns string type for a service object of type '<MoveToPose-response>"
  "neo_msgs/MoveToPoseResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveToPose-response)))
  "Returns string type for a service object of type 'MoveToPose-response"
  "neo_msgs/MoveToPoseResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveToPose-response>)))
  "Returns md5sum for a message object of type '<MoveToPose-response>"
  "550b9435c70b6cfbf9422fec504e8a70")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveToPose-response)))
  "Returns md5sum for a message object of type 'MoveToPose-response"
  "550b9435c70b6cfbf9422fec504e8a70")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveToPose-response>)))
  "Returns full string definition for message of type '<MoveToPose-response>"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveToPose-response)))
  "Returns full string definition for message of type 'MoveToPose-response"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveToPose-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveToPose-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveToPose-response
    (cl:cons ':event (event msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MoveToPose)))
  'MoveToPose-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MoveToPose)))
  'MoveToPose-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveToPose)))
  "Returns string type for a service object of type '<MoveToPose>"
  "neo_msgs/MoveToPose")