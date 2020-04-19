// Auto-generated. Do not edit!

// (in-package turtlebot_2dnav.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ROI = require('../msg/ROI.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class CarryingPersonRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.person = null;
    }
    else {
      if (initObj.hasOwnProperty('person')) {
        this.person = initObj.person
      }
      else {
        this.person = new ROI();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CarryingPersonRequest
    // Serialize message field [person]
    bufferOffset = ROI.serialize(obj.person, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CarryingPersonRequest
    let len;
    let data = new CarryingPersonRequest(null);
    // Deserialize message field [person]
    data.person = ROI.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += ROI.getMessageSize(object.person);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/CarryingPersonRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '60b1f66dc52c1ec4715013a78543dbbd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    turtlebot_2dnav/ROI person
    
    
    ================================================================================
    MSG: turtlebot_2dnav/ROI
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
    const resolved = new CarryingPersonRequest(null);
    if (msg.person !== undefined) {
      resolved.person = ROI.Resolve(msg.person)
    }
    else {
      resolved.person = new ROI()
    }

    return resolved;
    }
};

class CarryingPersonResponse {
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
    // Serializes a message object of type CarryingPersonResponse
    // Serialize message field [received]
    bufferOffset = _serializer.bool(obj.received, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CarryingPersonResponse
    let len;
    let data = new CarryingPersonResponse(null);
    // Deserialize message field [received]
    data.received = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/CarryingPersonResponse';
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
    const resolved = new CarryingPersonResponse(null);
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
  Request: CarryingPersonRequest,
  Response: CarryingPersonResponse,
  md5sum() { return '483ed3a7747788a7b78a207bdc605ba1'; },
  datatype() { return 'turtlebot_2dnav/CarryingPerson'; }
};
