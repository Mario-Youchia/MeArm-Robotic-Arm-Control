# MeArm Robotic Arm Control

A 3-DOF robotic arm, built as an Embedded-Systems and Robotics internship project. The project combines Inverse/forward kinematics, physical prototype testing, CAD motion demonstrations, Simscape Multibody analysis, and Arduino based servo control.

> **Note:** The complete CAD model, SolidWorks files, STL exports, and laser-cutting files are hosted on GrabCAD, you can find the link below.

<p align="center">
  <img src="public/images/projects/robotic-arm-control/Robotic%20Arm%20CAD%20Model.png" alt="MeArm robotic arm CAD model" width="720">
</p>

<p align="center">
  <a href="https://grabcad.com/library/mearm-robotic-arm-1"><b>View CAD model on GrabCAD</b></a>
  &nbsp;•&nbsp;
  <a href="https://drive.google.com/file/d/1N2jgzvmauV8Ic5TUkYzIh1V3nWVkhGx2/view?usp=sharing"><b>View internship report</b></a>
  &nbsp;•&nbsp;
  <a href="https://github.com/Mario-Youchia/Arduino-Four-Servo-Controller"><b>Related servo-controller project</b></a>
</p>

---

## Overview

This repository focuses on the software, kinematics, and MATLAB/Simscape-related export files for the robotic-arm project.

The arm uses three positioning joints:

- **Base rotation**
- **Shoulder motion**
- **Elbow motion**

A fourth servo actuates the gripper.

The full CAD package is available on GrabCAD:

[View and download the CAD model on GrabCAD](https://grabcad.com/library/mearm-robotic-arm-1)

---

## Motion Preview

<table>
  <tr>
    <td align="center" width="50%">
      <a href="Media/CAD%20Animation/Complete%20CAD%20Animation.mp4">
        <img src="public/images/projects/robotic-arm-control/Base%20Joint%20Rotation.gif" alt="Base joint rotation" width="320">
      </a>
      <br>
      <b>Base Joint Rotation</b>
      <br>
      Rotates the arm around the vertical base axis.
    </td>
    <td align="center" width="50%">
      <a href="Media/CAD%20Animation/Complete%20CAD%20Animation.mp4">
        <img src="public/images/projects/robotic-arm-control/Shoulder%20Joint%20Motion.gif" alt="Shoulder joint motion" width="320">
      </a>
      <br>
      <b>Shoulder Joint Motion</b>
      <br>
      Raises and lowers the main arm linkage.
    </td>
  </tr>
  <tr>
    <td align="center" width="50%">
      <a href="Media/CAD%20Animation/Complete%20CAD%20Animation.mp4">
        <img src="public/images/projects/robotic-arm-control/Elbow%20Joint%20Motion.gif" alt="Elbow joint motion" width="320">
      </a>
      <br>
      <b>Elbow Joint Motion</b>
      <br>
      Extends and retracts the forearm linkage.
    </td>
    <td align="center" width="50%">
      <a href="Media/CAD%20Animation/Complete%20CAD%20Animation.mp4">
        <img src="public/images/projects/robotic-arm-control/Gripper%20Motion.gif" alt="Gripper motion" width="320">
      </a>
      <br>
      <b>Gripper Motion</b>
      <br>
      Opens and closes the end-effector for object handling.
    </td>
  </tr>
</table>

---

## Physical Prototype Demonstration

<p align="center">
  <a href="Media/Real%20Robot/Real%20Robot%20Demonstration.mp4">
    <img src="public/images/projects/robotic-arm-control/Real%20Robot%20Demonstration.gif" alt="Real robotic arm demonstration" width="620">
  </a>
</p>

The physical prototype demonstrates the assembled robotic arm moving after mechanical assembly and calibration.

---

## Project Context

The internship project combined robotic-arm mechanical design, servo control, kinematic analysis, and vision-based control.

<table>
  <tr>
    <td align="center" width="50%">
      <img src="public/images/projects/robotic-arm-control/System%20Schematic.png" alt="System schematic" width="360">
      <br>
      <b>System Schematic</b>
    </td>
    <td align="center" width="50%">
      <img src="public/images/projects/robotic-arm-control/Computer%20Vision%20Detection.png" alt="Computer vision detection example" width="360">
      <br>
      <b>Computer Vision Context</b>
    </td>
  </tr>
</table>

The computer-vision image is just included to show the project direction.

---

## Arduino Arm Control

The Arduino control folder contains the firmware implementation for the robotic arm.

Main sketch:

```text
Arduino Arm Control/MeArmControl.ino
```

The firmware includes:

- servo pin and limit definitions;
- base, elbow, shoulder, and gripper servo control;
- inverse-kinematics calculations for target positions;
- point-to-point joint movement;
- simple pick-up and drop-off routines;

Configured servo pins:

| Joint / actuator | Arduino pin |
|---|---:|
| Base | 3 |
| Elbow | 5 |
| Shoulder | 6 |
| Gripper | 9 |

Before running the firmware on hardware, verify servo wiring, external power, angle limits, and mechanical clearance.

---

## Kinematics

`ForwardKinematics.m` calculates and visualizes the reachable workspace of the arm based on the base, shoulder, and elbow angle ranges used by the Arduino implementation.

The spreadsheet supports inverse-kinematics calculation and calibration work used during the project.

<p align="center">
  <img src="public/images/projects/robotic-arm-control/Inverse%20Kinematics%20Validation.png" alt="Inverse kinematics validation" width="430">
  &nbsp;
  <img src="public/images/projects/robotic-arm-control/Inverse%20Kinematics%20Refinement.png" alt="Inverse kinematics refinement" width="430">
</p>

---

## Mechanical Design and CAD Files

The complete mechanical design package is hosted on GrabCAD:

[View and download the CAD model on GrabCAD](https://grabcad.com/library/mearm-robotic-arm-1)

The GrabCAD model includes the CAD files such as:

- final Parasolid assembly;
- SolidWorks assemblies and parts;
- STL exports;
- laser-cutting files;
- CAD preview images.

The Simscape Multibody export package in included in theis repository because it is more related to MATLAB analysis.

---

## Simscape Multibody Export

It includes:

- the XML import file;
- referenced STEP geometry files;
- the associated export-error report.

<p align="center">
  <img src="public/images/projects/robotic-arm-control/Simscape%20Multibody%20Import.png" alt="Simscape Multibody import" width="620">
</p>

---

## Hardware and Assembly Media

<p align="center">
  <img src="public/images/projects/robotic-arm-control/Assembly%20Components.jpg" alt="Assembly components" width="430">
  &nbsp;
  <img src="public/images/projects/robotic-arm-control/Assembly%20Setup.png" alt="Assembly setup" width="430">
</p>

<p align="center">
  <img src="public/images/projects/robotic-arm-control/Hardware%20Setup%20Overview%201.jpg" alt="Hardware setup overview 1" width="430">
  &nbsp;
  <img src="public/images/projects/robotic-arm-control/Hardware%20Setup%20Overview%202.jpg" alt="Hardware setup overview 2" width="430">
</p>

---

## Related Project

This robotic-arm project is related to a separate servo-control interface project:

[Arduino Four-Servo Controller](https://github.com/Mario-Youchia/Arduino-Four-Servo-Controller)

That project focuses on a desktop interface for controlling four servos through Arduino.

---

## Tools

- **Arduino / C++** for servo-control firmware
- **MATLAB** for kinematics workspace analysis
- **Spreadsheet calculations** for inverse-kinematics validation and calibration
- **SolidWorks** for mechanical design and assembly
- **Simscape Multibody export** for MATLAB/Simulink mechanical-system import

---

## Third-Party Code

This repository includes the external `VarSpeedServo` Arduino library:

```text
Arduino Arm Control/VarSpeedServo.cpp
Arduino Arm Control/VarSpeedServo.h
```

The original copyright and license notices are preserved in the included source files.

---

## Report

[View internship report](https://drive.google.com/file/d/1N2jgzvmauV8Ic5TUkYzIh1V3nWVkhGx2/view?usp=sharing)

---

## Notes

- Verify servo limits, wiring, power supply, and mechanical clearance before running the hardware.
