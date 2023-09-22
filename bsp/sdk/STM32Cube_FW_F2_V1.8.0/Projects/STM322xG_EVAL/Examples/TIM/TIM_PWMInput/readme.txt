/**
  @page TIM_PWMInput TIM PWM Input example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    TIM/TIM_PWMInput/Readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM PWM Input example.
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

Use of the TIM peripheral to measure the frequency and 
duty cycle of an external signal.

The TIM4CLK frequency is set to SystemCoreClock/4 (Hz), the Prescaler is 0 so the 
counter clock is SystemCoreClock/2 (Hz).
SystemCoreClock is set to 120 MHz for STM32F2xx Devices.

TIM4 is configured in PWM Input Mode: the external signal is connected to 
TIM4 Channel2 used as input pin.
To measure the frequency and the duty cycle we use the TIM4 CC2 interrupt request,
so In the TIM4_IRQHandler routine, the frequency and the duty cycle of the external 
signal are computed.

"uwFrequency" variable contains the external signal frequency:
TIM4 counter clock = SystemCoreClock / 2,
Frequency = TIM4 counter clock / TIM4_CCR2 in Hz, 

"DutyCycle" variable contains the external signal duty cycle:
DutyCycle = (TIM4_CCR1*100)/(TIM4_CCR2) in %.

The minimum frequency value to measure is (TIM4 counter clock / CCR MAX)
                                         = (120MHz/2)/ 65535
                                         = 916 Hz

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Directory contents 

  - TIM/TIM_PWMInput/Inc/stm32f2xx_hal_conf.h    HAL configuration file
  - TIM/TIM_PWMInput/Inc/stm32f2xx_it.h          Interrupt handlers header file
  - TIM/TIM_PWMInput/Inc/main.h                  Main program header file  
  - TIM/TIM_PWMInput/Src/stm32f2xx_it.c          Interrupt handlers
  - TIM/TIM_PWMInput/Src/main.c                  Main program
  - TIM/TIM_PWMInput/Src/stm32f2xx_hal_msp.c     HAL MSP module
  - TIM/TIM_PWMInput/Src/system_stm32f2xx.c      STM32F2xx system clock configuration file


@par Hardware and Software environment 

  - This example runs on STM32F207xx/217xx device. 
    
  - This example has been tested with STMicroelectronics STM322xG-EVAL 
    evaluation boards and can be easily tailored to any other supported device and development board

  - STM322xG-EVAL Set-up 
    - Connect the external signal to measure to the TIM4 CH2 pin (PB.07: Pin12 in CN4).


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
   
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
