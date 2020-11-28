#include "main.h"
#include "cmsis_os.h"

#define RUN_TESTS
#ifdef RUN_TESTS
#include "test_framework.hh"
#include "test_encoder.hh"
#include "test_half_bridge.hh"
#endif

/* Constants */
const uint32_t task1Freq = 2; // [Hz]

/* Function Prototypes */
void startTask1(void * argument);

osThreadId_t task1Handle;

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

/**
 * @brief Main function that avoids all the auto-generated junk from ST CubeMX.
 * @retval int
 */
int main_run() {

#ifdef RUN_TESTS
	RunAllTests();
#endif

	task1Handle = osThreadNew(startTask1, NULL, &task1Attributes);

	return 1;
}

void startTask1(void * argument) {
	while(1) {
		uint32_t osTickCount = osKernelGetTickCount();
		uint32_t osTickFreq = osKernelGetTickFreq();
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		osDelayUntil(osTickCount + osTickFreq / task1Freq);
	}
}

#ifdef RUN_TESTS
void RunAllTests() {
	TestEncoderAll();
	TestHalfBridgeAll();
}
#endif


