/*
 * pid_controller.cc
 *
 *  Created on: Dec 6, 2020
 *      Author: jkailimcnelly
 */

#include "pid_controller.hh"

/**
 * @brief Constructor for PID Controller class. Creates a PID controller with the provided gains.
 * @param[in] k_p_in Proportional gain.
 * @param[in] k_i_in Integral gain.
 * @param[in] k_d_in Derivative gain.
 * @param[in] state_in Reference to the plant state, which is read during every update.
 */
PIDController::PIDController(float k_p_in, float k_i_in, float k_d_in, const float& state_in)
	: k_p(k_p_in)
	, k_i(k_i_in)
	, k_d(k_d_in)
	, state(state_in){}

/**
 * @brief Updates the PID controller based on a new sample. Updates output and error accumulator
 * based on the state and target of the plant, as well as the time elapsed since the last update.
 * @param[in] ms_since_last_update Milliseconds elapsed since last update function call. Used for
 * integrating error in the error accumulator.
 */
void PIDController::Update(float ms_since_last_update) {
	if (ms_since_last_update < 0) {
		return; // only allow updates with positive time steps (avoid errors for i, d)
	}

	float prev_error = error_; // store old error

	// Proportional Error
	error_ = state - target; // calculate current error

	// Populate circular error memory buffer with integrated chunk of previous error
	float i_curr_error =  error_  * ms_since_last_update;
#ifdef PID_FIR
	// Finite Impulse Response (accumulator is a moving window)
	i_error_ -= error_mem_[error_mem_index_]; // clear last entry
	error_mem_[error_mem_index_] = i_curr_error;
	error_mem_index_++;
	if (error_mem_index_ > error_mem_depth_) {
		error_mem_index_ = 0; // wrap error memory index
	}
#endif

	// Integral Error
	i_error_ += i_curr_error;

	// Derivative Error
	float d_error = 0;
	if (ms_since_last_update > 0.0f) {
		// avoid yuge spike during controller reset
		d_error = (error_ - prev_error) / ms_since_last_update;
	}

	output_ = k_p * (error_) + k_i * i_error_ + k_d * d_error;
}

/**
 * @brief Zeroes the integral accumulator of the PID Controller and forces an update.
 */
void PIDController::Reset() {
#ifdef PID_FIR
	for (uint16_t i = 0; i < error_mem_depth_; i++) {
		error_mem_[i] = 0;
	}
#else
	i_error_ = 0;
#endif
	error_ = 0;
	Update(0);
}

float PIDController::get_output() {
	return output_;
}
