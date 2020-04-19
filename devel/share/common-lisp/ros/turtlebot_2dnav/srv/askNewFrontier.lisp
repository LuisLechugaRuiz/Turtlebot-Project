; Auto-generated. Do not edit!


(cl:in-package turtlebot_2dnav-srv)


;//! \htmlinclude askNewFrontier-request.msg.html

(cl:defclass <askNewFrontier-request> (roslisp-msg-protocol:ros-message)
  ((addBlacklist
    :reader addBlacklist
    :initarg :addBlacklist
    :type cl:boolean
    :initform cl:nil)
   (clearBlacklist
    :reader clearBlacklist
    :initarg :clearBlacklist
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass askNewFrontier-request (<askNewFrontier-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <askNewFrontier-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'askNewFrontier-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<askNewFrontier-request> is deprecated: use turtlebot_2dnav-srv:askNewFrontier-request instead.")))

(cl:ensure-generic-function 'addBlacklist-val :lambda-list '(m))
(cl:defmethod addBlacklist-val ((m <askNewFrontier-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:addBlacklist-val is deprecated.  Use turtlebot_2dnav-srv:addBlacklist instead.")
  (addBlacklist m))

(cl:ensure-generic-function 'clearBlacklist-val :lambda-list '(m))
(cl:defmethod clearBlacklist-val ((m <askNewFrontier-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:clearBlacklist-val is deprecated.  Use turtlebot_2dnav-srv:clearBlacklist instead.")
  (clearBlacklist m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <askNewFrontier-request>) ostream)
  "Serializes a message object of type '<askNewFrontier-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'addBlacklist) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'clearBlacklist) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <askNewFrontier-request>) istream)
  "Deserializes a message object of type '<askNewFrontier-request>"
    (cl:setf (cl:slot-value msg 'addBlacklist) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'clearBlacklist) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<askNewFrontier-request>)))
  "Returns string type for a service object of type '<askNewFrontier-request>"
  "turtlebot_2dnav/askNewFrontierRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'askNewFrontier-request)))
  "Returns string type for a service object of type 'askNewFrontier-request"
  "turtlebot_2dnav/askNewFrontierRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<askNewFrontier-request>)))
  "Returns md5sum for a message object of type '<askNewFrontier-request>"
  "1218c344901f1bfc2f1bcf338db224b8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'askNewFrontier-request)))
  "Returns md5sum for a message object of type 'askNewFrontier-request"
  "1218c344901f1bfc2f1bcf338db224b8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<askNewFrontier-request>)))
  "Returns full string definition for message of type '<askNewFrontier-request>"
  (cl:format cl:nil "bool addBlacklist~%bool clearBlacklist~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'askNewFrontier-request)))
  "Returns full string definition for message of type 'askNewFrontier-request"
  (cl:format cl:nil "bool addBlacklist~%bool clearBlacklist~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <askNewFrontier-request>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <askNewFrontier-request>))
  "Converts a ROS message object to a list"
  (cl:list 'askNewFrontier-request
    (cl:cons ':addBlacklist (addBlacklist msg))
    (cl:cons ':clearBlacklist (clearBlacklist msg))
))
;//! \htmlinclude askNewFrontier-response.msg.html

(cl:defclass <askNewFrontier-response> (roslisp-msg-protocol:ros-message)
  ((done
    :reader done
    :initarg :done
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass askNewFrontier-response (<askNewFrontier-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <askNewFrontier-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'askNewFrontier-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_2dnav-srv:<askNewFrontier-response> is deprecated: use turtlebot_2dnav-srv:askNewFrontier-response instead.")))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <askNewFrontier-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_2dnav-srv:done-val is deprecated.  Use turtlebot_2dnav-srv:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <askNewFrontier-response>) ostream)
  "Serializes a message object of type '<askNewFrontier-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'done) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <askNewFrontier-response>) istream)
  "Deserializes a message object of type '<askNewFrontier-response>"
    (cl:setf (cl:slot-value msg 'done) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<askNewFrontier-response>)))
  "Returns string type for a service object of type '<askNewFrontier-response>"
  "turtlebot_2dnav/askNewFrontierResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'askNewFrontier-response)))
  "Returns string type for a service object of type 'askNewFrontier-response"
  "turtlebot_2dnav/askNewFrontierResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<askNewFrontier-response>)))
  "Returns md5sum for a message object of type '<askNewFrontier-response>"
  "1218c344901f1bfc2f1bcf338db224b8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'askNewFrontier-response)))
  "Returns md5sum for a message object of type 'askNewFrontier-response"
  "1218c344901f1bfc2f1bcf338db224b8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<askNewFrontier-response>)))
  "Returns full string definition for message of type '<askNewFrontier-response>"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'askNewFrontier-response)))
  "Returns full string definition for message of type 'askNewFrontier-response"
  (cl:format cl:nil "bool done~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <askNewFrontier-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <askNewFrontier-response>))
  "Converts a ROS message object to a list"
  (cl:list 'askNewFrontier-response
    (cl:cons ':done (done msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'askNewFrontier)))
  'askNewFrontier-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'askNewFrontier)))
  'askNewFrontier-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'askNewFrontier)))
  "Returns string type for a service object of type '<askNewFrontier>"
  "turtlebot_2dnav/askNewFrontier")