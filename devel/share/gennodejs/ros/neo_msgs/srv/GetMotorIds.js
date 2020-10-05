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

class GetMotorIdsRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetMotorIdsRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetMotorIdsRequest
    let len;
    let data = new GetMotorIdsRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/GetMotorIdsRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetMotorIdsRequest(null);
    return resolved;
    }
};

class GetMotorIdsResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.event = null;
      this.motor_ids = null;
    }
    else {
      if (initObj.hasOwnProperty('event')) {
        this.event = initObj.event
      }
      else {
        this.event = 0;
      }
      if (initObj.hasOwnProperty('motor_ids')) {
        this.motor_ids = initObj.motor_ids
      }
      else {
        this.motor_ids = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetMotorIdsResponse
    // Serialize message field [event]
    bufferOffset = _serializer.int32(obj.event, buffer, bufferOffset);
    // Serialize message field [motor_ids]
    bufferOffset = _arraySerializer.int32(obj.motor_ids, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetMotorIdsResponse
    let len;
    let data = new GetMotorIdsResponse(null);
    // Deserialize message field [event]
    data.event = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [motor_ids]
    data.motor_ids = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.motor_ids.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/GetMotorIdsResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'da45074f03ccd6c00fa83c029210839d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 event
    int32[] motor_ids
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetMotorIdsResponse(null);
    if (msg.event !== undefined) {
      resolved.event = msg.event;
    }
    else {
      resolved.event = 0
    }

    if (msg.motor_ids !== undefined) {
      resolved.motor_ids = msg.motor_ids;
    }
    else {
      resolved.motor_ids = []
    }

    return resolved;
    }
};

module.exports = {
  Request: GetMotorIdsRequest,
  Response: GetMotorIdsResponse,
  md5sum() { return 'da45074f03ccd6c00fa83c029210839d'; },
  datatype() { return 'neo_msgs/GetMotorIds'; }
};
