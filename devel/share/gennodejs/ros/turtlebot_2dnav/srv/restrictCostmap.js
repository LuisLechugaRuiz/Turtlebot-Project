// Auto-generated. Do not edit!

// (in-package turtlebot_2dnav.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------


//-----------------------------------------------------------

class restrictCostmapRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Point = null;
      this.index = null;
      this.color = null;
      this.restrict = null;
      this.isvertical = null;
      this.exit = null;
    }
    else {
      if (initObj.hasOwnProperty('Point')) {
        this.Point = initObj.Point
      }
      else {
        this.Point = new geometry_msgs.msg.Point();
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
      if (initObj.hasOwnProperty('restrict')) {
        this.restrict = initObj.restrict
      }
      else {
        this.restrict = false;
      }
      if (initObj.hasOwnProperty('isvertical')) {
        this.isvertical = initObj.isvertical
      }
      else {
        this.isvertical = false;
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
    // Serializes a message object of type restrictCostmapRequest
    // Serialize message field [Point]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.Point, buffer, bufferOffset);
    // Serialize message field [index]
    bufferOffset = _serializer.int32(obj.index, buffer, bufferOffset);
    // Serialize message field [color]
    bufferOffset = _serializer.int32(obj.color, buffer, bufferOffset);
    // Serialize message field [restrict]
    bufferOffset = _serializer.bool(obj.restrict, buffer, bufferOffset);
    // Serialize message field [isvertical]
    bufferOffset = _serializer.bool(obj.isvertical, buffer, bufferOffset);
    // Serialize message field [exit]
    bufferOffset = _serializer.bool(obj.exit, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type restrictCostmapRequest
    let len;
    let data = new restrictCostmapRequest(null);
    // Deserialize message field [Point]
    data.Point = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [index]
    data.index = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [color]
    data.color = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [restrict]
    data.restrict = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [isvertical]
    data.isvertical = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [exit]
    data.exit = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 35;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/restrictCostmapRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c14041ac6488aa9930bd5e86e63fb3d5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Point Point
    int32 index
    int32 color
    bool restrict
    bool isvertical
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
    const resolved = new restrictCostmapRequest(null);
    if (msg.Point !== undefined) {
      resolved.Point = geometry_msgs.msg.Point.Resolve(msg.Point)
    }
    else {
      resolved.Point = new geometry_msgs.msg.Point()
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

    if (msg.restrict !== undefined) {
      resolved.restrict = msg.restrict;
    }
    else {
      resolved.restrict = false
    }

    if (msg.isvertical !== undefined) {
      resolved.isvertical = msg.isvertical;
    }
    else {
      resolved.isvertical = false
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

class restrictCostmapResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.received = null;
      this.NewCenter = null;
    }
    else {
      if (initObj.hasOwnProperty('received')) {
        this.received = initObj.received
      }
      else {
        this.received = false;
      }
      if (initObj.hasOwnProperty('NewCenter')) {
        this.NewCenter = initObj.NewCenter
      }
      else {
        this.NewCenter = new geometry_msgs.msg.Point();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type restrictCostmapResponse
    // Serialize message field [received]
    bufferOffset = _serializer.bool(obj.received, buffer, bufferOffset);
    // Serialize message field [NewCenter]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.NewCenter, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type restrictCostmapResponse
    let len;
    let data = new restrictCostmapResponse(null);
    // Deserialize message field [received]
    data.received = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [NewCenter]
    data.NewCenter = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 25;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/restrictCostmapResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2123167eab87b647a50a6c172571b7b6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool received
    geometry_msgs/Point NewCenter
    
    
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
    const resolved = new restrictCostmapResponse(null);
    if (msg.received !== undefined) {
      resolved.received = msg.received;
    }
    else {
      resolved.received = false
    }

    if (msg.NewCenter !== undefined) {
      resolved.NewCenter = geometry_msgs.msg.Point.Resolve(msg.NewCenter)
    }
    else {
      resolved.NewCenter = new geometry_msgs.msg.Point()
    }

    return resolved;
    }
};

module.exports = {
  Request: restrictCostmapRequest,
  Response: restrictCostmapResponse,
  md5sum() { return 'ca045509d540aafaf4518df5620d8993'; },
  datatype() { return 'turtlebot_2dnav/restrictCostmap'; }
};
