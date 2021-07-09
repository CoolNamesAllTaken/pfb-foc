/*
 * test_foc_utils.cc
 *
 *  Created on: Jul 4, 2021
 *      Author: John McNelly
 */

#include "test_framework.hh"
#include "test_foc_utils.hh"
#include "foc_utils.hh"

#define ERROR_MARGIN 0.1

bool MatchThree(float a, float b, float c, float expect_a, float expect_b, float expect_c) {
	bool all_match = true;
	all_match &= WITHIN(a, expect_a, ERROR_MARGIN);
	all_match &= WITHIN(b, expect_b, ERROR_MARGIN);
	all_match &= WITHIN(c, expect_c, ERROR_MARGIN);

	return all_match;
}

bool TestTransFwddDQZ() {
	TEST_PRINT("Forward DQZ\r\n");

	T_TEST_PRINT("Give 'em the good ol 123.\r\n");

	float theta = 123.0f;

	float i_d = 0.0f;
	float i_q = 0.0f;
	float i_z = 0.0f;

	float i_u = 1.0f;
	float i_v = 2.0f;
	float i_w = 3.0f;


	float expect_i_d =  0.074014f;
	float expect_i_q =  1.412275f;
	float expect_i_z =  3.464102f;

	TransFwdDQZ(theta, i_u, i_v, i_w, i_d, i_q, i_z);

	if (!MatchThree(i_d, i_q, i_z, expect_i_d, expect_i_q, expect_i_z)) {
		TT_FAIL_PRINT("DQZ currents do not match.\r\n\t\tReceived: i_d = %f i_q = %f i_z = %f\r\n\t\tExpected: i_d = %f i_q = %f i_z = %f\r\n",
				i_d, i_q, i_z, expect_i_d, expect_i_q, expect_i_z);
		return false;
	}

	return true;
}

bool TestTransRevDQZ() {
	TEST_PRINT("Reverse DQZ\r\n");

	T_TEST_PRINT("Give 'em the good ol 123.\r\n");

	float theta = 123.0f;

	float i_u = 0.0f;
	float i_v = 0.0f;
	float i_w = 0.0f;

	float i_d = 1.0f;
	float i_q = 2.0f;
	float i_z = 3.0f;

	float expect_i_u =  -0.082188;
	float expect_i_v =  2.461964;
	float expect_i_w =  2.816377;

	TransRevDQZ(theta, i_d, i_q, i_z, i_u, i_v, i_w);

	if (!MatchThree(i_u, i_v, i_w, expect_i_u, expect_i_v, expect_i_w)) {
		TT_FAIL_PRINT("XYZ currents do not match.\r\n\t\tReceived: i_u = %f i_v = %f i_w = %f\r\n\t\tExpected: i_u = %f i_v = %f i_w = %f\r\n",
				i_u, i_v, i_w, expect_i_u, expect_i_v, expect_i_w);
		return false;
	}

	return true;
}

bool TestTransFwdRevDQZ() {
	TEST_PRINT("Forward then Reverse DQZ\r\n");

	T_TEST_PRINT("Random values.\r\n");

	float theta = 123.0f;

	float i_d = 0.0f;
	float i_q = 0.0f;
	float i_z = 0.0f;

	float i_u = 5.878f;
	float i_v = -1234.5f;
	float i_w = 68.547f;

	float expect_i_u =  i_u;
	float expect_i_v =  i_v;
	float expect_i_w =  i_w;

	TransFwdDQZ(theta, i_u, i_v, i_w, i_d, i_q, i_z);
	TransRevDQZ(theta, i_d, i_q, i_z, i_u, i_v, i_w);

	if (!MatchThree(i_u, i_v, i_w, expect_i_u, expect_i_v, expect_i_w)) {
		TT_FAIL_PRINT("XYZ currents do not match.\r\n\t\tReceived: i_u = %f i_v = %f i_w = %f\r\n\t\tExpected: i_u = %f i_v = %f i_w = %f\r\n",
				i_u, i_v, i_w, expect_i_u, expect_i_v, expect_i_w);
		return false;
	}

	return true;
}

void TestFOCUtilsAll() {
	L_PRINT("FOC Utils");
	bool utils_ok = true;

	utils_ok &= TestTransFwddDQZ();
	utils_ok &= TestTransRevDQZ();
	utils_ok &= TestTransFwdRevDQZ();

	if (utils_ok) {
		PASS_PRINT("FOC Utils\r\n");
	} else {
		FAIL_PRINT("FOC Utils\r\n");
	}
}
