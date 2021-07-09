/*
 * motor_driver.cc
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#include "motor_driver.hh"
#include "foc_utils.hh"

/**
 * @brief Links the MotorDriver instance to a HAL timer and corresponding channels for U, V, W phases.
 * @param[in] timer Pointer to motor phase PWM TIM_HandleTypeDef object.
 * @param[in] timer_u_channel_id ID of phase U timer channel.
 * @param[in] timer_v_channel_id ID of phase V timer channel.
 * @param[in] timer_w_channel_id ID of phase W timer channel.
 */
void MotorDriver::LinkToPWM(
	TIM_HandleTypeDef * timer,
	uint32_t timer_u_channel_id,
	uint32_t timer_v_channel_id,
	uint32_t timer_w_channel_id)
{
	timer_ = timer;
	timer_u_channel_id_ = timer_u_channel_id;
	timer_v_channel_id_ = timer_v_channel_id;
	timer_w_channel_id_ = timer_w_channel_id;
}

/**
 * @brief Start PWM timers.
 */
void MotorDriver::Init() {
	HAL_TIM_PWM_Start(timer_, timer_u_channel_id_); // get the party started
	HAL_TIMEx_PWMN_Start(timer_, timer_u_channel_id_); // get the (complementary) party started
	HAL_TIM_PWM_Start(timer_, timer_v_channel_id_); // get the party started
	HAL_TIMEx_PWMN_Start(timer_, timer_v_channel_id_); // get the (complementary) party started
	HAL_TIM_PWM_Start(timer_, timer_w_channel_id_); // get the party started
	HAL_TIMEx_PWMN_Start(timer_, timer_w_channel_id_); // get the (complementary) party started
}

/**
 *
 */
void MotorDriver::SetDutyCycle(float duty_u, float duty_v, float duty_w) {
	duty_u_ = CONSTRAIN(duty_u, duty_min_, duty_max_);
	duty_v_ = CONSTRAIN(duty_v, duty_min_, duty_max_);
	duty_w_ = CONSTRAIN(duty_w, duty_min_, duty_max_);

	// Set duty cycle: note that CH and CHN are in HIGH polarity; counter expiration triggers low side current sense
	__HAL_TIM_SET_COMPARE(timer_, timer_u_channel_id_, static_cast<uint16_t>(duty_u_ * pulse_max_));
	__HAL_TIM_SET_COMPARE(timer_, timer_v_channel_id_, static_cast<uint16_t>(duty_v_ * pulse_max_));
	__HAL_TIM_SET_COMPARE(timer_, timer_w_channel_id_, static_cast<uint16_t>(duty_w_ * pulse_max_));
}
