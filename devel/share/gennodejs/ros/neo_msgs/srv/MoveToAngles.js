// Auto-generated. Do not edit!

// (in-package neo_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class MoveToAnglesRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motor_ids = null;
      this.angles = null;
      this.velocity = null;
      this.acceleration = null;
      this.relative = null;
      this.block = null;
    }
    else {
      if (initObj.hasOwnProperty('motor_ids')) {
        this.motor_ids = initObj.motor_ids
      }
      else {
        this.motor_ids = [];
      }
      if (initObj.hasOwnProperty('angles')) {
        this.angles = initObj.angles
      }
      else {
        this.angles = [];
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
      if (initObj.hasOwnProperty('relative')) {
        this.relative = initObj.relative
      }
      else {
        this.relative = false;
      }
      if (initObj.hasOwnProperty('block')) {
        this.block = initObj.block
      }
      else {
        this.block = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MoveToAnglesRequest
    // Serialize message field [motor_ids]
    bufferOffset = _arraySerializer.int32(obj.motor_ids, buffer, bufferOffset, null);
    // Serialize message field [angles]
    bufferOffset = _arraySerializer.float64(obj.angles, buffer, bufferOffset, null);
    // Serialize message field [velocity]
    bufferOffset = _serializer.float32(obj.velocity, buffer, bufferOffset);
    // Serialize message field [acceleration]
    bufferOffset = _serializer.float32(obj.acceleration, buffer, bufferOffset);
    // Serialize message field [relative]
    bufferOffset = _serializer.bool(obj.relative, buffer, bufferOffset);
    // Serialize message field [block]
    bufferOffset = _serializer.bool(obj.block, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MoveToAnglesRequest
    let len;
    let data = new MoveToAnglesRequest(null);
    // Deserialize message field [motor_ids]
    data.motor_ids = _arrayDeserializer.int32(buffer, bufferOffset, null)
    // Deserialize message field [angles]
    data.angles = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [velocity]
    data.velocity = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [acceleration]
    data.acceleration = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [relative]
    data.relative = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [block]
    data.block = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.motor_ids.length;
    length += 8 * object.angles.length;
    return length + 18;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/MoveToAnglesRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '36e0733c6aa70456810eb19b39c1dd3b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32[] motor_ids
    float64[] angles
    float32 velocity
    float32 acceleration
    bool relative
    bool block
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MoveToAnglesRequest(null);
    if (msg.motor_ids !== undefined) {
      resolved.motor_ids = msg.motor_ids;
    }
    else {
      resolved.motor_ids = []
    }

    if (msg.angles !== undefined) {
      resolved.angles = msg.angles;
    }
    else {
      resolved.angles = []
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

    if (msg.relative !== undefined) {
      resolved.relative = msg.relative;
    }
    else {
      resolved.relative = false
    }

    if (msg.block !== undefined) {
      resolved.block = msg.block;
    }
    else {
      resolved.block = false
    }

    return resolved;
    }
};

class MoveToAnglesResponse {
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
    // Serializes a message object of type MoveToAnglesResponse
    // Serialize message field [event]
    bufferOffset = _serializer.int32(obj.event, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MoveToAnglesResponse
    let len;
    let data = new MoveToAnglesResponse(null);
    // Deserialize message field [event]
    data.event = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/MoveToAnglesResponse';
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
    const resolved = new MoveToAnglesResponse(null);
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
  Request: MoveToAnglesRequest,
  Response: MoveToAnglesResponse,
  md5sum() { return 'df013f5f4546b148508f366c4f2a3858'; },
  datatype() { return 'neo_msgs/MoveToAngles'; }
};
