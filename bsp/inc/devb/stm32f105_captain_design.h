#ifndef __STM32F10x_CAPTAIN_DESIGN_H__
#define __STM32F10x_CAPTAIN_DESIGN_H__

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/**
 * @name LEDs configuration
 * @{
 */
#define LED0_GPIO                               GPIOC
#define LED0_PIN                                GPIO_Pin_0
#define LED0_GPIO_CLK_ENABLE()                  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE)
#define LED0_GPIO_CLK_DISABLE()                 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, DISABLE)

#define LED1_GPIO                               GPIOC
#define LED1_PIN                                GPIO_Pin_1
#define LED1_GPIO_CLK_ENABLE()                  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE)
#define LED1_GPIO_CLK_DISABLE()                 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, DISABLE)

#define LED2_GPIO                               GPIOC
#define LED2_PIN                                GPIO_Pin_2
#define LED2_GPIO_CLK_ENABLE()                  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE)
#define LED2_GPIO_CLK_DISABLE()                 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, DISABLE)

#define LED_ON                                  Bit_RESET
#define LED_OFF                                 Bit_SET
/** @} */ /* LEDs configuration */

/**
 * @name Buttons configuration
 * @{
 */
#define BTN_GPIO                                GPIOB
#define BTN_PIN                                 GPIO_Pin_14
#define BTN_PORT_SRC                            GPIO_PortSourceGPIOB
#define BTN_PIN_SRC                             GPIO_PinSource14
#define BTN_EXTI_LINE                           EXTI_Line14
#define BTN_IRQ                                 EXTI15_10_IRQn
#define BTN_IRQ_HANDLER                         EXTI15_10_IRQHandler
#define BTN_GPIO_CLK_ENABLE()                   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE)
#define BTN_GPIO_CLK_DISABLE()                  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, DISABLE)
/** @} */ /* Buttons configuration */

/**
 * @name UART configuration
 * @{
 */
#define UART0_GPIO                              GPIOA
#define UART0_RX_PIN                            GPIO_Pin_10
#define UART0_TX_PIN                            GPIO_Pin_9
#define UART0_INST                              USART1
#define UART0_IRQ                               USART1_IRQn
#define UART0_IRQ_HANDLER                       USART1_IRQHandler
#define UART0_RX_DMA_CHANNEL                    DMA1_Channel5
#define UART0_TX_DMA_CHANNEL                    DMA1_Channel4
#define UART0_RX_DMA_IRQ                        DMA1_Channel5_IRQn
#define UART0_TX_DMA_IRQ                        DMA1_Channel4_IRQn
#define UART0_TX_DMA_IRQ_HANDLER                DMA1_Channel4_IRQHandler
#define UART0_DMA_IT_TC                         DMA1_IT_TC4
#define UART0_USE_DMA_RX                        0
#define UART0_USE_DMA_TX                        0

#define UART1_GPIO                              GPIOA
#define UART1_RX_PIN                            GPIO_Pin_3
#define UART1_TX_PIN                            GPIO_Pin_2
#define UART1_INST                              USART2
#define UART1_IRQ                               USART2_IRQn
#define UART1_IRQ_HANDLER                       USART2_IRQHandler
#define UART1_RX_DMA_CHANNEL                    DMA1_Channel6
#define UART1_TX_DMA_CHANNEL                    DMA1_Channel7
#define UART1_RX_DMA_IRQ                        DMA1_Channel6_IRQn
#define UART1_TX_DMA_IRQ                        DMA1_Channel7_IRQn
#define UART1_TX_DMA_IRQ_HANDLER                DMA1_Channel7_IRQHandler
#define UART1_DMA_IT_TC                         DMA1_IT_TC7
#define UART1_USE_DMA_RX                        0
#define UART1_USE_DMA_TX                        0

#define UART2_GPIO                              GPIOB
#define UART2_RX_PIN                            GPIO_Pin_11
#define UART2_TX_PIN                            GPIO_Pin_10
#define UART2_INST                              USART3
#define UART2_IRQ                               USART3_IRQn
#define UART2_IRQ_HANDLER                       USART3_IRQHandler
#define UART2_RX_DMA_CHANNEL                    DMA1_Channel3
#define UART2_TX_DMA_CHANNEL                    DMA1_Channel2
#define UART2_RX_DMA_IRQ                        DMA1_Channel3_IRQn
#define UART2_TX_DMA_IRQ                        DMA1_Channel2_IRQn
#define UART2_TX_DMA_IRQ_HANDLER                DMA1_Channel2_IRQHandler
#define UART2_DMA_IT_TC                         DMA1_IT_TC2
#define UART2_USE_DMA_RX                        0
#define UART2_USE_DMA_TX                        0

#define UART_GPIO_CLK_ENABLE(INDEX)             do { if (0 == (INDEX)) { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); } else if (1 == (INDEX))\
                                                                       { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); } else\
                                                                       { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); }} while (0)

#define UART_GPIO_CLK_DISABLE(INDEX)            do { if (0 == (INDEX)) { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, DISABLE); } else if (1 == (INDEX))\
                                                                       { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, DISABLE); } else\
                                                                       { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, DISABLE); }} while (0)

#define UART_CLK_ENABLE(INDEX)                  do { if (0 == (INDEX)) { RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); } else if (1 == (INDEX))\
                                                                       { RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); } else\
                                                                       { RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE); }} while (0)

#define UART_CLK_DISABLE(INDEX)                 do { if (0 == (INDEX)) { RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, DISABLE); } else if (1 == (INDEX))\
                                                                       { RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, DISABLE); } else\
                                                                       { RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, DISABLE); }} while (0)

#define UART_FORCE_RESET(INDEX)                 do { if (0 == (INDEX)) { RCC_APB2PeriphResetCmd(RCC_APB2Periph_USART1, ENABLE); } else if (1 == (INDEX))\
                                                                       { RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART2, ENABLE); } else\
                                                                       { RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART3, ENABLE); }} while (0)

#define UART_RELEASE_RESET(INDEX)               do { if (0 == (INDEX)) { RCC_APB2PeriphResetCmd(RCC_APB2Periph_USART1, DISABLE); } else if (1 == (INDEX))\
                                                                       { RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART2, DISABLE); } else\
                                                                       { RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART3, DISABLE); }} while (0)
/** @} */ /* UART configuration */

/** 
 * @name CAN configuration
 * @{
 */
#define CAN0_GPIO                               GPIOB
#define CAN0_RX_PIN                             GPIO_Pin_8
#define CAN0_TX_PIN                             GPIO_Pin_9
#define CAN0_INST                               CAN1
#define CAN0_GPIO_REMAP                         GPIO_Remap1_CAN1
#define CAN0_RX_IRQ                             CAN1_RX0_IRQn
#define CAN0_RX_IRQ_HANDLER                     CAN1_RX0_IRQHandler

#define CAN1_GPIO                               GPIOB
#define CAN1_RX_PIN                             GPIO_Pin_12
#define CAN1_TX_PIN                             GPIO_Pin_13
#define CAN1_INST                               CAN2
#define CAN1_GPIO_REMAP                         0
#define CAN1_RX_IRQ                             CAN2_RX0_IRQn
#define CAN1_RX_IRQ_HANDLER                     CAN2_RX0_IRQHandler

#define CAN_GPIO_CLK_ENABLE(INDEX)              do { if (0 == (INDEX)) { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); } else\
                                                                       { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); }} while (0)

#define CAN_GPIO_CLK_DISABLE(INDEX)             do { if (0 == (INDEX)) { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, DISABLE)(); } else\
                                                                       { RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, DISABLE)(); }} while (0)

#define CAN_CLK_ENABLE(INDEX)                   do { if (0 == (INDEX)) { RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE); } else\
                                                                       { RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1 | RCC_APB1Periph_CAN2, ENABLE); }} while (0)

#define CAN_CLK_DISABLE(INDEX)                  do { if (0 == (INDEX)) { RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, DISABLE); } else\
                                                                       { RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1 | RCC_APB1Periph_CAN2, DISABLE); }} while (0)

#define CAN_FORCE_RESET(INDEX)                  do { if (0 == (INDEX)) { RCC_APB1PeriphResetCmd(RCC_APB1Periph_CAN1, ENABLE); } else\
                                                                       { RCC_APB1PeriphResetCmd(RCC_APB1Periph_CAN2, ENABLE); }} while (0)

#define CAN_RELEASE_RESET(INDEX)                do { if (0 == (INDEX)) { RCC_APB1PeriphResetCmd(RCC_APB1Periph_CAN1, DISABLE); } else\
                                                                       { RCC_APB1PeriphResetCmd(RCC_APB1Periph_CAN2, DISABLE); }} while (0)
                                                                       
#define CAN_SLAVE_START_FILTER_BANK_NUM         21 /**< slave CAN start filter bank number */
/** @} */ /* CAN configuration */

/** 
 * @name I2C configuration
 * @{
 */
#define I2C0_INST                               I2C1
#define I2C0_EV_IRQ                             I2C1_EV_IRQn
#define I2C0_EV_IRQ_HANDLER                     I2C1_EV_IRQHandler
#define I2C0_ER_IRQ                             I2C1_ER_IRQn
#define I2C0_ER_IRQ_HANDLER                     I2C1_ER_IRQHandler
/** @} */ /* I2C configuration */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_CAPTAIN_DESIGN_H__ */
