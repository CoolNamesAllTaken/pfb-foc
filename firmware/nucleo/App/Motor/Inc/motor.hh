/*
 * motor.hh
 *
 *  Created on: Dec 23, 2020
 *      Author: jkailimcnelly
 */

#ifndef MOTOR_INC_MOTOR_HH_
#define MOTOR_INC_MOTOR_HH_

#include "stdint.h"
#include "foc_utils.hh"
#include "pid_controller.hh"
#include "motor_driver.hh"
#include "current_sensor.hh"
#include "encoder.hh"

class Motor {
public:
	enum ControlMode {
		CURRENT_CONTROL = 0,
		TORQUE_CONTROL,
		VELOCITY_CONTROL,
		POSITION_CONTROL
	};

	struct MotorConfig_t {
		uint16_t num_poles; // number of diametrically opposite pole pairs in motor
		float phase_resistance; // [Ohms] resistance of a single motor phase
		float phase_inductance; // [nH] unused
		float current_limit; // [A] current limit (max magnitude of i_dq vector)
		float power_supply_voltage; // [V] power supply voltage
	};

	/**
	 * @brief Constructor for Motor object.
	 * @param[in] driver MotorDriver for motor.
	 * @param[in] enc Absolute position encoder for motor.
	 */
	Motor(
		MotorConfig_t config,
		MotorDriver * driver,
		Encoder * enc,
		CurrentSensor * csense,
		PIDController * pid_torque)
		: config_(config)
		, driver_(driver)
		, enc_(enc)
		, csense_(csense)
		, pid_torque_(pid_torque) {};

	MotorConfig_t GetConfig();

	void Init();
	void Update(bool fast_only = false);
	void SlowUpdate();

	void SetCurrent(float i_u, float i_v, float i_w);
	void SetTorque(float i_q);
	void SetVelocity(float omega);
	void SetPosition(float theta);

private:
	MotorConfig_t config_;
	ControlMode mode_{CURRENT_CONTROL};

	MotorDriver * driver_{NULL};
	Encoder * enc_{NULL};
	CurrentSensor * csense_{NULL};

	PIDController * pid_torque_{NULL};
	PIDController * pid_velocity_{NULL};
	PIDController * pid_position_{NULL};

	uint32_t last_update_micros_{0}; // [us] timestamp of last control loop execution



	float theta_cmd_{0}; // [degrees] target encoder angle (electrical angle)
	float theta_meas_{0};
	float omega_cmd_{0}; // [degrees/sec] target angular velocity
	float omega_meas_{0};

	// Time invariant currents.
	float i_d_cmd_{0}; // direct current component in rotor reference frame
	float i_d_meas_{0};
	float i_q_cmd_{0}; // quadrature current component in rotor reference frame
	float i_q_meas_{0};
	float i_z_cmd_{0}; // zero current component in rotor reference frame
	float i_z_meas_{0};

	// Stator currents (measured).
	float i_u_meas_{0};
	float i_v_meas_{0};
	float i_w_meas_{0};

	// Rotating reference frame voltages (commanded, used to control rotating reference frame currents).
	float v_d_cmd_{0};
	float v_q_cmd_{0};
	float v_z_cmd_{0};

	// Stator voltages (transformed from rotating reference frame voltages), used to set duty cycle.
	float v_u_cmd_{0}; // phase U current (flowing to GND)
	float v_v_cmd_{0}; // phase V current (flowing to GND)
	float v_w_cmd_{0}; // phase W current (flowing to GND)

	void ControlCurrent();
	void ControlTorque();
	void ControlVelocity();
	void ControlPosition();
};




#endif /* MOTOR_INC_MOTOR_HH_ */
