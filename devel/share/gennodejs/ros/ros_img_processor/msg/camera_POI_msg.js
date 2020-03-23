// Auto-generated. Do not edit!

// (in-package ros_img_processor.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class camera_POI_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Header = null;
      this.type = null;
      this.pointleft = null;
      this.pointright = null;
    }
    else {
      if (initObj.hasOwnProperty('Header')) {
        this.Header = initObj.Header
      }
      else {
        this.Header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('type')) {
        this.type = initObj.type
      }
      else {
        this.type = '';
      }
      if (initObj.hasOwnProperty('pointleft')) {
        this.pointleft = initObj.pointleft
      }
      else {
        this.pointleft = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('pointright')) {
        this.pointright = initObj.pointright
      }
      else {
        this.pointright = new geometry_msgs.msg.Point();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type camera_POI_msg
    // Serialize message field [Header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.Header, buffer, bufferOffset);
    // Serialize message field [type]
    bufferOffset = _serializer.string(obj.type, buffer, bufferOffset);
    // Serialize message field [pointleft]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointleft, buffer, bufferOffset);
    // Serialize message field [pointright]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointright, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type camera_POI_msg
    let len;
    let data = new camera_POI_msg(null);
    // Deserialize message field [Header]
    data.Header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [type]
    data.type = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [pointleft]
    data.pointleft = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [pointright]
    data.pointright = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.Header);
    length += object.type.length;
    return length + 52;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ros_img_processor/camera_POI_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3889b5518a505b6dff84d0f699e8b734';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header Header
    string type
    geometry_msgs/Point pointleft
    geometry_msgs/Point pointright
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new camera_POI_msg(null);
    if (msg.Header !== undefined) {
      resolved.Header = std_msgs.msg.Header.Resolve(msg.Header)
    }
    else {
      resolved.Header = new std_msgs.msg.Header()
    }

    if (msg.type !== undefined) {
      resolved.type = msg.type;
    }
    else {
      resolved.type = ''
    }

    if (msg.pointleft !== undefined) {
      resolved.pointleft = geometry_msgs.msg.Point.Resolve(msg.pointleft)
    }
    else {
      resolved.pointleft = new geometry_msgs.msg.Point()
    }

    if (msg.pointright !== undefined) {
      resolved.pointright = geometry_msgs.msg.Point.Resolve(msg.pointright)
    }
    else {
      resolved.pointright = new geometry_msgs.msg.Point()
    }

    return resolved;
    }
};

module.exports = camera_POI_msg;
