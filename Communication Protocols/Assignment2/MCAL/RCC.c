/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: RCC.c
 *	@brief The implementation for the RCC peripheral
 *
 *****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "inc/RCC.h"

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/
extern vuint32_t configSizeRcc;

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE POINTERS TO EXTI AND AFIO */
static ST_RCC_t *const pRCC = RCC;

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/
void AHB_Prescaler(EN_AHBPRESCALER_t prescaler);
void APB1_Prescaler(EN_APBPRESCALER_t prescaler);
void APB2_Prescaler(EN_APBPRESCALER_t prescaler);
void PLL_MulFactor(EN_PLLMUL_t pllMul);
void PLL_PredivFactor(EN_PREDIV1_t pllPrediv);
void RCC_SelectClk(EN_CLOCK_SELECT_t clkSelect);
vuint32_t RCC_GetPllClk();

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/
void AHB_Prescaler(EN_AHBPRESCALER_t prescaler) {
  switch (prescaler) {
  case SYSCLK_1:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_1, 4);
    break;
  case SYSCLK_2:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_2, 4);
    break;
  case SYSCLK_4:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_4, 4);
    break;
  case SYSCLK_8:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_8, 4);
    break;
  case SYSCLK_16:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_16, 4);
    break;
  case SYSCLK_64:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_64, 4);
    break;
  case SYSCLK_128:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_128, 4);
    break;
  case SYSCLK_256:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_256, 4);
    break;
  case SYSCLK_512:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, SYSCLK_512, 4);
    break;
  }
}

void APB1_Prescaler(EN_APBPRESCALER_t prescaler) {
  switch (prescaler) {
  case HCLK_1:
    WRITE_3BITS(pRCC->CFGR, HCLK_1, 8);
    break;
  case HCLK_2:
    WRITE_3BITS(pRCC->CFGR, HCLK_2, 8);
    break;
  case HCLK_4:
    WRITE_3BITS(pRCC->CFGR, HCLK_4, 8);
    break;
  case HCLK_8:
    WRITE_3BITS(pRCC->CFGR, HCLK_8, 8);
    break;
  case HCLK_16:
    WRITE_3BITS(pRCC->CFGR, HCLK_16, 8);
    break;
  }
}

void APB2_Prescaler(EN_APBPRESCALER_t prescaler) {
  switch (prescaler) {
  case HCLK_1:
    WRITE_3BITS(pRCC->CFGR, HCLK_1, 11);
    break;
  case HCLK_2:
    WRITE_3BITS(pRCC->CFGR, HCLK_2, 11);
    break;
  case HCLK_4:
    WRITE_3BITS(pRCC->CFGR, HCLK_4, 11);
    break;
  case HCLK_8:
    WRITE_3BITS(pRCC->CFGR, HCLK_8, 11);
    break;
  case HCLK_16:
    WRITE_3BITS(pRCC->CFGR, HCLK_16, 11);
    break;
  }
}

void PLL_MulFactor(EN_PLLMUL_t pllMul) {
  switch (pllMul) {
  case PLL_X4:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, PLL_X4, 18);
    break;
  case PLL_X5:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, PLL_X5, 18);
    break;
  case PLL_X6:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, PLL_X6, 18);
    break;
  case PLL_X7:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, PLL_X7, 18);
    break;
  case PLL_X8:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, PLL_X8, 18);
    break;
  case PLL_X9:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, PLL_X9, 18);
    break;
  case PLL_X6_5:
    WRITE_NIBBLE_VALUE(pRCC->CFGR, PLL_X6_5, 18);
    break;
  default: /* DO NOTHING */
    break;
  }
}

void PLL_Prediv1Factor(EN_PREDIV1_t pllPrediv1) {
  switch (pllPrediv1) {
  case PREDIV1_NULL:
    break;
  case PREDIV1_1:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_1, 0);
    break;
  case PREDIV1_2:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_2, 0);
    break;
  case PREDIV1_3:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_3, 0);
    break;
  case PREDIV1_4:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_4, 0);
    break;
  case PREDIV1_5:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_5, 0);
    break;
  case PREDIV1_6:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_6, 0);
    break;
  case PREDIV1_7:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_7, 0);
    break;
  case PREDIV1_8:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_8, 0);
    break;
  case PREDIV1_9:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_9, 0);
    break;
  case PREDIV1_10:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_10, 0);
    break;
  case PREDIV1_11:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_11, 0);
    break;
  case PREDIV1_12:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_12, 0);
    break;
  case PREDIV1_13:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_13, 0);
    break;
  case PREDIV1_14:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_14, 0);
    break;
  case PREDIV1_15:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_15, 0);
    break;
  case PREDIV1_16:
    WRITE_NIBBLE_VALUE(pRCC->CFGR2, PREDIV1_16, 0);
    break;
  }
}

void RCC_SelectClk(EN_CLOCK_SELECT_t clkSelect) {
  AHB_Prescaler(SYSCLK_1);
  switch (clkSelect) {
  case RCC_SELECT_HSI:
    SET_BIT(pRCC->CR, 0);
    while (!READ_BIT(pRCC->CR, 0))
      ;
    CLR_2BITS(pRCC->CFGR, 0);
    while (0b00 != READ_2BITS(pRCC->CFGR, 0))
      ;
    CLR_BIT(pRCC->CR, 16);
    CLR_BIT(pRCC->CR, 24);
    break;

  case RCC_SELECT_HSE:
    SET_BIT(pRCC->CR, 16);
    while (!READ_BIT(pRCC->CR, 16))
      ;
    WRITE_2BITS(pRCC->CFGR, 0b01, 0);
    while (0b01 != READ_2BITS(pRCC->CFGR, 0))
      ;
    CLR_BIT(pRCC->CR, 0);
    CLR_BIT(pRCC->CR, 24);
    break;

  case RCC_SELECT_PLL:
    extern ST_PLL_Config_t configPll;
    switch (configPll.pllSource) {
    case HSI_CLK_BY2:
      CLR_BIT(pRCC->CFGR, 16);
      while (READ_BIT(pRCC->CFGR, 16))
        ;
      break;

    case PREDIV1:
      SET_BIT(pRCC->CFGR, 16);
      while (!READ_BIT(pRCC->CFGR, 16))
        ;
      PLL_Prediv1Factor(configPll.pllPrediv1);
    default:
      break;
    }
    WRITE_2BITS(pRCC->CFGR, 0b10, 0);
    while (0b10 != READ_2BITS(pRCC->CFGR, 0))
      ;
    PLL_MulFactor(configPll.pllMul);
    SET_BIT(pRCC->CR, 24);
    while (!READ_BIT(pRCC->CR, 24))
      ;
  default:
    break;
  }
}

extern vuint32_t RCC_GetPllClk() {
  vuint32_t pllClk = HSI_RC_CLK;
  switch (READ_BIT(pRCC->CFGR, 16)) {
  case LOW:
    pllClk /= 2;
    pllClk *= (READ_NIBBLE(pRCC->CFGR, 18) + 2);
    break;
  case HIGH:
    pllClk = HSE_CLK / (READ_NIBBLE(pRCC->CFGR2, 0) + 1);
    pllClk *= (READ_NIBBLE(pRCC->CFGR, 18) + 2);
    break;
  default:
    break;
  }
  return pllClk;
}

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: RCC_GetSysClk
 * Synatax: vuint32_t RCC_GetSysClk(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Get the frequency of the system clk in HZ
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
vuint32_t RCC_GetSysClk(void) {
  vuint32_t sysClk = 0;
  switch (READ_2BITS(pRCC->CFGR, 2)) {
  case 0:
    sysClk = HSI_RC_CLK;
    break;
  case 1:
    sysClk = HSE_CLK;
    break;
  case 2:
    sysClk = RCC_GetPllClk();
    break;
  default:
    sysClk = 0;
    break;
  }
  return sysClk;
}

/************************************************************************
 * Service Name: RCC_GetHClk
 * Synatax: vuint32_t RCC_GetHClk(void);
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Get the frequency of the AHB bus clk in HZ
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: frequency of the AHB bus clk
 *************************************************************************/
vuint32_t RCC_GetHClk(void) {
  vuint32_t HClk = RCC_GetSysClk();
  switch (READ_NIBBLE(pRCC->CFGR, 4)) {
  case SYSCLK_1:
    HClk = (RCC_GetSysClk() / 1U);
    break;
  case SYSCLK_2:
    HClk = (RCC_GetSysClk() / 2U);
    break;
  case SYSCLK_4:
    HClk = (RCC_GetSysClk() / 4U);
    break;
  case SYSCLK_8:
    HClk = (RCC_GetSysClk() / 8U);
    break;
  case SYSCLK_16:
    HClk = (RCC_GetSysClk() / 16U);
    break;
  case SYSCLK_64:
    HClk = (RCC_GetSysClk() / 64U);
    break;
  case SYSCLK_128:
    HClk = (RCC_GetSysClk() / 128U);
    break;
  case SYSCLK_256:
    HClk = (RCC_GetSysClk() / 256U);
    break;
  case SYSCLK_512:
    HClk = (RCC_GetSysClk() / 512U);
    break;
  default:
    break;
  }
  return HClk;
}

/************************************************************************
 * Service Name: RCC_GetPClk1
 * Synatax: vuint32_t RCC_GetPClk1(void);
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Get the frequency of the APB1 bus clk in HZ
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: frequency of the APB1 bus clk
 *************************************************************************/
vuint32_t RCC_GetPClk1(void) {
  vuint32_t PClk1 = RCC_GetHClk();
  switch (READ_3BITS(pRCC->CFGR, 8)) {
  case HCLK_1:
    PClk1 = (RCC_GetHClk() / 1U);
    break;
  case HCLK_2:
    PClk1 = (RCC_GetHClk() / 2U);
    break;
  case HCLK_4:
    PClk1 = (RCC_GetHClk() / 4U);
    break;
  case HCLK_8:
    PClk1 = (RCC_GetHClk() / 8U);
    break;
  case HCLK_16:
    PClk1 = (RCC_GetHClk() / 16U);
    break;
  default:
    break;
  }
  return PClk1;
}

/************************************************************************
 * Service Name: RCC_GetPClk2
 * Synatax: vuint32_t RCC_GetPClk2(void);
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Get the frequency of the APB2 bus clk in HZ
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: frequency of the APB2 bus clk
 *************************************************************************/
vuint32_t RCC_GetPClk2(void) {
  vuint32_t PClk2 = RCC_GetHClk();
  switch (READ_3BITS(pRCC->CFGR, 11)) {
  case HCLK_1:
    PClk2 = (RCC_GetHClk() / 1U);
    break;
  case HCLK_2:
    PClk2 = (RCC_GetHClk() / 2U);
    break;
  case HCLK_4:
    PClk2 = (RCC_GetHClk() / 4U);
    break;
  case HCLK_8:
    PClk2 = (RCC_GetHClk() / 8U);
    break;
  case HCLK_16:
    PClk2 = (RCC_GetHClk() / 16U);
    break;
  default:
    break;
  }
  return PClk2;
}

/************************************************************************
 * Service Name: RCC_Init
 * Synatax: void RCC_Init(ST_RCC_Config_t* configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Enable the selected clk source, wait until it's ready
 * 				select it clk source, wait until the clk source
 *is ready, and disable other clk sources
 * @param (in): configPtr a pointer to the RCC_Config structure
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void RCC_Init(const ST_RCC_Config_t *const configPtr) {
  APB1_Prescaler(HCLK_1);
  APB2_Prescaler(HCLK_1);
  vuint8_t i = 0, j = 0;
  for (i = 0; i < configSizeRcc; i++) {
    RCC_SelectClk(configPtr[i].clkSource);
    for (j = 0; j < USED_PERIPHERALS; j++) {
      switch (configPtr[i].clkGate[j]) {
      case RCC_GPIOA:
        RCC_GPIOA_CLK_EN();
        break;
      case RCC_GPIOB:
        RCC_GPIOB_CLK_EN();
        break;
      case RCC_GPIOC:
        RCC_GPIOC_CLK_EN();
        break;
      case RCC_GPIOD:
        RCC_GPIOD_CLK_EN();
        break;
      case RCC_AFIO:
        RCC_AFIO_CLK_EN();
        break;
      case RCC_USART1:
        RCC_USART1_CLK_EN();
        break;
      case RCC_USART2:
        RCC_USART2_CLK_EN();
        break;
      case RCC_USART3:
        RCC_USART3_CLK_EN();
        break;
      case RCC_SPI1:
        RCC_SPI1_CLK_EN();
        break;
      case RCC_SPI2:
        RCC_SPI2_CLK_EN();
        break;
      case RCC_I2C1:
        RCC_I2C1_CLK_EN();
        break;
      case RCC_I2C2:
        RCC_I2C2_CLK_EN();
        break;
      case RCC_DAC:
        RCC_DAC_CLK_EN();
        break;
      default: /* Do Nothing */
        break;
      }
    }
  }
}

/************************************************************************
 * Service Name: RCC_Reset
 * Synatax: void RCC_Reset(ST_RCC_Config_t* configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset the clock for all used peripherals
 * @param (in): configPtr a pointer to the RCC_Config structure
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void RCC_Reset(ST_RCC_Config_t *configPtr) {
  vuint8_t i = 0, j = 0;
  for (i = 0; i < configSizeRcc; i++) {
    for (j = 0; j < USED_PERIPHERALS; j++) {
      switch (configPtr[i].clkGate[j]) {
      case RCC_GPIOA:
        RCC_GPIOA_CLK_RESET();
        break;
      case RCC_GPIOB:
        RCC_GPIOB_CLK_RESET();
        break;
      case RCC_GPIOC:
        RCC_GPIOC_CLK_RESET();
        break;
      case RCC_GPIOD:
        RCC_GPIOD_CLK_RESET();
        break;
      case RCC_AFIO:
        RCC_AFIO_CLK_RESET();
        break;
      case RCC_USART1:
        RCC_USART1_CLK_RESET();
        break;
      case RCC_USART2:
        RCC_USART2_CLK_RESET();
        break;
      case RCC_USART3:
        RCC_USART3_CLK_RESET();
        break;
      case RCC_SPI1:
        RCC_SPI1_CLK_RESET();
        break;
      case RCC_SPI2:
        RCC_SPI2_CLK_RESET();
        break;
      case RCC_I2C1:
        RCC_I2C1_CLK_RESET();
        break;
      case RCC_I2C2:
        RCC_I2C2_CLK_RESET();
        break;
      case RCC_DAC:
        RCC_DAC_CLK_RESET();
        break;
      default: /* Do Nothing */
        break;
      }
    }
  }
}

/************************************************************************
 * Service Name: RCC_ModuleReset
 * Synatax: void RCC_ModuleReset(EN_RCC_CLOCK_GATE_t module)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset the clock for a peripheral
 * @param (in): module an enum represents the selected peripheral/module
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void RCC_ModuleReset(EN_RCC_CLOCK_GATE_t module) {
  switch (module) {
  case RCC_GPIOA:
    RCC_GPIOA_CLK_RESET();
    break;
  case RCC_GPIOB:
    RCC_GPIOB_CLK_RESET();
    break;
  case RCC_GPIOC:
    RCC_GPIOC_CLK_RESET();
    break;
  case RCC_GPIOD:
    RCC_GPIOD_CLK_RESET();
    break;
  case RCC_AFIO:
    RCC_AFIO_CLK_RESET();
    break;
  case RCC_USART1:
    RCC_USART1_CLK_RESET();
    break;
  case RCC_USART2:
    RCC_USART2_CLK_RESET();
    break;
  case RCC_USART3:
    RCC_USART3_CLK_RESET();
    break;
  case RCC_SPI1:
    RCC_SPI1_CLK_RESET();
    break;
  case RCC_SPI2:
    RCC_SPI2_CLK_RESET();
    break;
  case RCC_I2C1:
    RCC_I2C1_CLK_RESET();
    break;
  case RCC_I2C2:
    RCC_I2C2_CLK_RESET();
    break;
  case RCC_DAC:
    RCC_DAC_CLK_RESET();
    break;
  default: /* Do Nothing */
    break;
  }
}
