/**
  @page TIM_InputCapture TIM Input Capture example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    TIM/TIM_InputCapture/Readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM Input Capture example.
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

Use of the TIM peripheral to measure an external signal frequency.
  
  The TIM1CLK frequency is set to SystemCoreClock /2 (Hz), the Prescaler is 0,
  so the TIM1 counter clock is SystemCoreClock (Hz)/2.
  SystemCoreClock is set to 120 MHz for STM32F2xx Devices.

  TIM1 is configured in Input Capture Mode: the external signal is connected to 
  TIM1 Channel2 used as input pin.
  To measure the frequency we use the TIM1 CC2 interrupt request, so in the 
  TIM1_CC_IRQHandler routine, the frequency of the external signal is computed.
  
  The "uwFrequency" variable contains the external signal frequency:
  uwFrequency = TIM1 counter clock / uwDiffCapture (Hz),
  where "uwDiffCapture" is the difference between two consecutive TIM1 captures.


 The minimum frequency value to measure is 2x (TIM1 counter clock / CCR MAX)
                                              = 2x(120MHz/2)/ 65535
                                              = 1831 Hz  

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - TIM/TIM_InputCapture/Inc/stm32f2xx_hal_conf.h    HAL configuration file
  - TIM/TIM_InputCapture/Inc/stm32f2xx_it.h          Interrupt handlers header file
  - TIM/TIM_InputCapture/Inc/main.h                  Main program header file  
  - TIM/TIM_InputCapture/Src/stm32f2xx_it.c          Interrupt handlers
  - TIM/TIM_InputCapture/Src/main.c                  Main program
  - TIM/TIM_InputCapture/Src/stm32f2xx_hal_msp.c     HAL MSP module
  - TIM/TIM_InputCapture/Src/system_stm32f2xx.c      STM32F2xx system clock configuration file


@par Hardware and Software environment 

  - This example runs on STM32F207xx/217xx device.
    
  - This example has been tested with STMicroelectronics STM322xG-EVAL  
    evaluation boards and can be easily tailored to any other supported device and development board

  - STM322xG-EVAL Set-up 
    - Connect the external signal to measure to the TIM1 CH2 pin (PE.11: Pin26 in CN2).


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
   
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
