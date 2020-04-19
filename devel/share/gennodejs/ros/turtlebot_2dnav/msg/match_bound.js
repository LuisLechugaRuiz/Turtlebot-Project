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

class match_bound {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pointright = null;
      this.pointleft = null;
      this.pointcenter = null;
      this.matched = null;
      this.index = null;
      this.color = null;
    }
    else {
      if (initObj.hasOwnProperty('pointright')) {
        this.pointright = initObj.pointright
      }
      else {
        this.pointright = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('pointleft')) {
        this.pointleft = initObj.pointleft
      }
      else {
        this.pointleft = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('pointcenter')) {
        this.pointcenter = initObj.pointcenter
      }
      else {
        this.pointcenter = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('matched')) {
        this.matched = initObj.matched
      }
      else {
        this.matched = false;
      }
      if (initObj.hasOwnProperty('index')) {
        this.index = initObj.index
      }
      else {
        this.index = 0;
      }
      if (initObj.hasOwnProperty('color')) {
        this.color = initObj.color
      }
      else {
        this.color = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type match_bound
    // Serialize message field [pointright]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointright, buffer, bufferOffset);
    // Serialize message field [pointleft]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointleft, buffer, bufferOffset);
    // Serialize message field [pointcenter]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.pointcenter, buffer, bufferOffset);
    // Serialize message field [matched]
    bufferOffset = _serializer.bool(obj.matched, buffer, bufferOffset);
    // Serialize message field [index]
    bufferOffset = _serializer.int32(obj.index, buffer, bufferOffset);
    // Serialize message field [color]
    bufferOffset = _serializer.int32(obj.color, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type match_bound
    let len;
    let data = new match_bound(null);
    // Deserialize message field [pointright]
    data.pointright = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [pointleft]
    data.pointleft = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [pointcenter]
    data.pointcenter = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [matched]
    data.matched = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [index]
    data.index = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [color]
    data.color = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 81;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot_2dnav/match_bound';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c25fb2723cbd0da8861846f432114884';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Point pointright
    geometry_msgs/Point pointleft
    geometry_msgs/Point pointcenter
    bool matched
    int32 index
    int32 color
    
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
    const resolved = new match_bound(null);
    if (msg.pointright !== undefined) {
      resolved.pointright = geometry_msgs.msg.Point.Resolve(msg.pointright)
    }
    else {
      resolved.pointright = new geometry_msgs.msg.Point()
    }

    if (msg.pointleft !== undefined) {
      resolved.pointleft = geometry_msgs.msg.Point.Resolve(msg.pointleft)
    }
    else {
      resolved.pointleft = new geometry_msgs.msg.Point()
    }

    if (msg.pointcenter !== undefined) {
      resolved.pointcenter = geometry_msgs.msg.Point.Resolve(msg.pointcenter)
    }
    else {
      resolved.pointcenter = new geometry_msgs.msg.Point()
    }

    if (msg.matched !== undefined) {
      resolved.matched = msg.matched;
    }
    else {
      resolved.matched = false
    }

    if (msg.index !== undefined) {
      resolved.index = msg.index;
    }
    else {
      resolved.index = 0
    }

    if (msg.color !== undefined) {
      resolved.color = msg.color;
    }
    else {
      resolved.color = 0
    }

    return resolved;
    }
};

module.exports = match_bound;
