/*
 * test_pid_controller.cc
 *
 *  Created on: Dec 6, 2020
 *      Author: jkailimcnelly
 */

#include "test_framework.hh"
#include "test_pid_controller.hh"

#define private public
#include "pid_controller.hh"

bool TestPIDConfig() {
	TEST_PRINT("Create PIDConfig\r\n");
	PIDConfig gains{1.123, 2.234, 3.345};
	if (gains.k_p != 1.123) {
		FAIL_PRINT("Wrong k_p\r\n");
		return false;
	}
	if (gains.k_i != 2.234) {
		FAIL_PRINT("Wrong k_i\r\n");
		return false;
	}
	if (gains.k_d != 3.345) {
		FAIL_PRINT("Wrong k_d\r\n");
		return false;
	}

	return true;
}

bool TestPIDControllerCreate() {
	TEST_PRINT("Create PID Controller\r\n");

	T_TEST_PRINT("Set gains with PIDConfig struct.\r\n");
	PIDConfig gains_in = {1.2, 3.4, 5.6};
	PIDController pid(gains_in);

	PIDConfig gains_out = pid.get_gains();
	if (gains_out.k_p != gains_in.k_p) {
		T_FAIL_PRINT("Incorrect k_p, constructed with %f but got %f\r\n", gains_in.k_p, gains_out.k_p);
		return false;
	}
	if (gains_out.k_i != gains_in.k_i) {
		T_FAIL_PRINT("Incorrect k_i, constructed with %f but got %f\r\n", gains_in.k_i, gains_out.k_i);
		return false;
	}
	if (gains_out.k_d != gains_in.k_d) {
		T_FAIL_PRINT("Incorrect k_d, constructed with %f but got %f\r\n", gains_in.k_d, gains_out.k_d);
		return false;
	}

	T_TEST_PRINT("Set gains with PID values.\r\n");
	float k_p = 1.2;
	float k_i = 3.4;
	float k_d = 5.6;
	PIDController val_pid(k_p, k_i, k_d);

	gains_out = val_pid.get_gains();
	if (gains_out.k_p != gains_in.k_p) {
		T_FAIL_PRINT("Incorrect k_p, constructed with %f but got %f\r\n", k_p, gains_out.k_p);
		return false;
	}
	if (gains_out.k_i != gains_in.k_i) {
		T_FAIL_PRINT("Incorrect k_i, constructed with %f but got %f\r\n", k_i, gains_out.k_i);
		return false;
	}
	if (gains_out.k_d != gains_in.k_d) {
		T_FAIL_PRINT("Incorrect k_d, constructed with %f but got %f\r\n", k_d, gains_out.k_d);
		return false;
	}

	return true;
}

void TestPIDControllerAll() {
	L_PRINT("Test PID Controller Class");
	bool pid_passed = true;
	pid_passed &= TestPIDConfig();
	if (pid_passed) {
		PASS_PRINT("PID Controller Class\r\n");
	} else {
		FAIL_PRINT("PID Controller Class\r\n");
	}
}


