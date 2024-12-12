/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: EXTI.c
 *	@brief The implementation for the EXTI.
 *
 *****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "../inc/EXTI.h"

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/

/*- DEFINE POINTERS TO EXTI AND AFIO */
static ST_EXTI_t *const pEXTI = EXTI;
static ST_AFIO_t *const pAFIO = AFIO;

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/
extern vuint32_t ConfigSizeExti;

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE AN ARRAY OF POINTERS TO VOID FUNCTIONS */
void (*gPf_IRQ_Callback[15])(void);

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/
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
	vuint8_t i = 0;
	for (i = 5; i < 10; i++) {
		if (READ_BIT(pEXTI->PR, i)) {
			SET_BIT(pEXTI->PR, i);
			gPf_IRQ_Callback[i]();
		}
	}
}

void EXTI15_10_IRQHandler(void) {
	vuint8_t i = 0;
	for (i = 10; i < 16; i++) {
		if (READ_BIT(pEXTI->PR, i)) {
			SET_BIT(pEXTI->PR, i);
			gPf_IRQ_Callback[i]();
		}
	}
}

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
void EXTI_Init(ST_EXTIConfig_t *configPtr) {
	vuint8_t i = 0, localPortNumber, indexAfio, positionAfio;
	for (i = 0; i < ConfigSizeExti; i++) {
		GPIO_Init(configPtr[i].pSetExtiPin, 1);
		localPortNumber = configPtr[i].pSetExtiPin->portNumber;

		/*- ALTERNATE GPIO PINS TO EXTI PINS */
		indexAfio = configPtr[i].lineNumber / 4;
		positionAfio = (configPtr[i].lineNumber % 4) * 4;
		CLR_NIBBLE(pAFIO->EXTICR[indexAfio], positionAfio);
		WRITE_NIBBLE_VALUE(pAFIO->EXTICR[indexAfio],
				AFIO_EXTI_MAPPING(localPortNumber), positionAfio);

		/*- CONFIGURING THE TRIGGER STATE */
		CLR_BIT(pEXTI->FTSR, configPtr[i].lineNumber);
		CLR_BIT(pEXTI->RTSR, configPtr[i].lineNumber);
		if (configPtr[i].Trigger == RISING) {
			SET_BIT(pEXTI->RTSR, configPtr[i].lineNumber);
		} else if (configPtr[i].Trigger == FALLING) {
			SET_BIT(pEXTI->FTSR, configPtr[i].lineNumber);
		} else if (configPtr[i].Trigger == RISING_FALLING) {
			SET_BIT(pEXTI->RTSR, configPtr[i].lineNumber);
			SET_BIT(pEXTI->FTSR, configPtr[i].lineNumber);
		}

		/*- CONFIGURING THE IRQ */
		gPf_IRQ_Callback[configPtr[i].lineNumber] =
				configPtr[i].CallbackFunction;
		if (configPtr[i].irqState == IRQ_DISABLE) {
			CLR_BIT(pEXTI->IMR, configPtr[i].lineNumber);
			NVIC_DisableIRQ(configPtr[i].irqNumber);
		} else if (configPtr[i].irqState == IRQ_ENABLE) {
			SET_BIT(pEXTI->IMR, configPtr[i].lineNumber);
			NVIC_EnableIRQ(configPtr[i].irqNumber);
		}
	}
}

void EXTI_Update(ST_EXTIConfig_t *configPtr) {
	EXTI_Init(configPtr);
}

void EXTI_Reset(void) {
	pEXTI->IMR 	 = 0x00000000;
	pEXTI->EMR 	 = 0x00000000;
	pEXTI->FTSR  = 0x00000000;
	pEXTI->RTSR  = 0x00000000;
	pEXTI->SWIER = 0x00000000;
	pEXTI->PR 	 = 0xffffffff;
	vuint8_t i = 0;
	for (i = 6; i < 11; i++)
		NVIC_DisableIRQ(i);
	NVIC_DisableIRQ(EXTI5_IRQ);
	NVIC_DisableIRQ(EXTI10_IRQ);
}
