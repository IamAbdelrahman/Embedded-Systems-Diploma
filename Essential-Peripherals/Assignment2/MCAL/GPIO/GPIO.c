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
#include <GPIO.h>

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
extern vuint32_t ConfigSize;
const ST_GPIO_t *const GPIOx[NUMBER_OF_PORTS] = {GPIOA, GPIOB, GPIOC, GPIOD};
ST_RCC_t *pRCC = RCC;

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define NUMBER_OF_USED_PINS (11U) /** According to the application **/

//-*-*-*-*-*-*-*-*-*-*-*-
// clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN() (SET_BIT(pRCC->APB2ENR, 2))
#define RCC_GPIOB_CLK_EN() (SET_BIT(pRCC->APB2ENR, 3))
#define RCC_GPIOC_CLK_EN() (SET_BIT(pRCC->APB2ENR, 4))
#define RCC_GPIOD_CLK_EN() (SET_BIT(pRCC->APB2ENR, 5))

/**
 * Defines a table of pointers to the peripheral input register on the
 * microcontroller.
 */
static TYPE volatile *const DataIn[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->IDR, (TYPE *)&GPIOx[1]->IDR, (TYPE *)&GPIOx[2]->IDR,
    (TYPE *)&GPIOx[3]->IDR};

/**
 * Defines a table of pointers to the peripheral output register on the
 * microcontroller.
 */
TYPE volatile *const DataOut[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->ODR, (TYPE *)&GPIOx[1]->ODR, (TYPE *)&GPIOx[2]->ODR,
    (TYPE *)&GPIOx[3]->ODR};

/**
 * Defines a table of pointers to the peripheral input register on the
 * microcontroller.
 */
TYPE volatile *const ConfigLow[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->CRL, (TYPE *)&GPIOx[1]->CRL, (TYPE *)&GPIOx[2]->CRL,
    (TYPE *)&GPIOx[3]->CRL};

/**
 * Defines a table of pointers to the peripheral input register on the
 * microcontroller.
 */
TYPE volatile *const ConfigHigh[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->CRH, (TYPE *)&GPIOx[1]->CRH, (TYPE *)&GPIOx[2]->CRH,
    (TYPE *)&GPIOx[3]->CRH};

/**
 * Defines a table of pointers to the peripheral reset register on the
 * microcontroller.
 */
static TYPE volatile *const Reset[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->BRR, (TYPE *)&GPIOx[1]->BRR, (TYPE *)&GPIOx[2]->BRR,
    (TYPE *)&GPIOx[3]->BRR};

/**
 * Defines a table of pointers to the peripheral set/reset register on the
 * microcontroller.
 */
static TYPE volatile *const SetReset[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->BSRR, (TYPE *)&GPIOx[1]->BSRR, (TYPE *)&GPIOx[2]->BSRR,
    (TYPE *)&GPIOx[3]->BSRR};

/**
 * Defines a table of pointers to the peripheral lock register on the
 * microcontroller.
 */
static TYPE volatile *const Lock[NUMBER_OF_PORTS] = {
    (TYPE *)&GPIOx[0]->LCKR, (TYPE *)&GPIOx[1]->LCKR, (TYPE *)&GPIOx[2]->LCKR,
    (TYPE *)&GPIOx[3]->LCKR};

/**********************************************************************
 * Function : Clock_Init()
 *
 *  Description:
 *  This function is used to enable the APB2 GPIO peripherals clocks

 *  @return void
 **********************************************************************/
void Clock_Init() {
  RCC_GPIOA_CLK_EN();
  RCC_GPIOB_CLK_EN();
  RCC_GPIOC_CLK_EN();
  RCC_GPIOD_CLK_EN();
}
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/*********************************************************************
 * Function : Get_CRLH_Position()
 *
 * Description:
 *
 * This function is used to get the bit's position according to
 * the GPIO pin.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 * PRE-CONDITION: NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: NUMBER_OF_PORTS > 0
 * PRE-CONDITION: The MCU clocks must be configured and enabled.
 *
 * POST-CONDITION: The position of the pin is known.
 *
 * @param PinNumber is a variable to store the pin number.
 *
 * @return uint8_t
 * **********************************************************************/
uint8_t Get_CRLH_Position(uint8_t PinNumber) {
  switch (PinNumber) {
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
  }
  return 0;
}

void Clear_Cfg(uint8_t PortNumber, uint8_t PinNumber, uint8_t Position) {
  if (PinNumber < 8) {
    switch (PortNumber) {
    case 0:
      CLR_NIBBLE((*ConfigLow[0]), Position);
      break;
    case 1:
      CLR_NIBBLE((*ConfigLow[1]), Position);
      break;
    case 2:
      CLR_NIBBLE((*ConfigLow[2]), Position);
      break;
    case 3:
      CLR_NIBBLE((*ConfigLow[3]), Position);
      break;
    default:
      break;
    }
  } else {
    switch (PortNumber) {
    case 0:
      CLR_NIBBLE((*ConfigLow[0]), Position);
      break;
    case 1:
      CLR_NIBBLE((*ConfigLow[1]), Position);
      break;
    case 2:
      CLR_NIBBLE((*ConfigLow[2]), Position);
      break;
    case 3:
      CLR_NIBBLE((*ConfigLow[3]), Position);
      break;
    default:
      break;
    }
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
 * PRE-CONDITION: The MCU clocks must be configured and enabled.
 *
 * POST-CONDITION: The GPIO peripheral is set up with the configuration
 * settings.
 *
 * @param Config is a pointer to the configuration table that
 * contains the initialization for the peripheral.
 *
 * @return void
 * **********************************************************************/
void GPIO_Init(const ST_GPIOConfig_t *Config) {
  vuint8_t i = 0, PortNumber = 0, PinNumber = 0, PinConfig = 0;
  for (i = 0; i < NUMBER_OF_USED_PINS; i++) {
    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;

    vuint8_t Position = Get_CRLH_Position(PinNumber);
    Clear_Cfg(PortNumber, PinNumber, Position);
    if (Config[i].State == GPIO_OUTPUT_PUSHPULL ||
        Config[i].State == GPIO_OUTPUT_OPENDRAIN ||
        Config[i].State == GPIO_ALTERNATE_PUSHPULL ||
        Config[i].State == GPIO_ALTERNATE_OPENDRAIN) {
      PinConfig = ((((Config[i].State - 4) << 2) | (Config[i].Mode)) & 0x0f);
      if (Config[i].Pin < 8) {
        *(ConfigLow[PortNumber]) |= ((PinConfig) << Position);
      } else {
        *(ConfigHigh[PortNumber]) |= ((PinConfig) << Position);
      }
    } else if (Config[i].State == GPIO_INPUT_ANALOG) {
      PinConfig = (Config[i].State << 2) | 0x00;
      if (Config[i].Pin < 8) {
        *(ConfigLow[PortNumber]) |= (PinConfig << Position);
      } else {
        *(ConfigHigh[PortNumber]) |= (PinConfig << Position);
      }
    } else if (Config[i].State == GPIO_INPUT_FLOATING) {
      PinConfig = (Config[i].State << 2) | 0x00;
      if (Config[i].Pin < 8) {
        *(ConfigLow[PortNumber]) |= (PinConfig << Position);
      } else {
        *(ConfigHigh[PortNumber]) |= (PinConfig << Position);
      }
    } else {
      PinConfig = (GPIO_INPUT_PULLUP << 2) | 0x00;
      if (Config[i].Pin < 8) {
        *(ConfigLow[PortNumber]) |= (PinConfig << Position);
        if (Config[i].State == GPIO_INPUT_PULLUP) {
          SET_BIT(*(DataOut[PortNumber]), Config[i].Pin);
        } else if (Config[i].State == GPIO_INPUT_PULLDOWN) {
          CLR_BIT(*(DataOut[PortNumber]), Config[i].Pin);
        }
      } else {
        *(ConfigHigh[PortNumber]) |= (PinConfig << Position);
        if (Config[i].State == GPIO_INPUT_PULLUP) {
          SET_BIT(*(DataOut[PortNumber]), Config[i].Pin);
        } else if (Config[i].State == GPIO_INPUT_PULLDOWN) {
          CLR_BIT(*(DataOut[PortNumber]), Config[i].Pin);
        }
      }
    }
  }
}

/**********************************************************************
 * Function :GPIO_ChannelRead()
 *
 * Description:
 *
 * This function is used to read the state of a GPIO channel (pin)
 *
 * PRE-CONDITION: The channel is configured as INPUT
 * PRE-CONDITION: The channel is configured as GPIO
 * PRE-CONDITION: The channel is within the maximum GPIOChannel_t
 * definition
 *
 * POST-CONDITION: The channel state is returned.
 * @param Port is the port of the pin to read from using the GPIOX_t enum
 *definition
 * @param Pin is the GPIOChannel_t that represents a pin
 *
 * @return The state of the pin as HIGH or LOW
 **********************************************************************/
PinState_t GPIO_PinRead(EN_GPIOX_t Port, EN_GPIOPin_t Pin) {
  PinState_t state;
  state = READ_BIT(*(DataIn[Port]), Pin);
  return state;
}

/**********************************************************************
 * Function : GPIO_PinWrite()
 *
 *  Description:
 *  This function is used to write the state of a channel (pin) as either
 *  logic high or low through the use of the GPIOPin_t enum to select
 *  the channel and the PinState_t to define the desired state
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured as GPIO
 *  PRE-CONDITION: The channel is within the maximum GPIOPin_t definition
 *  POST-CONDITION: The channel state will be State
 *  @param Port is the port of the pin to write using the GPIOX_t enum
 *definition
 *  @param Pin is the pin to write using the GPIOPin_t enum definition
 *  @param State is HIGH or LOW as defined in the  PinState_t enum definition
 *  @return void
 **********************************************************************/
void GPIO_PinWrite(EN_GPIOX_t Port, EN_GPIOPin_t Pin, PinState_t State) {
  if (State == HIGH) {
    SET_BIT(*(DataOut[Port]), Pin);
  } else {
    CLR_BIT(*(DataOut[Port]), Pin);
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

 *  @param Port is the port of the pin to write using the GPIOX_t enum
 definition
 *  @param Pin is the pin to write using the GPIOPin_t enum definition

 *  @return void
 **********************************************************************/
void GPIO_PinToggle(EN_GPIOX_t Port, EN_GPIOPin_t Pin) {
  TOGGLE_BIT(*(DataOut[Port]), Pin);
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
  *(ConfigLow[Port]) 	= 0x44444444;
  *(ConfigHigh[Port]) 	= 0x44444444;
  *(DataOut[Port]) 	= 0x00000000;
  *(Reset[Port]) 	= 0x00000000;
  *(SetReset[Port]) 	= 0x00000000;
  *(Lock[Port]) 	= 0x00000000;
}

/**********************************************************************
 * Function : GPIO_ReadPort()
 *
 *  Description:
 *  This function is used to read the whole IDR register in GPIO

 *  @param Port is the port to be read using the GPIOX_t enum definition

 *  @return the value of the 16-bit register
 **********************************************************************/
uint16_t GPIO_ReadPort(EN_GPIOX_t Port) { return (vuint16_t) * (DataIn[Port]); }

/**********************************************************************
 * Function : GPIO_WritePort()
 *
 *  Description:
 *  This function is used to write to  the whole ODR register in GPIO

 *  @param Port is the port to be written using the GPIOX_t enum definition
 *  @param PortValue is the value we write to the port.

 *  @return void
 **********************************************************************/
void GPIO_WritePort(EN_GPIOX_t Port, vuint16_t PortValue) {
  *(DataOut[Port]) = PortValue;
}

/**********************************************************************
 * Function : GPIO_LockPort()
 *
 *  Description:
 *  This function is used to lock a bit of the GPIO register

 *  @param Port is the port number using the GPIOX_t enum definition
 *  @param Pin is the pin to be locked using the GPIOPin_t enum definition

 *  @return the state of the pin whether it's locked or not
 **********************************************************************/
EN_GPIOLockState_t GPIO_LockPort(EN_GPIOX_t Port, EN_GPIOPin_t Pin) {
  SET_BIT(*(Lock[Port]), Pin);
  SET_BIT(*(Lock[Port]), 16);
  CLR_BIT(*(Lock[Port]), 16);
  SET_BIT(*(Lock[Port]), 16);
  if (READ_BIT(*(Lock[Port]), 16)) {
    return GPIO_LOCK_Enabled;
  } else {
    return GPIO_LOCK_ERROR;
  }
}
