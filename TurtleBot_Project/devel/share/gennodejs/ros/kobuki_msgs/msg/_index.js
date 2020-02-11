
"use strict";

let ScanAngle = require('./ScanAngle.js');
let DigitalOutput = require('./DigitalOutput.js');
let CliffEvent = require('./CliffEvent.js');
let MotorPower = require('./MotorPower.js');
let ExternalPower = require('./ExternalPower.js');
let Sound = require('./Sound.js');
let PowerSystemEvent = require('./PowerSystemEvent.js');
let ControllerInfo = require('./ControllerInfo.js');
let KeyboardInput = require('./KeyboardInput.js');
let Led = require('./Led.js');
let VersionInfo = require('./VersionInfo.js');
let DockInfraRed = require('./DockInfraRed.js');
let RobotStateEvent = require('./RobotStateEvent.js');
let ButtonEvent = require('./ButtonEvent.js');
let WheelDropEvent = require('./WheelDropEvent.js');
let DigitalInputEvent = require('./DigitalInputEvent.js');
let SensorState = require('./SensorState.js');
let BumperEvent = require('./BumperEvent.js');
let AutoDockingFeedback = require('./AutoDockingFeedback.js');
let AutoDockingActionResult = require('./AutoDockingActionResult.js');
let AutoDockingAction = require('./AutoDockingAction.js');
let AutoDockingGoal = require('./AutoDockingGoal.js');
let AutoDockingActionFeedback = require('./AutoDockingActionFeedback.js');
let AutoDockingActionGoal = require('./AutoDockingActionGoal.js');
let AutoDockingResult = require('./AutoDockingResult.js');

module.exports = {
  ScanAngle: ScanAngle,
  DigitalOutput: DigitalOutput,
  CliffEvent: CliffEvent,
  MotorPower: MotorPower,
  ExternalPower: ExternalPower,
  Sound: Sound,
  PowerSystemEvent: PowerSystemEvent,
  ControllerInfo: ControllerInfo,
  KeyboardInput: KeyboardInput,
  Led: Led,
  VersionInfo: VersionInfo,
  DockInfraRed: DockInfraRed,
  RobotStateEvent: RobotStateEvent,
  ButtonEvent: ButtonEvent,
  WheelDropEvent: WheelDropEvent,
  DigitalInputEvent: DigitalInputEvent,
  SensorState: SensorState,
  BumperEvent: BumperEvent,
  AutoDockingFeedback: AutoDockingFeedback,
  AutoDockingActionResult: AutoDockingActionResult,
  AutoDockingAction: AutoDockingAction,
  AutoDockingGoal: AutoDockingGoal,
  AutoDockingActionFeedback: AutoDockingActionFeedback,
  AutoDockingActionGoal: AutoDockingActionGoal,
  AutoDockingResult: AutoDockingResult,
};
