/*
 * test_current_sensor.cc
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#include "test_framework.hh"
#include "test_current_sensor.hh"

bool CurrentsAreCorrect(CurrentSensor current_sensor, float i_u_expect, float i_v_expect, float i_w_expect) {
	if (current_sensor.i_u != i_u_expect) {
		T_FAIL_PRINT("Incorrect phase U current: expected %f but got %f.\r\n", i_u_expect, current_sensor.i_u);
		return false;
	} else if (current_sensor.i_v != i_v_expect) {
		T_FAIL_PRINT("Incorrect phase V current: expected %f but got %f.\r\n", i_v_expect, current_sensor.i_v);
		return false;
	} else if (current_sensor.i_w != i_w_expect) {
		T_FAIL_PRINT("Incorrect phase W current: expected %f but got %f.\r\n", i_w_expect, current_sensor.i_w);
		return false;
	}
	return true;
}

bool TestCurrentSensorCurrent() {
	TEST_PRINT("Simulate Current through Current Sensor.\r\n");
	uint16_t csense_adc_counts[3] = {0};

	uint16_t adc_max_counts = 0xFFF;
	float adc_max_volts = 3.3f;
	float adc_offset = 1.56f;
	float adc_gain = 0.33f;
	CurrentSensor current_sensor(adc_max_counts, adc_max_volts, adc_offset, adc_gain);
	current_sensor.LinkToADC(&(csense_adc_counts[0]), &(csense_adc_counts[1]), &(csense_adc_counts[2]));

	T_TEST_PRINT("Current sense ADC counts at 0.\r\n");
	current_sensor.ReadCurrents();
	float i_u_expect = -adc_offset / adc_gain * 1000;
	float i_v_expect = -adc_offset / adc_gain * 1000;
	float i_w_expect = -adc_offset / adc_gain * 1000;

	if (!CurrentsAreCorrect(current_sensor, i_u_expect, i_v_expect, i_w_expect)) {
		return false;
	}

	T_TEST_PRINT("Current sense ADC counts at random values.\r\n");
	csense_adc_counts[0] = 156;
	csense_adc_counts[1] = 0xFFF;
	csense_adc_counts[2] = 2934;
	current_sensor.ReadCurrents();
	i_u_expect = (static_cast<float>(csense_adc_counts[0]) / adc_max_counts * adc_max_volts - adc_offset) / adc_gain * 1000;
	i_v_expect = (static_cast<float>(csense_adc_counts[1]) / adc_max_counts * adc_max_volts - adc_offset) / adc_gain * 1000;
	i_w_expect = (static_cast<float>(csense_adc_counts[2]) / adc_max_counts * adc_max_volts - adc_offset) / adc_gain * 1000;

	if (!CurrentsAreCorrect(current_sensor, i_u_expect, i_v_expect, i_w_expect)) {
		return false;
	}
	return true;
}

void TestCurrentSensorAll() {
	bool csense_passed = true;
	L_PRINT("Test CurrentSensor Class");
	csense_passed &= TestCurrentSensorCurrent();
	if (csense_passed) {
		PASS_PRINT("CurrentSensor Class\r\n");
	} else {
		FAIL_PRINT("CurrentSensor Class\r\n");
	}
}


