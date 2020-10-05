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

class EndPose {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x = null;
      this.y = null;
      this.z = null;
      this.Rx = null;
      this.Ry = null;
      this.Rz = null;
    }
    else {
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = 0.0;
      }
      if (initObj.hasOwnProperty('Rx')) {
        this.Rx = initObj.Rx
      }
      else {
        this.Rx = 0.0;
      }
      if (initObj.hasOwnProperty('Ry')) {
        this.Ry = initObj.Ry
      }
      else {
        this.Ry = 0.0;
      }
      if (initObj.hasOwnProperty('Rz')) {
        this.Rz = initObj.Rz
      }
      else {
        this.Rz = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type EndPose
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float64(obj.z, buffer, bufferOffset);
    // Serialize message field [Rx]
    bufferOffset = _serializer.float64(obj.Rx, buffer, bufferOffset);
    // Serialize message field [Ry]
    bufferOffset = _serializer.float64(obj.Ry, buffer, bufferOffset);
    // Serialize message field [Rz]
    bufferOffset = _serializer.float64(obj.Rz, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type EndPose
    let len;
    let data = new EndPose(null);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Rx]
    data.Rx = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Ry]
    data.Ry = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [Rz]
    data.Rz = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'neo_msgs/EndPose';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9f62dbed28d2c842e4baf60dcb12c05c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 x
    float64 y
    float64 z
    float64 Rx
    float64 Ry
    float64 Rz
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new EndPose(null);
    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = 0.0
    }

    if (msg.Rx !== undefined) {
      resolved.Rx = msg.Rx;
    }
    else {
      resolved.Rx = 0.0
    }

    if (msg.Ry !== undefined) {
      resolved.Ry = msg.Ry;
    }
    else {
      resolved.Ry = 0.0
    }

    if (msg.Rz !== undefined) {
      resolved.Rz = msg.Rz;
    }
    else {
      resolved.Rz = 0.0
    }

    return resolved;
    }
};

module.exports = EndPose;
