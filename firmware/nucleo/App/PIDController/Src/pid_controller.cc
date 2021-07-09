/*
 * pid_controller.cc
 *
 *  Created on: Dec 6, 2020
 *      Author: jkailimcnelly
 */

#include "pid_controller.hh"
#include "foc_utils.hh"

const float kDefaultLimit = 1e3f;

/**
 * @brief Constructor for PID Controller class. Creates a PID controller with the provided gains.
 * @param[in] k_p_in Proportional gain.
 * @param[in] k_i_in Integral gain.
 * @param[in] k_d_in Derivative gain.
 * @param[in] ramp_in Maximum ramp (derivative) of output.
 * @param[in] limit_in Maximum value of output.
 */
PIDController::PIDController(float k_p_in, float k_i_in, float k_d_in, float ramp_in = 0.0f, float limit_in = kDefaultLimit)
	: k_p(k_p_in)
	, k_i(k_i_in)
	, k_d(k_d_in)
	, ramp(ramp_in >= 0.0f ? ramp_in : 0.0f) // don't allow negative ramp values
	, limit(limit_in > 0.0f ? limit_in : kDefaultLimit){} // don't allow zero or negative limit values

/**
 * @brief Updates the PID controller based on a new sample. Updates output and error accumulator
 * based on the state and target of the plant, as well as the time elapsed since the last update.
 * @param[in] ms_since_last_update Milliseconds elapsed since last update function call. Used for
 * integrating error in the error accumulator.
 * @retval Calculated output response of PID controller.
 */
float PIDController::Update(float error, float ms_since_last_update) {
	if (ms_since_last_update <= 0.0f) {
		return 0; // only allow updates with positive time steps (avoid errors for i, d)
	}

	float p = k_p * error;
	float i = i_error_ + k_i * ((error + prev_error_)*ms_since_last_update/2); // Tustin's method (trapezoidal integration)
	i = CONSTRAIN(i, -limit, limit); // integral anti-windup
	float d = k_d * (error - prev_error_) / ms_since_last_update;

	float output = CONSTRAIN(p + i + d, -limit, limit); // sum and constrain output

	if (ramp > 0.0f) { // output ramp is defined
		if (output - prev_output_ > ramp) {
			output = prev_output_ + ramp; // rail to positive ramp
		} else if (output - prev_output_ < -ramp) {
			output = prev_output_ - ramp; // rail to negative ramp
		}
	}

	// save stuff for next round
	prev_error_ = error;
	prev_output_ = output;
	i_error_ = i;

	return output;
}

/**
 * @brief Zeroes the integral accumulator of the PID Controller and forces an update.
 */
void PIDController::Reset() {
	i_error_ = 0;
	prev_error_ = 0;
	prev_output_ = 0;
}
