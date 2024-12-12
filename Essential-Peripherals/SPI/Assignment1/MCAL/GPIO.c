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
#include "../inc/GPIO.h"

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/
/*- USED PINS ACCORDING TO THE APPLICATION */
#define NUMBER_OF_USED_PINS (11UL)

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE AN ARRAY OF GPIO INSTANCES */
static const ST_GPIO_t *const GPIOx[NUMBER_OF_PORTS] = { GPIOA, GPIOB, GPIOC,
GPIOD };

/*- DEFINE A TABLE OF POINTER TO THE RESET REGISTER */
static TYPE volatile *const reset[NUMBER_OF_PORTS] = { (TYPE*) &GPIOx[0]->BRR,
		(TYPE*) &GPIOx[1]->BRR, (TYPE*) &GPIOx[2]->BRR, (TYPE*) &GPIOx[3]->BRR };

/*- DEFINE A TABLE OF POINTER TO THE SET_RESET REGISTER */
static TYPE volatile *const setReset[NUMBER_OF_PORTS] = {
		(TYPE*) &GPIOx[0]->BSRR, (TYPE*) &GPIOx[1]->BSRR,
		(TYPE*) &GPIOx[2]->BSRR, (TYPE*) &GPIOx[3]->BSRR };

/*- DEFINE A TABLE OF POINTER TO THE LOCK REGISTER */
static TYPE volatile *const lock[NUMBER_OF_PORTS] = { (TYPE*) &GPIOx[0]->LCKR,
		(TYPE*) &GPIOx[1]->LCKR, (TYPE*) &GPIOx[2]->LCKR,
		(TYPE*) &GPIOx[3]->LCKR };

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE A TABLE OF POINTER TO THE INPUT REGISTER */
TYPE volatile *const dataIn[NUMBER_OF_PORTS] = { (TYPE*) &GPIOx[0]->IDR,
		(TYPE*) &GPIOx[1]->IDR, (TYPE*) &GPIOx[2]->IDR, (TYPE*) &GPIOx[3]->IDR };

/*- DEFINE A TABLE OF POINTER TO THE OUTPUT REGISTER */
TYPE volatile *const dataOut[NUMBER_OF_PORTS] = { (TYPE*) &GPIOx[0]->ODR,
		(TYPE*) &GPIOx[1]->ODR, (TYPE*) &GPIOx[2]->ODR, (TYPE*) &GPIOx[3]->ODR };

/*- DEFINE A TABLE OF POINTER TO THE CFG_LOW REGISTER */
TYPE volatile *const configLow[NUMBER_OF_PORTS] = { (TYPE*) &GPIOx[0]->CRL,
		(TYPE*) &GPIOx[1]->CRL, (TYPE*) &GPIOx[2]->CRL, (TYPE*) &GPIOx[3]->CRL };

/*- DEFINE A TABLE OF POINTER TO THE CFG_HIGH REGISTER */
TYPE volatile *const configHigh[NUMBER_OF_PORTS] = { (TYPE*) &GPIOx[0]->CRH,
		(TYPE*) &GPIOx[1]->CRH, (TYPE*) &GPIOx[2]->CRH, (TYPE*) &GPIOx[3]->CRH };

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/
extern vuint32_t configSizeGpio;

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/
vuint8_t GetPosition(vuint8_t pinNumber);
void ClearConfig(uint8_t portNumber, uint8_t pinNumber, uint8_t Position);

/*- LOCAL (HELPER) FUNCTIONS IMPLEMENTATION
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

void ClearConfig(uint8_t portNumber, uint8_t pinNumber, uint8_t Position) {
	if (pinNumber < 8) {
		switch (portNumber) {
		case 0:
			CLR_NIBBLE((*configLow[0]), Position);
			break;
		case 1:
			CLR_NIBBLE((*configLow[1]), Position);
			break;
		case 2:
			CLR_NIBBLE((*configLow[2]), Position);
			break;
		case 3:
			CLR_NIBBLE((*configLow[3]), Position);
			break;
		default:
			break;
		}
	} else {
		switch (portNumber) {
		case 0:
			CLR_NIBBLE((*configLow[0]), Position);
			break;
		case 1:
			CLR_NIBBLE((*configLow[1]), Position);
			break;
		case 2:
			CLR_NIBBLE((*configLow[2]), Position);
			break;
		case 3:
			CLR_NIBBLE((*configLow[3]), Position);
			break;
		default:
			break;
		}
	}
}

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
void GPIO_Init(const ST_GPIOConfig_t * const configPtr, vuint8_t configSize) {
  vuint8_t i = 0, localPortNumber = 0, localPinNumber = 0, localPinCfg = 0;
  for (i = 0; i < configSize; i++) {
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

EN_PIN_STATE_t GPIO_PinRead(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber) {
	EN_PIN_STATE_t state;
	state = READ_BIT(*(dataIn[portNumber]), pinNumber);
	return state;
}

void GPIO_PinWrite(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber,
		EN_PIN_STATE_t pinState) {
	if (pinState == HIGH) {
		SET_BIT(*(dataOut[portNumber]), pinNumber);
	} else {
		CLR_BIT(*(dataOut[portNumber]), pinNumber);
	}
}

void GPIO_PinToggle(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber) {
	TOGGLE_BIT(*(dataOut[portNumber]), pinNumber);
}

void GPIO_Reset(EN_GPIOX_t portNumber) {
	*(configLow[portNumber]) = 0x44444444;
	*(configHigh[portNumber]) = 0x44444444;
	*(dataOut[portNumber]) = 0x00000000;
	*(reset[portNumber]) = 0x00000000;
	*(setReset[portNumber]) = 0x00000000;
	*(lock[portNumber]) = 0x00000000;
	RCC_ModuleReset(portNumber);
}

vuint16_t GPIO_PortRead(EN_GPIOX_t portNumber) {
	return (vuint16_t) *(dataIn[portNumber]);
}

void GPIO_PortWrite(EN_GPIOX_t portNumber, vuint16_t portValue) {
	*(dataOut[portNumber]) = portValue;
}

EN_GPIO_LOCK_STATE_t GPIO_LockPin(EN_GPIOX_t portNumber,
		EN_GPIO_PIN_t pinNumber) {
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
