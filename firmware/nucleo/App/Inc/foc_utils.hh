/*
 * foc_utils.hh
 *
 *  Created on: Jun 27, 2021
 *      Author: John McNelly
 */

#ifndef _FOC_UTILS_HH_
#define _FOC_UTILS_HH_

#include "stm32f7xx_hal.h"
#include <stdint.h>

#define CONSTRAIN(val, low, high) ((val) < (low) ? (low) : ((val) > (high) ? (high) : (val)))
#define WITHIN(val1, val2, diff) ((val1) > (val2) ? ((val1) - (val2) < (diff)) : ((val2) - (val1) < (diff)))

uint32_t GetTickMicros();

#endif /* INC_FOC_UTILS_HH_ */
