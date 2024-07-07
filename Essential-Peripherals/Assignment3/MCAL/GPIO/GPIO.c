/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO.c
 * @brief The implementation for the GPIO
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
const ST_GPIO_t *const GPIOx[NUMBER_OF_PORTS] = {GPIOA, GPIOB, GPIOC, GPIOD};

/**
 * Defines a table of pointers to the Dio peripheral data, data direction
 * and input pin registers on the avr microcontroller.
 */
TYPE volatile *Data[NUMBER_OF_PORTS];
TYPE volatile *DataDir[NUMBER_OF_PORTS];
TYPE volatile *DataIn[NUMBER_OF_PORTS];

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/*********************************************************************
 * Function : initializeDataArrays()
 *
 * Description:
 *
 * This function is used to initialize Data, DataDir, and DataIn arrays
 * PRE-CONDITION: NUMBER_OF_PORTS > 0
 *
 * POST-CONDITION: The pointers to GPIO peripheral's registers
 * are set up with the corresponding initialization.
 *
 * @return void
 * **********************************************************************/
void initializeDataArrays() {
  for (int i = 0; i < NUMBER_OF_PORTS; ++i) {
    Data[i] = (TYPE *)&GPIOx[i]->PORT;
    DataDir[i] = (TYPE *)&GPIOx[i]->DDR;
    DataIn[i] = (TYPE *)&GPIOx[i]->PIN;
  }
}

/*********************************************************************
 * Function : GPIO_Init()
 *
 * Description:
 *
 * This function is used to initialize the GPIO based on the configuration
 * table defined in GPIO_cfg module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 * PRE-CONDITION: NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: NUMBER_OF_PORTS > 0
 *
 * POST-CONDITION: The GPIO peripheral is set up with the configuration
 * settings.
 *
 * @param Config is a pointer to the configuration table that
 * contains the initialization for the peripheral.
 *
 * @return void
 * **********************************************************************/
void GPIO_Init(const ST_GPIOConfig_t *const Config) {
  void initializeDataArrays();
  initializeDataArrays();
  vuint8_t i = 0;
  vuint8_t PortNumber = 0;
  vuint8_t PinNumber = 0;
  for (i = 0; i < NUMBER_OF_USED_PINS; i++) {
    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
    if (Config[i].State == GPIO_INPUT_FLOATING) {
      CLR_BIT(*(DataDir[PortNumber]), PinNumber);
      CLR_BIT(*(Data[PortNumber]), PinNumber);
    } else if (Config[i].State == GPIO_INPUT_PULLUP) {
      CLR_BIT(SFIOR, PUD);
      CLR_BIT(*(DataDir[PortNumber]), PinNumber);
      SET_BIT(*(Data[PortNumber]), PinNumber);
    } else if (Config[i].State == GPIO_OUTPUT) {
      SET_BIT(*(DataDir[PortNumber]), PinNumber);
    }
  }
}

/**********************************************************************
 * Function :GPIO_PinRead()
 *
 * Description:
 *
 * This function is used to read the state of a GPIO channel (pin)
 *
 * PRE-CONDITION: The channel is configured as INPUT
 * PRE-CONDITION: The channel is configured as GPIO
 * PRE-CONDITION: The channel is within the maximum GPIOPin_t
 * definition
 *
 * POST-CONDITION: The channel state is returned.
 * @param Port is the port of the pin to read from using the GPIOX_t enum
 *definition
 * @param Pin is the GPIOPin_t that represents a pin
 *
 * @return The state of the pin as HIGH or LOW
 **********************************************************************/
PinState_t GPIO_PinRead(EN_GPIOX_t Port, EN_GPIOPin_t Pin) {
  return (READ_BIT(*(DataIn[Port]), Pin));
}

/**********************************************************************
 * Function : GPIO_PinWrite()
 *
 *  Description:
 *  This function is used to write the state of a channel (pin) as either
 *  logic high or low through the use of the GPIOPin_t enum to select
 *  the channel and the State_t to define the desired state
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured as GPIO
 *  PRE-CONDITION: The channel is within the maximum GPIOPin_t definition
 *  POST-CONDITION: The channel state will be State
 * @param Port is the port of the pin to read from using the GPIOX_t enum
 *definition
 * @param Pin is the GPIOPin_t that represents a pinn
 *  @param State is HIGH or LOW as defined in the  State_t enum definition
 *  @return void
 **********************************************************************/
void GPIO_PinWrite(EN_GPIOX_t Port, EN_GPIOPin_t Pin, PinState_t state) {
  if (state == HIGH) {
    SET_BIT(*(Data[Port]), Pin);
  } else if (state == LOW) {
    CLR_BIT(*(Data[Port]), Pin);
  }
}

/**********************************************************************
 * Function : GPIO_PinToggle()
 *
 *  Description:
 *  This function is used to toggle the state of a channel (pin) as either
 *  logic high or low through the use of the GPIOPin_t enum
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured as GPIO
 *  PRE-CONDITION: The channel is within the maximum GPIOPin_t definition

 * @param Port is the port of the pin to read from using the GPIOX_t enum
 definition
 * @param Pin is the GPIOPin_t that represents a pinn

 *  @return void
 **********************************************************************/
void GPIO_PinToggle(EN_GPIOX_t Port, EN_GPIOPin_t Pin) {
  TOGGLE_BIT(*(Data[Port]), Pin);
}

/**********************************************************************
 * Function : GPIO_Reset()
 *
 *  Description:
 *  This function is used to reset all the GPIO Registers

 *  @param Port is the port to be reset using the GPIOX_t enum definition

 *  @return void
 **********************************************************************/
void GPIO_Reset(EN_GPIOX_t Port) {
  *(Data[Port]) = 0x00;
  *(DataDir[Port]) = 0x00;
}

/**********************************************************************
 * Function : GPIO_ReadPort()
 *
 *  Description:
 *  This function is used to read the whole PIN register in GPIO

 *  @param Port is the port to be read using the GPIOX_t enum definition

 *  @return the value of the 16-bit register
 **********************************************************************/
vuint8_t GPIO_ReadPort(EN_GPIOX_t Port) { return (vuint8_t)(*DataIn[Port]); }

/**********************************************************************
 * Function : GPIO_WritePort()
 *
 *  Description:
 *  This function is used to write to  the whole PORT register in GPIO

 *  @param Port is the port to be written using the GPIOX_t enum definition
 *  @param PortValue is the value we write to the port.

 *  @return void
 **********************************************************************/
void GPIO_WritePort(EN_GPIOX_t Port, vuint8_t PortValue) {
  *(Data[Port]) = PortValue;
}
