/* CMSIS-DAP Interface Firmware
 * Copyright (c) 2009-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef USB_BUF_H
#define USB_BUF_H

#include <absacc.h>
#include <stdint.h>

#if defined(TARGET_LPC11U35) && (defined(DBG_STM32F103RC) || defined(DBG_STM32F051))
/* For Mass storage, each sector is 512 Byte.
 * and LPC11U35 only 2K. also need buffer for iHex function 
*/
#define FLASH_USB_SECTOR_SIZE			512				//same as FLASH_PROGRAM_PAGE_SIZE

uint32_t usb_buffer[FLASH_USB_SECTOR_SIZE/4] __at(0x20000000);

#else

uint32_t usb_buffer[FLASH_SECTOR_SIZE/4] __at(0x20000000);

#if defined(TARGET_LPC11U35) && (FLASH_SECTOR_SIZE > 2048)
  // SRAM block on LPC11U35 is limited to 2KB
  #error "USB buffer too large for this platform"
#endif

#endif

#endif
