/*
 * foc_utils.cc
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#include "foc_utils.hh"

/**
 * Utility function that returns the current time in microseconds.
 * @retval Current uptime, in microseconds.
 */
uint32_t GetTickMicros() {
	return HAL_GetTick() * 1000 - SysTick->VAL / ((SysTick->LOAD + 1) / 1000);
}
