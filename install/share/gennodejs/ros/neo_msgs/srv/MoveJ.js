// Auto-generated. Do not edit!

// (in-package neo_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let EndPose = require('../msg/EndPose.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class MoveJRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.points = null;
      this.velocity = null;
      this.acceleration = null;
      this.interval = null;
      this.close = null;
    }
    else {
      if (initObj.hasOwnProperty('points')) {
        this.points = initObj.points
      }
      else {
        this.points = [];
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = 0.0;
      }
      if (initObj.hasOwnProperty('acceleration')) {
        this.acceleration = initObj.acceleration
      }
      else {
        this.acceleration = 0.0;
      }
      if (initObj.hasOwnProperty('interval')) {
        this.interval = initObj.interval
      }
      else {
        this.interval = 0.0;
      }
      if (initObj.hasOwnProperty('close')) {
        this.close = initObj.close
      }
      else {
        this.close = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MoveJRequest
    // Serialize message field [points]
    // Serialize the length for message field [points]
    bufferOffset = _serializer.uint32(obj.points.length, buffer, bufferOffset);
    obj.points.forEach((val) => {
      bufferOffset = EndPose.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [velocity]
    bufferOffset = _serializer.float32(obj.velocity, buffer, bufferOffset);
    // Serialize message field [acceleration]
    bufferOffset = _serializer.float32(obj.acceleration, buffer, bufferOffset);
    // Serialize message field [interval]
    bufferOffset = _serializer.float32(obj.interval, buffer, bufferOffset);
    // Serialize message field [close]
    bufferOffset = _serializer.bool(obj.close, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MoveJRequest
    let len;
    let data = new MoveJRequest(null);
    // Deserialize message field [points]
    // Deserialize array length for message field [points]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.points = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.points[i] = EndPose.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [velocity]
    data.velocity = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [acceleration]
    data.acceleration = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [interval]
    data.interval = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [close]
    data.close = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 48 * object.points.length;
    return length + 17;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/MoveJRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd558b745fb37989689e245ec7c7b467c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    EndPose[] points
    float32 velocity
    float32 acceleration
    float32 interval
    bool close
    
    ================================================================================
    MSG: neo_msgs/EndPose
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
    const resolved = new MoveJRequest(null);
    if (msg.points !== undefined) {
      resolved.points = new Array(msg.points.length);
      for (let i = 0; i < resolved.points.length; ++i) {
        resolved.points[i] = EndPose.Resolve(msg.points[i]);
      }
    }
    else {
      resolved.points = []
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = 0.0
    }

    if (msg.acceleration !== undefined) {
      resolved.acceleration = msg.acceleration;
    }
    else {
      resolved.acceleration = 0.0
    }

    if (msg.interval !== undefined) {
      resolved.interval = msg.interval;
    }
    else {
      resolved.interval = 0.0
    }

    if (msg.close !== undefined) {
      resolved.close = msg.close;
    }
    else {
      resolved.close = false
    }

    return resolved;
    }
};

class MoveJResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.event = null;
    }
    else {
      if (initObj.hasOwnProperty('event')) {
        this.event = initObj.event
      }
      else {
        this.event = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MoveJResponse
    // Serialize message field [event]
    bufferOffset = _serializer.int32(obj.event, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MoveJResponse
    let len;
    let data = new MoveJResponse(null);
    // Deserialize message field [event]
    data.event = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/MoveJResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b2a9c605bb7a420089b02c6063322298';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 event
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MoveJResponse(null);
    if (msg.event !== undefined) {
      resolved.event = msg.event;
    }
    else {
      resolved.event = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: MoveJRequest,
  Response: MoveJResponse,
  md5sum() { return 'c94ebec1f5e856eae9ca23929e46a5f8'; },
  datatype() { return 'neo_msgs/MoveJ'; }
};
