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

bool TestPIDControllerCreate() {
	TEST_PRINT("Create PID Controller.\r\n");

	T_TEST_PRINT("Set gains with PID values.\r\n");
	float k_p = 1.2;
	float k_i = 3.4;
	float k_d = 5.6;
	float state = 2.1;
	PIDController pid(k_p, k_i, k_d, state);

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

	if (pid.state != state) {
		T_FAIL_PRINT("Incorrect state, constructed with %f but got %f.\r\n", state, pid.state);
		return false;
	}
	state = 345.67;
	if (pid.state != state) {
		T_FAIL_PRINT("State does not track, expected %f but got %f.\r\n", state, pid.state);
		return false;
	}

	return true;
}

bool TestPIDControllerResponse() {
	TEST_PRINT("Test PID Controller Response.\r\n");
	T_TEST_PRINT("Test default response afer initialization.\r\n");
	float state = 0;
	PIDController pid = PIDController(0, 0, 0, state);
	if (pid.get_output() != 0) {
		T_FAIL_PRINT("Nonzero output after creation, expected %f but got %f.\r\n", 0.0, pid.get_output());
		return false;
	}

	T_TEST_PRINT("k_p Test #1.\r\n");
	state = 1.0;
	pid.target = 2.0;
	pid.k_p = 5.0;
	pid.Update(10.5);
	float expect_output = (1.0 - 2.0) * 5.0;
	if (pid.get_output() != expect_output) {
		T_FAIL_PRINT("Failed k_p test #1, expected output %f but got %f.\r\n",
				expect_output, pid.get_output());
		return false;
	}

	T_TEST_PRINT("k_i Test #1.\r\n");
	pid.k_p = 0;
	pid.k_i = 3;
	pid.target = 98.5;
	state = 70;
	pid.Update(10.7);
	expect_output = (1.0-2.0) * 10.7 * 3;
	if (pid.get_output() != expect_output) {
		T_FAIL_PRINT("Failed k_i test #1, expected output %f but got %f.\r\n",
				expect_output, pid.get_output());
		return false;
	}

	T_TEST_PRINT("k_i Test #2.\r\n");
	pid.Update(11.9);
	expect_output += (70-98.5) * 11.9 * 3;
	if (pid.get_output() != expect_output) {
		T_FAIL_PRINT("Failed k_i test #2, expected output %f but got %f.\r\n",
				expect_output, pid.get_output());
		return false;
	}

	T_TEST_PRINT("k_i Test #3 (overflow test).\r\n");
	for (uint16_t i = 0; i < 2*pid.error_mem_depth_; i++) {
		pid.Update(12.1);
		expect_output += (70-98.5) * 12.1 * 3;
		if (!CheckClose(pid.get_output(), expect_output, (float)0.5)) {
			T_FAIL_PRINT("Failed overflow test on iteration %d, expected output %f but got %f.\r\n",
					i, expect_output, pid.get_output());
			return false;
		}
	}

	T_TEST_PRINT("Reset Test #1.\r\n");
	pid.Reset();
	pid.k_p = 0;
	pid.k_i = 0;
	pid.k_d = 0;
	expect_output = 0;
	if (pid.get_output() != expect_output) {
		T_FAIL_PRINT("Failed reset test #1, expected output %f but got %f.\r\n",
				expect_output, pid.get_output());
		return false;
	}

	T_TEST_PRINT("Reset Test #2.\r\n");
	state = 0;
	pid.target = 0;
	pid.Update(10);
	expect_output = 0;
	if (pid.get_output() != expect_output) {
		T_FAIL_PRINT("Failed reset test #2, expected output %f but got %f.\r\n",
				expect_output, pid.get_output());
		return false;
	}

	T_TEST_PRINT("k_d Test #1.\r\n");
	pid.k_d = 13.5;
	state = -487.3;
	pid.target = 22;
	pid.Update(10);
	expect_output = (-487.3 - 22) * 13.5;
	if (pid.get_output() != expect_output) {
		T_FAIL_PRINT("Failed k_d Test #1, expected output %f but got %f.\r\n",
				expect_output, pid.get_output());
		return false;
	}

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


