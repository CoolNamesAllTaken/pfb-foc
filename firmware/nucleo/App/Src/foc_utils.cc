/*
 * foc_utils.cc
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#include "foc_utils.hh"
#include "arm_math.h"

/**
 * @brief Utility function that returns the current time in microseconds.
 * @retval Current uptime, in microseconds.
 */
uint32_t GetTickMicros() {
	return HAL_GetTick() * 1000 - SysTick->VAL / ((SysTick->LOAD + 1) / 1000);
}

/**
 * @brief Helper function that converts an angle in radians to an angle in degrees.
 * @param[in] Angle value in radians.
 * @retval Angle value in degrees.
 */
float RadToDeg(float rad) {
	return rad * 360.0f / (2.0f * PI);
}

/**
 * @brief Helper function that converts an angle in degrees to an angle in radians.
 * @param[in] Angle value in degrees.
 * @retval Angle value in radians.
 */
float DegToRad(float deg) {
	return deg / 360.0f * 2.0f * PI;
}

/**
 * @brief Returns the sine of an angle (degrees).
 * @param[in] theta Angle, in degrees.
 * @retval Sine of theta.
 */
float sind(float theta) {
	return arm_sin_f32(DegToRad(theta));
}

/**
 * @brief Returns thecosine of an angle (degrees).
 * @param[in] theta Angle, in degrees.
 * @retval Cosine of theta.
 */
float cosd(float theta) {
	return arm_cos_f32(DegToRad(theta));
}

/**
 * @brief Direct Quadrature Zero Transformation
 *
 * Transforms phase a, b, c currents in the XYZ reference frame into
 * direct, quadrature, zero currents in the rotating rotor reference frame.
 *
 * @param[in] theta Rotor position, in degrees.
 * @param[in] i_u Current in X direction in XYZ reference frame.
 * @param[in] i_v Current in Y direction in XYZ reference frame.
 * @param[in] i_w Current in Z direction in XYZ reference frame.
 * @param[out] i_d Direct current magntiude in rotating reference frame.
 * @param[out] i_q Quadrature current magnitude in rotating reference frame.
 * @param[out] i_z Zero current magnitude in rotating reference frame.
 */
void TransFwdDQZ(
		float theta, float i_u, float i_v, float i_w,
		float& i_d, float& i_q, float& i_z)
{
	i_d = sqrtf(2.0f/3.0f) * (cosd(theta)*i_u + cosd(theta-120.0f)*i_v + cosd(theta+120.0f)*i_w);
	i_q = sqrtf(2.0f/3.0f) * (-sind(theta)*i_u - sind(theta-120.0f)*i_v - sind(theta+120.0f)*i_w);
	i_z = sqrtf(2.0f/3.0f) * (sqrtf(2.0f)/2.0f*i_u + sqrtf(2.0f)/2.0f*i_v + sqrtf(2.0f)/2.0f*i_w);
}

/**
 * @brief Inverse Direct Quadrature Zero Transformation
 *
 * Transforms direct, quadrature, zero currents into the phase a, b, c currents
 * in the XYZ reference frame.
 *
 * @param[in] theta Rotor position, in degrees.
 * @param[in] i_d Direct current magntiude in rotating reference frame.
 * @param[in] i_q Quadrature current magnitude in rotating reference frame.
 * @param[in] i_z Zero current magnitude in rotating reference frame.
 * @param[out] i_u Current in X direction in XYZ reference frame.
 * @param[out] i_v Current in Y direction in XYZ reference frame.
 * @param[out] i_w Current in Z direction in XYZ reference frame.
 */
void TransRevDQZ(
		float theta, float i_d, float i_q, float i_z,
		float& i_u, float& i_v, float& i_w)
{
	i_u = sqrtf(2.0f/3.0f) * (cosd(theta)*i_d - sind(theta)*i_q + sqrtf(2.0f)/2.0f*i_z);
	i_v = sqrtf(2.0f/3.0f) * (cosd(theta-120.0f)*i_d - sind(theta-120.0f)*i_q + sqrtf(2.0f)/2.0f*i_z);
	i_w = sqrtf(2.0f/3.0f) * (cosd(theta+120.0f)*i_d - sind(theta+120.0f)*i_q + sqrtf(2.0f)/2.0f*i_z);
}

/**
 * @brief Converts mechanical shaft angle into an electrical angle, since one 360 degree rotation of the shaft
 * represents 360 degrees * num poles rotation of the electrical angle.
 * @param[in] shaft_angle Shaft angle, in degrees.
 * @param[in] num_pole_pairs Number of pole pairs in the motor.
 * @retval Electrical angle, in degrees.
 */
float ElectricalAngle(float shaft_angle, uint16_t num_pole_pairs) {
	return shaft_angle * static_cast<float>(num_pole_pairs);
}

/**
 * @brief Normalizes the value of an angle in degrees to between 0-360 degrees.
 * @param[in] angle Angle to be normalized, in degrees.
 * @retval Normalized angle value between 0 and 360 degrees.
 */
float NormalizeAngle(float angle) {
	float normalized_angle = fmod(angle, 360.0f);
	return normalized_angle > 0 ? normalized_angle : normalized_angle + 360.0f;
}
