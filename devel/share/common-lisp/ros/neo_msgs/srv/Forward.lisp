; Auto-generated. Do not edit!


(cl:in-package neo_msgs-srv)


;//! \htmlinclude Forward-request.msg.html

(cl:defclass <Forward-request> (roslisp-msg-protocol:ros-message)
  ((angles
    :reader angles
    :initarg :angles
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass Forward-request (<Forward-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Forward-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Forward-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Forward-request> is deprecated: use neo_msgs-srv:Forward-request instead.")))

(cl:ensure-generic-function 'angles-val :lambda-list '(m))
(cl:defmethod angles-val ((m <Forward-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:angles-val is deprecated.  Use neo_msgs-srv:angles instead.")
  (angles m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Forward-request>) ostream)
  "Serializes a message object of type '<Forward-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Forward-request>) istream)
  "Deserializes a message object of type '<Forward-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Forward-request>)))
  "Returns string type for a service object of type '<Forward-request>"
  "neo_msgs/ForwardRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Forward-request)))
  "Returns string type for a service object of type 'Forward-request"
  "neo_msgs/ForwardRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Forward-request>)))
  "Returns md5sum for a message object of type '<Forward-request>"
  "56fbdb4f932ad85907ae86d07f710cb2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Forward-request)))
  "Returns md5sum for a message object of type 'Forward-request"
  "56fbdb4f932ad85907ae86d07f710cb2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Forward-request>)))
  "Returns full string definition for message of type '<Forward-request>"
  (cl:format cl:nil "float64[] angles~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Forward-request)))
  "Returns full string definition for message of type 'Forward-request"
  (cl:format cl:nil "float64[] angles~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Forward-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'angles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Forward-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Forward-request
    (cl:cons ':angles (angles msg))
))
;//! \htmlinclude Forward-response.msg.html

(cl:defclass <Forward-response> (roslisp-msg-protocol:ros-message)
  ((event
    :reader event
    :initarg :event
    :type cl:integer
    :initform 0)
   (pose
    :reader pose
    :initarg :pose
    :type neo_msgs-msg:EndPose
    :initform (cl:make-instance 'neo_msgs-msg:EndPose)))
)

(cl:defclass Forward-response (<Forward-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Forward-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Forward-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-srv:<Forward-response> is deprecated: use neo_msgs-srv:Forward-response instead.")))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <Forward-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:event-val is deprecated.  Use neo_msgs-srv:event instead.")
  (event m))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <Forward-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-srv:pose-val is deprecated.  Use neo_msgs-srv:pose instead.")
  (pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Forward-response>) ostream)
  "Serializes a message object of type '<Forward-response>"
  (cl:let* ((signed (cl:slot-value msg 'event)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Forward-response>) istream)
  "Deserializes a message object of type '<Forward-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Forward-response>)))
  "Returns string type for a service object of type '<Forward-response>"
  "neo_msgs/ForwardResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Forward-response)))
  "Returns string type for a service object of type 'Forward-response"
  "neo_msgs/ForwardResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Forward-response>)))
  "Returns md5sum for a message object of type '<Forward-response>"
  "56fbdb4f932ad85907ae86d07f710cb2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Forward-response)))
  "Returns md5sum for a message object of type 'Forward-response"
  "56fbdb4f932ad85907ae86d07f710cb2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Forward-response>)))
  "Returns full string definition for message of type '<Forward-response>"
  (cl:format cl:nil "int32 event~%EndPose pose~%~%================================================================================~%MSG: neo_msgs/EndPose~%float64 x~%float64 y~%float64 z~%float64 Rx~%float64 Ry~%float64 Rz~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Forward-response)))
  "Returns full string definition for message of type 'Forward-response"
  (cl:format cl:nil "int32 event~%EndPose pose~%~%================================================================================~%MSG: neo_msgs/EndPose~%float64 x~%float64 y~%float64 z~%float64 Rx~%float64 Ry~%float64 Rz~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Forward-response>))
  (cl:+ 0
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Forward-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Forward-response
    (cl:cons ':event (event msg))
    (cl:cons ':pose (pose msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Forward)))
  'Forward-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Forward)))
  'Forward-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Forward)))
  "Returns string type for a service object of type '<Forward>"
  "neo_msgs/Forward")