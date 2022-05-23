/**
  @page GPIO_EXTI GPIO EXTI example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    GPIO/GPIO_EXTI/Readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the GPIO EXTI example.
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

How to configure external interrupt lines.

In this example, 2 EXTI lines (EXTI Line0 and Line15) are configured  to generate
an interrupt on each rising and falling edge, respectively. 
In the interrupt routine a LED connected to a specific GPIO pin is toggled.

In this example:
    - EXTI Line0 is connected to PA0 pin
    - EXTI Line15 is connected to PG15 pin

- when falling edge is detected on EXTI Line0, LED1 toggles
    - when falling edge is detected on EXTI Line15, LED2 toggles

On STM322xG-EVAL:
    - EXTI Line0 is connected to Wakeup push-button
    - EXTI Line15 is connected to Key push-button
  
In this example, HCLK is configured at 120 MHz.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - GPIO/GPIO_IOToggle/Inc/stm32f2xx_hal_conf.h    HAL configuration file
  - GPIO/GPIO_IOToggle/Inc/stm32f2xx_it.h          Interrupt handlers header file
  - GPIO/GPIO_IOToggle/Inc/main.h                  Main program header file  
  - GPIO/GPIO_IOToggle/Src/stm32f2xx_it.c          Interrupt handlers
  - GPIO/GPIO_IOToggle/Src/main.c                  Main program
  - GPIO/GPIO_IOToggle/Src/system_stm32f2xx.c      STM32F2xx system clock configuration file


@par Hardware and Software environment  
  - This example runs on STM32F207xx/217xx device.    
  - This example has been tested with STMicroelectronics STM322xG-EVAL 
    evaluation boards and can be easily tailored to any other supported device 
    and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
