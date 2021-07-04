/*
 * current_sensor.hh
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#ifndef _CURRENT_SENSOR_HH_
#define _CURRENT_SENSOR_HH_

#include <stdint.h> // for uint stuff
#include <cstddef> // for NULL ptr

class CurrentSensor {
public:
	float curr_u{0}; // [mA] current measured by current sensor
	float curr_v{0};
	float curr_w{0};

	// Consturctor
	CurrentSensor(
		uint16_t adc_max_counts_in,
		float adc_max_volts_in,
		float adc_offset_volts_in,
		float adc_gain_in)
		: adc_max_counts_(adc_max_counts_in)
		, adc_max_volts_(adc_max_volts_in)
		, adc_offset_volts_(adc_offset_volts_in)
		, adc_gain_(adc_gain_in){};

	void LinkToADC(uint16_t* adc_counts_u_in, uint16_t* adc_counts_v_in, uint16_t* adc_counts_w_in); // where to look for ADC values
	void ReadCurrents(); // conversion complete callback

protected:
	// Setup and Calibration variables
	uint16_t adc_max_counts_{0xFFF};
	float adc_max_volts_{3.3f};
	float adc_offset_volts_{0.0f};
	float adc_gain_{1.0f};


	uint16_t* adc_counts_u_{NULL};
	uint16_t* adc_counts_v_{NULL};
	uint16_t* adc_counts_w_{NULL};
};

#endif /* _CURRENT_SENSOR_HH_ */
