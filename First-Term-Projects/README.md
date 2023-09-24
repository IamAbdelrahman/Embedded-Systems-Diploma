# Pressure Control System

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Usage](#usage)
- [Testing](#testing)
- [Contact Information](#contact-information)


## Project Description

The Pressure Control System is designed for monitoring and controlling pressure in a cabin or closed environment. It includes a pressure sensor that detects pressure values and triggers an alarm when the pressure exceeds a certain threshold.

## Features

- Real-time monitoring of pressure values.
- Alarm activation when pressure exceeds 20 bars.
- Automatic alarm deactivation after 60 seconds.
- User-friendly interface.

## Prerequisites
### Hardware Requirements 
- STM32 Microcontroller
- 8 Switch Buttons
- 1 LED
### Software Requirements
- Proteus Simulation
- Visual Studio CodeIDE
- GNU Arm Embedded Toolchain
- Makefile

## Usage

### Hardware Connections
- Connect the 8 switch buttons to GPIO PortA pin0:7 act as the pressure sensor.
-  Connect the LED indicator to GPIO PortA pin13.
## Testing

To ensure that the Pressure Control System operates correctly, follow these test procedures:
### Test Case 1: Alarm Deactivation

**Description:** Confirm that the LED alarm indicator turns off when pressure is below the threshold.

**Test Steps:**

1. Build and flash the project to the microcontroller.
2. Apply pressure to the sensor beyond the threshold (e.g., < 20 bars). Through pressing the switch button (Set PA0, and PA0:PA3).
3. Observe the LED indicator on the microcontroller board.

**Expected Results:** The LED alarm indicator should turn off when the pressure is below the threshold and toggles when the pressure exceeds the threshold.

### Test Case 2: Alarm Activation

**Description:** Confirm that the LED alarm indicator toggles for some milliseconds when pressure exceeds the threshold.
**Test Steps:**

1. Build and flash the project to the microcontroller.
2. Apply pressure to the sensor above the threshold (e.g., > 20 bars). Through pressing the switch button (Set PA0+PA7, and PA0:PA4).
3. Observe the LED indicator on the microcontroller board.

**Expected Results:** The alarm LED should remain on for some milliseconds when triggered.


## Contact Information

If you have any questions, feedback, or encounter issues while using the Pressure Control System project, please don't hesitate to get in touch with us. We're here to help!

- **Email:** abdelruhman.m.kamal@gmail.com
- [Twitter](https://twitter.com/IAmAbdoKamal)
- [LinkedIn](https://www.linkedin.com/in/iamabdelrahmankamal/)