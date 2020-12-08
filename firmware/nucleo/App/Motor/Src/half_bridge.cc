/*
 * half_bridge.cc
 *
 *  Created on: Nov 26, 2020
 *      Author: jkailimcnelly
 */

#include "half_bridge.hh"

/**
 * @brief Sets the target current of the half-bridge.
 * @param[in] target_current Target current, in milliamps.
 */
void HalfBridge::set_target_current(uint16_t target_current) {
	target_current_ = target_current;
}

/**
 * @brief Returns the target current of the half-bridge.
 * @retval Target current, in milliamps.
 */
uint16_t HalfBridge::get_target_current() {
	return target_current_;
}

/**
 * @brief Set the current limit, which, if exceeded, will turn the half-bridge off and enter the FAULT state.
 * @param[in] current_limit Current limit in milliamps.
 */
void HalfBridge::set_current_limit(uint16_t current_limit) {
	current_limit_ = current_limit;
}

/**
 * @brief Returns the current limit, which, if exceeded, will turn the half-bridge off and ener the FAULT state.
 * @retval Current limit in milliamps.
 */
uint16_t HalfBridge::get_current_limit() {
	return current_limit_;
}

/**
 * @brief Sets the operation mode of the half-bridge.
 * @param[in] op_mode New operation mode for the half-bridge.
 */
void HalfBridge::set_op_mode(HalfBridge::OpMode op_mode) {
	op_mode_ = op_mode;
}

/**
 * @brief Returns the operation mode of the half-bridge.
 * @retval Halfbridge operation mode.
 */
HalfBridge::OpMode HalfBridge::get_op_mode() {
	return op_mode_;
}
