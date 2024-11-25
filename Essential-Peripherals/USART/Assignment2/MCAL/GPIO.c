/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: GPIO.c
 *	@brief The implementation for the GPIO.
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "inc/GPIO.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/
/*- USED PINS ACCORDING TO THE APPLICATION */
#define NUMBER_OF_USED_PINS (11UL)

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
/*- DEFINE AN ARRAY OF GPIO INSTANCES */
static const ST_GPIO_t *const GPIOx[NUMBER_OF_PORTS] = {GPIOA, GPIOB, GPIOC,
                                                        GPIOD};

/*- DEFINE A TABLE OF POINTER TO THE RESET REGISTER */
static TYPE volatile *const reset[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->BRR, (TYPE *)&GPIOx[1]->BRR, (TYPE *)&GPIOx[2]->BRR,
    (TYPE *)&GPIOx[3]->BRR};

/*- DEFINE A TABLE OF POINTER TO THE SET_RESET REGISTER */
static TYPE volatile *const setReset[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->BSRR, (TYPE *)&GPIOx[1]->BSRR, (TYPE *)&GPIOx[2]->BSRR,
    (TYPE *)&GPIOx[3]->BSRR};

/*- DEFINE A TABLE OF POINTER TO THE LOCK REGISTER */
static TYPE volatile *const lock[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->LCKR, (TYPE *)&GPIOx[1]->LCKR, (TYPE *)&GPIOx[2]->LCKR,
    (TYPE *)&GPIOx[3]->LCKR};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
/*- DEFINE A TABLE OF POINTER TO THE INPUT REGISTER */
TYPE volatile *const dataIn[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->IDR, (TYPE *)&GPIOx[1]->IDR, (TYPE *)&GPIOx[2]->IDR,
    (TYPE *)&GPIOx[3]->IDR};

/*- DEFINE A TABLE OF POINTER TO THE OUTPUT REGISTER */
TYPE volatile *const dataOut[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->ODR, (TYPE *)&GPIOx[1]->ODR, (TYPE *)&GPIOx[2]->ODR,
    (TYPE *)&GPIOx[3]->ODR};

/*- DEFINE A TABLE OF POINTER TO THE CFG_LOW REGISTER */
TYPE volatile *const configLow[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->CRL, (TYPE *)&GPIOx[1]->CRL, (TYPE *)&GPIOx[2]->CRL,
    (TYPE *)&GPIOx[3]->CRL};

/*- DEFINE A TABLE OF POINTER TO THE CFG_HIGH REGISTER */
TYPE volatile *const configHigh[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->CRH, (TYPE *)&GPIOx[1]->CRH, (TYPE *)&GPIOx[2]->CRH,
    (TYPE *)&GPIOx[3]->CRH};

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern vuint32_t ConfigSizeGpio;

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
vuint8_t GetPosition(vuint8_t pinNumber);
void ClearConfig(uint8_t portNumber, uint8_t pinNumber, uint8_t position);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
vuint8_t GetPosition(vuint8_t pinNumber) {
  switch (pinNumber) {
  case GPIO_PIN0:
    return 0;
    break;
  case GPIO_PIN1:
    return 4;
    break;
  case GPIO_PIN2:
    return 8;
    break;
  case GPIO_PIN3:
    return 12;
    break;
  case GPIO_PIN4:
    return 16;
    break;
  case GPIO_PIN5:
    return 20;
    break;
  case GPIO_PIN6:
    return 24;
    break;
  case GPIO_PIN7:
    return 28;
    break;
  case GPIO_PIN8:
    return 0;
    break;
  case GPIO_PIN9:
    return 4;
    break;
  case GPIO_PIN10:
    return 8;
    break;
  case GPIO_PIN11:
    return 12;
    break;
  case GPIO_PIN12:
    return 16;
    break;
  case GPIO_PIN13:
    return 20;
    break;
  case GPIO_PIN14:
    return 24;
    break;
  case GPIO_PIN15:
    return 28;
    break;
  default:
    break;
  }
  return 0;
}

void ClearConfig(uint8_t portNumber, uint8_t pinNumber, uint8_t position) {
  if (pinNumber < 8) {
    switch (portNumber) {
    case 0:
      CLR_NIBBLE((*configLow[0]), position);
      break;
    case 1:
      CLR_NIBBLE((*configLow[1]), position);
      break;
    case 2:
      CLR_NIBBLE((*configLow[2]), position);
      break;
    case 3:
      CLR_NIBBLE((*configLow[3]), position);
      break;
    default:
      break;
    }
  } else {
    switch (portNumber) {
    case 0:
      CLR_NIBBLE((*configLow[0]), position);
      break;
    case 1:
      CLR_NIBBLE((*configLow[1]), position);
      break;
    case 2:
      CLR_NIBBLE((*configLow[2]), position);
      break;
    case 3:
      CLR_NIBBLE((*configLow[3]), position);
      break;
    default:
      break;
    }
  }
}

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: GPIO_Init
 * Synatax: void GPIO_Init(const ST_GPIOConfig_t *configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize the GPIO based on the config table defined in
 *GPIO_Cfg PRE-CONDITION: Config table needs to populated (configGpio > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: The MCU clock must be configured and enabled
 * POST-CONDITION: The GPIO is initialized and set up with the defined
 *configuration
 * @param (in): configPtr a pointer to GPIO_Config struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_Init(const ST_GPIOConfig_t *configPtr) {
  vuint8_t i = 0, localPortNumber = 0, localPinNumber = 0, localPinCfg = 0;
  for (i = 0; i < NUMBER_OF_USED_PINS; i++) {
    localPortNumber = configPtr[i].portNumber % NUMBER_OF_PORTS;
    localPinNumber = configPtr[i].pinNumber % NUMBER_OF_PINS_PER_PORT;

    vuint8_t position = GetPosition(localPinNumber);
    ClearConfig(localPortNumber, localPinNumber, position);
    if (configPtr[i].pinState == GPIO_OUTPUT_PUSHPULL ||
        configPtr[i].pinState == GPIO_OUTPUT_OPENDRAIN ||
        configPtr[i].pinState == GPIO_ALTERNATE_PUSHPULL ||
        configPtr[i].pinState == GPIO_ALTERNATE_OPENDRAIN) {
      localPinCfg =
          ((((configPtr[i].pinState - 4) << 2) | (configPtr[i].pinMode)) &
           0x0f);
      if (configPtr[i].pinNumber < 8) {
        *(configLow[localPortNumber]) |= ((localPinCfg) << position);
      } else {
        *(configHigh[localPortNumber]) |= ((localPinCfg) << position);
      }
    } else if (configPtr[i].pinState == GPIO_INPUT_ANALOG) {
      localPinCfg = (configPtr[i].pinState << 2) | 0x00;
      if (configPtr[i].pinNumber < 8) {
        *(configLow[localPortNumber]) |= (localPinCfg << position);
      } else {
        *(configHigh[localPortNumber]) |= (localPinCfg << position);
      }
    } else if (configPtr[i].pinState == GPIO_INPUT_FLOATING) {
      localPinCfg = (configPtr[i].pinState << 2) | 0x00;
      if (configPtr[i].pinNumber < 8) {
        *(configLow[localPortNumber]) |= (localPinCfg << position);
      } else {
        *(configHigh[localPortNumber]) |= (localPinCfg << position);
      }
    } else {
      localPinCfg = (GPIO_INPUT_PULLUP << 2) | 0x00;
      if (configPtr[i].pinNumber < 8) {
        *(configLow[localPortNumber]) |= (localPinCfg << position);
        if (configPtr[i].pinState == GPIO_INPUT_PULLUP) {
          SET_BIT(*(dataOut[localPortNumber]), configPtr[i].pinNumber);
        } else if (configPtr[i].pinState == GPIO_INPUT_PULLDOWN) {
          CLR_BIT(*(dataOut[localPortNumber]), configPtr[i].pinNumber);
        }
      } else {
        *(configHigh[localPortNumber]) |= (localPinCfg << position);
        if (configPtr[i].pinState == GPIO_INPUT_PULLUP) {
          SET_BIT(*(dataOut[localPortNumber]), configPtr[i].pinNumber);
        } else if (configPtr[i].pinState == GPIO_INPUT_PULLDOWN) {
          CLR_BIT(*(dataOut[localPortNumber]), configPtr[i].pinNumber);
        }
      }
    }
  }
}

/************************************************************************
 * Service Name: GPIO_PinRead
 * Synatax: EN_PIN_STATE_t GPIO_PinRead(EN_GPIOX_t portNumber, EN_GPIO_PIN_t
 *pinNumber) Sync/Async: Synchronous Reentrancy: Non reentrant
 * @description: Read the state of a GPIO channel (pin)
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The channel (pin) state is returned
 * @param (in): portNumber to be set by the user
 * @param (in): pinNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: EN_PIN_STATE_t an enum state is returned
 *************************************************************************/
EN_PIN_STATE_t GPIO_PinRead(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber) {
  EN_PIN_STATE_t state;
  state = READ_BIT(*(dataIn[portNumber]), pinNumber);
  return state;
}

/************************************************************************
 * Service Name: GPIO_PinWrite
 * Synatax: void GPIO_PinWrite(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber,
 *EN_PIN_STATE_t state) Sync/Async: Synchronous Reentrancy: Non reentrant
 * @description: Write the state of a GPIO channel (pin) as either logic high or
 *low PRE-CONDITION: The GPIO is configured and initialized POST-CONDITION: The
 *channel (pin) has a logic level (1 or 0)
 * @param (in): portNumber to be set by the user
 * @param (in): pinNumber to be set by the user
 * @param (in): pinState the pin level as either logic high or low
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_PinWrite(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber, EN_PIN_STATE_t pinState) {
  if (pinState == HIGH) {
    SET_BIT(*(dataOut[portNumber]), pinNumber);
  } else {
    CLR_BIT(*(dataOut[portNumber]), pinNumber);
  }
}

/************************************************************************
 * Service Name: GPIO_PinToggle
 * Synatax: void GPIO_PinToggle(EN_GPIOX_t portNumber, EN_GPIOPin_t pinNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Toggle the state of a channel (pin) as either logic high or low
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The channel (pin) changes its logic level
 * @param (in): port number to be set by the user
 * @param (in): pinNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_PinToggle(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber) {
  TOGGLE_BIT(*(dataOut[portNumber]), pinNumber);
}

/************************************************************************
 * Service Name: GPIO_Reset
 * Synatax: void GPIO_Reset(EN_GPIOX_t portNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset all the GPIO registers
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The GPIO registers are reset
 * @param (in): portNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void GPIO_Reset(EN_GPIOX_t portNumber) {
  *(configLow[portNumber])  = 0x44444444;
  *(configHigh[portNumber]) = 0x44444444;
  *(dataOut[portNumber])    = 0x00000000;
  *(reset[portNumber])      = 0x00000000;
  *(setReset[portNumber])   = 0x00000000;
  *(lock[portNumber])       = 0x00000000;
  RCC_ModuleReset(portNumber);
}

/************************************************************************
 * Service Name: GPIO_PortRead
 * Synatax: vuint16_t GPIO_PortRead(EN_GPIOX_t portNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Read the IDR register in the GPIO
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The IDR register content is returned
 * @param (in): portNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned short int
 *************************************************************************/
vuint16_t GPIO_PortRead(EN_GPIOX_t portNumber) {
  return (vuint16_t) * (dataIn[portNumber]);
}

/************************************************************************
 * Service Name: GPIO_PortWrite
 * Synatax: void GPIO_PortWrite(EN_GPIOX_t portNumber, vuint16_t portValue)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Write to the ODR register in the GPIO
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The ODR register in the GPIO has a new value
 * @param (in): portNumber to be set by the user
 * @param (in): portValue is the value to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned short int
 *************************************************************************/
void GPIO_PortWrite(EN_GPIOX_t portNumber, vuint16_t portValue) {
  *(dataOut[portNumber]) = portValue;
}

/************************************************************************
 * Service Name: GPIO_LockPort
 * Synatax: EN_GPIO_LOCK_STATE_t GPIO_LockPin(EN_GPIOX_t portNumber,
 *EN_GPIO_PIN_t pin) Sync/Async: Synchronous Reentrancy: Non reentrant
 * @description: Lock a pin of the GPIO register
 * PRE-CONDITION: The GPIO is configured and initialized
 * POST-CONDITION: The pin is locked correctly or not
 * @param (in): portNumber to be set by the user
 * @param (in): pinNumber to be set by the user
 * @param (inout): None
 * @param (out): None
 * @return: EN_GPIO_LOCK_STATE_t as it returns the state of the lock
 *************************************************************************/
EN_GPIO_LOCK_STATE_t GPIO_LockPin(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber) {
  SET_BIT(*(lock[portNumber]), pinNumber);
  SET_BIT(*(lock[portNumber]), 0x10);
  CLR_BIT(*(lock[portNumber]), 0x10);
  SET_BIT(*(lock[portNumber]), 0x10);
  if (READ_BIT(*(lock[portNumber]), 0x10)) {
    return GPIO_LOCK_Enabled;
  } else {
    return GPIO_LOCK_ERROR;
  }
}
