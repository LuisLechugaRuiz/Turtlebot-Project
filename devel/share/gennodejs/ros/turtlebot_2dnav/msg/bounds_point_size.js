// Auto-generated. Do not edit!

// (in-package turtlebot_2dnav.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class bounds_point_size {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.points_size = null;
      this.red_zones_active = null;
    }
    else {
      if (initObj.hasOwnProperty('points_size')) {
        this.points_size = initObj.points_size
      }
      else {
        this.points_size = [];
      }
      if (initObj.hasOwnProperty('red_zones_active')) {
        this.red_zones_active = initObj.red_zones_active
      }
      else {
        this.red_zones_active = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type bounds_point_size
    // Serialize message field [points_size]
    bufferOffset = _arraySerializer.int32(obj.points_size, buffer, bufferOffset, null);
    // Serialize message field [red_zones_active]
    bufferOffset = _serializer.bool(obj.red_zones_active, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type bounds_point_size
    let len;
    let data = new bounds_point_size(null);
    // Deserialize message field [points_size]
    data.points_size = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [red_zones_active]
    data.red_zones_active = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.points_size.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot_2dnav/bounds_point_size';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2760f00cd3ace23bdfe186aae6abbb4b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32[] points_size
    bool red_zones_active
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new bounds_point_size(null);
    if (msg.points_size !== undefined) {
      resolved.points_size = msg.points_size;
    }
    else {
      resolved.points_size = []
    }

    if (msg.red_zones_active !== undefined) {
      resolved.red_zones_active = msg.red_zones_active;
    }
    else {
      resolved.red_zones_active = false
    }

    return resolved;
    }
};

module.exports = bounds_point_size;
