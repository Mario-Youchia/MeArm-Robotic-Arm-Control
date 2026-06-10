#pragma once
#ifndef MEARM_h
#define MEARM_h
#include <Arduino.h>
#include <Math.h>
#include "VarSpeedServo.h"

#define JOINTS 3
#define ServoSpeed 20

extern VarSpeedServo servos[12];

extern const double q0[JOINTS];
extern double qX[JOINTS];

// Base
extern const int BaseServoPin;
extern const int BaseMaxAngleLimit;
extern const int BaseMinAngleLimit;

//Elbow
extern const int ElbowServoPin;
extern const int ElbowMaxAngleLimit;
extern const int ElbowMinAngleLimit;

// Gripper
extern const int GripperServoPin;
extern const int GripperMaxAngleLimit;
extern const int GripperMinAngleLimit;

// Shoulder
extern const int ShoulderServoPin;
extern const int ShoulderMaxAngleLimit;
extern const int ShoulderMinAngleLimit;

typedef struct {
	int pin;
  String Name;
	int MaxAngle;
	int MinAngle;
} RobotServo_t;

typedef struct {
	double l0;
	double h1;
	double l1;
	double l2;
	double l3;
	double l3I;
	double l3O;
	double l4;
	double l5;
	double d5;
} RobotParams_t;

typedef struct {
	double x;
	double y;
	double z;
} RobotPosition_t;

extern const RobotServo_t robotServos[JOINTS];
extern const RobotServo_t robotGripper;
extern const RobotParams_t params;

extern RobotPosition_t pT0;
extern RobotPosition_t pT1;
extern RobotPosition_t pT2;
extern RobotPosition_t pT3;
extern RobotPosition_t pT4;
extern RobotPosition_t pT5;
extern RobotPosition_t pT6;

#endif
