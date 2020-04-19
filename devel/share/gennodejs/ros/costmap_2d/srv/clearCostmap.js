// Auto-generated. Do not edit!

// (in-package costmap_2d.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class clearCostmapRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.clear = null;
    }
    else {
      if (initObj.hasOwnProperty('clear')) {
        this.clear = initObj.clear
      }
      else {
        this.clear = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type clearCostmapRequest
    // Serialize message field [clear]
    bufferOffset = _serializer.bool(obj.clear, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type clearCostmapRequest
    let len;
    let data = new clearCostmapRequest(null);
    // Deserialize message field [clear]
    data.clear = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'costmap_2d/clearCostmapRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0f13874ec47789a29a9f87f75379435d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool clear
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new clearCostmapRequest(null);
    if (msg.clear !== undefined) {
      resolved.clear = msg.clear;
    }
    else {
      resolved.clear = false
    }

    return resolved;
    }
};

class clearCostmapResponse {
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
    // Serializes a message object of type clearCostmapResponse
    // Serialize message field [received]
    bufferOffset = _serializer.bool(obj.received, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type clearCostmapResponse
    let len;
    let data = new clearCostmapResponse(null);
    // Deserialize message field [received]
    data.received = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'costmap_2d/clearCostmapResponse';
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
    const resolved = new clearCostmapResponse(null);
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
  Request: clearCostmapRequest,
  Response: clearCostmapResponse,
  md5sum() { return '6f1cadb125ab62799a65523a8282332f'; },
  datatype() { return 'costmap_2d/clearCostmap'; }
};
