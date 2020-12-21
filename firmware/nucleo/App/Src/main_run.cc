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

/**
 * Task Map
 * Task1 Example task.
 * current_control_task Current control task for testing half bridge.
 */

// Task Handles
osThreadId_t task1Handle;
osThreadId_t current_control_task_handle;

/* Constants */
const uint32_t task1Freq = 2; // [Hz]
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

const uint32_t current_control_task_freq = 1000; // [Hz]
const osThreadAttr_t current_control_task_attrs = {
	"current_control_task", 			// cost char * name = name of the thread
	0, 									// uint32_t attr_bits = attribute bits
	osThreadDetached, 					// void * cb_mem = memory for control block
	0, 							// uint32_t cb_size = size of provided memory for control block
	NULL, 								// void * stack_mem = memory for stack
	0, 									// uint32_t stack_size = size of stack
	(osPriority_t) osPriorityHigh7, 	// osPriority_t priority = initial thread priority (default: osPriorityNormal)
	0, 									// TZModuleId_t tz_module = TrustZone module identifier
	0 									// reserved = reserved (must be 0)
};

/* Function Prototypes */
void startTask1(void * argument);
void StartCurrentControlTask(void * argument);

/* Global Variables */
STSPIN830 * g_half_bridge;

/**
 * @brief Main function that avoids all the auto-generated junk from ST CubeMX.
 * @retval int
 */
int main_run() {
	static STSPIN830 my_half_bridge(
		half_bridge_pwm_timer,  // PWM timer
		TIM_CHANNEL_1,			// PWM timer channel
		curr_sense_adc_buf[0] /* curr_sense_adc_voltage */);
	g_half_bridge = &my_half_bridge;
	g_half_bridge->Init();
	g_half_bridge->set_target_current(50); // [10mA]

#ifdef RUN_TESTS
	RunAllTests();
#endif

	task1Handle = osThreadNew(startTask1, NULL, &task1Attributes);
	current_control_task_handle = osThreadNew(StartCurrentControlTask, NULL, &current_control_task_attrs);

	return 1;
}

void startTask1(void * argument) {
	while(1) {
		uint32_t osTickCount = osKernelGetTickCount();
		uint32_t osTickFreq = osKernelGetTickFreq();
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		if (g_half_bridge->get_target_current() == 50) {
			g_half_bridge->set_target_current(100);
		} else {
			g_half_bridge->set_target_current(50);
		}
		osDelayUntil(osTickCount + osTickFreq / task1Freq);
	}
}

void StartCurrentControlTask(void * argument) {
	uint32_t osTickFreq = osKernelGetTickFreq();
	while (1) {
		uint32_t osTickCount = osKernelGetTickCount();
		g_half_bridge->Update();
		osDelayUntil(osTickCount + osTickFreq / current_control_task_freq);
	}
}

#ifdef RUN_TESTS
void RunAllTests() {
	TestEncoderAll();
	TestPIDControllerAll();
	TestHalfBridgeAll();

}
#endif


