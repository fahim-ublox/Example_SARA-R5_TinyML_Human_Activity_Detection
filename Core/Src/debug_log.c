/*
 * 2023 u-blox
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Includes ------------------------------------------------------------------*/
#include "tensorflow/lite/micro/debug_log.h"
#include "stm32f4xx_hal.h"
#include "usbd_cdc_if.h"
#include <stdio.h>

/* Extern Variables ---------------------------------------------------------*/

/* Function Definitions -----------------------------------------------------*/
int __io_putchar(int ch)
{
    while(!(CDC_Transmit_FS((uint8_t*)&ch, 1) == USBD_BUSY));
    HAL_Delay(1);
    return ch;
}


// Used by TFLite error_reporter
void DebugLog(const char *s)
{
	fprintf(stderr, "%s", s);
	// NOTE: fprintf uses _write(), which is defined in syscall.c
	//       _write() uses __io_putchar(), which is a weak function
	//       and needs to be implemented by user.
}

