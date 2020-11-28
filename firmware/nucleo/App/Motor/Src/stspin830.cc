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



/**
 * @brief Initializes the relevant channel of the STSPIN320 half-bridge.
 */
void STSPIN830::Init() {
	// Initialize with H-bridge in high-Z state.
	HAL_GPIO_WritePin(en_port_, en_pin_, en_state_);
	HAL_GPIO_WritePin(in_port_, in_pin_, in_state_);
}

void STSPIN830::Update() {
	// Check current
	current_ma_ = ((static_cast<float>(curr_sense_adc_voltage_) / kADCMaxCounts) - kADCOffsetVolts) / kADCGain;

}




