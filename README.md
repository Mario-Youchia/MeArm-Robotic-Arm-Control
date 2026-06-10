# Robotic Arm Design, Control, and Analysis Internship Project

This repository preserves the main technical outputs of a 2022 robotics internship focused on the mechanical design, kinematic analysis, assembly, calibration, and Arduino-based control of a four-servo robotic arm.

## Current Contents

* `control-and-communication/arduino-arm-control/` — Arduino firmware for inverse-kinematics-based servo control and pick-and-place experiments.
* `kinematics/` — forward and inverse kinematics calculations, MATLAB scripts, calibration work, and supporting analysis.
* `mechanical-design/` — recovered 2022 SolidWorks parts and assemblies, neutral CAD exports, laser-cutting material, test fixtures, and previews.
* `simulation-and-analysis/simscape-multibody-export/` — Simscape Multibody Link export files generated from the SolidWorks assembly, including the import XML, STEP dependencies, and the associated export-error report.
* `documentation/final-report/` — the final internship report in PDF format.
* `media/assembly-animation/` — an assembly animation produced during the project.

## CAD Recovery

The primary CAD source is the recovered 2022 SolidWorks set. When a later 2022 copy was missing or corrupted, the most recent valid earlier 2022 version was selected. Files carrying September 2023 timestamps were not promoted because metadata analysis indicated that they were batch-resaved copies of an earlier 2022 branch rather than later design work.

## Project Status

This is a recovered experimental internship project rather than production-ready firmware. It documents successful CAD, kinematics, calibration, direct servo control, pick-and-place experimentation, and an attempted SolidWorks-to-Simscape Multibody export. The Simscape export includes unsupported-constraint warnings and is retained as an intermediate analysis output, not as a complete simulation model.

## Third-Party Code

The Arduino control source includes `VarSpeedServo`, distributed under the GNU Lesser General Public License version 2.1 or later. Its original copyright and license notices remain in `VarSpeedServo.h` and `VarSpeedServo.cpp`.
