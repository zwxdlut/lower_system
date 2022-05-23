/**
  @page TIM_DMA TIM DMA example

  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    TIM/TIM_DMA/Readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM DMA example.
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

Use of the DMA with TIMER Update request 
to transfer data from memory to TIMER Capture Compare Register 3 (TIM1_CCR3).

  The following configuration values are used in this example:
  
    - TIM1CLK = SystemCoreClock
    - Counter repetition = 3 
    - Prescaler = 0 
    - TIM1 counter clock = SystemCoreClock
    - SystemCoreClock is set to 120 MHz for STM32F2xx

  The objective is to configure TIM1 channel 3 to generate complementary PWM 
  (Pulse Width Modulation) signal with a frequency equal to 17.57 KHz, and a variable 
  duty cycle that is changed by the DMA after a specific number of Update DMA request.

  The number of this repetitive requests is defined by the TIM1 Repetition counter,
  each 3 Update Requests, the TIM1 Channel 3 Duty Cycle changes to the next new 
  value defined by the aSRC_Buffer.

The PWM waveforms can be displayed using an oscilloscope.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - TIM/TIM_DMA/system_stm32f2xx.c         STM32F2xx system clock configuration file
  - TIM/TIM_DMA/stm32f2xx_hal_conf.h       HAL configuration file
  - TIM/TIM_DMA/stm32f2xx_it.h             Interrupt handlers header file
  - TIM/TIM_DMA/stm32f2xx_it.c             Interrupt handlers
  - TIM/TIM_DMA/main.c                     Main program
  - TIM/TIM_DMA/main.h                     Main program header file


@par Hardware and Software environment

  - This example runs on STM32F207xx/217xx device.
    
  - This example has been tested with STMicroelectronics STM322xG-EVAL
    evaluation board and can be easily tailored to any other supported device
    and development board. 

  - STM322xG-EVAL Set-up    
    - Connect the TIM1 pin to an oscilloscope to monitor the different waveforms: 
        - TIM1 CH3  (PE.13: Pin28 in CN2)


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
