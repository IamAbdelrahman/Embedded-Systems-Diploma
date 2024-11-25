/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file KEYPAD_Config.c
 * @brief This module contains the implementation for the KEYPAD configuration
 *
 * @author Abdelrahman Kamal
 *
 */
/**********************************************************************
 * Includes
 **********************************************************************/
#include "KEYPAD_Config.h"

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
 * The following array contains the configuration data for each KEYPAD driver
 * Each row represents a single pin. 
 * Each column is representing a member of the GpioConfig_t structure.
 * This table is read in by KEYPAD_Init(), where each pin is then set up based on this table.
 */
const ST_GpioConfig_t KEYPADConfig[] = {
/*   PORT            PIN					STATE			*/
    {KEYPAD_PORT,         Pin0,               DIO_OUTPUT},
    {KEYPAD_PORT,         Pin1,               DIO_OUTPUT},
    {KEYPAD_PORT,         Pin2,               DIO_OUTPUT},  
    {KEYPAD_PORT,         Pin3,               DIO_OUTPUT},
    {KEYPAD_PORT,         Pin4,               DIO_INPUT_PULLUP},
    {KEYPAD_PORT,         Pin5,               DIO_INPUT_PULLUP},
    {KEYPAD_PORT,         Pin6,               DIO_INPUT_PULLUP},
    {KEYPAD_PORT,         Pin7,               DIO_INPUT_PULLUP}
};

 /**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : KEYPAD_ConfigGet()
 *
 * This function is used to initialize the KEYPAD based on the configuration
 * table defined in LCDConfig module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_GpioConfig_t* const KEYPAD_ConfigGet(void) {
	return (ST_GpioConfig_t *const)&KEYPADConfig[0];
}
