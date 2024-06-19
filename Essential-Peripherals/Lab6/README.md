# Basic Calculator-Atmega32

## Table of Contents
- [Lab Description](#lab-description)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Usage](#usage)
- [Testing](#testing)
- [Files](#files)
- [Contact Information](#contact-information)


## Lab Description

This basic calculator lab is designed for performing simple arithmetic operations "+, -, * , /".

## Features
- Calculating summation, subtraction, multiplication, and division operation.
- Handling zero-division error.
- Handling out of range errors.
- No calculations of float, negative, and large integer numbers.
- Supporting only one calculation process at a time.
- User-friendly interface.

## Prerequisites

### Hardware Requirements 
- ATmega32 Microcontroller
- 4x4 Keypad connected to port D.
- 16x2 LCD is connected to port A and port B and working in 8-bit mode.

### Software Requirements
- Proteus Simulation
- MPLAB X IDE
- Git
**Peripherals used:**
- DIO

## Usage

### Hardware Connections
- LCD is connected to port A for data register and port B for command register.
- Keypad is connected to port D.

## Testing

#### The calculator is designed as a state machine with 3 states:

 1. State_getNumber1
 2. State_getNumber2
 3. State_calculate

After initializing, the program's state is set to State_getNumber1 and waits for input from the keypad, the input is saved in an 8-bit array of size 16.

When you press an operand "+, -, * , /", the program saves the input number in the array, tnen jumps to the State_getNumber2 state.

While in the State_getNumber2 state and after entering the second operand, 

If you press on '=' the program jumps to State_result state and shows the result.

If you press on 'ON/C' button it returns to the State_getNumber1 state to start a new calculation process.

To ensure that the Basic Calculator  operates correctly, follow these test procedures:

### Test Case 1: Arithmetic Operations

**Description:** Confirm that the results of arithmetic operations are correct.

**Test Steps:**

1. Build and flash the project to the microcontroller.
2. Enter the first number (e.g. 10), then press on an operator (e.g. +).
3. Enter the second number (e.g. 10), then press on '='.
3. Check the result of your operation.

**Expected Results:** The first number and the operator are displayed on the first row of the LCD, and the
second number and the '=' are displayed beside them, then the result is displayed correctly on the second row.

### Test Case 2: Zero-Division Error

**Description:** Confirm that the application gets an error message if we try to divide by zero.
**Test Steps:**

1. Build and flash the project to the microcontroller.
2. Enter the first number (e.g. 10), then press on '/' operator.
3. Enter zero as the second number, then press on '='.
4. Wait for the error message.

**Expected Results:** The LCD shows an error message for 1 sec, then starts to get a new operation.

### Test Case 3: Out-Of-Range Error

**Description:** Confirm that the application gets an error message if we try to fill the first row with numbers.
**Test Steps:**

1. Build and flash the project to the microcontroller.
2. Enter the first number till filling the first row of the LCD.
3. Wait for the error message.

**Expected Results:** The LCD shows an error message for 1 sec, then starts to get a new operation.

## Files

 - **Application:** Contains program application
 - **HAL:** Hardware abstraction layer: contains software related to any onboard hardware element
 - **MCAL:** Microcontroller abstraction layer: contains software related to any peripheral inside the microcontroller
 - **Utilities:** Contains my data types and some bit math operations

## Contact Information

If you have any questions, feedback, or encounter issues while using the Pressure Control System project, please don't hesitate to get in touch with us. We're here to help!

- **Email:** abdelruhman.m.kamal@gmail.com
- [Twitter](https://twitter.com/IAmAbdoKamal)
- [LinkedIn](https://www.linkedin.com/in/iamabdelrahmankamal/)


[Simple Calculator (ATMEGA32) - GIF]![untitled](https://github.com/IamAbdelrahman/Embedded-Systems-Diploma/assets/108472811/9fd2a99f-3cdf-4014-a335-d1d16b27d6d0)