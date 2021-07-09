/*
 * motor_driver.hh
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#ifndef _MOTOR_DRIVER_HH_
#define _MOTOR_DRIVER_HH_

#include "stm32f7xx_hal.h"


class MotorDriver {
public:

	/**
	 * @brief MotorDriver constructor.
	 * @param[in] duty_max_in Float containing maximum allowable duty cycle.
	 */
	MotorDriver(float duty_max_in, float duty_min_in, uint16_t pulse_max_in)
		: duty_max_(duty_max_in)
		, duty_min_(duty_min_in)
		, pulse_max_(pulse_max_in){};

	void Init();
	void LinkToPWM(
			TIM_HandleTypeDef * timer,
			uint32_t timer_u_channel_id,
			uint32_t timer_v_channel_id,
			uint32_t timer_w_channel_id);
	void SetDutyCycle(float duty_u, float duty_v, float duty_w);

protected:
	float duty_u_{0};
	float duty_v_{0};
	float duty_w_{0};

//	float deadtime_{0}; // TODO: make this do something
	float duty_max_{1.0};
	float duty_min_{0};
	uint16_t pulse_max_{0};

	TIM_HandleTypeDef * timer_{NULL};
	uint32_t timer_u_channel_id_{0};
	uint32_t timer_v_channel_id_{0};
	uint32_t timer_w_channel_id_{0};
};


#endif /* MOTOR_INC_MOTOR_DRIVER_HH_ */
