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
#include "foc_utils.hh"

const float kErrorMargin = 0.01;

bool TestPIDControllerCreate() {
	TEST_PRINT("Create PID Controller.\r\n");

	T_TEST_PRINT("Set gains with PID values.\r\n");
	float k_p = 1.2;
	float k_i = 3.4;
	float k_d = 5.6;
	float ramp = 5.1;
	float limit = 2.2;
	PIDController pid(k_p, k_i, k_d, ramp, limit);

	if (pid.k_p != k_p) {
		T_FAIL_PRINT("Incorrect k_p, constructed with %f but got %f.\r\n", k_p, pid.k_p);
		return false;
	}
	if (pid.k_i != k_i) {
		T_FAIL_PRINT("Incorrect k_i, constructed with %f but got %f.\r\n", k_i, pid.k_i);
		return false;
	}
	if (pid.k_d != k_d) {
		T_FAIL_PRINT("Incorrect k_d, constructed with %f but got %f.\r\n", k_d, pid.k_d);
		return false;
	}
	if (pid.ramp != ramp) {
		T_FAIL_PRINT("Incorrect ramp, constructed with %f but got %f.\r\n", ramp, pid.ramp);
		return false;
	}
	if (pid.limit != limit) {
		T_FAIL_PRINT("Incorrect limit, constructed with %f but got %f.\r\n", limit, pid.limit);
		return false;
}

	return true;
}

bool TestPIDControllerResponse() {
	float state = 0;
	float target = 0;
	float output = 0;

	float ramp = 0;
	float limit = 0;

	TEST_PRINT("Test PID Controller Response.\r\n");
	T_TEST_PRINT("Test default response afer initialization.\r\n");
	PIDController pid = PIDController(0, 0, 0, ramp, limit);
	output = pid.Update(0.0f, 10.0f);
	if (output != 0) {
		T_FAIL_PRINT("Nonzero output after creation, expected %f but got %f.\r\n", 0.0, output);
		return false;
	}

	T_TEST_PRINT("k_p Test #1.\r\n");
	state = 1.0;
	target = 2.0;
	pid.k_p = 5.0;
	output = pid.Update(state - target, 10.5);
	float expect_output = (1.0 - 2.0) * 5.0;
	if (output != expect_output) {
		T_FAIL_PRINT("Failed k_p test #1, expected output %f but got %f.\r\n",
				expect_output, output);
		return false;
	}

	T_TEST_PRINT("k_i Test #1.\r\n");
	float prev_error = state - target;
	pid.k_p = 0;
	pid.k_i = 3;
	target = 98.5;
	state = 70;
	output = pid.Update(state - target, 10.7);
	expect_output = pid.k_i * (prev_error + (state - target)) * 10.7f / 2.0f;
	if (!WITHIN(output, expect_output, kErrorMargin)) {
		T_FAIL_PRINT("Failed k_i test #1, expected output %f but got %f.\r\n",
				expect_output, output);
		return false;
	}

	T_TEST_PRINT("k_i Test #2.\r\n");
	prev_error = state - target;
	target = 2;
	state = 5;
	output = pid.Update(state - target, 11.9);
	expect_output += pid.k_i * (prev_error + (state - target)) * 11.9f / 2.0f;
	if (!WITHIN(output, expect_output, kErrorMargin)) {
		T_FAIL_PRINT("Failed k_i test #2, expected output %f but got %f.\r\n",
				expect_output, output);
		return false;
	}

	T_TEST_PRINT("Reset Test #1.\r\n");
	pid.Reset();
	pid.k_p = 0;
	pid.k_i = 0;
	pid.k_d = 0;
	output = pid.Update(5.0, 1.2);
	expect_output = 0;
	if (!WITHIN(output, expect_output, kErrorMargin)) {
		T_FAIL_PRINT("Failed reset test #1, expected output %f but got %f.\r\n",
				expect_output, output);
		return false;
	}

	T_TEST_PRINT("Reset Test #2.\r\n");
	state = 0;
	target = 0;
	output = pid.Update(state - target, 10);
	expect_output = 0;
	if (!WITHIN(output, expect_output, kErrorMargin)) {
		T_FAIL_PRINT("Failed reset test #2, expected output %f but got %f.\r\n",
				expect_output, output);
		return false;
	}

	T_TEST_PRINT("k_d Test #1.\r\n");
	pid.k_d = 13.5;
	state = -487.3;
	target = 22;
	output = pid.Update(state - target, 10);
	expect_output = (-487.3 - 22) * 13.5 / 10;
	if (!WITHIN(output, expect_output, kErrorMargin)) {
		T_FAIL_PRINT("Failed k_d Test #1, expected output %f but got %f.\r\n",
				expect_output, output);
		return false;
	}

	// TODO: test ramp and limit

	return true;
}

void TestPIDControllerAll() {
	L_PRINT("Test PID Controller Class");
	bool pid_passed = true;
	pid_passed &= TestPIDControllerCreate();
	pid_passed &= TestPIDControllerResponse();
	if (pid_passed) {
		PASS_PRINT("PID Controller Class\r\n");
	} else {
		FAIL_PRINT("PID Controller Class\r\n");
	}
}


