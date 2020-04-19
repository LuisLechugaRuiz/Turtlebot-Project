// Auto-generated. Do not edit!

// (in-package turtlebot_2dnav.msg)


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

class ROI {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Header = null;
      this.type = null;
      this.center = null;
      this.size_x = null;
      this.size_y = null;
      this.index = null;
      this.isnew = null;
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
      if (initObj.hasOwnProperty('center')) {
        this.center = initObj.center
      }
      else {
        this.center = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('size_x')) {
        this.size_x = initObj.size_x
      }
      else {
        this.size_x = 0.0;
      }
      if (initObj.hasOwnProperty('size_y')) {
        this.size_y = initObj.size_y
      }
      else {
        this.size_y = 0.0;
      }
      if (initObj.hasOwnProperty('index')) {
        this.index = initObj.index
      }
      else {
        this.index = 0;
      }
      if (initObj.hasOwnProperty('isnew')) {
        this.isnew = initObj.isnew
      }
      else {
        this.isnew = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ROI
    // Serialize message field [Header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.Header, buffer, bufferOffset);
    // Serialize message field [type]
    bufferOffset = _serializer.string(obj.type, buffer, bufferOffset);
    // Serialize message field [center]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.center, buffer, bufferOffset);
    // Serialize message field [size_x]
    bufferOffset = _serializer.float32(obj.size_x, buffer, bufferOffset);
    // Serialize message field [size_y]
    bufferOffset = _serializer.float32(obj.size_y, buffer, bufferOffset);
    // Serialize message field [index]
    bufferOffset = _serializer.uint8(obj.index, buffer, bufferOffset);
    // Serialize message field [isnew]
    bufferOffset = _serializer.bool(obj.isnew, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ROI
    let len;
    let data = new ROI(null);
    // Deserialize message field [Header]
    data.Header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [type]
    data.type = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [center]
    data.center = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [size_x]
    data.size_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [size_y]
    data.size_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [index]
    data.index = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [isnew]
    data.isnew = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.Header);
    length += object.type.length;
    return length + 38;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot_2dnav/ROI';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fe6aa07fdbecd8b2e91005f5ecf70714';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header Header
    string type
    geometry_msgs/Point center
    float32 size_x
    float32 size_y
    uint8 index
    bool isnew
    
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
    const resolved = new ROI(null);
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

    if (msg.center !== undefined) {
      resolved.center = geometry_msgs.msg.Point.Resolve(msg.center)
    }
    else {
      resolved.center = new geometry_msgs.msg.Point()
    }

    if (msg.size_x !== undefined) {
      resolved.size_x = msg.size_x;
    }
    else {
      resolved.size_x = 0.0
    }

    if (msg.size_y !== undefined) {
      resolved.size_y = msg.size_y;
    }
    else {
      resolved.size_y = 0.0
    }

    if (msg.index !== undefined) {
      resolved.index = msg.index;
    }
    else {
      resolved.index = 0
    }

    if (msg.isnew !== undefined) {
      resolved.isnew = msg.isnew;
    }
    else {
      resolved.isnew = false
    }

    return resolved;
    }
};

module.exports = ROI;
