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
#include "pid_controller.hh"

class STSPIN830 : public HalfBridge {
private:
	TIM_HandleTypeDef * timer_;
	uint32_t timer_channel_id_;

	const volatile uint16_t& curr_sense_adc_counts_;
	float current_ma_{0}; // current flowing to GND via sense resistor (bottom side Id)

	uint32_t pid_last_update_us{0};
	float duty_cycle_{0};

	const uint16_t kADCMax{0xFFFF};

	bool is_initialized_{false};

public:
	PIDController pid;

	/**
	 * @brief Constructor for creating an instance of an STSPIN830 h-bridge interface (single channel). Can control
	 * current through the h-bridge channel via current limiting based on the provided pointer to an ADC value
	 * (should be populated via DMA) and a GPIO interface to the STSPIN830's ENx and INx pins.
	 * @param[in] timer 					HAL Timer handle for the advanced timer used for the EN/IN pin PWM.
	 * @param[in] timer_channel_id 			Identifier of the channel on the HAL timer being used for the EN/IN pin PWM.
	 * @param[in] curr_sense_adc_voltage	Pointer to the ADC current sense value, to be updated continuously over DMA.
	 * 										Passed as a const reference; will not be changed by the STSPIN830. Is a count
	 * 										out of the full resolution of the ADC.
	 */
	STSPIN830(
			TIM_HandleTypeDef * timer,
			uint32_t timer_channel_id,
			const volatile uint16_t& curr_sense_adc_voltage)
		: timer_(timer)
		, timer_channel_id_(timer_channel_id)
		, curr_sense_adc_counts_(curr_sense_adc_voltage)
		, pid(0.0005, 0.0, 0.000001, current_ma_){};

	void Init();
	void Update();



};



#endif /* MOTOR_INC_STSPIN830_HH_ */
