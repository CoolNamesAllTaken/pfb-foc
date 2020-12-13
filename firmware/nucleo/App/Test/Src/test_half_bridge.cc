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
 * Pin Mapping
 *
 * ENU = PB13	TIM1_CH1N
 * ENV = PB14	TIM1_CH2N
 * ENW = PB15	TIM1_CH3N
 *
 * INU = PA8	TIM1_CH1
 * INV = PA9	TIM1_CH2
 * INW = PA10	TIM1_CH3
 */

/**
 * Test Setup Instructions
 */

bool TestHalfBridgeCreate() {
	TIM_HandleTypeDef * dummy_timer = NULL;
	uint32_t dummy_timer_id = 0;
	uint16_t adc_buf[1];
	STSPIN830 half_bridge(
			dummy_timer,
			dummy_timer_id,
			adc_buf[0]);

	if (half_bridge.get_op_mode() != HalfBridge::OFF) {
		FAIL_PRINT("HalfBridge not initialized in OFF op mode.\r\n");
		return false;
	}
	return true;
}

bool TestHalfBridgeHardware() {
	STSPIN830 half_bridge(
			half_bridge_pwm_timer,  // PWM timer
			TIM_CHANNEL_1,			// PWM timer channel
			curr_sense_adc_buf[0] /* curr_sense_adc_voltage */);
	half_bridge.Init();
	half_bridge.set_target_current(10); // [10mA]
	while(true) {
		half_bridge.Update();
	}
}


void TestHalfBridgeAll() {
	L_PRINT("Test HalfBridge Class");
	bool hb_passed = true;
	hb_passed &= TestHalfBridgeCreate();
#ifdef HARDWARE_TEST
	hb_passed &= TestHalfBridgeHardware();
#endif
	if (hb_passed) {
		PASS_PRINT("HalfBridge Class\r\n");
	} else {
		FAIL_PRINT("HalfBridge Class\r\n");
	}

}
