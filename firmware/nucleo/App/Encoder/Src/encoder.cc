/*
 * encoder.cc
 *
 *  Created on: Nov 23, 2020
 *      Author: jkailimcnelly
 */

#include "encoder.hh"
#include <math.h>

/**
 * @brief Helper function that wraps an angle into the range 0-360 degrees.
 * @param[in] angle Angle value to be wrapped (float, degrees).
 * @retval Wrapped value, in degrees.
 */
float Encoder::WrapAngle_(float raw_angle) {
	float wrapped_angle = raw_angle - 360.0 * floor(raw_angle / 360.0);
	if (wrapped_angle < 0) {
		wrapped_angle += 360.0;
	}
	return wrapped_angle;
}

/**
 * @brief Sets the current absolute encoder angle (degrees) as the zero position.
 */
void Encoder::set_zero_angle() {
	zero_angle_ = angle_;
}

/**
 * @brief Sets the encoder zero position to a specific value.
 * @param[in] new_zero_angle The new zero position of the encoder, in degrees.
 */
void Encoder::set_zero_angle(float new_zero_angle) {
	zero_angle_ = WrapAngle_(new_zero_angle);
}

/**
 * @brief Returns the current angle of the encoder, in degrees.
 * @retval Angle of the encoder, in degrees.
 */
float Encoder::get_angle() {
	return WrapAngle_(angle_ - zero_angle_);
//	float rel_angle = angle_ - zero_angle_;
//	if (rel_angle < 0) {
//		return 360.0 - rel_angle;
//	}
//	return rel_angle;
//	if (angle_ >= zero_angle_) {
//		return angle_ - zero_angle_;
//	} else {
//		return 360.0 - zero_angle_ - angle_;
//	}

}

/**
 * @brief Sets the angle (in degrees) stored by the Encoder object. Takes care of wrapping to store the value
 * between 0-360.
 * @param[in] angle Angle value in degrees (float).
 */
void Encoder::set_angle(float new_angle) {
//	float new_angle = fmod(angle, 360);
//	if (new_angle < 0) {
//		new_angle += 360;
//	} else if (new_angle > 360) {
//		new_angle -= 360;
//	}
	angle_ = WrapAngle_(new_angle);
}
