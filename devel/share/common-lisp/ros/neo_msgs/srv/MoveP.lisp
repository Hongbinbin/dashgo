; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude MoveP-request.msg.html

(cl:defclass <MoveP-request> (roslisp-msg-protocol:ros-message)
  ((points
    :reader points
    :initarg :points
    :type (cl:vector neo_msgs-msg:EndPose)
   :initform (cl:make-array 0 :element-type 'neo_msgs-msg:EndPose :initial-element (cl:make-instance 'neo_msgs-msg:EndPose)))
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
   (interval
    :reader interval
    :initarg :interval
    :type cl:float
    :initform 0.0)
   (close
    :reader close
    :initarg :close
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass MoveP-request (<MoveP-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveP-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveP-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<MoveP-request> is deprecated: use neo_msgs-srv:MoveP-request instead.")))

(cl:ensure-generic-function 'points-val :lambda-list '(m))
(cl:defmethod points-val ((m <MoveP-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:points-val is deprecated.  Use neo_msgs-srv:points instead.")
  (points m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <MoveP-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:velocity-val is deprecated.  Use neo_msgs-srv:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'acceleration-val :lambda-list '(m))
(cl:defmethod acceleration-val ((m <MoveP-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:acceleration-val is deprecated.  Use neo_msgs-srv:acceleration instead.")
  (acceleration m))

(cl:ensure-generic-function 'interval-val :lambda-list '(m))
(cl:defmethod interval-val ((m <MoveP-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:interval-val is deprecated.  Use neo_msgs-srv:interval instead.")
  (interval m))

(cl:ensure-generic-function 'close-val :lambda-list '(m))
(cl:defmethod close-val ((m <MoveP-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:close-val is deprecated.  Use neo_msgs-srv:close instead.")
  (close m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveP-request>) ostream)
  "Serializes a message object of type '<MoveP-request>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'points))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'points))
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'interval))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'close) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveP-request>) istream)
  "Deserializes a message object of type '<MoveP-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'points) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'points)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'neo_msgs-msg:EndPose))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
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
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'interval) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'close) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveP-request>)))
  "Returns string type for a service object of type '<MoveP-request>"
  "neo_msgs/MovePRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveP-request)))
  "Returns string type for a service object of type 'MoveP-request"
  "neo_msgs/MovePRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveP-request>)))
  "Returns md5sum for a message object of type '<MoveP-request>"
  "c94ebec1f5e856eae9ca23929e46a5f8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveP-request)))
  "Returns md5sum for a message object of type 'MoveP-request"
  "c94ebec1f5e856eae9ca23929e46a5f8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveP-request>)))
  "Returns full string definition for message of type '<MoveP-request>"
  (cl:format cl:nil "EndPose[] points~%float32 velocity~%float32 acceleration~%float32 interval~%bool close~%~%================================================================================~%MSG: neo_msgs/EndPose~%float64 x~%float64 y~%float64 z~%float64 Rx~%float64 Ry~%float64 Rz~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveP-request)))
  "Returns full string definition for message of type 'MoveP-request"
  (cl:format cl:nil "EndPose[] points~%float32 velocity~%float32 acceleration~%float32 interval~%bool close~%~%================================================================================~%MSG: neo_msgs/EndPose~%float64 x~%float64 y~%float64 z~%float64 Rx~%float64 Ry~%float64 Rz~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveP-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'points) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveP-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveP-request
    (cl:cons ':points (points msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':acceleration (acceleration msg))
    (cl:cons ':interval (interval msg))
    (cl:cons ':close (close msg))
))
;//! \htmlinclude MoveP-response.msg.html

(cl:defclass <MoveP-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0))
)

(cl:defclass MoveP-response (<MoveP-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveP-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveP-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<MoveP-response> is deprecated: use neo_msgs-srv:MoveP-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <MoveP-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveP-response>) ostream)
  "Serializes a message object of type '<MoveP-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveP-response>) istream)
  "Deserializes a message object of type '<MoveP-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveP-response>)))
  "Returns string type for a service object of type '<MoveP-response>"
  "neo_msgs/MovePResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveP-response)))
  "Returns string type for a service object of type 'MoveP-response"
  "neo_msgs/MovePResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveP-response>)))
  "Returns md5sum for a message object of type '<MoveP-response>"
  "c94ebec1f5e856eae9ca23929e46a5f8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveP-response)))
  "Returns md5sum for a message object of type 'MoveP-response"
  "c94ebec1f5e856eae9ca23929e46a5f8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveP-response>)))
  "Returns full string definition for message of type '<MoveP-response>"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveP-response)))
  "Returns full string definition for message of type 'MoveP-response"
  (cl:format cl:nil "int32 event~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveP-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveP-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveP-response
    (cl:cons ':event (event msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MoveP)))
  'MoveP-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MoveP)))
  'MoveP-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveP)))
  "Returns string type for a service object of type '<MoveP>"
  "neo_msgs/MoveP")