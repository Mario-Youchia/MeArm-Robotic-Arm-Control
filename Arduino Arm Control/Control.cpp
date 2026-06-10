#include "Control.h"

VarSpeedServo servos[12];
double qX[JOINTS];

void writeServo(const RobotServo_t &servo, int angle)
{
  angle = constrain(angle, servo.MinAngle, servo.MaxAngle);
  servos[servo.pin].attach(servo.pin);
  servos[servo.pin].write(angle, ServoSpeed, true);
}

void moveAbsJ(const RobotServo_t robotServos[JOINTS], const double qN[JOINTS], const double qT[JOINTS], const double T) {
  double a[JOINTS], b[JOINTS], c[JOINTS], d[JOINTS], q, t, t0;
  for (int i = 0; i < JOINTS; i++)
  {
    a[i] = (-2 * (qT[i] - qN[i]) / pow(T, 3));
    b[i] = (3 * (qT[i] - qN[i]) / pow(T, 2));
    c[i] = 0.0;
    d[i] = qN[i];
  }
  t0 = millis() / 1000.0;
  t = 0.0;
  while (t < T)
  {
    for (int i = 0; i < JOINTS; i++)
    {
      q = a[i] * pow(t, 3) + b[i] * pow(t, 2) + c[i] * t + d[i];
      writeServo(robotServos[i], (int)q);
    }
    delay(20);
    t = millis() / 1000.0 - t0;

    Serial.print("t = ");
    Serial.println(t);
    Serial.print("millis() = ");
    Serial.println(millis());
    Serial.print("T = ");
    Serial.println(T);
    Serial.print("t0 = ");
    Serial.println(t0);
  }
}

//Point to point movement function
void moveJ(const RobotServo_t robotServos[JOINTS], const double qN[JOINTS], const RobotPosition_t target, const float T, const RobotParams_t &params)
{
  Serial.println("moveJ starts");  
  double qT[JOINTS];
  inverseKin(target, params, qT);
  moveAbsJ(robotServos, qN, qT, T);
  qX[0] = qT[0];
  qX[1] = qT[1];
  qX[2] = qT[2];
  Serial.println("moveJ ends");
}

void PickUp (const RobotPosition_t target1, const RobotPosition_t target2) {
  // Initial Position -> Target 1
  Serial.println("Pick Up Function Begins");
  moveJ(robotServos, q0, target1, 3, params);
  delay(200);
  // Open Gripper
  writeServo(robotGripper, robotGripper.MinAngle);
  // Target 1 -> Target 2
  moveJ(robotServos, qX, target2, 3, params);
  // Close Gripper
  writeServo(robotGripper, robotGripper.MaxAngle);
  // Target 2 -> Initial Position
  moveJ(robotServos, qX, pT0, 3, params);
  delay(500);
}

void DropOff (const RobotPosition_t target) {
  // Initial Position -> Target
  moveJ(robotServos, q0, target, 3, params);
  delay(200);
  // Open Gripper
  writeServo(robotGripper, robotGripper.MinAngle);
  delay(1000);
  // Close Gripper
  writeServo(robotGripper, robotGripper.MaxAngle);
  // Target -> Initial Position
  moveJ(robotServos, qX, pT0, 3, params);
}

void MoveItem (const RobotPosition_t target1, const RobotPosition_t target2, const RobotPosition_t target) {
  PickUp(target1, target2);
  DropOff(target);
}