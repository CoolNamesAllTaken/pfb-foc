/*
 * motor.cc
 *
 *  Created on: Dec 23, 2020
 *      Author: jkailimcnelly
 */

#include "motor.hh"
#include "foc_utils.hh"

Motor::MotorConfig_t Motor::GetConfig() {
	return config_;
}

void Motor::Init() {
	// Initialize all the lil bits
	enc_->Init();
	//	enc_.set_zero_angle(); // startup position is the zero position
	driver_->Init(); // start driver PWM
	last_update_micros_ = GetTickMicros();

	// initialization sequence for motor will go here

}

/**
 * @brief Set target phase currents, set motor to current control mode.
 * @param[in] i_u Target current for phase U, in Amps.
 * @param[in] i_v Target current for phase V, in Amps.
 * @param[in] i_w Target current for phase W, in Amps.
 */
void Motor::SetCurrent(float i_u, float i_v, float i_w) {
	mode_ = CURRENT_CONTROL;
	// Simple open loop control with voltage setpoints.
	v_u_cmd_ = i_u * config_.phase_resistance;
	v_v_cmd_ = i_v * config_.phase_resistance;
	v_w_cmd_ = i_w * config_.phase_resistance;
}

/**
 * @brief Set target quadrature current magnitude (torque) and set motor to torque
 * control mode.
 * @param[in] i_q Target quadrature current, in Amps.
 */
void Motor::SetTorque(float i_q) {
	mode_ = TORQUE_CONTROL;
	i_q_cmd_ = CONSTRAIN(i_q, -config_.current_limit, config_.current_limit);
}

/**
 * @brief Set target velocity and set motor to velocity control mode.
 * @param[in] omega Target angular velocity, in degrees per second.
 */
void Motor::SetVelocity(float omega) {
	mode_ = VELOCITY_CONTROL;
	omega_cmd_ = omega;
}

/**
 * @brief Set target position and set motor to mosition control mode.
 * @param[in] theta Target angular position (shaft angle), in degrees.
 */
void Motor::SetPosition(float theta) {
	mode_ = POSITION_CONTROL;
	theta_cmd_ = theta;
}

/**
 * @brief Runs the motor control loop. Slow / blocking functions can be optionally
 * run using a separate, slower control loop with a lower frequency.
 * @param[in] fast_only Run slow updates in a separate loop.
 */
void Motor::Update(bool fast_only) {
	uint32_t curr_time_micros = GetTickMicros();
	float ms_since_last_update = (static_cast<float>(curr_time_micros - last_update_micros_)) / 1000.0f;

	if (!fast_only) {
		SlowUpdate();
	}

	// Read the current sensors
	csense_->ReadCurrents();
	i_u_meas_ = csense_->i_u;
	i_v_meas_ = csense_->i_v;
	i_w_meas_ = csense_->i_w;

	switch(mode_) {
	case POSITION_CONTROL:
		// Set velocity to control position.
	case VELOCITY_CONTROL:
		// Set torque to control velocity.
	case TORQUE_CONTROL:
		// Use DQZ transform to transform measured phase currents into rotating reference frame.
		TransFwdDQZ(
				theta_meas_, i_u_meas_, i_v_meas_, i_w_meas_, // params in
				i_d_meas_, i_q_meas_, i_z_meas_); // params out

		// Set voltages in rotating reference frame to control currents in rotating reference frame.
		v_d_cmd_ = 0.0f; // TODO: add PID controller for i_d error for true FOC control.
		v_q_cmd_ = pid_torque_->Update(i_q_cmd_ - i_q_meas_, ms_since_last_update);
		v_z_cmd_ = 0;

		// Convert rotating reference frame voltages back into stator voltages.
		TransRevDQZ(
				theta_meas_, v_d_cmd_, v_q_cmd_, v_z_cmd_, // params in
				v_u_cmd_, v_v_cmd_, v_w_cmd_); // params out

	case CURRENT_CONTROL:
		// Set voltage (duty cycle) to control current.
		// Open-loop PWM duty cycle control.
		driver_->SetDutyCycle(
			v_u_cmd_ / config_.power_supply_voltage,
			v_v_cmd_ / config_.power_supply_voltage,
			v_w_cmd_ / config_.power_supply_voltage);
	}

	// Save as a snack for later.
	last_update_micros_ = curr_time_micros;

}

/**
 * @brief Control loop for slower / blocking functions. Can be executed separately to keep the
 * main control loop running fast.
 */
void Motor::SlowUpdate() {
	// Read the encoder
	enc_->Update();
	theta_meas_ = NormalizeAngle(ElectricalAngle(enc_->get_angle(), config_.num_poles));
}


