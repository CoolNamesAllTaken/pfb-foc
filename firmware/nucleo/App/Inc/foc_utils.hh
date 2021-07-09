/*
 * foc_utils.hh
 *
 *  Created on: Jun 27, 2021
 *      Author: John McNelly
 */

#ifndef _FOC_UTILS_HH_
#define _FOC_UTILS_HH_

#include "stm32f7xx_hal.h"
#include <stdint.h>

#define CONSTRAIN(val, low, high) ((val) < (low) ? (low) : ((val) > (high) ? (high) : (val)))
#define WITHIN(val1, val2, diff) ((val1) > (val2) ? ((val1) - (val2) < (diff)) : ((val2) - (val1) < (diff)))

uint32_t GetTickMicros();

float RadToDeg(float rad);
float DegToRad(float deg);

float sind(float theta);
float cosd(float theta);

void TransFwdDQZ(
		float theta, float i_u, float i_v, float i_w,
		float& i_d, float& i_q, float& i_z);

void TransRevDQZ(
		float theta, float i_d, float i_q, float i_z,
		float& i_u, float& i_v, float& i_w);

float ElectricalAngle(float shaft_angle, uint16_t num_pole_pairs);
float NormalizeAngle(float angle);

#endif /* INC_FOC_UTILS_HH_ */
