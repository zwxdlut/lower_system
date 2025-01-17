#include "system.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
 #if !defined USING_OS_FREERTOS
static uint32_t g_sys_tick_cnt = 0; /* the SysTick count */
#endif

/*******************************************************************************
 * Local function prototypes
 ******************************************************************************/

/*******************************************************************************
 * Functions
 ******************************************************************************/
int32_t sys_init(void)
{
	/* setup the SysTick */
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);

	return 0;
}

void gpio_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* initialize the LEDs */
	LED0_GPIO_CLK_ENABLE();
	GPIO_InitStructure.GPIO_Pin = LED0_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED0_GPIO, &GPIO_InitStructure);
	GPIO_WriteBit(LED0_GPIO, LED0_PIN, LED_OFF);

	LED1_GPIO_CLK_ENABLE();	
	GPIO_InitStructure.GPIO_Pin = LED1_PIN; 
	GPIO_Init(LED1_GPIO, &GPIO_InitStructure);
	GPIO_WriteBit(LED1_GPIO, LED1_PIN, LED_OFF);
	
	LED2_GPIO_CLK_ENABLE();
	GPIO_InitStructure.GPIO_Pin = LED2_PIN;
	GPIO_Init(LED2_GPIO, &GPIO_InitStructure);
	GPIO_WriteBit(LED2_GPIO, LED2_PIN, LED_OFF);
	
	/* initialize the buttons */
	BTN_GPIO_CLK_ENABLE();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_InitStructure.GPIO_Pin = BTN_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(BTN_GPIO, &GPIO_InitStructure);
	GPIO_EXTILineConfig(BTN_PORT_SRC, BTN_PIN_SRC);
  	EXTI_InitStructure.EXTI_Line = BTN_EXTI_LINE;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);
   	NVIC_InitStructure.NVIC_IRQChannel = BTN_IRQ;
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  	NVIC_Init(&NVIC_InitStructure);
}

void gpio_deinit(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = BTN_IRQ;
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
  	NVIC_Init(&NVIC_InitStructure);

	EXTI_ClearITPendingBit(BTN_EXTI_LINE);
	EXTI_DeInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, DISABLE);

	GPIO_DeInit(LED0_GPIO);
	GPIO_DeInit(LED1_GPIO);
	GPIO_DeInit(LED2_GPIO);
	GPIO_DeInit(BTN_GPIO);

	LED0_GPIO_CLK_DISABLE();
	LED1_GPIO_CLK_DISABLE();
	LED2_GPIO_CLK_DISABLE();
	BTN_GPIO_CLK_DISABLE();
}

/**
 * Get the processor clock time since the program invocation.
 *
 * This is the implementation of the C standard library function.
 *
 * @return the processor clock time
 */
clock_t clock(void)
{
#if defined USING_OS_FREERTOS
	return xTaskGetTickCount();
#else
	return g_sys_tick_cnt;
#endif
}

void delay(const uint32_t _ms)
{
#if defined USING_OS_FREERTOS
	vTaskDelay(pdMS_TO_TICKS(_ms));
#else
	uint32_t start = g_sys_tick_cnt;
    uint32_t delta = 0;

    while (delta < _ms)
	{
		delta = g_sys_tick_cnt - start;
	}
#endif
}

void reset(void)
{
	__set_FAULTMASK(1);
	NVIC_SystemReset();
}

void pwr_mode_trans(const uint8_t _mode)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);

	/* suspend the SysTick */
	SysTick->CTRL &= ~(SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);

	switch(_mode)
	{
	case PWR_MODE_SLEEP:
		PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);
		break;

	case PWR_MODE_DEEPSLEEP:
	    PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);
	    break;

	default:
		break;
	}

	SystemInit();

	/* resume the SysTick */
	SysTick->CTRL |= (SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, DISABLE);
}

int32_t wdog_enable(void)
{
#if 0 /* the individual watch dog */
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDOG_PRV);
	IWDG_SetReload(IWDOG_RLV);
	IWDG_ReloadCounter();
	IWDG_Enable();
#endif

	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	WWDG_ClearFlag();
	WWDG_SetPrescaler(WWDOG_PRV);
	WWDG_SetWindowValue(WWDOG_WV);    
	WWDG_Enable(WWDOG_RLV);
	WWDG_EnableIT();

	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);

	return 0;
}

int32_t wdog_refresh(void)
{
#if 0 /* the individual watch dog */
	IWDG_ReloadCounter();	
#endif

	WWDG_SetCounter(WWDOG_RLV);

	return 0;
}

int32_t wdog_disable(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE; 
	NVIC_Init(&NVIC_InitStructure);

	WWDG_ClearFlag();
	WWDG_DeInit();
	RCC_APB1PeriphResetCmd(RCC_APB1Periph_WWDG, DISABLE);

	return 0;
}

/**
 * @name IRQ handlers
 * @{
 */

#if !defined USING_OS_FREERTOS
/**
 * System tick timer handler.
 */
void SysTick_Handler(void)
{
	g_sys_tick_cnt++;
}
#endif

/**
 * Button IRQ handler.
 */
void BTN_IRQ_HANDLER(void)
{
	if (RESET != EXTI_GetITStatus(BTN_EXTI_LINE))
	{
		EXTI_ClearITPendingBit(BTN_EXTI_LINE);
	}
}

/**
 * Window watch dog IRQ handler.
 */
void WWDG_IRQHandler(void)
{
	reset();
}

/** @} */ /* IRQ handlers */

/*******************************************************************************
 * Local functions
 ******************************************************************************/
