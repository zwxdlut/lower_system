#include "can.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
can_msg_t g_can_rx_queue[CAN_CH1 + 1][CAN_MSG_RX_QUEUE_MAX_LENGTH]; /* receiving queue */
uint8_t g_can_rx_queue_head[CAN_CH1 + 1] = {0, 0}; /* receiving queue head */
uint8_t g_can_rx_queue_tail[CAN_CH1 + 1] = {0, 0}; /* receiving queue tail */

typedef struct
{
	PORT_Type *port_;
	uint8_t rx_pin_;
	uint8_t tx_pin_;
	port_mux_t gpio_af_;
	IRQn_Type irqs_[5];
#if defined MX_TB
	PORT_Type *trans_stb_n_port_;
	GPIO_Type *trans_stb_n_gpio_;
	uint8_t trans_stb_n_pin_;
	PORT_Type *trans_en_port_;
	GPIO_Type *trans_en_gpio_;
	uint8_t trans_en_pin_;
	PORT_Type *trans_inh_port_;
	GPIO_Type *trans_inh_gpio_;
	uint8_t trans_inh_pin_;
	IRQn_Type trans_inh_irq_;
#endif
} comm_config_t;

static comm_config_t g_comm_config[CAN_CH1 + 1] =
{
	{
		.port_             = CAN0_PORT,
		.rx_pin_           = CAN0_RX_PIN,
		.tx_pin_           = CAN0_TX_PIN,
		.gpio_af_          = CAN0_GPIO_AF,
		.irqs_             = {CAN0_ORED_IRQ, CAN0_ERROR_IRQ, CAN0_WAKEUP_IRQ, CAN0_ORED_0_15_IRQ, CAN0_ORED_16_31_IRQ},
#if defined MX_TB
		.trans_stb_n_port_ = CAN0_TRANS_STB_N_PORT,
		.trans_stb_n_gpio_ = CAN0_TRANS_STB_N_GPIO,
		.trans_stb_n_pin_  = CAN0_TRANS_STB_N_PIN,
		.trans_en_port_    = CAN0_TRANS_EN_PORT,
		.trans_en_gpio_    = CAN0_TRANS_EN_GPIO,
		.trans_en_pin_     = CAN0_TRANS_EN_PIN,
		.trans_inh_port_   = CAN0_TRANS_INH_PORT,
		.trans_inh_gpio_   = CAN0_TRANS_INH_GPIO,
		.trans_inh_pin_    = CAN0_TRANS_INH_PIN,
		.trans_inh_irq_    = CAN0_TRANS_INH_IRQ,
#endif
	},

	{
		.port_             = CAN1_PORT,
		.rx_pin_           = CAN1_RX_PIN,
		.tx_pin_           = CAN1_TX_PIN,
		.gpio_af_          = CAN1_GPIO_AF,
		.irqs_             = {CAN1_ORED_IRQ, CAN1_ERROR_IRQ, CAN1_ORED_0_15_IRQ, NotAvail_IRQn, NotAvail_IRQn},
#if defined MX_TB
		.trans_stb_n_port_ = CAN1_TRANS_STB_N_PORT,
		.trans_stb_n_gpio_ = CAN1_TRANS_STB_N_GPIO,
		.trans_stb_n_pin_  = CAN1_TRANS_STB_N_PIN,
		.trans_en_port_    = CAN1_TRANS_EN_PORT,
		.trans_en_gpio_    = CAN1_TRANS_EN_GPIO,
		.trans_en_pin_     = CAN1_TRANS_EN_PIN,
		.trans_inh_port_   = CAN1_TRANS_INH_PORT,
		.trans_inh_gpio_   = CAN1_TRANS_INH_GPIO,
		.trans_inh_pin_    = CAN1_TRANS_INH_PIN,
		.trans_inh_irq_    = CAN1_TRANS_INH_IRQ,
#endif
	}
};

static uint8_t g_handle[CAN_CH1 + 1] =
{
#if defined INST_CANCOM0
	INST_CANCOM0,
#else
	0xFF,
#endif

#if defined INST_CANCOM1
	INST_CANCOM1
#else
	0xFF
#endif
};

static flexcan_user_config_t *g_config[CAN_CH1 + 1] =
{
#if defined INST_CANCOM0
	&canCom0_InitConfig0,
#else
	NULL,
#endif

#if defined INST_CANCOM1
	&canCom1_InitConfig0
#else
	NULL
#endif
};

static flexcan_state_t *g_state[CAN_CH1 + 1] =
{
#if defined INST_CANCOM0
	&canCom0_State,
#else
	NULL,
#endif

#if defined INST_CANCOM1
	&canCom1_State
#else
	NULL
#endif
};

static flexcan_msgbuff_t g_rx_buf[CAN_CH1 + 1]; /* receiving buffer */
static int8_t g_tx_mailbox[CAN_CH1 + 1] = {31, 15}; /* sending mailboxes */
static mutex_t g_tx_mutex[CAN_CH1 + 1]; /* sending mutex */

/*******************************************************************************
 * Local function prototypes
 ******************************************************************************/
static void can_irq_handler(uint8_t _inst, flexcan_event_type_t _event_type, uint32_t _buf_index, flexcan_state_t *_state);

#if defined MX_TB
static void pin_irq_handler(void);
#endif

/*******************************************************************************
 * Functions
 ******************************************************************************/
int32_t can_init(const uint8_t _chl, const uint32_t *_filter_id_list, const uint8_t _filter_id_num)
{
	assert(CAN_CH1 >= _chl);

	/* initialize the rx queue */
	g_can_rx_queue_head[_chl] = 0;
	g_can_rx_queue_tail[_chl] = 0;

	OSIF_MutexCreate(&g_tx_mutex[_chl]);

	/* Initialize FlexCAN driver:
	   - 8 byte payload size
	   - FD disabled
	   - Bus clock as peripheral engine clock */
	FLEXCAN_DRV_Init(g_handle[_chl], g_state[_chl], g_config[_chl]);

	/* initialize the CAN filter */
	if (NULL == _filter_id_list || 0 == _filter_id_num)
	{
		/* set receiving all id messages */
		FLEXCAN_DRV_SetRxMaskType(g_handle[_chl], FLEXCAN_RX_MASK_GLOBAL);
		FLEXCAN_DRV_SetRxFifoGlobalMask(g_handle[_chl], FLEXCAN_MSG_ID_STD, 0);
	}
	else
	{
		flexcan_id_table_t id_filter_table[88];
		uint8_t size = g_config[_chl]->num_id_filters * 8 + 8 > _filter_id_num ? _filter_id_num : g_config[_chl]->num_id_filters * 8 + 8;

		memset(id_filter_table, 0, sizeof(id_filter_table));

		for (uint8_t i = 0; i < size; i++)
		{
			id_filter_table[i].id = _filter_id_list[i];
		}
			
		FLEXCAN_DRV_ConfigRxFifo(g_handle[_chl], FLEXCAN_RX_FIFO_ID_FORMAT_A, id_filter_table);
	}

	/* Install callback for can which will be invoked after the frame was
	   received and read into the specified buffer */
	FLEXCAN_DRV_InstallEventCallback(g_handle[_chl], can_irq_handler, (void *)((uint32_t)_chl));

	/* initialize the GPIOs */
	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].port_, g_comm_config[_chl].rx_pin_, g_comm_config[_chl].gpio_af_);
	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].port_, g_comm_config[_chl].tx_pin_, g_comm_config[_chl].gpio_af_);

#if defined USING_OS_FREERTOS
	/* The interrupt calls an interrupt safe API function - so its priority must
	   be equal to or lower than configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY */
	for (uint8_t i = 0; i < sizeof(g_comm_config[_chl].irqs_) && NotAvail_IRQn != g_comm_config[_chl].irqs_[i]; i++)
	{
		INT_SYS_SetPriority( g_comm_config[_chl].irqs_[i], configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
	}	
#endif

#if defined MX_TB
	/* initialize the CAN transceiver */
	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].trans_stb_n_port_, g_comm_config[_chl].trans_stb_n_pin_, PORT_MUX_AS_GPIO);
	PINS_DRV_SetPinDirection(g_comm_config[_chl].trans_stb_n_gpio_, g_comm_config[_chl].trans_stb_n_pin_, GPIO_OUTPUT_DIRECTION);
	PINS_DRV_WritePin(g_comm_config[_chl].trans_stb_n_gpio_, g_comm_config[_chl].trans_stb_n_pin_, 1);

	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].trans_en_port_, g_comm_config[_chl].trans_en_pin_, PORT_MUX_AS_GPIO);
	PINS_DRV_SetPinDirection(g_comm_config[_chl].trans_en_gpio_, g_comm_config[_chl].trans_en_pin_, GPIO_OUTPUT_DIRECTION);
	PINS_DRV_WritePin(g_comm_config[_chl].trans_en_gpio_, g_comm_config[_chl].trans_en_pin_, 1);

	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].trans_inh_port_, g_comm_config[_chl].trans_inh_pin_, PORT_MUX_AS_GPIO);
	PINS_DRV_SetPinDirection(g_comm_config[_chl].trans_inh_gpio_, g_comm_config[_chl].trans_inh_pin_, GPIO_INPUT_DIRECTION);
	PINS_DRV_SetPinIntSel(g_comm_config[_chl].trans_inh_port_, g_comm_config[_chl].trans_inh_pin_, PORT_INT_RISING_EDGE);
	PINS_DRV_SetPullSel(g_comm_config[_chl].trans_inh_port_, g_comm_config[_chl].trans_inh_pin_, PORT_INTERNAL_PULL_DOWN_ENABLED);
	INT_SYS_InstallHandler(g_comm_config[_chl].trans_inh_irq_, &pin_irq_handler, NULL);
	INT_SYS_EnableIRQ(g_comm_config[_chl].trans_inh_irq_);

#if defined USING_OS_FREERTOS
	/* The interrupt calls an interrupt safe API function - so its priority must
	   be equal to or lower than configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY */
	INT_SYS_SetPriority( g_comm_config[_chl].trans_inh_irq_, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY );
#endif
#endif

	/* trigger receiving */
	FLEXCAN_DRV_RxFifo(g_handle[_chl], &g_rx_buf[_chl]);

	return 0;
}

int32_t can_deinit(const uint8_t _chl)
{
	assert(CAN_CH1 >= _chl);

#if defined MX_TB
	PINS_DRV_ClearPinIntFlagCmd(g_comm_config[_chl].trans_inh_port_, g_comm_config[_chl].trans_inh_pin_);
	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].trans_stb_n_port_, g_comm_config[_chl].trans_stb_n_pin_, PORT_PIN_DISABLED);
	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].trans_en_port_, g_comm_config[_chl].trans_en_pin_, PORT_PIN_DISABLED);
	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].trans_inh_port_, g_comm_config[_chl].trans_inh_pin_, PORT_PIN_DISABLED);
#endif

	FLEXCAN_DRV_Deinit(g_handle[_chl]);
	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].port_, g_comm_config[_chl].rx_pin_, PORT_PIN_DISABLED);
	PINS_DRV_SetMuxModeSel(g_comm_config[_chl].port_, g_comm_config[_chl].tx_pin_, PORT_PIN_DISABLED);
	OSIF_MutexDestroy(&g_tx_mutex[_chl]);

	return 0;
}

uint8_t can_send(const uint8_t _chl, const uint32_t _id, const uint8_t _buf[], const uint8_t _size)
{
	assert(CAN_CH1 >= _chl && NULL != _buf);

	uint8_t size = 0;

    /* Set information about the data to be sent:
       - 1 byte in length
       - Standard message ID
       - Bit rate switch enabled to use a different bitrate for the data segment
       - Flexible data rate enabled
       - Use zeros for FD padding */
    flexcan_data_info_t dataInfo =
    {
		.data_length = _size,
		.msg_id_type = FLEXCAN_MSG_ID_STD,
		.enable_brs  = false,
		.fd_enable   = false,
		.fd_padding  = 0,
		.is_remote   = false
    };

	OSIF_MutexLock(&g_tx_mutex[_chl], OSIF_WAIT_FOREVER);

	/* configure the tx message buffer with channel, message_id and g_tx_mailbox[_inst]. */
	FLEXCAN_DRV_ConfigTxMb(g_handle[_chl], g_tx_mailbox[_chl], &dataInfo, _id);

	if (STATUS_SUCCESS == FLEXCAN_DRV_Send(g_handle[_chl], g_tx_mailbox[_chl], &dataInfo, _id, _buf))
	{
		status_t status = STATUS_SUCCESS;

		while (STATUS_BUSY == (status = FLEXCAN_DRV_GetTransferStatus(g_handle[_chl], g_tx_mailbox[_chl]))) {}

		if (STATUS_SUCCESS == status)
		{
			size = _size;
		}	
	}

	OSIF_MutexUnlock(&g_tx_mutex[_chl]);

	return size;
}

int32_t can_pwr_mode_trans(const uint8_t _chl, const uint8_t _mode)
{
	assert(CAN_CH1 >= _chl);

#if defined MX_TB
	PINS_DRV_WritePin(g_comm_config[_chl].trans_stb_n_gpio_, g_comm_config[_chl].trans_stb_n_pin_, _mode);
#else
	(void)_mode;
#endif

    return 0;
}

/*******************************************************************************
 * Local functions
 ******************************************************************************/
/**
 * CAN IRQ handler.
 *
 * @param [in] _inst the CAN instance
 * @param [in] _event_type the CAN event type
 * @param [in] _buf_index the message buffer index
 * @param [in] _state the driver state
 */
static void can_irq_handler(uint8_t _inst, flexcan_event_type_t _event_type, uint32_t _buf_index, flexcan_state_t *_state)
{
	(void)_buf_index;

	uint32_t chl = (uint32_t)_state->callbackParam;

	switch (_event_type)
	{
		case FLEXCAN_EVENT_RXFIFO_COMPLETE:
			/* check if the rx queue is full */
			if (g_can_rx_queue_head[chl] == (g_can_rx_queue_tail[chl] + 1) % CAN_MSG_RX_QUEUE_MAX_LENGTH)
			{
				/* dequeue */
				g_can_rx_queue_head[chl] = (g_can_rx_queue_head[chl] + 1) % CAN_MSG_RX_QUEUE_MAX_LENGTH;
			}

			/* enqueue */
			g_can_rx_queue[chl][g_can_rx_queue_tail[chl]].id_ = g_rx_buf[chl].msgId;
			g_can_rx_queue[chl][g_can_rx_queue_tail[chl]].dlc_ = g_rx_buf[chl].dataLen > 8 ? 8 : g_rx_buf[chl].dataLen;
			memcpy(g_can_rx_queue[chl][g_can_rx_queue_tail[chl]].data_, g_rx_buf[chl].data, g_can_rx_queue[chl][g_can_rx_queue_tail[chl]].dlc_);
			g_can_rx_queue_tail[chl] = (g_can_rx_queue_tail[chl] + 1) % CAN_MSG_RX_QUEUE_MAX_LENGTH;
			break;

		case FLEXCAN_EVENT_TX_COMPLETE:
		case FLEXCAN_EVENT_RXFIFO_WARNING:
		case FLEXCAN_EVENT_RXFIFO_OVERFLOW:
		case FLEXCAN_EVENT_ERROR:
		default:
			break;
	}

	/* trigger receiving */
	FLEXCAN_DRV_RxFifo(_inst, &g_rx_buf[chl]);
}

#if defined MX_TB
/**
 * Pin IRQ handler.
 */
static void pin_irq_handler(void)
{
	uint32_t pins = PINS_DRV_GetPortIntFlag(CAN0_TRANS_INH_PORT) & (1 << CAN0_TRANS_INH_PIN);

    if (pins != 0)
    {
        switch (pins)
        {
            case (1 << CAN0_TRANS_INH_PIN):
                PINS_DRV_ClearPinIntFlagCmd(CAN0_TRANS_INH_PORT, CAN0_TRANS_INH_PIN);
                break;

            default:
                PINS_DRV_ClearPortIntFlagCmd(CAN0_TRANS_INH_PORT);
                break;
        }
    }

    pins = PINS_DRV_GetPortIntFlag(CAN1_TRANS_INH_PORT) & (1 << CAN1_TRANS_INH_PIN);

    if (pins != 0)
    {
        switch (pins)
        {
            case (1 << CAN1_TRANS_INH_PIN):
                PINS_DRV_ClearPinIntFlagCmd(CAN1_TRANS_INH_PORT, CAN1_TRANS_INH_PIN);
                break;

            default:
                PINS_DRV_ClearPortIntFlagCmd(CAN1_TRANS_INH_PORT);
                break;
        }
    }
}
#endif
