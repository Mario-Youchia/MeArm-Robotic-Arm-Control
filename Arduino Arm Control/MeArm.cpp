#include "MeArm.h"

const double q0[JOINTS] = {68, 90.0, 105.0};

// Base
const int BaseServoPin = 3;
const int BaseMaxAngleLimit = 180;
const int BaseMinAngleLimit = 0;

//Elbow
const int ElbowServoPin = 5;
const int ElbowMaxAngleLimit = 135;
const int ElbowMinAngleLimit = 0;

// Gripper
const int GripperServoPin = 9;
const int GripperMaxAngleLimit = 100;
const int GripperMinAngleLimit = 55;

// Shoulder
const int ShoulderServoPin = 6;
const int ShoulderMaxAngleLimit = 180;
const int ShoulderMinAngleLimit = 25;

const RobotServo_t robotServos[JOINTS] = {
  { BaseServoPin, "Base", BaseMaxAngleLimit, BaseMinAngleLimit },
  { ElbowServoPin, "Elbow", ElbowMaxAngleLimit, ElbowMinAngleLimit },
  { ShoulderServoPin, "Shoulder", ShoulderMaxAngleLimit , ShoulderMinAngleLimit }
};

const RobotServo_t robotGripper = { GripperServoPin, "Gripper",  GripperMaxAngleLimit, GripperMinAngleLimit};

//const RobotParams_t params = {5, 64.5, 15.1, 80, 80, 23.9, 35, 80, 52, 5};
const RobotParams_t params = {5, 87.5, 15.1, 80, 80, 23.9, 35, 80, 10.7, 0};

//RobotPosition_t pT0 = { 134, -120, 122 };
RobotPosition_t pT0 = { 10, 0,60 };


RobotPosition_t pT1 = { 160, -10.7, 53 };
RobotPosition_t pT2 = { 135, -10.7, 53 };
RobotPosition_t pT3 = { 143.4, 83.82, 53 };
RobotPosition_t pT4 = { 123.1, 69.64, 53 };
RobotPosition_t pT5 = { 146.78, -77.92, 53 };
RobotPosition_t pT6 = { 124.36, -67.47, 53 };
