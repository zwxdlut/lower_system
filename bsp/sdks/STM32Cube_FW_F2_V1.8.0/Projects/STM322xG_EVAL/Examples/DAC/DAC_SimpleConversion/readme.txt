/**
  @page DAC_SimpleConversion DAC Simple Conversion example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    DAC/DAC_Simple_Conversion/Readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the DAC Simple Conversion example.
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

How to use the DAC peripheral to do a simple conversion.

This example provides a short description of how to use the DAC peripheral to 
do a simple conversation in 8 bits right alignment of 0xFF value, the result of 
conversion can be seen by connecting PA4(DAC channel1) to an oscilloscope.

STM32 Eval board's LEDs can be used to monitor the transfer status:
  - LED3 is ON when there are an error in initialization.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - DAC/DAC_SimpleConversion/Inc/stm32f2xx_hal_conf.h    HAL configuration file
  - DAC/DAC_SimpleConversion/Inc/stm32f2xx_it.h          Interrupt handlers header file
  - DAC/DAC_SimpleConversion/Inc/main.h                  Main program header file  
  - DAC/DAC_SimpleConversion/Src/stm32f2xx_it.c          Interrupt handlers
  - DAC/DAC_SimpleConversion/Src/main.c                  Main program
  - DAC/DAC_SimpleConversion/Src/stm32f2xx_hal_msp.c     HAL MSP module
  - DAC/DAC_SimpleConversion/Src/system_stm32f2xx.c      STM32F2xx system clock configuration file
  

@par Hardware and Software environment

  - This example runs on STM32F2xx devices.
    
  - This example has been tested with STM322xG-EVAL evaluation board and can be
    easily tailored to any other supported device and development board.

  - STM322xG-EVAL Set-up 	
     - Connect PA4 (DAC Channel1) pin 4 connector CN2 to an oscilloscope.
   

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
  
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

