/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file EXTI.c
 * @brief The implementation for the EXTI peripheral.
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "EXTI.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
/**********************************************************************
 * Typedefs
 **********************************************************************/

/**********************************************************************
 * Module Variables
 **********************************************************************/
/**
 * Define const pointers to EXTI and AFIO peripherals
 */
ST_EXTI_t *const pEXTI = EXTI;
ST_AFIO_t *const pAFIO = AFIO;

/**
 * Declare the EXTI_ConfigSize
 */
extern vuint32_t EXTI_ConfigSize;

/**
 * Declara an array of 15 global pointers to function
 * takes void and returns void.
 */
void (*gPf_IRQ_Callback[15])(void);

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function :EXTI_Init()
 *
 * Description:
 *
 * This function is used to initialize the EXTI peripheral through:-
 * a) specifing/configuring
 * the port number and pin number as input floating then using the AFIO
 *peripheral to route the pin from a GPIO pin to an EXTI pin. b) using the EXTI
 *line number to get the index and the position in the AFIO_EXTICR register. c)
 *clearing the AFIO_EXTICR register, then set a nibble using the index and the
 *position. d) clearing the EXTI_FTSR_RTSR registers, then check for the trigger
 *state to select it. e) initializing the global pointer to function with the
 *EXTI_Line_Number as an index with the matched address of the callback
 *function. f) enable/disable the interrupt in the EXTI_IMR register and in the
 *NVIC too.
 *
 * PRE-CONDITION: EXTI is configured.
 *
 * POST-CONDITION: The EXTI peripheral is set up with the configuration settings
 * and is initiailized.
 *
 * @param EXTI_Config is a pointer to the EXTI_PINConfig structure.
 *
 * @return void
 **********************************************************************/
void EXTI_Init(ST_EXTI_PINConfig_t *EXTI_Config) {
  const ST_GPIOConfig_t *const pConfig_EXTI = EXTI_ConfigGet();
  GPIO_Init(pConfig_EXTI);

  vuint8_t i = 0, PortNumber = 0, PinNumber = 0, AFIO_EXTICR_Index,
           AFIO_EXTICR_Position;
  for (i = 0; i < EXTI_ConfigSize; i++) {
    PortNumber = pConfig_EXTI[i].Port % NUMBER_OF_PORTS;
    PinNumber = pConfig_EXTI[i].Pin % NUMBER_OF_PINS_PER_PORT;
    EXTI_Config->EXTI_PIN.EXTI_Port = PortNumber;
    EXTI_Config->EXTI_PIN.EXTI_Pin = PinNumber;

    AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number / 4;
    AFIO_EXTICR_Position =
        (EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number % 4) * 4;
    CLR_NIBBLE((pAFIO->EXTICR[AFIO_EXTICR_Index]), AFIO_EXTICR_Position);
    SET_NIBBLE_VALUE(pAFIO->EXTICR[AFIO_EXTICR_Index],
                     AFIO_EXTI_MAPPING(PortNumber), AFIO_EXTICR_Position);

    CLR_BIT((pEXTI->FTSR), EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
    CLR_BIT((pEXTI->RTSR), EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
    if (EXTI_Config->EXTI_Trigger == RISING) {
      SET_BIT((pEXTI->RTSR), EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
    } else if (EXTI_Config->EXTI_Trigger == FALLING) {
      SET_BIT((pEXTI->FTSR), EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
    } else if (EXTI_Config->EXTI_Trigger == RISING_FALLING) {
      SET_BIT((pEXTI->RTSR), EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
      SET_BIT((pEXTI->FTSR), EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
    }

    gPf_IRQ_Callback[EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number] =
        EXTI_Config->EXTI_PIN.CallbackFunction;
    if (EXTI_Config->EXTI_IRQ == IRQ_DISABLE) {
      CLR_BIT((pEXTI->IMR), EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
      NVIC_disableIRQ(EXTI_Config->EXTI_PIN.IRQ_Number);
    } else if (EXTI_Config->EXTI_IRQ == IRQ_ENABLE) {
      SET_BIT((pEXTI->IMR), EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
      NVIC_enableIRQ(EXTI_Config->EXTI_PIN.IRQ_Number);
    }
  }
}

/**********************************************************************
 * Function :EXTI_Update()
 *
 * Description:
 *
 * This function is used to update the states of the EXTI peripheral.
 *
 * PRE-CONDITION: EXTI is configured and initialized
 *
 * POST-CONDITION: The EXTI peripheral is set up with the configuration and is
 *initiailized. settings.
 * @param EXTI_Config is a pointer to the EXTI_PINConfig structure.
 *
 * @return void
 **********************************************************************/
void EXTI_Update(ST_EXTI_PINConfig_t *EXTI_Config) { EXTI_Init(EXTI_Config); }

/**********************************************************************
 * Function :EXTI_Reset()
 *
 * Description:
 *
 * This function is used to reset the EXTI peripheral
 *
 * PRE-CONDITION: EXTI is configured and initialized
 *
 * POST-CONDITION: The EXTI peripheral is reset.
 * @param void
 *
 * @return void
 **********************************************************************/
void EXTI_Reset(void) {
  pEXTI->IMR   = 	0x00000000;
  pEXTI->EMR   = 	0x00000000;
  pEXTI->FTSR  = 	0x00000000;
  pEXTI->RTSR  = 	0x00000000;
  pEXTI->SWIER = 	0x00000000;
  pEXTI->PR    = 	0xffffffff;
  NVIC_disableIRQ(EXTI0_IRQ);
  NVIC_disableIRQ(EXTI1_IRQ);
  NVIC_disableIRQ(EXTI2_IRQ);
  NVIC_disableIRQ(EXTI3_IRQ);
  NVIC_disableIRQ(EXTI4_IRQ);
  NVIC_disableIRQ(EXTI5_IRQ);
  NVIC_disableIRQ(EXTI6_IRQ);
  NVIC_disableIRQ(EXTI7_IRQ);
  NVIC_disableIRQ(EXTI8_IRQ);
  NVIC_disableIRQ(EXTI9_IRQ);
  NVIC_disableIRQ(EXTI10_IRQ);
  NVIC_disableIRQ(EXTI11_IRQ);
  NVIC_disableIRQ(EXTI12_IRQ);
  NVIC_disableIRQ(EXTI13_IRQ);
  NVIC_disableIRQ(EXTI14_IRQ);
  NVIC_disableIRQ(EXTI15_IRQ);
}

void EXTI0_IRQHandler(void) {
  SET_BIT((pEXTI->PR), 0);
  gPf_IRQ_Callback[0]();
}

void EXTI1_IRQHandler(void) {
  SET_BIT((pEXTI->PR), 1);
  gPf_IRQ_Callback[1]();
}
void EXTI2_IRQHandler(void) {
  SET_BIT((pEXTI->PR), 2);
  gPf_IRQ_Callback[2]();
}
void EXTI3_IRQHandler(void) {
  SET_BIT((pEXTI->PR), 3);
  gPf_IRQ_Callback[3]();
}
void EXTI4_IRQHandler(void) {
  SET_BIT((pEXTI->PR), 4);
  gPf_IRQ_Callback[4]();
}

void EXTI9_5_IRQHandler(void) {
  if (pEXTI->PR & 1 << 5) {
    SET_BIT((pEXTI->PR), 5);
    gPf_IRQ_Callback[5]();
  }
  if (pEXTI->PR & 1 << 6) {
    SET_BIT((pEXTI->PR), 6);
    gPf_IRQ_Callback[6]();
  }
  if (pEXTI->PR & 1 << 7) {
    SET_BIT((pEXTI->PR), 7);
    gPf_IRQ_Callback[7]();
  }
  if (pEXTI->PR & 1 << 8) {
    SET_BIT((pEXTI->PR), 8);
    gPf_IRQ_Callback[8]();
  }
  if (pEXTI->PR & 1 << 9) {
    SET_BIT((pEXTI->PR), 9);
    gPf_IRQ_Callback[9]();
  }
}

void EXTI15_10_IRQHandler(void) {
  if (pEXTI->PR & 1 << 10) {
    SET_BIT((pEXTI->PR), 10);
    gPf_IRQ_Callback[10]();
  }
  if (pEXTI->PR & 1 << 11) {
    SET_BIT((pEXTI->PR), 11);
    gPf_IRQ_Callback[11]();
  }
  if (pEXTI->PR & 1 << 12) {
    SET_BIT((pEXTI->PR), 12);
    gPf_IRQ_Callback[12]();
  }
  if (pEXTI->PR & 1 << 13) {
    SET_BIT((pEXTI->PR), 13);
    gPf_IRQ_Callback[13]();
  }
  if (pEXTI->PR & 1 << 14) {
    SET_BIT((pEXTI->PR), 14);
    gPf_IRQ_Callback[14]();
  }
  if (pEXTI->PR & 1 << 15) {
    SET_BIT((pEXTI->PR), 15);
    gPf_IRQ_Callback[15]();
  }
}
