/*
 * motor.hh
 *
 *  Created on: Dec 23, 2020
 *      Author: jkailimcnelly
 */

#ifndef MOTOR_INC_MOTOR_HH_
#define MOTOR_INC_MOTOR_HH_

#include "stm32f7xx_hal.h"
#include "half_bridge.hh"
#include "pid_controller.hh"
#include "Encoder.hh"

class Motor {
public:
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

private:
	HalfBridge& u_bridge_;
	HalfBridge& v_bridge_;
	HalfBridge& w_bridge_;
	Encoder& enc_;
};




#endif /* MOTOR_INC_MOTOR_HH_ */
