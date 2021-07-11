/*
 * current_sensor.cc
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#include "current_sensor.hh"

/**
 * @brief Points the current sensor ADC count references to the correct spot. Assumes that conversion has been started and
 * is being transferred to a buffer via DMA.
 * @param[in] adc_counts_u_in Reference pointing to location in ADC buffer for phase U current.
 * @param[in] adc_counts_v_in Reference pointing to location in ADC buffer for phase V current.
 * @param[in] adc_counts_w_in Reference pointing to location in ADC buffer for phase W current.
 */
void CurrentSensor::LinkToADC(volatile uint16_t* adc_counts_u_in, volatile uint16_t* adc_counts_v_in, volatile uint16_t* adc_counts_w_in) {
	adc_counts_u_ = adc_counts_u_in;
	adc_counts_v_ = adc_counts_v_in;
	adc_counts_w_ = adc_counts_w_in;
}

void CurrentSensor::ReadCurrents() {
	i_u = (static_cast<float>(*adc_counts_u_));
	i_u /= adc_max_counts_;
	i_u *= adc_max_volts_;
	i_u -= adc_offset_volts_;
	i_u /= adc_gain_;
	i_u = (static_cast<float>(*adc_counts_u_) / adc_max_counts_ * adc_max_volts_ - adc_offset_volts_) / adc_gain_;
	i_v = (static_cast<float>(*adc_counts_v_) / adc_max_counts_ * adc_max_volts_ - adc_offset_volts_) / adc_gain_;
	i_w = (static_cast<float>(*adc_counts_w_) / adc_max_counts_ * adc_max_volts_ - adc_offset_volts_) / adc_gain_;
}
