; Auto-generated. Do not edit!


(cl:in-package neo_msgs-msg)


;//! \htmlinclude JointAngles.msg.html

(cl:defclass <JointAngles> (roslisp-msg-protocol:ros-message)
  ((angles
    :reader angles
    :initarg :angles
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass JointAngles (<JointAngles>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <JointAngles>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'JointAngles)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-msg:<JointAngles> is deprecated: use neo_msgs-msg:JointAngles instead.")))

(cl:ensure-generic-function 'angles-val :lambda-list '(m))
(cl:defmethod angles-val ((m <JointAngles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-msg:angles-val is deprecated.  Use neo_msgs-msg:angles instead.")
  (angles m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <JointAngles>) ostream)
  "Serializes a message object of type '<JointAngles>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <JointAngles>) istream)
  "Deserializes a message object of type '<JointAngles>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<JointAngles>)))
  "Returns string type for a message object of type '<JointAngles>"
  "neo_msgs/JointAngles")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'JointAngles)))
  "Returns string type for a message object of type 'JointAngles"
  "neo_msgs/JointAngles")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<JointAngles>)))
  "Returns md5sum for a message object of type '<JointAngles>"
  "b7ca77b9da2dfe623a276e10b570d2df")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'JointAngles)))
  "Returns md5sum for a message object of type 'JointAngles"
  "b7ca77b9da2dfe623a276e10b570d2df")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<JointAngles>)))
  "Returns full string definition for message of type '<JointAngles>"
  (cl:format cl:nil "float64[] angles~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'JointAngles)))
  "Returns full string definition for message of type 'JointAngles"
  (cl:format cl:nil "float64[] angles~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <JointAngles>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'angles) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <JointAngles>))
  "Converts a ROS message object to a list"
  (cl:list 'JointAngles
    (cl:cons ':angles (angles msg))
))
