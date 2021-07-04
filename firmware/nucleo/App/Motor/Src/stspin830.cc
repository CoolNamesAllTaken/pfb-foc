/*
 * stspin830.cc
 *
 *  Created on: Nov 27, 2020
 *      Author: jkailimcnelly
 */

#include "stspin830.hh"
#include "foc_utils.hh"

/* Private Constants */
const uint16_t kADCMaxCounts = 0xFFFF>>4; // 12-bit ADC value
const float kADCMaxVolts = 3.3f; // [V] VDD rail of current sense ADCs
const float kADCOffsetVolts = 1.56f; // [V] ADC offset voltage (from IHM16M1 datasheet)
const float kADCGain = 1.53f * 0.33f; // [Ohms] Gain of current sense op-amp * sense resistor value

const uint16_t kPulseMax = 10000; // maximum counts for timer PWM pulse length
const float kDutyCycleMax = 0.95f; // max value of D
const float kDutyCycleMin = 0.05f; // allow current measurement during D

/**
 * @brief Initializes the relevant channel of the STSPIN320 half-bridge.
 */
void STSPIN830::Init() {
	pid_last_update_us = GetTickMicros(); // enable time intervals to be passed to PID controller
	HAL_TIM_PWM_Start(timer_, timer_channel_id_); // get the party started
	HAL_TIMEx_PWMN_Start(timer_, timer_channel_id_); // get the (complementary) party started
	is_initialized_ = true;
}

/**
 * Updates the PWM period of the half bridge based on the measured current. Should be called by the ConversionCplt callback
 * of the ADC, which should in turn have been called by a reset trigger event from the half bridge timer.
 */
void STSPIN830::Update() {
	if (!is_initialized_) {
		// Don't run until the important stuff is set up!
		return;
	}
	// Calculate current
	float curr_sense_adc_voltage = static_cast<float>(curr_sense_adc_counts_) / kADCMaxCounts * kADCMaxVolts;
	current_ma_ = (curr_sense_adc_voltage - kADCOffsetVolts) / kADCGain * 1000;
	// TODO: set break bit for the PWM if current too large, enter FAULT state
	// Update target current
	uint32_t curr_time_us = GetTickMicros();
	// Calculate duty cycle for closed loop control
	duty_cycle_ -= pid.Update(target_current_ - current_ma_, (curr_time_us - pid_last_update_us) / 1000.0f);
	if (duty_cycle_ > kDutyCycleMax) {
		duty_cycle_ = kDutyCycleMax;
	} else if (duty_cycle_ < kDutyCycleMin) {
		duty_cycle_ = kDutyCycleMin;
	}
	pid_last_update_us = curr_time_us;
	// Set duty cycle: note that CH and CHN are in HIGH polarity; counter expiration triggers low side current sense
	__HAL_TIM_SET_COMPARE(timer_, timer_channel_id_, static_cast<uint16_t>(duty_cycle_ * kPulseMax));
}




