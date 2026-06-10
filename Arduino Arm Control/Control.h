#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include "InverseKinematics.h"

void writeServo(const RobotServo_t &servo, int angle);
void moveAbsJ(const RobotServo_t robotServos[JOINTS], const double qN[JOINTS], const double qT[JOINTS], const double T);
void moveJ(const RobotServo_t robotServos[JOINTS], const double qN[JOINTS], const RobotPosition_t target, const float T, const RobotParams_t &params);
void PickUp (const RobotPosition_t target1, const RobotPosition_t target2);
void DropOff (const RobotPosition_t target);
void MoveItem (const RobotPosition_t target1, const RobotPosition_t target2, const RobotPosition_t target);

#endif
