#include "main.h"
//#include "cmsis_os.h"

#define RUN_TESTS
#ifdef RUN_TESTS
#include "test_framework.hh"
#include "test_encoder.hh"
#include "test_pid_controller.hh"
#include "test_current_sensor.hh"
#include "test_motor_driver.hh"
#include "test_foc_utils.hh"
#endif

#include "motor.hh"
#include "defaults.hh"
// Include child classes of motor controller components
#include "AS5048A.hh"

/* Constants */
const uint16_t kUserPotADCBufIndex = 3;

/* Function Prototypes */

/* Global Variables */
Motor * motor;

/**
 * @brief Main function that avoids all the auto-generated junk from ST CubeMX.
 * @retval int
 */
int main_run() {
	Motor::MotorConfig_t config = {
		6, // num_pole_pairs
		5.0f, // [Ohms] phase_resistance
		0.0f, // [nH] phase_inductance (unused)
		4.0f, // [A] current_limit
		DEFAULT_POWER_SUPPLY_VOLTAGE // [V] power_suply_voltage
	};

	const float kDutyMax = 0.95;
	const float kDutyMin = 0.05f;
	const uint16_t kPulseMax = 10000;
	MotorDriver * driver = new MotorDriver(kDutyMax, kDutyMin, kPulseMax);
	driver->LinkToPWM(half_bridge_pwm_timer, TIM_CHANNEL_1, TIM_CHANNEL_2, TIM_CHANNEL_3);

	Encoder * enc = new AS5048A(encoder_hspi, ENC_SPI_CS_GPIO_Port, ENC_SPI_CS_Pin);

	const float kADCMaxCounts = 0xFFF; // 12-bit ADC
	const float kADCMaxVolts = 3.3f; // VDD rail of MCU
	const float kADCOffsetVolts = 1.56f; // IHM16M1 datasheet
	const float kADCGain = 1.53f * 0.33f;
	CurrentSensor * csense = new CurrentSensor(kADCMaxCounts, kADCMaxVolts, kADCOffsetVolts, kADCGain);
	csense->LinkToADC(&(curr_sense_adc_buf[0]), &(curr_sense_adc_buf[1]), &(curr_sense_adc_buf[2]));

	const float kMaxPhaseVoltage = CONSTRAIN(DEFAULT_POWER_SUPPLY_VOLTAGE, 0.0f, config.current_limit * config.phase_resistance);
	PIDController * pid_torque = new PIDController(DEFAULT_PID_CURR_P, DEFAULT_PID_CURR_I, DEFAULT_PID_CURR_D, DEFAULT_PID_CURR_RAMP, kMaxPhaseVoltage);

	motor = new Motor(config, driver, enc, csense, pid_torque);
	motor->Init();
	HAL_TIM_Base_Start_IT(half_bridge_pwm_timer); // start interrupts for TIM1 Update, which will trigger the motor updates

#ifdef RUN_TESTS
	RunAllTests();
#endif


	float homing_current = motor->GetConfig().current_limit;
	motor->SetCurrent(homing_current, -homing_current/2.0f, -homing_current/2.0f);
	motor->Update();
	HAL_Delay(1000); // Let motor settle. Should line up so that all i_d=current_limit, i_q=0
	motor->Update(); // for debug viewing
	enc->set_zero_angle();

//	motor->SetTorque(-10);

	while(1) {
		motor->SetTorque(homing_current * (curr_sense_adc_buf[kUserPotADCBufIndex]-static_cast<float>(kADCMaxCounts)/2.0f)/(static_cast<float>(kADCMaxCounts)/2.0f));
		motor->Update(); // perform fast and slow update
	}

	return 1;
}

void ADCConvCpltCallback() {
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
//	motor->Update(true);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
}

#ifdef RUN_TESTS
void RunAllTests() {
	TestEncoderAll();
	TestPIDControllerAll();
	TestCurrentSensorAll();
	TestMotorDriverAll();
	TestFOCUtilsAll();
}
#endif


