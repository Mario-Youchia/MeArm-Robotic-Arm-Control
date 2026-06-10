#pragma once
#ifndef INVERSEKINEMATICS_H
#define INVERSEKINEMATICS_H

#include "MeArm.h"

extern double Pi;

double q_0(const RobotPosition_t& target, const RobotParams_t& params);
double q_1(const RobotPosition_t& target, const RobotParams_t& params, double& gamma, double q0);
double q_2(const RobotPosition_t& target, const RobotParams_t& params, double& gamma, double q1);

void inverseKin(const RobotPosition_t& target, const RobotParams_t& params, double* q);

#endif
