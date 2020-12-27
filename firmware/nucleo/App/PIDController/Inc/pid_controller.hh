/*
 * pid_controller.hh
 *
 *  Created on: Dec 6, 2020
 *      Author: jkailimcnelly
 */

#ifndef PIDCONTROLLER_INC_PID_CONTROLLER_HH_
#define PIDCONTROLLER_INC_PID_CONTROLLER_HH_

#include <stdint.h> // for uint16_t

#define PID_MAX_MEM_DEPTH 2
#define PID_FIR

class PIDController {
private:
#ifdef PID_FIR
	// Circular error buffer for Finite Impulse Response
	uint16_t error_mem_depth_{PID_MAX_MEM_DEPTH};
	float error_mem_[PID_MAX_MEM_DEPTH]{0};
	uint16_t error_mem_index_{0};
#else
	// Error accumulation term for Infinite Impulse Response
	float i_error_{0};
#endif

	float output_{0};
	float error_{0};

public:
	float k_p{0};
	float k_i{0};
	float k_d{0};

	const float& state;
	float target{0};

	PIDController(float k_p_in, float k_i_in, float k_d_in, const float& state_in);

	void Update(float ms_since_last_update);
	void Reset();

	float get_output();
};

#endif /* PIDCONTROLLER_INC_PID_CONTROLLER_HH_ */
