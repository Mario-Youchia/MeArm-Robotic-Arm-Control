# MeArm Robotic Arm Control

A 3-DOF MeArm-style robotic arm with a servo-actuated gripper, developed as part of an embedded-systems and robotics internship project. The project combines Arduino-based servo control, inverse/forward kinematics, physical prototype testing, CAD motion demonstrations, and a CAD-to-Simscape Multibody export package.

> **Note:** The complete CAD model, SolidWorks files, STL exports, and laser-cutting files are hosted separately on GrabCAD because GrabCAD is more suitable for distributing mechanical-design files.

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

This repository focuses on the software, kinematics, project media, and MATLAB/Simscape-related export files for the robotic-arm project.

The arm uses three positioning joints:

- **Base rotation**
- **Shoulder motion**
- **Elbow motion**

A fourth servo actuates the gripper, so the most accurate description is:

> **3-DOF robotic arm with a servo-actuated gripper**

The full CAD package is available on GrabCAD:

[https://grabcad.com/library/mearm-robotic-arm-1](https://grabcad.com/library/mearm-robotic-arm-1)

---

## Motion Preview

Click any GIF to open the complete CAD animation video.

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

Click the GIF to open the full real-robot demonstration video.

<p align="center">
  <a href="Media/Real%20Robot/Real%20Robot%20Demonstration.mp4">
    <img src="public/images/projects/robotic-arm-control/Real%20Robot%20Demonstration.gif" alt="Real robotic arm demonstration" width="620">
  </a>
</p>

The physical prototype demonstrates the assembled robotic arm moving under servo control after mechanical assembly and calibration.

---

## Project Context

The internship project combined robotic-arm mechanical design, servo control, kinematic analysis, and vision-based manipulation context.

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

The computer-vision image is included to show the broader project direction. This repository mainly preserves the robotic-arm control, kinematics, media, and Simscape-export artifacts.

---

## Repository Structure

```text
.
├── Arduino Arm Control/
│   ├── MeArmControl.ino
│   ├── Control.cpp
│   ├── Control.h
│   ├── InverseKinematics.cpp
│   ├── InverseKinematics.h
│   ├── MeArm.cpp
│   ├── MeArm.h
│   ├── VarSpeedServo.cpp
│   └── VarSpeedServo.h
│
├── Kinematics/
│   ├── ForwardKinematics.m
│   └── Inverse Kinematics.xlsx
│
├── Mechanical Design/
│   └── Simscape Multibody Export/
│       ├── Part 9 - Final Assembly.xml
│       ├── Part 9 - Final Assembly_error.txt
│       └── referenced STEP geometry files
│
├── Media/
│   ├── CAD Animation/
│   ├── Hardware Setup/
│   └── Real Robot/
│
└── public/images/projects/robotic-arm-control/
```

---

## Arduino Arm Control

The Arduino control folder contains the selected firmware implementation for the robotic arm.

Main sketch:

```text
Arduino Arm Control/MeArmControl.ino
```

Supporting files:

```text
Arduino Arm Control/Control.cpp
Arduino Arm Control/Control.h
Arduino Arm Control/InverseKinematics.cpp
Arduino Arm Control/InverseKinematics.h
Arduino Arm Control/MeArm.cpp
Arduino Arm Control/MeArm.h
Arduino Arm Control/VarSpeedServo.cpp
Arduino Arm Control/VarSpeedServo.h
```

The firmware includes:

- servo pin and limit definitions;
- base, elbow, shoulder, and gripper servo control;
- inverse-kinematics calculations for target positions;
- point-to-point joint movement;
- simple pick-up and drop-off routines;
- serial debug output for testing and calibration.

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

The kinematics folder contains MATLAB and spreadsheet-based analysis files.

```text
Kinematics/ForwardKinematics.m
Kinematics/Inverse Kinematics.xlsx
```

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

The GrabCAD model includes the CAD-focused files such as:

- final Parasolid assembly;
- native SolidWorks assemblies and parts;
- STL exports;
- laser-cutting files;
- CAD preview images.

This GitHub repository includes only the Simscape Multibody export package because it is more closely related to MATLAB/Simulink analysis than to direct CAD distribution.

---

## Simscape Multibody Export

The folder:

```text
Mechanical Design/Simscape Multibody Export/
```

contains an intermediate CAD-to-Simscape Multibody export package generated from the SolidWorks assembly.

It includes:

- the XML import file;
- referenced STEP geometry files;
- the associated export-error report.

This is **not** presented as a finished Simscape simulation. It is kept as an intermediate import/export artifact for MATLAB/Simulink-based mechanical-system analysis.

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

The media folders preserve the project images, CAD animations, hardware setup photos, and physical robot demonstration files.

---

## Related Project

This robotic-arm project is related to a separate servo-control interface project:

[Arduino Four-Servo Controller](https://github.com/Mario-Youchia/Arduino-Four-Servo-Controller)

That project focuses on a desktop interface for controlling four servos through Arduino. It complements this robotic-arm project by showing a separate servo-control workflow and user-interface implementation.

---

## Tools and Technologies

- **Arduino / C++** for servo-control firmware
- **VarSpeedServo** for controlled servo movement
- **MATLAB** for forward-kinematics workspace analysis
- **Spreadsheet calculations** for inverse-kinematics validation and calibration
- **SolidWorks** for mechanical design and assembly
- **Simscape Multibody export** for MATLAB/Simulink mechanical-system import
- **GrabCAD** for CAD model distribution

---

## Third-Party Code

This repository includes the external `VarSpeedServo` Arduino library:

```text
Arduino Arm Control/VarSpeedServo.cpp
Arduino Arm Control/VarSpeedServo.h
```

The library headers state that it is distributed under the GNU Lesser General Public License, version 2.1 or later. The original copyright and license notices are preserved in the included source files.

---

## Report

The internship report is hosted externally on Google Drive:

[View internship report](REPORT_GOOGLE_DRIVE_LINK)

Replace `https://drive.google.com/file/d/1N2jgzvmauV8Ic5TUkYzIh1V3nWVkhGx2/view?usp=sharing` with the final public or shareable Google Drive URL before publishing the repository.

---

## Notes

- This is an academic/internship project, not a production-ready robotic-arm platform.
- Verify servo limits, wiring, power supply, and mechanical clearance before running the hardware.
- The CAD files are distributed through GrabCAD rather than duplicated inside this GitHub repository.
- The Simscape Multibody folder contains an intermediate export package, not a complete finished simulation.
- The MP4 files are included in the repository media folders and are intended to be uploaded using Git/CLI rather than the GitHub browser uploader.
