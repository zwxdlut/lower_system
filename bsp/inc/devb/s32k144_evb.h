#ifndef __S32K144_EVB_H__
#define __S32K144_EVB_H__

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
#define LED0_PORT       					    PORTD
#define LED0_GPIO      						    PTD
#define LED0_PIN          					    0

#define LED1_PORT       					    PORTD
#define LED1_GPIO       					    PTD
#define LED1_PIN           					    16

#define LED2_PORT       					    PORTD
#define LED2_GPIO      						    PTD
#define LED2_PIN           					    15

#define LED_ON          					    0
#define LED_OFF         					    1
/** @} */ /* LEDs configuration */

/**
 * @name Buttons configuration
 * @{
 */
#define BTN_PORT        					    PORTC
#define BTN_GPIO        					    PTC
#define BTN_PIN         					    13
#define BTN_IRQ                                 PORTC_IRQn
/** @} */ /* Buttons configuration */

/**
 * @name UART configuration
 * @{
 */
#define UART0_PORT                              PORTB
#define UART0_RX_PIN                            0
#define UART0_TX_PIN                            1
#define UART0_GPIO_AF                           PORT_MUX_ALT2
#define UART0_IRQ                               LPUART0_RxTx_IRQn

#define UART1_PORT                              PORTC
#define UART1_RX_PIN                            6
#define UART1_TX_PIN                            7
#define UART1_GPIO_AF                           PORT_MUX_ALT2
#define UART1_IRQ                               LPUART1_RxTx_IRQn
/** @} */ /* UART configuration */

/** 
 * @name CAN configuration
 * @{
 */
#define CAN0_PORT                               PORTE
#define CAN0_RX_PIN                             4
#define CAN0_TX_PIN                             5
#define CAN0_GPIO_AF                            PORT_MUX_ALT5
#define CAN0_ORED_IRQ                           CAN0_ORed_IRQn
#define CAN0_ERROR_IRQ                          CAN0_Error_IRQn
#define CAN0_WAKEUP_IRQ                         CAN0_Wake_Up_IRQn
#define CAN0_ORED_0_15_IRQ                      CAN0_ORed_0_15_MB_IRQn
#define CAN0_ORED_16_31_IRQ                     CAN0_ORed_16_31_MB_IRQn
	
#define CAN1_PORT                               PORTC
#define CAN1_RX_PIN                             16
#define CAN1_TX_PIN                             17
#define CAN1_GPIO_AF                            PORT_MUX_ALT3
#define CAN1_ORED_IRQ                           CAN1_ORed_IRQn
#define CAN1_ERROR_IRQ                          CAN1_Error_IRQn
#define CAN1_ORED_0_15_IRQ                      CAN1_ORed_0_15_MB_IRQn
/** @} */ /* CAN configuration */

/** 
 * @name I2C configuration
 * @{
 */
#define I2C0_PORT                               PORTA
#define I2C0_SCL_PIN                            3
#define I2C0_SDA_PIN                            2
#define I2C0_GPIO_AF                            PORT_MUX_ALT3
#define I2C0_IRQ                                LPI2C0_Master_IRQn
/** @} */ /* I2C configuration */

/**
 * @name SPI configuration
 * @{
 */
#define SPI0_SCK_PORT                           PORTB
#define SPI0_SCK_PIN                            14
#define SPI0_SDI_PORT                           PORTD
#define SPI0_SDI_PIN                            1
#define SPI0_SDO_PORT                           PORTD
#define SPI0_SDO_PIN                            2
#define SPI0_CS_PORT                            PORTD
#define SPI0_CS_PIN                             3
#define SPI0_GPIO_AF                            PORT_MUX_ALT3
#define SPI0_IRQ                                LPSPI1_IRQn
/** @} */ /* SPI configuration */

#ifdef __cplusplus
}
#endif

#endif /* __S32K144_EVB_H__ */
