#include "main.h"
#include "cmsis_os.h"

#define RUN_TESTS
#ifdef RUN_TESTS
#include "test_framework.hh"
#include "test_encoder.hh"
#include "test_half_bridge.hh"
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

// Task Handles
osThreadId_t task1Handle;
osThreadId_t motor_control_task_handle;

/* Constants */
const uint32_t task1Freq = 10; // [Hz]
const osThreadAttr_t task1Attributes = {
	"task1", 							// cost char * name = name of the thread
	0, 									// uint32_t attr_bits = attribute bits
	osThreadDetached, 					// void * cb_mem = memory for control block
	0, 									// uint32_t cb_size = size of provided memory for control block
	NULL, 								// void * stack_mem = memory for stack
	0, 									// uint32_t stack_size = size of stack
	(osPriority_t) osPriorityNormal, 	// osPriority_t priority = initial thread priority (default: osPriorityNormal)
	0, 									// TZModuleId_t tz_module = TrustZone module identifier
	0 									// reserved = reserved (must be 0)
};

const osThreadAttr_t motor_control_task_attrs = {
	"current_control_task", 			// cost char * name = name of the thread
	0, 									// uint32_t attr_bits = attribute bits
	osThreadDetached, 					// void * cb_mem = memory for control block
	0, 									// uint32_t cb_size = size of provided memory for control block
	NULL, 								// void * stack_mem = memory for stack
	0, 									// uint32_t stack_size = size of stack
	(osPriority_t) osPriorityHigh7, 	// osPriority_t priority = initial thread priority (default: osPriorityNormal)
	0, 									// TZModuleId_t tz_module = TrustZone module identifier
	0 									// reserved = reserved (must be 0)
};

/* Function Prototypes */
void startTask1(void * argument);
void StartMotorControlTask(void * argument);

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

#ifdef RUN_TESTS
	RunAllTests();
#endif

	task1Handle = osThreadNew(startTask1, NULL, &task1Attributes);
	motor_control_task_handle = osThreadNew(StartMotorControlTask, NULL, &motor_control_task_attrs);

	return 1;
}

void startTask1(void * argument) {
	// Currents to toggle between
	float theta = 0;
	float dtheta = 1;
	float max_current = 2.0; // [A]

	while(1) {
		uint32_t osTickCount = osKernelGetTickCount();
		uint32_t osTickFreq = osKernelGetTickFreq();
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

		motor->SetCurrent(max_current, 0.0f, 0.0f);
		osDelayUntil(osTickCount + osTickFreq / task1Freq);
		osTickCount = osKernelGetTickCount();
		motor->SetCurrent(0.0f, max_current, 0.0f);
		osDelayUntil(osTickCount + osTickFreq / task1Freq);
		osTickCount = osKernelGetTickCount();
		motor->SetCurrent(0.0f, 0.0f, max_current);

		// Wrap theta
//		theta = WrapAngle(theta + dtheta);

		osDelayUntil(osTickCount + osTickFreq / task1Freq);
	}
}

void StartMotorControlTask(void * argument) {

	motor->Init();

	while (1) {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
		motor->Update();
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY); // wait indefinitely for run notification, clear notifications (set to 0) upon receiving one
	}
}

#ifdef RUN_TESTS
void RunAllTests() {
	TestEncoderAll();
	TestPIDControllerAll();
	TestHalfBridgeAll();
	TestCurrentSensorAll();
	TestMotorDriverAll();
	TestFOCUtilsAll();
}
#endif


