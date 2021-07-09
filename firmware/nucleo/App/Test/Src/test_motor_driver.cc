/*
 * test_motor_driver.hh
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#include "test_framework.hh"
#include "test_motor_driver.hh"
#include "motor_driver.hh"

bool TestMotorDriverCreate() {
	float duty_cycle_max = 0.95;
	float duty_cycle_min = 0.05;
	uint16_t pulse_max_in = 0xFFFF;

	MotorDriver md(duty_cycle_max, duty_cycle_min, pulse_max_in);
	return true;
}

void TestMotorDriverAll() {
	L_PRINT("MotorDriver Class");
	bool md_ok = true;
	md_ok &= TestMotorDriverCreate();
	if (md_ok) {
		PASS_PRINT("MotorDriver Class\r\n");
	} else {
		FAIL_PRINT("MotorDriver Class\r\n");
	}

}



