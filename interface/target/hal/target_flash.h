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
#ifndef TARGET_FLASH_H
#define TARGET_FLASH_H

#include "target_struct.h"
#include "swd_host.h"
#include "target_reset.h"
#include <stdint.h>
#include <debug_cm.h>
#include <RTL.h>


typedef struct{
    uint16_t           (*GetSecNum)    (unsigned long adr);
    unsigned long      (*GetSecAddress)(uint16_t sector);
    unsigned long      (*GetSecLength)(uint16_t sector);
    const TARGET_FLASH *flash;
}Target_Flash;

uint8_t target_flash_init(uint32_t clk);
uint8_t target_flash_uninit(void);
uint8_t target_flash_erase_chip(void);
uint8_t target_flash_erase_sector(uint32_t adr);
uint8_t target_flash_program_page(uint32_t adr, uint8_t * buf, uint32_t size);

uint32_t target_flash_autoincrementpagesize(void);
uint32_t target_flash_baseaddress(void);
uint32_t target_flash_sectorsize(void);

#endif
