#include "InverseKinematics.h"

double Pi = 2 * acos(0.0);

double q_0(const RobotPosition_t& target, const RobotParams_t& params) {
	return 180 - ((atan(target.y/target.x) + Pi/2)/Pi)*180;
}

double q_1(const RobotPosition_t& target, const RobotParams_t& params, double& gamma, double q0) {
	float r = sqrt(pow(target.x,2) + pow(target.y,2));
	float temp1 = 2*atan((57.3-target.z)/(r-65));
	float temp2 = 2*asin((57.3-target.z)/(160*sin(temp1/2)));
	float u = 0.5*(temp2 - temp1);
	float u_e = 0;
	if (u >=0)
    	u_e = Pi/2 - u;
	else
    	u_e = Pi/2 + u;
	
	int offsetElbow = 89;
	float U = offsetElbow - ((u_e/Pi)*180);
	return U;
}

double q_2(const RobotPosition_t& target, const RobotParams_t& params, double& gamma, double q1) {
	float r = sqrt(pow(target.x,2) + pow(target.y,2));
	float temp1 = 2*atan((57.3-target.z)/(r-65));
	float temp2 = 2*asin((57.3-target.z)/(160*sin(temp1/2)));
	float l = 0.5*(temp1 + temp2);
	//float l_s = Pi/2 - l;
	float l_s = l;
	int offsetShoulder = 95;
	float L = ((l_s/Pi)*180) + offsetShoulder;
	return L;
}
void inverseKin(const RobotPosition_t& target, const RobotParams_t& params, double* q)
{
	q[0] = q_0(target, params);
	double gamma;
	q[1] = q_1(target, params, gamma, q[0]);
	q[2] = q_2(target, params, gamma, q[1]);
}