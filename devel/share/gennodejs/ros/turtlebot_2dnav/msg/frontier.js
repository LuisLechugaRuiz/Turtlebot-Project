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

class frontier {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.goal = null;
      this.frontiers_count = null;
    }
    else {
      if (initObj.hasOwnProperty('goal')) {
        this.goal = initObj.goal
      }
      else {
        this.goal = new geometry_msgs.msg.PoseStamped();
      }
      if (initObj.hasOwnProperty('frontiers_count')) {
        this.frontiers_count = initObj.frontiers_count
      }
      else {
        this.frontiers_count = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type frontier
    // Serialize message field [goal]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.goal, buffer, bufferOffset);
    // Serialize message field [frontiers_count]
    bufferOffset = _serializer.uint8(obj.frontiers_count, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type frontier
    let len;
    let data = new frontier(null);
    // Deserialize message field [goal]
    data.goal = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [frontiers_count]
    data.frontiers_count = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.goal);
    return length + 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot_2dnav/frontier';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '72fa4e2f921957ecbe666961f3773de7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/PoseStamped goal
    uint8 frontiers_count
    
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
    const resolved = new frontier(null);
    if (msg.goal !== undefined) {
      resolved.goal = geometry_msgs.msg.PoseStamped.Resolve(msg.goal)
    }
    else {
      resolved.goal = new geometry_msgs.msg.PoseStamped()
    }

    if (msg.frontiers_count !== undefined) {
      resolved.frontiers_count = msg.frontiers_count;
    }
    else {
      resolved.frontiers_count = 0
    }

    return resolved;
    }
};

module.exports = frontier;
