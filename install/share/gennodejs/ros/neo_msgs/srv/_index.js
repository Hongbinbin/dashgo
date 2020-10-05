
"use strict";

let MoveToAngles = require('./MoveToAngles.js')
let MoveP = require('./MoveP.js')
let Release = require('./Release.js')
let SetEOATAction = require('./SetEOATAction.js')
let Forward = require('./Forward.js')
let MoveJ = require('./MoveJ.js')
let Hold = require('./Hold.js')
let Calibrate = require('./Calibrate.js')
let Reset = require('./Reset.js')
let MoveToPose = require('./MoveToPose.js')
let Recover = require('./Recover.js')
let GetInput = require('./GetInput.js')
let MoveL = require('./MoveL.js')
let Stop = require('./Stop.js')
let Inverse = require('./Inverse.js')
let SetOutput = require('./SetOutput.js')
let GetMotorIds = require('./GetMotorIds.js')

module.exports = {
  MoveToAngles: MoveToAngles,
  MoveP: MoveP,
  Release: Release,
  SetEOATAction: SetEOATAction,
  Forward: Forward,
  MoveJ: MoveJ,
  Hold: Hold,
  Calibrate: Calibrate,
  Reset: Reset,
  MoveToPose: MoveToPose,
  Recover: Recover,
  GetInput: GetInput,
  MoveL: MoveL,
  Stop: Stop,
  Inverse: Inverse,
  SetOutput: SetOutput,
  GetMotorIds: GetMotorIds,
};
