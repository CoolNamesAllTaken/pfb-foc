/*
 * test_half_bridge.cc
 *
 *  Created on: Nov 26, 2020
 *      Author: jkailimcnelly
 */

#include "test_framework.hh"
#include "test_half_bridge.hh"

#define private public
#define protected public
#include "stspin830.hh"

#define HARDWARE_TEST
#ifdef HARDWARE_TEST
#include "main.h"
#endif

#define CURR_FB_U ADC1_IN1
#define CURR_FB_V ADC1_IN7
#define CURR_FB_W ADC1_IN8

/**
 * Test Setup Instructions
 */

bool TestHalfBridgeCreate() {
	GPIO_TypeDef * dummy_gpio_port = NULL;
	uint16_t dummy_gpio_pin = 0;
	uint16_t adc_buf[1];
	STSPIN830 half_bridge(
			dummy_gpio_port,
			dummy_gpio_pin,
			dummy_gpio_port,
			dummy_gpio_pin,
			adc_buf[0]);

	if (half_bridge.get_op_mode() != HalfBridge::OFF) {
		FAIL_PRINT("HalfBridge not initialized in OFF op mode.\r\n");
		return false;
	}
	return true;
}


void TestHalfBridgeAll() {
	L_PRINT("Test HalfBridge Class");
	bool hb_passed = true;
	hb_passed &= TestHalfBridgeCreate();
	if (hb_passed) {
		PASS_PRINT("HalfBridge Class\r\n");
	} else {
		FAIL_PRINT("HalfBridge Class\r\n");
	}

}