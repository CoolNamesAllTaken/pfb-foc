/*
 * pid_controller.hh
 *
 *  Created on: Dec 6, 2020
 *      Author: jkailimcnelly
 */

#ifndef _PID_CONTROLLER_HH_
#define _PID_CONTROLLER_HH_

#include <stdint.h> // for uint16_t
#include "foc_utils.hh"

class PIDController {

public:
	float k_p{0};
	float k_i{0};
	float k_d{0};

	float ramp{0};
	float limit{1e3};

	PIDController(float k_p_in, float k_i_in, float k_d_in, float ramp_in, float limit_in);

	float Update(float error, float ms_since_last_update);
	void Reset();

protected:
	float i_error_{0}; // error accumulation term

	float prev_output_{0};
	float prev_error_{0};
};

#endif /* _PID_CONTROLLER_HH_ */
