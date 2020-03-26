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

class returnCostRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.start = null;
      this.goal = null;
    }
    else {
      if (initObj.hasOwnProperty('start')) {
        this.start = initObj.start
      }
      else {
        this.start = new geometry_msgs.msg.PoseStamped();
      }
      if (initObj.hasOwnProperty('goal')) {
        this.goal = initObj.goal
      }
      else {
        this.goal = new geometry_msgs.msg.PoseStamped();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type returnCostRequest
    // Serialize message field [start]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.start, buffer, bufferOffset);
    // Serialize message field [goal]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.goal, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type returnCostRequest
    let len;
    let data = new returnCostRequest(null);
    // Deserialize message field [start]
    data.start = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [goal]
    data.goal = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.start);
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.goal);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/returnCostRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2fe3126bd5b2d56edd5005220333d4fd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/PoseStamped start
    
    geometry_msgs/PoseStamped goal
    
    
    ================================================================================
    MSG: geometry_msgs/PoseStamped
    # A Pose with reference coordinate frame and timestamp
    Header header
    Pose pose
    
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
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new returnCostRequest(null);
    if (msg.start !== undefined) {
      resolved.start = geometry_msgs.msg.PoseStamped.Resolve(msg.start)
    }
    else {
      resolved.start = new geometry_msgs.msg.PoseStamped()
    }

    if (msg.goal !== undefined) {
      resolved.goal = geometry_msgs.msg.PoseStamped.Resolve(msg.goal)
    }
    else {
      resolved.goal = new geometry_msgs.msg.PoseStamped()
    }

    return resolved;
    }
};

class returnCostResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.cost = null;
    }
    else {
      if (initObj.hasOwnProperty('cost')) {
        this.cost = initObj.cost
      }
      else {
        this.cost = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type returnCostResponse
    // Serialize message field [cost]
    bufferOffset = _serializer.int64(obj.cost, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type returnCostResponse
    let len;
    let data = new returnCostResponse(null);
    // Deserialize message field [cost]
    data.cost = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'turtlebot_2dnav/returnCostResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b6afcd538e7323896023cc11da5d0344';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    int64 cost
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new returnCostResponse(null);
    if (msg.cost !== undefined) {
      resolved.cost = msg.cost;
    }
    else {
      resolved.cost = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: returnCostRequest,
  Response: returnCostResponse,
  md5sum() { return 'f0ab08f6ab3861462bec12fbd2aae873'; },
  datatype() { return 'turtlebot_2dnav/returnCost'; }
};
