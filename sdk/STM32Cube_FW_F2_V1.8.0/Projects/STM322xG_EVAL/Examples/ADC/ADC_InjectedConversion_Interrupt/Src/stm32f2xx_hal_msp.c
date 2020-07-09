/**
  ******************************************************************************
  * @file    ADC/ADC_InjectedConversion_Interrupt/Src/stm32f2xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.    
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F2xx_HAL_Examples
  * @{
  */

/** @defgroup ADC_InjectedConversion_Interrupt
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief ADC MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  GPIO_InitTypeDef          GPIO_InitStruct;
  
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* ADC3 Periph clock enable */
  ADCx_CLOCK_ENABLE();
  /* Enable GPIO clock ****************************************/
  ADCx_REG_CHANNEL_GPIO_CLK_ENABLE();
  ADCx_INJ_CHANNEL_GPIO_CLK_ENABLE();
  
  /*##-2- Configure peripheral GPIO ##########################################*/ 
  /* ADC1 Channel11 GPIO pin configuration */
  GPIO_InitStruct.Pin = ADCx_REG_CHANNEL_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ADCx_REG_CHANNEL_GPIO_PORT, &GPIO_InitStruct);
  /* ADC1 Channel12 GPIO pin configuration */
  GPIO_InitStruct.Pin = ADCx_INJ_CHANNEL_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ADCx_INJ_CHANNEL_GPIO_PORT, &GPIO_InitStruct);
  
  
  /*##-3- Configure the NVIC #################################################*/
  /* NVIC configuration for conversion complete complete interrupt */
  HAL_NVIC_SetPriority(ADCx_IRQn, 15, 0);
  HAL_NVIC_EnableIRQ(ADCx_IRQn);
}
  
/**
  * @brief ADC MSP De-Initialization 
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO to their default state
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc)
{
  
  /*##-1- Reset peripherals ##################################################*/
  ADCx_FORCE_RESET();
  ADCx_RELEASE_RESET();

  /*##-2- Disable peripherals and GPIO Clocks ################################*/
  /* De-initialize the ADC1 Channel11 GPIO pin */
  HAL_GPIO_DeInit(ADCx_REG_CHANNEL_GPIO_PORT, ADCx_REG_CHANNEL_PIN);
  /* De-initialize the ADC1 Channel12 GPIO pin */
  HAL_GPIO_DeInit(ADCx_INJ_CHANNEL_GPIO_PORT, ADCx_INJ_CHANNEL_PIN);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
