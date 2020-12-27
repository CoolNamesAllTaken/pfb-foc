#include "main.h"
#include "cmsis_os.h"

#define RUN_TESTS
#ifdef RUN_TESTS
#include "test_framework.hh"
#include "test_encoder.hh"
#include "test_half_bridge.hh"
#include "test_pid_controller.hh"
#endif

#include "stspin830.hh"

#include "arm_math.h"

/**
 * Task Map
 * Task1 Example task.
 * current_control_task Current control task for testing half bridge.
 */

// Task Handles
osThreadId_t task1Handle;
osThreadId_t motor_control_task_handle;

/* Constants */
const uint32_t task1Freq = 500; // [Hz]
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
STSPIN830 * g_half_bridge_u;
STSPIN830 * g_half_bridge_v;
STSPIN830 * g_half_bridge_w;

/**
 * @brief Main function that avoids all the auto-generated junk from ST CubeMX.
 * @retval int
 */
int main_run() {
	static STSPIN830 half_bridge_u(
		half_bridge_pwm_timer,  // PWM timer
		TIM_CHANNEL_1,			// PWM timer channel
		curr_sense_adc_buf[0] /* curr_sense_adc_voltage */);
	g_half_bridge_u = &half_bridge_u;
	g_half_bridge_u->Init();

	static STSPIN830 half_bridge_v(
			half_bridge_pwm_timer,  // PWM timer
			TIM_CHANNEL_2,			// PWM timer channel
			curr_sense_adc_buf[1] /* curr_sense_adc_voltage */);
	g_half_bridge_v = &half_bridge_v;
	g_half_bridge_v->Init();

	static STSPIN830 half_bridge_w(
			half_bridge_pwm_timer,  // PWM timer
			TIM_CHANNEL_3,			// PWM timer channel
			curr_sense_adc_buf[2] /* curr_sense_adc_voltage */);
	g_half_bridge_w = &half_bridge_w;
	g_half_bridge_w->Init();

#ifdef RUN_TESTS
	RunAllTests();
#endif

	task1Handle = osThreadNew(startTask1, NULL, &task1Attributes);
	motor_control_task_handle = osThreadNew(StartMotorControlTask, NULL, &motor_control_task_attrs);

	return 1;
}

// NOTE: this only works for angles from -720 to 720 deg!
float WrapAngle(float theta) {
	if (theta > 360.0f) {
		theta -= 360.0f;
	} else if (theta < 0.0f) {
		theta += 360.0f;
	}
	return theta;
}

void startTask1(void * argument) {
	// Currents to toggle between
	float theta = 0;
	float dtheta = 10;
	float max_current = 100; // [mA]

	while(1) {
		uint32_t osTickCount = osKernelGetTickCount();
		uint32_t osTickFreq = osKernelGetTickFreq();
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

		// Wrap theta
		theta = WrapAngle(theta + dtheta);

		g_half_bridge_u->set_target_current(arm_sin_f32(theta * 2 * 3.1415f / 360.0f) * max_current);
		g_half_bridge_v->set_target_current(arm_sin_f32(WrapAngle(theta + 120.0f) * 2 * 3.1415f / 360.0f) * max_current);
//		float i_w = arm_sin_f32(WrapAngle(theta + 240.0f) * 2 * 3.1415f / 360.0f) * max_current;
//		g_half_bridge_w->set_target_current(i_w > 0 ? 500: -500);
		g_half_bridge_w->set_target_current(arm_sin_f32(WrapAngle(theta + 240.0f) * 2 * 3.1415f / 360.0f) * max_current);

		osDelayUntil(osTickCount + osTickFreq / task1Freq);
	}
}

void StartMotorControlTask(void * argument) {

	while (1) {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_SET);
		g_half_bridge_u->Update();
		g_half_bridge_v->Update();
		g_half_bridge_w->Update();
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY); // wait indefinitely for run notification, clear notifications (set to 0) upon receiving one
	}
}

#ifdef RUN_TESTS
void RunAllTests() {
	TestEncoderAll();
	TestPIDControllerAll();
	TestHalfBridgeAll();

}
#endif


