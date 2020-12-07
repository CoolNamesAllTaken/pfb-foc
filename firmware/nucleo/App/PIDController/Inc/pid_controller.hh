/*
 * pid_controller.hh
 *
 *  Created on: Dec 6, 2020
 *      Author: jkailimcnelly
 */

#ifndef PIDCONTROLLER_INC_PID_CONTROLLER_HH_
#define PIDCONTROLLER_INC_PID_CONTROLLER_HH_

#include <stdint.h> // for uint16_t

#define PID_MAX_MEM_DEPTH 100

struct PIDConfig {
	float k_p;
	float k_i;
	float k_d;
};

class PIDController {
private:
	PIDConfig gains_;

	uint16_t state_mem_depth_{PID_MAX_MEM_DEPTH};
	float state_mem_[PID_MAX_MEM_DEPTH]{0};
	uint16_t state_mem_index_{0};

	float output_{0};

public:
	float target{0};
	float k_p{0};
	float k_i{0};
	float k_d{0};

	PIDController(float k_p, float k_i, float k_d);
	PIDController(PIDConfig gains);

	void set_gains(PIDConfig gains);
	PIDConfig get_gains();

	void Update(float state);

	void set_target();
	float get_target();

	float get_state();
	float get_output();
};



#endif /* PIDCONTROLLER_INC_PID_CONTROLLER_HH_ */
