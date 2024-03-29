/*
 * encoder.hh
 *
 *  Created on: Nov 23, 2020
 *      Author: jkailimcnelly
 */

#ifndef ENCODER_INC_ENCODER_HH_
#define ENCODER_INC_ENCODER_HH_

#include <stdint.h>


class Encoder {
private:
	float zero_angle_{0}; // value of the absolute zero angle, in degrees
	float angle_{0}; // value of the current absolute angle, in degrees

	float WrapAngle_(float raw_angle);

protected:
	void set_angle(float new_angle); // angle_ can be set by child classes that implement specific encoders

public:
	Encoder() {} // constructor does nothing

	/* Pure virtual functions: hardware-specific */
	virtual void Init() = 0; // initialize the encoder
	virtual void Update() = 0; // communicate with the encoder to read the new angle

	void set_zero_angle();
	void set_zero_angle(float new_zero_angle);
	float get_angle();

};


#endif /* ENCODER_INC_ENCODER_HH_ */
