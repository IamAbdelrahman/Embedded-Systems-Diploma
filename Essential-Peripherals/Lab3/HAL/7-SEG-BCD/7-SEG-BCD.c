/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file 7-SEG-BCD.c
 * @brief The implementation for the 7-segment-BCD driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "7-SEG-BCD.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/

/**********************************************************************
 * Function : SevenSegment_Enable()
 *
 *  Description:
 *  This function is used to enable the 7-SEG so it can turn it on/off.
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @param Pin is the pin to write using the DIOPin_t enum definition
 *  @param State is ON or OFF as defined in the  State_t enum definition
 *  @return void
 **********************************************************************/
vuint8_t SevenSegment_Enable (DIOPin_t Pin) {
    return (1 << Pin);
}

/**********************************************************************
 * Function : SevenSegment_DisplayDigit()
 *
 *  Description:
 *  This function is used to display a digit on 
 *  a 7-segment connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @param Pin is the pin to write using the DIOPin_t enum definition. Please note
 * this pin is the first pin of the BCD output pins and the remaining 3 pins must
 * be sequential in the hardware connection, for instance, 
 * if pin is pin0 the connection must be pin0:3...etc. Pin takes numbers from 
 * (0:4) only.
 *  @param digit is the input digit by the user to be displayed from (0:9)

 *  @return void
 **********************************************************************/
void SevenSegment_DisplayDigit(DIOPORTX_t Port, DIOPin_t Pin, vuint8_t digit) {
    DIO_WritePort(Port, digit<<Pin);
}
