/*
 * motor.cc
 *
 *  Created on: Dec 23, 2020
 *      Author: jkailimcnelly
 */

#include "motor.hh"
#include "foc_utils.hh"

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
 * @param[in] i_d Target quadrature current, in Amps.
 */
void Motor::SetTorque(float i_d) {
	mode_ = TORQUE_CONTROL;
	i_d_cmd_ = CONSTRAIN(i_d, 0.0f, config_.current_limit);
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

void Motor::Update() {
	uint32_t curr_time_micros = GetTickMicros();
	float ms_since_last_update = (static_cast<float>(curr_time_micros - last_update_micros_)) / 1000.0f;

	// Read the encoder
//	enc_->Update();
//	theta_meas_ = NormalizeAngle(ElectricalAngle(enc_->get_angle(), config_.num_pole_pairs));

	// Read the current sensors
//	csense_->ReadCurrents();
//	i_u_meas_ = csense_->i_u;
//	i_v_meas_ = csense_->i_v;
//	i_w_meas_ = csense_->i_w;

	switch(mode_) {
	case POSITION_CONTROL:
		// Set velocity to control position.
	case VELOCITY_CONTROL:
		// Set torque to control velocity.
	case TORQUE_CONTROL:
		// Use DQZ transform to transform measured phase currents into rotating reference frame.
		TransFwdDQZ(theta_meas_, i_u_meas_, i_v_meas_, i_w_meas_, i_d_meas_, i_q_meas_, i_z_meas_);

		// Set voltages in rotating reference frame to control currents in rotating reference frame.
		v_d_cmd_ = 0; // TODO: add PID controller for i_d error for true FOC control.
		v_q_cmd_ = pid_torque_->Update(i_q_cmd_ - i_q_meas_, ms_since_last_update);
		v_z_cmd_ = 0;

		// Convert rotating reference frame voltages back into stator voltages.
		TransRevDQZ(theta_meas_, v_d_cmd_, v_q_cmd_, v_z_cmd_, v_u_cmd_, v_v_cmd_, v_w_cmd_);

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


