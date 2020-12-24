/*
 * motor.hh
 *
 *  Created on: Dec 23, 2020
 *      Author: jkailimcnelly
 */

#ifndef MOTOR_INC_MOTOR_HH_
#define MOTOR_INC_MOTOR_HH_

#include "stm32f7xx_hal.h"
#include "stdint.h"
#include "half_bridge.hh"
#include "pid_controller.hh"
#include "Encoder.hh"

class Motor {
public:
	struct MotorConfig_t {
		uint16_t current_limit{0}; // [mA] current limit (max magnitude of i_dq vector)
	};

	/**
	 * @brief Constructor for Motor object.
	 * @param[in] u_bridge HalfBridge for phase U.
	 * @param[in] v_bridge HalfBridge for phase V.
	 * @param[in] w_bridge HalfBridge for phase W.
	 * @param[in] enc Absolute position encoder for motor.
	 */
	Motor(
		HalfBridge& u_bridge,
		HalfBridge& v_bridge,
		HalfBridge& w_bridge,
		Encoder& enc)
		: u_bridge_(u_bridge)
		, v_bridge_(v_bridge)
		, w_bridge_(w_bridge)
		, enc_(enc) {};

	void Init();
	void Update();

	void SetTorque(float torque);
	void SetVelocity(float velocity);
	void SetPosition(float angle);

private:
	HalfBridge& u_bridge_;
	HalfBridge& v_bridge_;
	HalfBridge& w_bridge_;
	Encoder& enc_;

	float theta{0}; // target encoder angle

	// Time invariant currents
	float i_d_{0}; // direct current component in rotor reference frame
	float i_q_{0}; // quadrature current component in rotor reference frame

	// Stator currents
	float i_u_{0}; // phase U current (flowing to GND)
	float i_v_{0}; // phase V current (flowing to GND)
	float i_w_{0}; // phase W current (flowing to GND)

	void ControlTorque();
	void ControlVelocity();
	void ControlPosition();
};




#endif /* MOTOR_INC_MOTOR_HH_ */
