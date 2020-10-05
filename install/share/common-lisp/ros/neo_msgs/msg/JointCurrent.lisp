; Auto-generated. Do not edit!


(cl:in-package neo_msgs-msg)


;//! \htmlinclude JointCurrent.msg.html

(cl:defclass <JointCurrent> (roslisp-msg-protocol:ros-message)
  ((current
    :reader current
    :initarg :current
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass JointCurrent (<JointCurrent>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <JointCurrent>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'JointCurrent)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_msgs-msg:<JointCurrent> is deprecated: use neo_msgs-msg:JointCurrent instead.")))

(cl:ensure-generic-function 'current-val :lambda-list '(m))
(cl:defmethod current-val ((m <JointCurrent>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_msgs-msg:current-val is deprecated.  Use neo_msgs-msg:current instead.")
  (current m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <JointCurrent>) ostream)
  "Serializes a message object of type '<JointCurrent>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'current))))
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
   (cl:slot-value msg 'current))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <JointCurrent>) istream)
  "Deserializes a message object of type '<JointCurrent>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'current) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'current)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<JointCurrent>)))
  "Returns string type for a message object of type '<JointCurrent>"
  "neo_msgs/JointCurrent")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'JointCurrent)))
  "Returns string type for a message object of type 'JointCurrent"
  "neo_msgs/JointCurrent")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<JointCurrent>)))
  "Returns md5sum for a message object of type '<JointCurrent>"
  "1634c573362b3eca9589d81d03b20094")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'JointCurrent)))
  "Returns md5sum for a message object of type 'JointCurrent"
  "1634c573362b3eca9589d81d03b20094")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<JointCurrent>)))
  "Returns full string definition for message of type '<JointCurrent>"
  (cl:format cl:nil "float64[] current~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'JointCurrent)))
  "Returns full string definition for message of type 'JointCurrent"
  (cl:format cl:nil "float64[] current~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <JointCurrent>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'current) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <JointCurrent>))
  "Converts a ROS message object to a list"
  (cl:list 'JointCurrent
    (cl:cons ':current (current msg))
))
