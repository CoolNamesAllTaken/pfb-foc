/*
 * test_framework.hh
 *
 *  Created on: Nov 23, 2020
 *      Author: jkailimcnelly
 */

#ifndef TEST_INC_TEST_FRAMEWORK_HH_
#define TEST_INC_TEST_FRAMEWORK_HH_

#include <stdio.h>

extern "C" {
#define L_PRINT(...) printf("=====%-50s=====\r\n", __VA_ARGS__) // decorated, left-justified printf
#define T_PRINT(...) printf("  " __VA_ARGS__) // indented printf
#define TT_PRINT(...) printf("    " __VA_ARGS__)
#define TEST_PRINT(...) printf("Starting Test: " __VA_ARGS__)
#define T_TEST_PRINT(...) printf("  Starting Test: " __VA_ARGS__)
#define FAIL_PRINT(...) printf("\033[31mTEST FAILED:\033[39m " __VA_ARGS__)
#define T_FAIL_PRINT(...) printf("\033[31m  TEST FAILED:\033[39m " __VA_ARGS__)
#define TT_FAIL_PRINT(...) printf("\033[31m    TEST FAILED:\033[39m " __VA_ARGS__)
#define PASS_PRINT(...) printf("\033[32mTEST PASSED:\033[39m " __VA_ARGS__)
#define T_PASS_PRINT(...) printf("\033[32m  TEST PASSED:\033[39m " __VA_ARGS__)
#define TT_PASS_PRINT(...) printf("\033[32m    TEST PASSED:\033[39m " __VA_ARGS__)
}

template <class T>
bool CheckEqual(T a, T b) {
	return a == b;
}

template <class T>
bool CheckClose(T a, T b, T margin) {
	return (a - b <= margin) || (b - a <= margin);
}

void RunAllTests();

#endif /* TEST_INC_TEST_FRAMEWORK_HH_ */
