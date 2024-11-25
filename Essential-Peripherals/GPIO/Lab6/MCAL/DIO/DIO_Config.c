/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file DIO_Config.c
 * @brief This module contains the implementation for the DIO peripheral
 * configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each GPIO peripheral
 * pin. Each row represents a single pin. Each column is representing a member
 * of the GpioConfig_t structure. This table is read in by DIO_Init(), where
 * each pin is then set up based on this table.
 */
const ST_GpioConfig_t GpioConfig[] = {
    /*   PORT            PIN					STATE
     */
    {PORTA, Pin0, DIO_INPUT_FLOATING}, {PORTA, Pin1, DIO_INPUT_FLOATING},
    {PORTA, Pin2, DIO_INPUT_FLOATING}, {PORTA, Pin3, DIO_INPUT_FLOATING},
    {PORTA, Pin4, DIO_INPUT_FLOATING}, {PORTA, Pin5, DIO_INPUT_FLOATING},
    {PORTA, Pin6, DIO_INPUT_FLOATING}, {PORTA, Pin7, DIO_INPUT_FLOATING},
    {PORTB, Pin0, DIO_INPUT_FLOATING}, {PORTB, Pin1, DIO_INPUT_FLOATING},
    {PORTB, Pin2, DIO_INPUT_FLOATING}, {PORTB, Pin3, DIO_INPUT_FLOATING},
    {PORTB, Pin4, DIO_INPUT_FLOATING}, {PORTB, Pin5, DIO_INPUT_FLOATING},
    {PORTB, Pin6, DIO_INPUT_FLOATING}, {PORTB, Pin7, DIO_INPUT_FLOATING},
    {PORTC, Pin0, DIO_INPUT_FLOATING}, {PORTC, Pin1, DIO_INPUT_FLOATING},
    {PORTC, Pin2, DIO_INPUT_FLOATING}, {PORTC, Pin3, DIO_INPUT_FLOATING},
    {PORTC, Pin4, DIO_INPUT_FLOATING}, {PORTC, Pin5, DIO_INPUT_FLOATING},
    {PORTC, Pin6, DIO_INPUT_FLOATING}, {PORTC, Pin7, DIO_INPUT_FLOATING},
    {PORTD, Pin0, DIO_INPUT_FLOATING}, {PORTD, Pin1, DIO_INPUT_FLOATING},
    {PORTD, Pin2, DIO_INPUT_FLOATING}, {PORTD, Pin3, DIO_INPUT_FLOATING},
    {PORTD, Pin4, DIO_INPUT_FLOATING}, {PORTD, Pin5, DIO_INPUT_FLOATING},
    {PORTD, Pin6, DIO_INPUT_FLOATING}, {PORTD, Pin7, DIO_INPUT_FLOATING}};

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : GpioConfig_t()
 *
 * This function is used to initialize the DIO based on the configuration
 * table defined in GpioConfig module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_GpioConfig_t *const Gpio_ConfigGet(void) {
  return (ST_GpioConfig_t *const) & GpioConfig[0];
}
