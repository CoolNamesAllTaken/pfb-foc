/*
 * as5048a.hh
 *
 *  Created on: Nov 23, 2020
 *      Author: jkailimcnelly
 */

#ifndef ENCODER_INC_AS5048A_HH_
#define ENCODER_INC_AS5048A_HH_

#include "encoder.hh"
#include "stm32f7xx_hal.h"

class AS5048A : public Encoder {
private:
	SPI_HandleTypeDef * encoder_spi_;
	GPIO_TypeDef * encoder_cs_port_;
	uint16_t encoder_cs_pin_;
	uint32_t spi_timeout_;

	/* SPI Packet Assembly Functions */
	uint8_t CalcEvenParity_(uint16_t val);
	uint16_t CreateCommandPacket_(uint16_t addr, uint8_t rw);
	uint16_t CreateWritePacket_(uint16_t data);
	uint16_t ParseReceivedPacket_(uint16_t packet);

	float ReadAngle_();
	uint16_t ClearErrorFlag_();

	/* SPI Interface Functions */
	void SPITransmit16_(uint16_t tx_data);
	uint16_t SPITransmitReceive16_(uint16_t tx_data);

public:
	AS5048A(
			SPI_HandleTypeDef * encoder_spi,
			GPIO_TypeDef * encoder_cs_port,
			uint16_t encoder_cs_pin,
			uint32_t spi_timeout = 500);
	void Init();
	void Update();

};



#endif /* ENCODER_INC_AS5048A_HH_ */
