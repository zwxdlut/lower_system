
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "serial_port/serial_port.h"
#include "can/can.h"
#include "diag/diag_client.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/          
#define DUMMY_PACKAGE                          0x36u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, \
						                       0x0Cu, 0x0Du, 0x0Eu, 0x0Fu, 0x10u, 0x11u, 0x12u, 0x13u, 0x14u, 0x15u, 0x16u, 0x17u, \
								               0x36u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, \
								               0x0Cu, 0x0Du, 0x0Eu, 0x0Fu, 0x10u, 0x11u, 0x12u, 0x13u, 0x14u, 0x15u, 0x16u, 0x17u, \
								               0x36u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, \
								               0x0Cu, 0x0Du, 0x0Eu, 0x0Fu, 0x10u, 0x11u, 0x12u, 0x13u, 0x14u, 0x15u, 0x16u, 0x17u, \
								               0x36u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, \
								               0x0Cu, 0x0Du, 0x0Eu, 0x0Fu, 0x10u, 0x11u, 0x12u, 0x13u, 0x14u, 0x15u, 0x16u, 0x17u, \
								               0x36u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, \
								               0x0Cu, 0x0Du, 0x0Eu, 0x0Fu, 0x10u, 0x11u, 0x12u, 0x13u, 0x14u, 0x15u, 0x16u, 0x17u, \
								               0x36u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, \
								               0x0Cu, 0x0Du, 0x0Eu, 0x0Fu, 0x10u, 0x11u, 0x12u, 0x13u, 0x14u, 0x15u, 0x16u, 0x17u

/**
 * @name Communication protocal with the lower computer
 * @{
 */
#define ID_LENGTH                               2

/**
 * @name Update protocal
 * @{
 */
#define UPDATE_NOTIFY_ID                        0x000C
/** @} */ // Update protocal

/**
 * @defgroup Transfer data protocal
 * @{
 */
#define TRANSFER_DATA_ID                        0x000D
#define TRANSFER_RE_SEND                        0x41
#define TRANSFER_ACK                            0x45
#define TRANSFER_BREAK                          0x46
/** @} */ // Ttransfer data protocal
/** @} */ // Communication protocal with the lower computer

/*******************************************************************************
 * Variables
 ******************************************************************************/
 /**
  * @name Diagnostic
  * @{
  */
static IsoTpLink g_client_link;                      /**< client ISOTP link */
static uint8_t   g_client_rx_buf[DIAG_MAX_BUF_SIZE]; /**< client receive buffer */
static uint8_t   g_client_tx_buf[DIAG_MAX_BUF_SIZE]; /**< client transmit buffer */
/** @} */ // Diagnostic

static can g_can(USBCAN_II, CAN_DEV_IDX0);      /**< CAN device */

/*******************************************************************************
 * Local Function prototypes
 ******************************************************************************/
/**
  * @name Callbacks
  * @{
  */
static uint8_t client_receive_callback(uint32_t* const _id, uint8_t* const _buf, const uint8_t _size);
static int32_t transmit_callback(const uint32_t _id, const uint8_t* _buf, const uint8_t _size);
/** @} */ // Callbacks

static void update_by_serial_port(std::string &_fp);
static void update_by_can(std::string &_fp);
static uint32_t sys_time(void);
static void hexstr2bytes(const uint8_t* _src, uint8_t* _dst, const uint16_t _size);
static void debug(const char* _message, ...);
static void print_buf(const char* _prefix, const uint32_t _id, const uint8_t* _buf, const uint16_t _size);

/*******************************************************************************
 * Functions
 ******************************************************************************/
int main(void)
{
	while (1)
	{
		std::string str;
		char type;

		printf("please input the file path: ");
		std::cin >> str;
		printf("please select the communication type:\nS)Serial port(default)\nC)CAN\n");
		while ('\n' != getchar()) {}
		type = getchar();

		if ('C' == type)
		{
			update_by_can(str);
		}
		else if ('S' == type || '\n' == type)
		{
			update_by_serial_port(str);
		}
	}

	return 0;
}

/*******************************************************************************
 * Local Functions
 ******************************************************************************/
static uint8_t client_receive_callback(uint32_t* const _id, uint8_t* const _buf, const uint8_t _size)
{
	assert(NULL != _id && NULL != _buf);

	uint8_t size = 0;

	if (0 < (size = g_can.receive(CAN_CHL0, _id, _buf, _size)))
	{
		print_buf("CAN RX", *_id, _buf, size);
	}

	return size;
}

static int32_t transmit_callback(const uint32_t _id, const uint8_t* const _buf, const uint8_t _size)
{
	assert(NULL != _buf);
	g_can.send(CAN_CHL0, _id, _buf, _size);
	print_buf("CAN TX", _id, _buf, _size);
	return 0;
}

static void update_by_serial_port(std::string& _fp)
{
	std::ifstream ifs;
	std::string   type;
	std::string   chl = "\\\\.\\COM";
	serial_port   sp;
	uint16_t      block_size = 0;
	int32_t       remained_size = 0;
	uint32_t      duration = 0;
	uint32_t      temp = 0;

	// open the file
	type = std::strrchr(_fp.c_str(), '.');

	if (".srec" == type || ".SREC" == type)
	{
		ifs.open(_fp);
	}
	else if (".bin" == type)
	{
		ifs.open(_fp, std::ios::binary);
	}

	if (!ifs.is_open())
	{
		printf("open the file failed!\n");
		return;
	}

	// get the file length
	ifs.seekg(0, ifs.end);
	remained_size = (int32_t)ifs.tellg();
	ifs.seekg(0, ifs.beg);

	// open the serial port
	printf("please input the serial port channel number: ");
	std::cin >> temp;
	chl += std::to_string(temp);
	sp.open(chl, 115200, SP_DATA_BITS_8, SP_STOP_BITS_1, SP_PARITY_MODE_NONE);

	// notify update
	temp = UPDATE_NOTIFY_ID;
	sp.send_with_header((uint8_t*)(&temp), ID_LENGTH);
	print_buf("COM TX", 0, (uint8_t*)(&temp), ID_LENGTH);

	printf("start waiting for update request...\n");

	while (1)
	{
		std::string phrase;
		uint16_t    size = 0;
		uint8_t     buf[SERIAL_PORT_BUFFER_SIZE];

		// receive routine
		if (0 == (size = sp.receive_with_header_poll(buf, ID_LENGTH + 2)))
		{
			continue;
		}

		print_buf("COM RX", 0, buf, size);

		if ((TRANSFER_DATA_ID == *((uint16_t*)buf) && TRANSFER_ACK == buf[ID_LENGTH]) || UPDATE_NOTIFY_ID == *((uint16_t*)buf))
		{
			if (ifs.eof())
			{
				break;
			}

			if (UPDATE_NOTIFY_ID == *((uint16_t*)buf))
			{
				block_size = *((uint16_t*)(buf + ID_LENGTH));
				*((uint16_t*)buf) = TRANSFER_DATA_ID;
				printf("programing...\n");
				duration = sys_time();
			}

			if (".srec" == type || ".SREC" == type)
			{
				std::getline(ifs, phrase);

				if (phrase.empty())
				{
					continue;
				}

				debug("srec phrase: %s\n", phrase.c_str());
				memcpy(buf + ID_LENGTH, phrase.c_str(), phrase.length());
				size = ID_LENGTH + (uint16_t)phrase.length();
			}
			else if (".bin" == type)
			{				
				ifs.read(reinterpret_cast<char*>(buf + ID_LENGTH), block_size);

				if (remained_size >= block_size)
				{
					size = block_size;
				}
				else
				{
					size = remained_size;
				}

				remained_size -= size;
				size += ID_LENGTH;
			}
		}
		else if (!(TRANSFER_DATA_ID == *((uint16_t*)buf) && TRANSFER_RE_SEND == buf[ID_LENGTH]))
		{
			debug("Invalid control code, continue waiting...\n");
			continue;
		}

		// Send routine
		sp.send_with_header(buf, size);
		print_buf("COM TX", 0, buf, size);
	}

	printf("program done(%d ms)!\n", (sys_time() - duration));
	sp.close();
	ifs.close();
}

static void update_by_can(std::string &_fp)
{
	std::ifstream ifs;
	std::string   type;
	uint32_t      address = 0;
	uint32_t      size = 0;
	uint32_t      download_size = 0;
	uint32_t      remained_size = 0;
	uint8_t       buf[DIAG_MAX_BUF_SIZE];
	uint8_t       *code_buf = NULL;
	uint32_t      duration = 0;

	// open the file
	type = std::strrchr(_fp.c_str(), '.');

	if (".srec" == type || ".SREC" == type)
	{
		ifs.open(_fp);
	}
	else if (".bin" == type)
	{
		ifs.open(_fp, std::ios::binary);
	}

	if (!ifs.is_open())
	{
		printf("open the file failed!\n");
		return;
	}

	// get the file length
	ifs.seekg(0, ifs.end);
	remained_size = (uint32_t)ifs.tellg();
	ifs.seekg(0, ifs.beg);

	// open and initialize the CAN device
	g_can.open();
	g_can.init(CAN_CHL0);
	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	// initialize the diagnostic
	memset(g_client_tx_buf, 0, sizeof(g_client_tx_buf));
	memset(g_client_rx_buf, 0, sizeof(g_client_rx_buf));
	diag_client_init(&g_client_link, CLIENT_TX_ID, CLIENT_RX_ID
		, g_client_tx_buf, sizeof(g_client_tx_buf)
		, g_client_rx_buf, sizeof(g_client_rx_buf)
		, transmit_callback, client_receive_callback, sys_time, debug);

	// ECU reset
	buf[0] = UDS_SID_ECU_RESET;
	buf[1] = UDS_ECU_RESET_SF_SOFT;
	diag_client_request(&g_client_link, buf, 2);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	// tester present
	buf[0] = UDS_SID_TESTER_PRESENT;
	buf[1] = UDS_TESTER_PRESENT_SF_ZERO;
	diag_client_request(&g_client_link, buf, 2);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));

	// enter extend session
	buf[0] = UDS_SID_DIAG_SESSION_CTRL;
	buf[1] = UDS_DIAG_SESSION_CTRL_SF_EXTEND_MODE;
	diag_client_request(&g_client_link, buf, 2);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));

	// control DTC setting
	buf[0] = UDS_SID_CTRL_DTC_SETTING;
	buf[1] = UDS_CTRL_DTC_SETTING_SF_OFF;
	diag_client_request(&g_client_link, buf, 2);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));

	// communication control
	buf[0] = UDS_SID_COM_CTRL;
	buf[1] = UDS_COM_CTRL_SF_DIS_RX_TX;
	buf[2] = COMM_MSG_TYPE_MASK_NCM | COMM_MSG_TYPE_MASK_NWMCM;
	diag_client_request(&g_client_link, buf, 3);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));

	// enter program session
	buf[0] = UDS_SID_DIAG_SESSION_CTRL;
	buf[1] = UDS_DIAG_SESSION_CTRL_SF_PROGRAM_MODE;
	diag_client_request(&g_client_link, buf, 2);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));

	// erase memory
	printf("please input the erase flash start address(hex):");
	std::cin >> std::hex >> address;
	printf("please input the erase flash size(hex):");
	std::cin >> size;
	buf[0] = UDS_SID_ROUTINE_CTRL;
	buf[1] = UDS_ROUTINE_CTRL_SF_START;
	buf[2] = UDS_RID_ERASE_MEM >> 8;
	buf[3] = (uint8_t)UDS_RID_ERASE_MEM;
	buf[4] = 0x44;
	*((uint32_t*)(buf + 5)) = address;
	bytesswap(buf + 5, 4);
	*((uint32_t*)(buf + 9)) = size;
	bytesswap(buf + 9, 4);
	printf("erasing...\n");
	duration = sys_time();
	diag_client_request(&g_client_link, buf, 13);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));
	printf("erase done(%d ms)!\n", (sys_time() - duration));

	// download routine
	printf("please input the download size(dec): ");
	std::cin >> std::dec >> download_size;
	code_buf = new uint8_t[download_size + 100];
	memset(code_buf, 0xFF, download_size + 100);
	printf("programing...\n");
	duration = sys_time();

	while (!ifs.eof() || 0 != remained_size)
	{
		uint32_t n = 0;
		uint32_t block_size = 0;
		uint8_t  block_count = 0;
		uint8_t* p = NULL;

		if (".bin" == type)
		{
			ifs.read(reinterpret_cast<char*>(code_buf), download_size);

			if (remained_size >= download_size)
			{
				size = download_size;
			}
			else
			{
				size = remained_size;
			}

			remained_size -= size;
			print_buf("bin data", 0, code_buf, size);
			
			// request download
			buf[0] = UDS_SID_REQT_DOWNLOAD;
			buf[1] = 0;
			buf[2] = 0x44;
			*((uint32_t*)(buf + 3)) = address;
			bytesswap(buf + 3, 4);
			*((uint32_t*)(buf + 7)) = size;
			bytesswap(buf + 7, 4);
			diag_client_request(&g_client_link, buf, 11);
			diag_client_poll_response(&g_client_link, buf, sizeof(buf));
			memcpy(&block_size, buf + 2, buf[1] >> 4);
			bytesswap(&block_size, buf[1] >> 4);
			address += size;

			// transfer data
			n = 0;
			block_count = 0;
			p = code_buf;

			do
			{
				n = size > block_size ? block_size : size;
				buf[0] = UDS_SID_TRANSFER_DATA;
				buf[1] = ++block_count;
				memcpy(buf + 2, p, n);
				diag_client_request(&g_client_link, buf, n + 2);
				diag_client_poll_response(&g_client_link, buf, sizeof(buf));
				p += n;
			} while (0 != (size -= n));

			memset(code_buf, 0xFF, download_size);

			// request transfer exit
			buf[0] = UDS_SID_REQT_TRANSFER_EXIT;
			diag_client_request(&g_client_link, buf, 1);
			diag_client_poll_response(&g_client_link, buf, sizeof(buf));
		}
		else if (".srec" == type || ".SREC" == type)
		{
			static bool phrase_started = false;
			std::string phrase;
			uint32_t addr = 0;
			uint32_t addr_len = 0;
			uint8_t  temp_buf[100];

			std::getline(ifs, phrase);

			if (phrase.empty())
			{
				continue;
			}

			debug("srec phrase: %s\n", phrase.c_str());
			hexstr2bytes((uint8_t*)(phrase.c_str() + 2), temp_buf, (uint16_t)phrase.length() - 2);

			switch (phrase[1])
			{
			case '1':
				addr_len = 2;
				goto CONTINUE;

			case '2':
				addr_len = 3;
				goto CONTINUE;

			case '3':
				addr_len = 4;
CONTINUE:
				memcpy(&addr, temp_buf + 1, addr_len);
				bytesswap(&addr, addr_len);

				if (!phrase_started)
				{
					address = addr;
					phrase_started = true;
				}

				if (download_size <= (addr - address))
				{
					size = download_size;

					// request download
					buf[0] = UDS_SID_REQT_DOWNLOAD;
					buf[1] = 0;
					buf[2] = 0x44;
					*((uint32_t*)(buf + 3)) = address;
					bytesswap(buf + 3, 4);
					*((uint32_t*)(buf + 7)) = size;
					bytesswap(buf + 7, 4);
					diag_client_request(&g_client_link, buf, 11);
					diag_client_poll_response(&g_client_link, buf, sizeof(buf));
					memcpy(&block_size, buf + 2, buf[1] >> 4);
					bytesswap(&block_size, buf[1] >> 4);
					address += size;

					// transfer data
					n = 0;
					block_count = 0;
					p = code_buf;
					do
					{
						n = size > block_size ? block_size : size;
						buf[0] = UDS_SID_TRANSFER_DATA;
						buf[1] = ++block_count;
						memcpy(buf + 2, p, n);
						diag_client_request(&g_client_link, buf, n + 2);
						diag_client_poll_response(&g_client_link, buf, sizeof(buf));
						p += n;
					} while (0 != (size -= n));
					memset(code_buf, 0xFF, download_size);
					memcpy(code_buf, code_buf + download_size, addr - address);

					// request transfer exit
					buf[0] = UDS_SID_REQT_TRANSFER_EXIT;
					diag_client_request(&g_client_link, buf, 1);
					diag_client_poll_response(&g_client_link, buf, sizeof(buf));
				}

				memcpy(code_buf + (addr - address), temp_buf + addr_len + 1, temp_buf[0] - addr_len - 1);
				break;

			case '7':
			case '8':
			case '9':
				size = download_size;
				n = 0;
				block_count = 0;
				p = code_buf;

				// request download
				buf[0] = UDS_SID_REQT_DOWNLOAD;
				buf[1] = 0;
				buf[2] = 0x44;
				*((uint32_t*)(buf + 3)) = address;
				bytesswap(buf + 3, 4);
				*((uint32_t*)(buf + 7)) = size;
				bytesswap(buf + 7, 4);
				diag_client_request(&g_client_link, buf, 11);
				diag_client_poll_response(&g_client_link, buf, sizeof(buf));
				memcpy(&block_size, buf + 2, buf[1] >> 4);
				bytesswap(&block_size, buf[1] >> 4);

				// transfer data
				do
				{
					n = size > block_size ? block_size : size;
					buf[0] = UDS_SID_TRANSFER_DATA;
					buf[1] = ++block_count;
					memcpy(buf + 2, p, n);
					diag_client_request(&g_client_link, buf, n + 2);
					diag_client_poll_response(&g_client_link, buf, sizeof(buf));
					p += n;
				} while (0 != (size -= n));

				// request transfer exit
				buf[0] = UDS_SID_REQT_TRANSFER_EXIT;
				diag_client_request(&g_client_link, buf, 1);
				diag_client_poll_response(&g_client_link, buf, sizeof(buf));
				break;

			default:
				phrase_started = false;
				break;
			}
		}
	}

	printf("program done(%d ms)!\n", (sys_time() - duration));
	delete []code_buf;
	
	// check program dependence
	buf[0] = UDS_SID_ROUTINE_CTRL;
	buf[1] = UDS_ROUTINE_CTRL_SF_START;
	buf[2] = UDS_RID_CHECK_PROM_DPED >> 8;
	buf[3] = (uint8_t)UDS_RID_CHECK_PROM_DPED;
	diag_client_request(&g_client_link, buf, 8);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));

	// ECU reset
	buf[0] = UDS_SID_ECU_RESET;
	buf[1] = UDS_ECU_RESET_SF_HARD;
	diag_client_request(&g_client_link, buf, 2);
	diag_client_poll_response(&g_client_link, buf, sizeof(buf));

	diag_client_deinit(&g_client_link);
	g_can.close();
	ifs.close();
}

static uint32_t sys_time(void)
{
	return (1000 * clock() / CLOCKS_PER_SEC);
}

static void hexstr2bytes(const uint8_t *_src, uint8_t *_dst, const uint16_t _size)
{
	uint8_t high_byte = 0;
	uint8_t low_byte = 0;

	for (uint16_t i = 0; i < _size; i += 2)
	{
		high_byte = toupper(_src[i]);
		if (i + 1 < _size)
		{
			low_byte = toupper(_src[i + 1]);
		}
		else
		{
			low_byte = 0;
		}
			
		if (high_byte > 0x39)
		{
			high_byte -= 0x37;
		}
		else
		{
			high_byte -= 0x30;
		}
			
		if (low_byte > 0x39)
		{
			low_byte -= 0x37;
		}
		else
		{
			low_byte -= 0x30;
		}

		_dst[i / 2] = (high_byte << 4) | low_byte;
	}
}

static void debug(const char* _info, ...)
{
#ifdef _UDEBUG
	va_list args;
	va_start(args, _info);
	vprintf(_info, args);
	va_end(args);
#endif
}

static void print_buf(const char* _prefix, const uint32_t _id, const uint8_t* _buf, const uint16_t _size)
{
#if defined _UDEBUG
	static std::mutex mtx;
	std::lock_guard<std::mutex> guard(mtx);

	printf("%s(0x%X,%d): ", _prefix, (unsigned int)_id, _size);

	for (uint16_t i = 0; i < _size; i++)
	{
		printf("%02X ", _buf[i]);
	}

	printf("\n");
#endif
}