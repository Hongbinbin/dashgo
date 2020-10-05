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

class InverseRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pose = null;
    }
    else {
      if (initObj.hasOwnProperty('pose')) {
        this.pose = initObj.pose
      }
      else {
        this.pose = new EndPose();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type InverseRequest
    // Serialize message field [pose]
    bufferOffset = EndPose.serialize(obj.pose, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type InverseRequest
    let len;
    let data = new InverseRequest(null);
    // Deserialize message field [pose]
    data.pose = EndPose.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/InverseRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ff5c892304a46764ae660fc40994aefa';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    EndPose pose
    
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
    const resolved = new InverseRequest(null);
    if (msg.pose !== undefined) {
      resolved.pose = EndPose.Resolve(msg.pose)
    }
    else {
      resolved.pose = new EndPose()
    }

    return resolved;
    }
};

class InverseResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.event = null;
      this.angles = null;
    }
    else {
      if (initObj.hasOwnProperty('event')) {
        this.event = initObj.event
      }
      else {
        this.event = 0;
      }
      if (initObj.hasOwnProperty('angles')) {
        this.angles = initObj.angles
      }
      else {
        this.angles = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type InverseResponse
    // Serialize message field [event]
    bufferOffset = _serializer.int32(obj.event, buffer, bufferOffset);
    // Serialize message field [angles]
    bufferOffset = _arraySerializer.float64(obj.angles, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type InverseResponse
    let len;
    let data = new InverseResponse(null);
    // Deserialize message field [event]
    data.event = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [angles]
    data.angles = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.angles.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'neo_msgs/InverseResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5cefdabf35619b2c09882073aebe171a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 event
    float64[] angles
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new InverseResponse(null);
    if (msg.event !== undefined) {
      resolved.event = msg.event;
    }
    else {
      resolved.event = 0
    }

    if (msg.angles !== undefined) {
      resolved.angles = msg.angles;
    }
    else {
      resolved.angles = []
    }

    return resolved;
    }
};

module.exports = {
  Request: InverseRequest,
  Response: InverseResponse,
  md5sum() { return 'a7f6d41d0e750d2b5bb2a289caba9efe'; },
  datatype() { return 'neo_msgs/Inverse'; }
};
