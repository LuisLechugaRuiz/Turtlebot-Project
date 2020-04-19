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

class askNewFrontierRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.addBlacklist = null;
      this.clearBlacklist = null;
    }
    else {
      if (initObj.hasOwnProperty('addBlacklist')) {
        this.addBlacklist = initObj.addBlacklist
      }
      else {
        this.addBlacklist = false;
      }
      if (initObj.hasOwnProperty('clearBlacklist')) {
        this.clearBlacklist = initObj.clearBlacklist
      }
      else {
        this.clearBlacklist = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type askNewFrontierRequest
    // Serialize message field [addBlacklist]
    bufferOffset = _serializer.bool(obj.addBlacklist, buffer, bufferOffset);
    // Serialize message field [clearBlacklist]
    bufferOffset = _serializer.bool(obj.clearBlacklist, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type askNewFrontierRequest
    let len;
    let data = new askNewFrontierRequest(null);
    // Deserialize message field [addBlacklist]
    data.addBlacklist = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [clearBlacklist]
    data.clearBlacklist = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/askNewFrontierRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f91fbc6af54a796311a6569836b84444';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool addBlacklist
    bool clearBlacklist
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new askNewFrontierRequest(null);
    if (msg.addBlacklist !== undefined) {
      resolved.addBlacklist = msg.addBlacklist;
    }
    else {
      resolved.addBlacklist = false
    }

    if (msg.clearBlacklist !== undefined) {
      resolved.clearBlacklist = msg.clearBlacklist;
    }
    else {
      resolved.clearBlacklist = false
    }

    return resolved;
    }
};

class askNewFrontierResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.done = null;
    }
    else {
      if (initObj.hasOwnProperty('done')) {
        this.done = initObj.done
      }
      else {
        this.done = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type askNewFrontierResponse
    // Serialize message field [done]
    bufferOffset = _serializer.bool(obj.done, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type askNewFrontierResponse
    let len;
    let data = new askNewFrontierResponse(null);
    // Deserialize message field [done]
    data.done = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/askNewFrontierResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '89bb254424e4cffedbf494e7b0ddbfea';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool done
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new askNewFrontierResponse(null);
    if (msg.done !== undefined) {
      resolved.done = msg.done;
    }
    else {
      resolved.done = false
    }

    return resolved;
    }
};

module.exports = {
  Request: askNewFrontierRequest,
  Response: askNewFrontierResponse,
  md5sum() { return '1218c344901f1bfc2f1bcf338db224b8'; },
  datatype() { return 'turtlebot_2dnav/askNewFrontier'; }
};
