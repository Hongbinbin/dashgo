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

class HoldRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motor_ids = null;
    }
    else {
      if (initObj.hasOwnProperty('motor_ids')) {
        this.motor_ids = initObj.motor_ids
      }
      else {
        this.motor_ids = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type HoldRequest
    // Serialize message field [motor_ids]
    bufferOffset = _arraySerializer.int32(obj.motor_ids, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type HoldRequest
    let len;
    let data = new HoldRequest(null);
    // Deserialize message field [motor_ids]
    data.motor_ids = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.motor_ids.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/HoldRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bb0d6c2d9cfe8f7b5cba05d61857b47e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32[] motor_ids
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new HoldRequest(null);
    if (msg.motor_ids !== undefined) {
      resolved.motor_ids = msg.motor_ids;
    }
    else {
      resolved.motor_ids = []
    }

    return resolved;
    }
};

class HoldResponse {
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
    // Serializes a message object of type HoldResponse
    // Serialize message field [event]
    bufferOffset = _serializer.int32(obj.event, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type HoldResponse
    let len;
    let data = new HoldResponse(null);
    // Deserialize message field [event]
    data.event = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/HoldResponse';
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
    const resolved = new HoldResponse(null);
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
  Request: HoldRequest,
  Response: HoldResponse,
  md5sum() { return '1e3ab015e243c7706c372ab529619c93'; },
  datatype() { return 'neo_msgs/Hold'; }
};
