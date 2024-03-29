/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO_Config.c
 * @brief This module contains the implementation for the GPIO peripheral configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each GPIO peripheral pin.
 * Each row represents a single pin. Each column is representing a member of the GpioConfig_t structure.
 * This table is read in by Gpio_Init(), where each pin is then set up based on this table.
 */
const GpioConfig_t GpioConfig[] = {
/*PORT		PIN					STATE									MODE 			*/
{ PORTA,	PIN1, 		GPIO_INPUT_FLOATING,   			GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
{ PORTA,	PIN13, 		GPIO_INPUT_FLOATING,   			GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
{ PORTB,	PIN1, 		GPIO_OUTPUT_PUSHPULL,   			GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
{ PORTB,	PIN13, 		GPIO_OUTPUT_PUSHPULL,   			GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ}
};

vuint32_t ConfigSize = sizeof(GpioConfig) / sizeof(GpioConfig[0]);
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : Gpio_ConfigGet()
 *
 * Description:
 *
 * This function is used to initialize the GPIO based on the configuration
 * table defined in GpioConfig module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const GpioConfig_t* const Gpio_ConfigGet(void) {
	return (GpioConfig_t *const)&GpioConfig[0];
}

