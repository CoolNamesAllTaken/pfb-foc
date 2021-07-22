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

/**
 * Task Map
 * Task1 Example task.
 * current_control_task Current control task for testing half bridge.
 */

/* Constants */
/* Function Prototypes */

/* Global Variables */
Motor * motor;
//STSPIN830 * g_half_bridge_u;
//STSPIN830 * g_half_bridge_v;
//STSPIN830 * g_half_bridge_w;

/**
 * @brief Main function that avoids all the auto-generated junk from ST CubeMX.
 * @retval int
 */
int main_run() {
	Motor::MotorConfig_t config = {
		10, // num_pole_pairs
		5.0f, // [Ohms] phase_resistance
		0.0f, // [nH] phase_inductance (unused)
		2.0f, // [A] current_limit
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

	// Currents to toggle between
	float theta = 0;
	float dtheta = 1;
	float max_current = 2.0; // [A]

	while(1) {
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

		motor->SetCurrent(max_current, 0.0f, 0.0f);
		HAL_Delay(1000);
//		osDelayUntil(osTickCount + osTickFreq / task1Freq);
		motor->SetCurrent(0.0f, max_current, 0.0f);
		HAL_Delay(1000);
//		osDelayUntil(osTickCount + osTickFreq / task1Freq);
		motor->SetCurrent(0.0f, 0.0f, max_current);
		HAL_Delay(1000);

		// Wrap theta
//		theta = WrapAngle(theta + dtheta);

//		osDelayUntil(osTickCount + osTickFreq / task1Freq);
	}

	return 1;
}

void ADCConvCpltCallback() {
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
	motor->Update();
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


