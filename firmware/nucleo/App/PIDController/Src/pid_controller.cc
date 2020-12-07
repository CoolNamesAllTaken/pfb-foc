/*
 * pid_controller.cc
 *
 *  Created on: Dec 6, 2020
 *      Author: jkailimcnelly
 */

#include "pid_controller.hh"

/**
 * @brief Constructor for PID Controller class. Creates a PID controller with the provided gains.
 * @param[in] k_p Proportional gain.
 * @param[in] k_i Integral gain.
 * @param[in] k_d Derivative gain.
 */
PIDController::PIDController(float k_p, float k_i, float k_d) {
	gains_ = {k_p, k_i, k_d};
}

/**
 * @brief Constructor for the PID Controller class. Creates a PID controller with the gains in
 * the provided PIDConfig struct.
 * @param[in] gains PIDConfig struct with configuration parameters for the PIDController to be
 * created.
 */
PIDController::PIDController(PIDConfig gains) {
	gains_ = gains;
}

/**
 * @brief Getter function for the PID Controller's PIDConfig.
 * @retval PIDConfig struct with controller's gains.
 */
PIDConfig PIDController::get_gains() {
	return gains_;
}

/**
 * @brief Setter function for the PID Controller's PIDConfig.
 * @param[in] gains New PIDConfig struct to use as controller's gains.
 */
void PIDController::set_gains(PIDConfig gains) {
	gains_ = gains;
}

/**
 * @brief Update function that must be called at regular time intervals.
 * @param[in] Current state of the plant being controlled.
 */
void PIDController::Update(float state) {

	// Wrap state memory index
	state_mem_index_++;
	if (state_mem_index_ > state_mem_depth_) {
		state_mem_index_ = 0;
	}

}

float PIDController::get_state() {
	return state_mem_[state_mem_index_];
}
