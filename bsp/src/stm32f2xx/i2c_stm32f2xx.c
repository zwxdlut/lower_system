#include "i2c.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/
#if defined USING_OS_FREERTOS
SemaphoreHandle_t g_i2c_mutex[I2C_CH0 + 1] = {NULL}; /* receiving/sending mutex */
#endif

typedef struct
{
	GPIO_TypeDef *gpio_;
	uint16_t scl_pin_;
	uint16_t sda_pin_;
	uint8_t gpio_af_;
	IRQn_Type irqs_[2];
} comm_config_t;

static comm_config_t g_comm_config[I2C_CH0 + 1] =
{
	{
		.gpio_     = I2C0_GPIO,
		.scl_pin_  = I2C0_SCL_PIN,
		.sda_pin_  = I2C0_SDA_PIN,
		.gpio_af_  = I2C0_GPIO_AF,
		.irqs_     = {I2C0_EV_IRQ, I2C0_ER_IRQ},
	}
};

static I2C_HandleTypeDef g_handle[I2C_CH0 + 1] = 
{
	{
		.Instance             = I2C0_INST,
		.Init.ClockSpeed      = 400000,
		.Init.DutyCycle       = I2C_DUTYCYCLE_2,
		.Init.OwnAddress1     = 0,
		.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT,
		.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE,
		.Init.OwnAddress2     = 0,
		.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE,
		.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE,
	}
};

/******************************************************************************
 * Local function prototypes
 ******************************************************************************/

/******************************************************************************
 * Functions
 ******************************************************************************/
int32_t i2c_master_init(const uint8_t _chl, const uint32_t _baudrate, const bool _is_10bit_addr)
{
	assert(I2C_CH0 >= _chl);

	GPIO_InitTypeDef GPIO_InitStructure;
	
#if defined USING_OS_FREERTOS
	g_i2c_mutex[_chl] = xSemaphoreCreateMutex();
#endif
	
	/* initialize the GPIOs */
	I2C_GPIO_CLK_ENABLE(_chl);
	GPIO_InitStructure.Pin       = g_comm_config[_chl].scl_pin_ | g_comm_config[_chl].sda_pin_;
	GPIO_InitStructure.Mode      = GPIO_MODE_AF_OD;
	GPIO_InitStructure.Pull      = GPIO_PULLUP;
	GPIO_InitStructure.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.Alternate = g_comm_config[_chl].gpio_af_;
	HAL_GPIO_Init(g_comm_config[_chl].gpio_, &GPIO_InitStructure);
	
	/* initialize the I2C */
	I2C_CLK_ENABLE(_chl);
	g_handle[_chl].Init.ClockSpeed     = _baudrate;
	g_handle[_chl].Init.AddressingMode = _is_10bit_addr ? I2C_ADDRESSINGMODE_10BIT : I2C_ADDRESSINGMODE_7BIT;
	HAL_I2C_Init(&g_handle[_chl]);
	
	/* initialize the NVIC */
	for (uint8_t i = 0; i < sizeof(g_comm_config[_chl].irqs_); i++)
	{
		HAL_NVIC_SetPriority(g_comm_config[_chl].irqs_[i], 0, 0);
		HAL_NVIC_EnableIRQ(g_comm_config[_chl].irqs_[i]);
	}

	return 0;
}

int32_t i2c_master_deinit(const uint8_t _chl)
{
	assert(I2C_CH0 >= _chl);

	for (uint8_t i = 0; i < sizeof(g_comm_config[_chl].irqs_); i++)
	{
		HAL_NVIC_DisableIRQ(g_comm_config[_chl].irqs_[i]);
	}

	HAL_I2C_DeInit(&g_handle[_chl]);
	I2C_CLK_DISABLE(_chl);
	I2C_FORCE_RESET(_chl);
	I2C_RELEASE_RESET(_chl);
	HAL_GPIO_DeInit(g_comm_config[_chl].gpio_, g_comm_config[_chl].scl_pin_ | g_comm_config[_chl].sda_pin_);

#if defined USING_OS_FREERTOS
	vSemaphoreDelete(g_i2c_mutex[_chl]);
#endif

	return 0;
}

int32_t i2c_master_receive(const uint8_t _chl, const uint16_t _addr, uint8_t _buf[], const uint16_t _size, const bool _stop)
{
	assert(I2C_CH0 >= _chl && NULL != _buf);

	if (HAL_OK != HAL_I2C_Master_Receive_IT(&g_handle[_chl], _addr << 1, _buf, _size))
	{
		return -1;
	}

	while (HAL_I2C_STATE_READY != HAL_I2C_GetState(&g_handle[_chl])) {}

	return 0;
}

int32_t i2c_master_send(const uint8_t _chl, const uint16_t _addr, const uint8_t _buf[], const uint16_t _size, const bool _stop)
{
	assert(I2C_CH0 >= _chl && NULL != _buf);

	if (HAL_OK != HAL_I2C_Master_Transmit_IT(&g_handle[_chl], _addr << 1, (uint8_t*)_buf, _size))
	{
		return -1;
	}

	while (HAL_I2C_STATE_READY != HAL_I2C_GetState(&g_handle[_chl])) {}
	HAL_Delay(10);
	
	return 0;
}

/**
 * @name IRQ handlers
 * @{
 */

/**
 * I2C0 event IRQ handler.
 */
void I2C0_EV_IRQ_HANDLER(void)
{
	HAL_I2C_EV_IRQHandler(&g_handle[I2C_CH0]);
}

/**
 * I2C0 error IRQ handler.
 */
void I2C0_ER_IRQ_HANDLER(void)
{
	HAL_I2C_ER_IRQHandler(&g_handle[I2C_CH0]);
}

/** @} */ /* IRQ handlers */

/******************************************************************************
 * Local functions
 ******************************************************************************/
