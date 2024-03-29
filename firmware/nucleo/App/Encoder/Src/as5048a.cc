#include "as5048a.hh"

#define ADDR_NOP 					0x0000
#define ADDR_CLEAR_ERROR_FLAG 		0X0001
#define ADDR_PROG_CONTROL			0x0003
#define ADDR_OTP_REG_ZERO_POS_HI	0x0016 // high byte
#define ADDR_OTP_REG_ZERO_POS_LOW	0x0017 // lower 6 LSBs
#define ADDR_DIAG_AGC				0x3FFD
#define ADDR_MAG					0x3FFE
#define ADDR_ANGLE					0x3FFF

#define CMD_WRITE					0x0
#define CMD_READ					0X1

#define DATA_DUMMY					0x0000
#define DATA_MAX					0x3FFF

#define PARSE_ERR					0xFFFF // for internal use when an invalid packet is parsed

/* NOTE: Code is written for SPI mode 1 (I think), with 8-bit words. Could be rewritten for 16-bit words using HAL NSS pin function. */

/**
 * @brief Constructor.
 */
AS5048A::AS5048A(
		SPI_HandleTypeDef * encoder_spi,
		GPIO_TypeDef * encoder_cs_port,
		uint16_t encoder_cs_pin,
		uint32_t spi_timeout)
	: encoder_spi_(encoder_spi)
	, encoder_cs_port_(encoder_cs_port)
	, encoder_cs_pin_(encoder_cs_pin)
	, spi_timeout_(spi_timeout)
{

}

/**
 * @brief Initializes the interface to the AS5048A
 */
void AS5048A::Init() {
	ClearErrorFlag_(); // clear the error flag in case it was set during a previous transaction
}

/**
 * @brief Reads the AS5048A encoder over SPI.
 */
void AS5048A::Update() {
	set_angle(ReadAngle_());
}

/**
 * @brief Calculates the parity bit to ensure that a 16-bit unsigned integer has even parity.
 * @param[in] val 16-bit value that needs a parity bit (only the 15 LS bits are read).
 * @retval The parity bit that will reside in the MS bit to make the uint16_t have even parity.
 */
uint8_t AS5048A::CalcEvenParity_(uint16_t val) {
	// Efficient method for calculating parity: https://www.geeksforgeeks.org/finding-the-parity-of-a-number-efficiently/
	val = val<<1; // mask off 16th bit (MSb)
	uint8_t x = val ^ (val>>8);
	x = x^(x>>4);
	x = x^(x>>2);
	x = x^(x>>1);
	return x&0b1 ? 1 : 0; // present parity bit to make integer has even parity
	// Old algorithm.
//	uint8_t par = 0;
//	for (uint8_t shift = 0; shift < 15; shift++) {
//		par ^= ((val >> shift) & 0x1);
//	}
//	return par;
}

/**
 * @brief Creates a data packet for specifying an AS5048A address.
 * @param[in] addr 14 bit address code.
 * @param[in] rw 1-bit read(1)/write(0) flag.
 * @retval 16-bit command packet.
 */
uint16_t AS5048A::CreateCommandPacket_(uint16_t addr, uint8_t rw) {
	uint16_t pack = addr & (0xFFFF >> 2); // ignore 2 MSbs
	pack |= (rw & 0b1) << 14; // mask r/w bit, set as bit 15
	pack |= CalcEvenParity_(pack) << 15; // set parity bit
	return pack;
}

/**
 * @brief Creates a data packet that can be written to a previously specified AS5048A address.
 * @param[in] data 14 bit data to write to the selected address.
 * @retval 16-bit write packet with parity bit and reserved bit populated.
 */
uint16_t AS5048A::CreateWritePacket_(uint16_t data) {
	uint16_t pack = data & (0xFFFF >> 2); // ignore 2 MSBs
	// bit 14 has to be 0 (already done)
	pack |= CalcEvenParity_(pack) << 15; // set parity bit
	return pack;
}

/**
 * @brief Extracts data from a packet received from the AS5048A. Can indicate a parity error with PARSE_ERR.
 * @param[in] packet Raw SPI packet received from AS5048a.
 * @retval Extracted data if parse successful, otherwise PARSE_ERR.
 */
uint16_t AS5048A::ParseReceivedPacket_(uint16_t packet) {
	if ((packet >> 14) & 0x1) {
		// EF error flag is set, issue with previous host transmission
		return PARSE_ERR;
	}
	if (CalcEvenParity_(packet) != (packet >> 15)) {
		// parity bit is incorrect
		return PARSE_ERR;
	}
	return (packet & (0xFFFF >> 2));
}

/**
 * @brief SPI interface function that reads the current angle from the encoder.
 * @retval The value of the angle that was read, or PARSE_ERR (0xFFFF) if error encountered.
 */
float AS5048A::ReadAngle_() {
	uint16_t read_cmd = CreateCommandPacket_(ADDR_ANGLE, CMD_READ);
	SPITransmit16_(read_cmd);

	uint16_t dummy_data = CreateWritePacket_(DATA_DUMMY);
	uint16_t raw_angle_val = ParseReceivedPacket_(SPITransmitReceive16_(dummy_data));
	return static_cast<float>(raw_angle_val) * 360.0f / static_cast<float>(DATA_MAX);
}

/**
 * @brief Clears the error flag from the AS5048A to allow transmissions to continue after an error.
 * @retval The contents of the error register (parity bit and error flag masked off, 14 LSb's only).
 */
uint16_t AS5048A::ClearErrorFlag_() {
	uint16_t clear_err_flag_cmd = CreateCommandPacket_(ADDR_CLEAR_ERROR_FLAG, CMD_READ);
	SPITransmit16_(clear_err_flag_cmd);
	uint16_t dummy_data = CreateWritePacket_(DATA_DUMMY);
	uint16_t error_reg_content = SPITransmitReceive16_(dummy_data) & (0xFF >> 2); // mask off parity bit and error flag
	// new error reg contents will be returned on next command
	return error_reg_content;
}

/**
 * @brief Helper utility that writes 16 bits over SPI. Used because sending MSB first is a pain.
 */
void AS5048A::SPITransmit16_(uint16_t tx_data) {
	uint8_t tx_buf[2];
	tx_buf[0] = tx_data >> 8; // MSB first
	tx_buf[1] = tx_data & 0xFF; // LSB second
	HAL_GPIO_WritePin(encoder_cs_port_, encoder_cs_pin_, GPIO_PIN_RESET);
	HAL_SPI_Transmit(encoder_spi_, (uint8_t *)&tx_buf, 2, spi_timeout_);
	HAL_GPIO_WritePin(encoder_cs_port_,  encoder_cs_pin_, GPIO_PIN_SET);
}

/**
 * @brief Helper utility that writes 16 bits and reads 16 bits over SPI. Used because sending MSB first is a pain.
 * @retval 16 bits that are read.
 */
uint16_t AS5048A::SPITransmitReceive16_(uint16_t tx_data) {
	uint8_t tx_buf[2];
	uint8_t rx_buf[2];
	tx_buf[0] = tx_data >> 8; // send MSB first
	tx_buf[1] = tx_data & 0xFF; // send LSB second
	HAL_GPIO_WritePin(encoder_cs_port_, encoder_cs_pin_, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(encoder_spi_, (uint8_t *)&tx_buf, (uint8_t *)&rx_buf, 2, spi_timeout_);
	HAL_GPIO_WritePin(encoder_cs_port_,  encoder_cs_pin_, GPIO_PIN_SET);

	uint16_t rx_data = 0;
	rx_data |= (rx_buf[0] << 8); // received MSB first
	rx_data |= rx_buf[1]; // received LSB second TODO: is this right?
	return rx_data;
}
