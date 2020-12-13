/*
 * half_bridge.hh
 *
 *  Created on: Nov 26, 2020
 *      Author: jkailimcnelly
 */

#ifndef MOTOR_INC_HALF_BRIDGE_HH_
#define MOTOR_INC_HALF_BRIDGE_HH_

#include <stdint.h>

class HalfBridge {
public:
	enum OpMode {
		OFF = 0,
		LOW_SIDE_ON, // lock high side of half-bridge OFF, low side ON
		HIGH_SIDE_ON, // lock high side of half-bridge ON, low side OFF
		CURR_LIMIT, // control current through half-bridge with PWM
		FAULT // overcurrent or other event has occurred, half-bridge disabled
	};

	HalfBridge() {} // abstract class due to pure virtual functions: constructor does nothing

	virtual void Init() = 0;
	virtual void Update() = 0; // must be called with HIGH FREQUENCY for current limiting

	void set_target_current(uint16_t new_target_current);
	uint16_t get_target_current();

	void set_current_limit(uint16_t current_limit);
	uint16_t get_current_limit();

	void set_op_mode(OpMode op_mode);
	OpMode get_op_mode();

protected:
	uint16_t target_current_{0}; // [mA]
	uint16_t current_limit_{0}; // [mA]

	OpMode op_mode_{OFF};


};



#endif /* MOTOR_INC_HALF_BRIDGE_HH_ */