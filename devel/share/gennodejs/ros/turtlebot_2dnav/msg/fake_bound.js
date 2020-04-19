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

//-----------------------------------------------------------

class fake_bound {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pointleftmin = null;
      this.pointleftmax = null;
      this.pointrightmin = null;
      this.pointrightmax = null;
      this.isvertical = null;
      this.index = null;
      this.resize = null;
      this.exit = null;
    }
    else {
      if (initObj.hasOwnProperty('pointleftmin')) {
        this.pointleftmin = initObj.pointleftmin
      }
      else {
        this.pointleftmin = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('pointleftmax')) {
        this.pointleftmax = initObj.pointleftmax
      }
      else {
        this.pointleftmax = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('pointrightmin')) {
        this.pointrightmin = initObj.pointrightmin
      }
      else {
        this.pointrightmin = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('pointrightmax')) {
        this.pointrightmax = initObj.pointrightmax
      }
      else {
        this.pointrightmax = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('isvertical')) {
        this.isvertical = initObj.isvertical
      }
      else {
        this.isvertical = false;
      }
      if (initObj.hasOwnProperty('index')) {
        this.index = initObj.index
      }
      else {
        this.index = 0;
      }
      if (initObj.hasOwnProperty('resize')) {
        this.resize = initObj.resize
      }
      else {
        this.resize = false;
      }
      if (initObj.hasOwnProperty('exit')) {
        this.exit = initObj.exit
      }
      else {
        this.exit = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type fake_bound
    // Serialize message field [pointleftmin]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointleftmin, buffer, bufferOffset);
    // Serialize message field [pointleftmax]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointleftmax, buffer, bufferOffset);
    // Serialize message field [pointrightmin]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointrightmin, buffer, bufferOffset);
    // Serialize message field [pointrightmax]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointrightmax, buffer, bufferOffset);
    // Serialize message field [isvertical]
    bufferOffset = _serializer.bool(obj.isvertical, buffer, bufferOffset);
    // Serialize message field [index]
    bufferOffset = _serializer.uint8(obj.index, buffer, bufferOffset);
    // Serialize message field [resize]
    bufferOffset = _serializer.bool(obj.resize, buffer, bufferOffset);
    // Serialize message field [exit]
    bufferOffset = _serializer.bool(obj.exit, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type fake_bound
    let len;
    let data = new fake_bound(null);
    // Deserialize message field [pointleftmin]
    data.pointleftmin = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [pointleftmax]
    data.pointleftmax = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [pointrightmin]
    data.pointrightmin = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [pointrightmax]
    data.pointrightmax = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [isvertical]
    data.isvertical = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [index]
    data.index = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [resize]
    data.resize = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [exit]
    data.exit = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 100;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot_2dnav/fake_bound';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd1c2e5bd63abef51265cdf5e8668cf43';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Point pointleftmin
    geometry_msgs/Point pointleftmax
    geometry_msgs/Point pointrightmin
    geometry_msgs/Point pointrightmax
    bool isvertical
    uint8 index
    bool resize
    bool exit
    
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
    const resolved = new fake_bound(null);
    if (msg.pointleftmin !== undefined) {
      resolved.pointleftmin = geometry_msgs.msg.Point.Resolve(msg.pointleftmin)
    }
    else {
      resolved.pointleftmin = new geometry_msgs.msg.Point()
    }

    if (msg.pointleftmax !== undefined) {
      resolved.pointleftmax = geometry_msgs.msg.Point.Resolve(msg.pointleftmax)
    }
    else {
      resolved.pointleftmax = new geometry_msgs.msg.Point()
    }

    if (msg.pointrightmin !== undefined) {
      resolved.pointrightmin = geometry_msgs.msg.Point.Resolve(msg.pointrightmin)
    }
    else {
      resolved.pointrightmin = new geometry_msgs.msg.Point()
    }

    if (msg.pointrightmax !== undefined) {
      resolved.pointrightmax = geometry_msgs.msg.Point.Resolve(msg.pointrightmax)
    }
    else {
      resolved.pointrightmax = new geometry_msgs.msg.Point()
    }

    if (msg.isvertical !== undefined) {
      resolved.isvertical = msg.isvertical;
    }
    else {
      resolved.isvertical = false
    }

    if (msg.index !== undefined) {
      resolved.index = msg.index;
    }
    else {
      resolved.index = 0
    }

    if (msg.resize !== undefined) {
      resolved.resize = msg.resize;
    }
    else {
      resolved.resize = false
    }

    if (msg.exit !== undefined) {
      resolved.exit = msg.exit;
    }
    else {
      resolved.exit = false
    }

    return resolved;
    }
};

module.exports = fake_bound;
