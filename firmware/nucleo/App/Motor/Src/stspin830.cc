/*
 * stspin830.cc
 *
 *  Created on: Nov 27, 2020
 *      Author: jkailimcnelly
 */

#include "stspin830.hh"

/* Private Constants */
const uint16_t kADCMaxCounts = 0xFFFF>>2; // 14-bit ADC value
const float kADCMaxVolts = 3.3; // [V] VDD rail of current sense ADCs
const float kADCOffsetVolts = 1.56; // [V] ADC offset voltage (from IHM16M1 datasheet)
const float kADCGain = 1.53 * 0.33; // [Ohms] Gain of current sense op-amp * sense resistor value

const uint16_t kPulseMax = 65535; // maximum counts for timer PWM pulse length

/**
 * Utility function that returns the current time in microseconds.
 * @retval Current uptime, in microseconds.
 */
uint32_t GetTickMicros() {
	return HAL_GetTick() * 1000 - SysTick->VAL / ((SysTick->LOAD + 1) / 1000);
}

/**
 * @brief Initializes the relevant channel of the STSPIN320 half-bridge.
 */
void STSPIN830::Init() {
	pid_last_update_us = GetTickMicros(); // enable time intervals to be passed to PID controller

	HAL_TIM_PWM_Start(timer_, timer_channel_id_); // get the party started
}

/**
 * Updates the PWM period of the half bridge based on the measured current. Should be called by the ConversionCplt callback
 * of the ADC, which should in turn have been called by a reset trigger event from the half bridge timer.
 */
void STSPIN830::Update() {
	// Update target current
	pid.target = target_current_;
	uint32_t curr_time_us = GetTickMicros();
	pid.Update((curr_time_us - pid_last_update_us) / 1000.0);
	pid_last_update_us = curr_time_us;
	// Calculate current
	current_ma_ = ((static_cast<float>(curr_sense_adc_voltage_) / kADCMaxCounts) - kADCOffsetVolts) / kADCGain;
	// Calculate duty cycle for closed loop control
	duty_cycle_ -= pid.get_output();
	if (duty_cycle_ > 1.0) {
		duty_cycle_ = 1.0;
	} else if (duty_cycle_ < 0.0) {
		duty_cycle_ = 0.0;
	}
	// Set duty cycle
	__HAL_TIM_SET_COMPARE(timer_, timer_channel_id_, static_cast<uint16_t>(duty_cycle_ * 65535.0));
}




