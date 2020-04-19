// Auto-generated. Do not edit!

// (in-package turtlebot_2dnav.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class recalculateBoundRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.recalculate = null;
    }
    else {
      if (initObj.hasOwnProperty('recalculate')) {
        this.recalculate = initObj.recalculate
      }
      else {
        this.recalculate = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type recalculateBoundRequest
    // Serialize message field [recalculate]
    bufferOffset = _serializer.bool(obj.recalculate, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type recalculateBoundRequest
    let len;
    let data = new recalculateBoundRequest(null);
    // Deserialize message field [recalculate]
    data.recalculate = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/recalculateBoundRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '713c5ce4862e541c2c00a5b48ff7df97';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool recalculate
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new recalculateBoundRequest(null);
    if (msg.recalculate !== undefined) {
      resolved.recalculate = msg.recalculate;
    }
    else {
      resolved.recalculate = false
    }

    return resolved;
    }
};

class recalculateBoundResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.received = null;
    }
    else {
      if (initObj.hasOwnProperty('received')) {
        this.received = initObj.received
      }
      else {
        this.received = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type recalculateBoundResponse
    // Serialize message field [received]
    bufferOffset = _serializer.bool(obj.received, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type recalculateBoundResponse
    let len;
    let data = new recalculateBoundResponse(null);
    // Deserialize message field [received]
    data.received = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/recalculateBoundResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dd4152e077925db952c78baadb1e48b7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool received
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new recalculateBoundResponse(null);
    if (msg.received !== undefined) {
      resolved.received = msg.received;
    }
    else {
      resolved.received = false
    }

    return resolved;
    }
};

module.exports = {
  Request: recalculateBoundRequest,
  Response: recalculateBoundResponse,
  md5sum() { return 'ccb08b87036c8a7862161f690fdb0a11'; },
  datatype() { return 'turtlebot_2dnav/recalculateBound'; }
};
