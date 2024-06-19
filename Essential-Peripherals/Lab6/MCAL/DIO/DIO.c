/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file DIO.c
 * @brief The implementation for the GPIO
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
const ST_DIO_t *const DIOx[NUMBER_OF_PORTS] = {DIOA, DIOB, DIOC, DIOD};

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
 * POST-CONDITION: The pointers to DIO peripheral's registers
 * are set up with the corresponding initialization.
 *
 * @return void
 * **********************************************************************/
void initializeDataArrays() {
  for (int i = 0; i < NUMBER_OF_PORTS; ++i) {
    Data[i] = (TYPE *)&DIOx[i]->PORT;
    DataDir[i] = (TYPE *)&DIOx[i]->DDR;
    DataIn[i] = (TYPE *)&DIOx[i]->PIN;
  }
}

/*********************************************************************
 * Function : DIO_Init()
 *
 * Description:
 *
 * This function is used to initialize the DIO based on the configuration
 * table defined in Dio_cfg module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 * PRE-CONDITION: NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: NUMBER_OF_PORTS > 0
 *
 * POST-CONDITION: The DIO peripheral is set up with the configuration
 * settings.
 *
 * @param Config is a pointer to the configuration table that
 * contains the initialization for the peripheral.
 *
 * @return void
 * **********************************************************************/
void DIO_Init(const ST_GpioConfig_t *const Config) {
  void initializeDataArrays();
  initializeDataArrays();
  vuint8_t i = 0;
  vuint8_t PortNumber = 0;
  vuint8_t PinNumber = 0;
  for (i = 0; i < NUMBER_OF_USED_PINS; i++) {
    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
    if (Config[i].State == DIO_INPUT_FLOATING) {
      CLR_BIT(*(DataDir[PortNumber]), PinNumber);
      CLR_BIT(*(Data[PortNumber]), PinNumber);
    } else if (Config[i].State == DIO_INPUT_PULLUP) {
      CLR_BIT(SFIOR, PUD);
      CLR_BIT(*(DataDir[PortNumber]), PinNumber);
      SET_BIT(*(Data[PortNumber]), PinNumber);
    } else if (Config[i].State == DIO_OUTPUT) {
      SET_BIT(*(DataDir[PortNumber]), PinNumber);
    }
  }
}

/**********************************************************************
 * Function :DIO_PinRead()
 *
 * Description:
 *
 * This function is used to read the state of a DIO channel (pin)
 *
 * PRE-CONDITION: The channel is configured as INPUT
 * PRE-CONDITION: The channel is configured as DIO
 * PRE-CONDITION: The channel is within the maximum DIOPin_t
 * definition
 *
 * POST-CONDITION: The channel state is returned.
 * @param Port is the port of the pin to read from using the GpioX_t enum
 *definition
 * @param Pin is the GpioPin_t that represents a pin
 *
 * @return The state of the pin as HIGH or LOW
 **********************************************************************/
EN_State_t DIO_PinRead(EN_GpioX_t Port, EN_GpioPin_t Pin) {
  return (READ_BIT(*(DataIn[Port]), Pin));
}

/**********************************************************************
 * Function : DIO_PinWrite()
 *
 *  Description:
 *  This function is used to write the state of a channel (pin) as either
 *  logic high or low through the use of the GpioPin_t enum to select
 *  the channel and the State_t to define the desired state
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition
 *  POST-CONDITION: The channel state will be State
 * @param Port is the port of the pin to read from using the GpioX_t enum
 *definition
 * @param Pin is the GpioPin_t that represents a pinn
 *  @param State is HIGH or LOW as defined in the  State_t enum definition
 *  @return void
 **********************************************************************/
void DIO_PinWrite(EN_GpioX_t Port, EN_GpioPin_t Pin, EN_State_t state) {
  if (state == HIGH) {
    SET_BIT(*(Data[Port]), Pin);
  } else if (state == LOW) {
    CLR_BIT(*(Data[Port]), Pin);
  }
}

/**********************************************************************
 * Function : DIO_WritePort()
 *
 *  Description:
 *  This function is used to write to  the whole PORT register in DIO

 *  @param Port is the port to be written using the GpioX_t enum definition
 *  @param PortValue is the value we write to the port.

 *  @return void
 **********************************************************************/
void DIO_WritePort(EN_GpioX_t Port, vuint8_t PortValue) {
  *(Data[Port]) = PortValue;
}