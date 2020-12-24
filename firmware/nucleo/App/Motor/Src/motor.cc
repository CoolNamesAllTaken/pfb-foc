/*
 * motor.cc
 *
 *  Created on: Dec 23, 2020
 *      Author: jkailimcnelly
 */

#include "motor.hh"

#include "arm_math.h"

void Motor::Init() {
	// Initialize all the lil bits
	enc_.Init();
//	enc_.set_zero_angle(); // startup position is the zero position
	// initialization sequence for motor will go here
}

void Motor::Update() {
	// Read the encoder
	enc_.Update();

	/**
	 * Control structure
	 * Position Control -> Target Velocity
	 * Velocity Control -> Target Torque
	 * Torque Control -> Target Current
	 */
	// Position control loop
	// Velocity control loop
	// Torque (current) control loop

	// Set phase currents
	u_bridge_.set_target_current(i_u_);
	v_bridge_.set_target_current(i_v_);
	w_bridge_.set_target_current(i_w_);

	// Update duty cycles
	u_bridge_.Update();
	v_bridge_.Update();
	w_bridge_.Update();

}


