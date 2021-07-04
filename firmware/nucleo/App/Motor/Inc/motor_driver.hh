/*
 * motor_driver.hh
 *
 *  Created on: Jul 3, 2021
 *      Author: John McNelly
 */

#ifndef _MOTOR_DRIVER_HH_
#define _MOTOR_DRIVER_HH_


class MotorDriver {
public:
	float duty_u{0};
	float duty_v{0};
	float duty_w{0};

	float deadtime{0};
	float duty_max{1.0};
	float duty_min{0};

	virtual void Init() = 0;
	virtual void SetDutyCycle() = 0;

protected:

};


#endif /* MOTOR_INC_MOTOR_DRIVER_HH_ */
