/*
 * stspin830.hh
 *
 *  Created on: Nov 27, 2020
 *      Author: jkailimcnelly
 */

#ifndef MOTOR_INC_STSPIN830_HH_
#define MOTOR_INC_STSPIN830_HH_

#include "stm32f7xx_hal.h"
#include "half_bridge.hh"

class STSPIN830 : public HalfBridge {
private:
	GPIO_TypeDef * en_port_;
	uint16_t en_pin_;

	GPIO_TypeDef * in_port_;
	uint16_t in_pin_;

	GPIO_PinState en_state_{GPIO_PIN_RESET};
	GPIO_PinState in_state_{GPIO_PIN_RESET};

	const uint16_t& curr_sense_adc_voltage_;
	uint16_t current_ma_{0};

	const uint16_t kADCMax{0xFFFF };

public:
	/**
	 * @brief Constructor for creating an instance of an STSPIN830 h-bridge interface (single channel). Can control
	 * current through the h-bridge channel via current limiting based on the provided pointer to an ADC value
	 * (should be populated via DMA) and a GPIO interface to the STSPIN830's ENx and INx pins.
	 * @param[in] en_port 					GPIO port for the ENx pin.
	 * @param[in] en_pin 					GPIO pin for the ENx pin.
	 * @param[in] in_port 					GPIO port for the INx pin.
	 * @param[in] in_pin 					GPIO pin for the INx pin.
	 * @param[in] curr_sense_adc_voltage	Pointer to the ADC current sense value, to be updated continuously over DMA.
	 * 										Passed as a const reference; will not be changed by the STSPIN830. Is a count
	 * 										out of the full resolution of the ADC.
	 */
	STSPIN830(
			GPIO_TypeDef * en_port,
			uint16_t en_pin,
			GPIO_TypeDef * in_port,
			uint16_t in_pin,
			const uint16_t& curr_sense_adc_voltage)
		: en_port_(en_port)
		, en_pin_(en_pin)
		, in_port_(in_port)
		, in_pin_(in_pin)
		, curr_sense_adc_voltage_(curr_sense_adc_voltage) {};

	void Init();
	void Update();



};



#endif /* MOTOR_INC_STSPIN830_HH_ */