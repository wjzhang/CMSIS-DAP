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

#if defined(TARGET_LPC11U35)
/* For Mass storage, each sector is 512 Byte.
 * and LPC11U35 only 2K. also need buffer for iHex function 
*/
#define USB_BUFFER_SIZE			512				//512 bytes per Sector for FAT.

uint32_t usb_buffer[USB_BUFFER_SIZE/4] __at(0x20000000);

#endif

#endif  //USB_BUF_H
