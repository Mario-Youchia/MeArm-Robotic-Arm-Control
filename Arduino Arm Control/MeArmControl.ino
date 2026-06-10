#include "Control.h"

void setup() {
  Serial.begin(9600);

  RobotPosition_t pT0 = { 134, -120, 122 };
  RobotPosition_t pT1 = {30, -172, 150};
  RobotPosition_t pT2 = {30, -172, 120};

  RobotPosition_t PTest1 = {20,-36,100};
  RobotPosition_t PTest2 = {10,-55,100};
  RobotPosition_t PTest3 = {173,35,30};
  RobotPosition_t PTest4 = {0,-55,100};
  RobotPosition_t PTest5 = {2,-55,100};

  double q[3];

  inverseKin(PTest3, params, q);
  Serial.println("Base Angle = " + String(int(q[0])));
  writeServo(robotServos[0], int(q[0]));
  Serial.println("Elbow Angle = " + String(int(q[1])));
  writeServo(robotServos[1], int(q[1]));
  Serial.println("Shoulder Angle = " + String(int(q[2])));
  writeServo(robotServos[2], int(q[2]));
  writeServo(robotGripper, 50);
  delay(1000);
  writeServo(robotGripper, 120);
  
  inverseKin(PTest1, params, q);
  Serial.println("Base Angle = " + String(int(q[0])));
  writeServo(robotServos[0], int(q[0]));
  Serial.println("Elbow Angle = " + String(int(q[1])));
  writeServo(robotServos[1], int(q[1]));
  Serial.println("Shoulder Angle = " + String(int(q[2])));
  writeServo(robotServos[2], int(q[2]));
  writeServo(robotGripper, 50);
  delay(1000);
  writeServo(robotGripper, 120);

  inverseKin(PTest3, params, q);
  Serial.println("Base Angle = " + String(int(q[0])));
  writeServo(robotServos[0], int(q[0]));
  Serial.println("Elbow Angle = " + String(int(q[1])));
  writeServo(robotServos[1], int(q[1]));
  Serial.println("Shoulder Angle = " + String(int(q[2])));
  writeServo(robotServos[2], int(q[2]));
  writeServo(robotGripper, 50);
  delay(1000);
  writeServo(robotGripper, 120);
  
  inverseKin(PTest2, params, q);
  Serial.println("Base Angle = " + String(int(q[0])));
  writeServo(robotServos[0], int(q[0]));
  Serial.println("Elbow Angle = " + String(int(q[1])));
  writeServo(robotServos[1], int(q[1]));
  Serial.println("Shoulder Angle = " + String(int(q[2])));
  writeServo(robotServos[2], int(q[2]));
  writeServo(robotGripper, 50);
  delay(1000);
  writeServo(robotGripper, 120);

  inverseKin(PTest3, params, q);
  Serial.println("Base Angle = " + String(int(q[0])));
  writeServo(robotServos[0], int(q[0]));
  Serial.println("Elbow Angle = " + String(int(q[1])));
  writeServo(robotServos[1], int(q[1]));
  Serial.println("Shoulder Angle = " + String(int(q[2])));
  writeServo(robotServos[2], int(q[2]));
  writeServo(robotGripper, 50);
  delay(1000);
  writeServo(robotGripper, 120);
  
  inverseKin(PTest4, params, q);
  Serial.println("Base Angle = " + String(int(q[0])));
  writeServo(robotServos[0], int(q[0]));
  Serial.println("Elbow Angle = " + String(int(q[1])));
  writeServo(robotServos[1], int(q[1]));
  Serial.println("Shoulder Angle = " + String(int(q[2])));
  writeServo(robotServos[2], int(q[2]));
  writeServo(robotGripper, 50);
  delay(1000);
  writeServo(robotGripper, 120);

  inverseKin(PTest3, params, q);
  Serial.println("Base Angle = " + String(int(q[0])));
  writeServo(robotServos[0], int(q[0]));
  Serial.println("Elbow Angle = " + String(int(q[1])));
  writeServo(robotServos[1], int(q[1]));
  Serial.println("Shoulder Angle = " + String(int(q[2])));
  writeServo(robotServos[2], int(q[2]));
  writeServo(robotGripper, 50);
  delay(1000);
  writeServo(robotGripper, 120);
  
  inverseKin(PTest5, params, q);
  Serial.println("Base Angle = " + String(int(q[0])));
  writeServo(robotServos[0], int(q[0]));
  Serial.println("Elbow Angle = " + String(int(q[1])));
  writeServo(robotServos[1], int(q[1]));
  Serial.println("Shoulder Angle = " + String(int(q[2])));
  writeServo(robotServos[2], int(q[2]));
  writeServo(robotGripper, 50);
  delay(1000);
  writeServo(robotGripper, 120);
  Serial.println("DONE");
}

void loop() {
}
