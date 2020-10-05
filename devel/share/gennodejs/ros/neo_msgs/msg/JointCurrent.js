// Auto-generated. Do not edit!

// (in-package neo_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class JointCurrent {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.current = null;
    }
    else {
      if (initObj.hasOwnProperty('current')) {
        this.current = initObj.current
      }
      else {
        this.current = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type JointCurrent
    // Serialize message field [current]
    bufferOffset = _arraySerializer.float64(obj.current, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type JointCurrent
    let len;
    let data = new JointCurrent(null);
    // Deserialize message field [current]
    data.current = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.current.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'neo_msgs/JointCurrent';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1634c573362b3eca9589d81d03b20094';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] current
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new JointCurrent(null);
    if (msg.current !== undefined) {
      resolved.current = msg.current;
    }
    else {
      resolved.current = []
    }

    return resolved;
    }
};

module.exports = JointCurrent;
