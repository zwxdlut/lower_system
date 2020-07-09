/**
  @page RCC_OutputSystemClockOnMCO RCC example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    Examples_LL/RCC/RCC_OutputSystemClockOnMCO/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the RCC example.
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
  @endverbatim

@par Example Description

This example describes how to configure MCO pins (PA8 and PC9) to output the system clock.

At start-up, USER button and MCO pin are configured. The program configures SYSCLK
to the max frequency using the PLL with HSE as clock source.

The signal on PA8 and PC9 can be monitored with an oscilloscope
to check the different MCO configuration set at each button press.
Different configuration will be observed
 - HSI frequency with frequency value around @16MHz.
 - PLLCLK frequency value divided by 4, hence around @30MHz.
 - SYSCLK frequency value divided by 2, hence around @60MHz.
 - HSE frequency value divided by 2, hence around @4MHz.

When user press User push-button, a LED1 toggle is done to indicate a change in MCO config.

@par Directory contents 

  - RCC/RCC_OutputSystemClockOnMCO/Inc/stm32f2xx_it.h          Interrupt handlers header file
  - RCC/RCC_OutputSystemClockOnMCO/Inc/main.h                  Header for main.c module
  - RCC/RCC_OutputSystemClockOnMCO/Inc/stm32_assert.h          Template file to include assert_failed function
  - RCC/RCC_OutputSystemClockOnMCO/Src/stm32f2xx_it.c          Interrupt handlers
  - RCC/RCC_OutputSystemClockOnMCO/Src/main.c                  Main program
  - RCC/RCC_OutputSystemClockOnMCO/Src/system_stm32f2xx.c      STM32F2xx system source file


@par Hardware and Software environment

  - This example runs on STM32F207xx devices.
    
  - This example has been tested with NUCLEO-F207ZG board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-F207ZG Set-up
    - Connect the MCO pin to an oscilloscope to monitor the different waveforms:
      - PA.08: connected to pin 23 of CN12 connector for Nucleo-144 (MB1137)
      - PC.09: connected to pin 1 of CN12 connector for Nucleo-144 (MB1137)

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
