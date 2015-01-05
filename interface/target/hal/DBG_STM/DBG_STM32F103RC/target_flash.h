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

#define FLASH_SECTOR_SIZE                  (2048)
#define TARGET_AUTO_INCREMENT_PAGE_SIZE    (2048)
#define TARGET_FALSH_BASE_ADDR		   (0x08000000)

static uint8_t target_flash_init(uint32_t clk);
static uint8_t target_flash_uninit(void);
static uint8_t target_flash_erase_chip(void);
static uint8_t target_flash_erase_sector(uint32_t adr);
static uint8_t target_flash_program_page(uint32_t adr, uint8_t * buf, uint32_t size);


static const uint32_t STM32F103RC_FLM[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x49384839, 0x49396041, 0x20006041, 0x49364770, 0x60c82034, 0x47702000, 0x47702000, 0xb5004a32, 
    0x06006910, 0xf7ffd501, 0x68d0ffeb, 0xd1fc07c0, 0xf0406910, 0x61100004, 0xf0406910, 0x61100040, 
    0x07c068d0, 0x6910d1fc, 0x0004f020, 0x20006110, 0x4a25bd00, 0x4603b500, 0x06006910, 0xf7ffd501, 
    0x68d1ffcf, 0xd1fc07c9, 0xf0406910, 0x61100002, 0x69106153, 0x0040f040, 0x68d06110, 0xd1fc07c0, 
    0xf0206910, 0x61100002, 0xbd002000, 0x4d16b570, 0x460e4603, 0x24006928, 0xd5010600, 0xffb0f7ff, 
    0x07c068e8, 0xe014d1fc, 0x0001f040, 0x88106128, 0x68e88018, 0xd1fc07c0, 0x88198810, 0xd0054288, 
    0xf0206928, 0x61280001, 0xbd702001, 0x1c9b1c92, 0x69281c64, 0x0f56ebb4, 0xf020d3e6, 0x61280001, 
    0xbd702000, 0x45670123, 0x40022000, 0xcdef89ab, 0x00000000,
};

static const TARGET_FLASH flash = {
    0x2000002F, // Init
    0x20000039, // UnInit
    0x2000003D, // EraseChip
    0x20000073, // EraseSector
    0x200000AD, // ProgramPage

    // RSB : base adreess is address of Execution Region PrgData in map file
    //       to access global/static data
    // RSP : Initial stack pointer
    {
      0x20000001,             // breakpoint location
      0x20000020+0x00000114,  // static_base
      0x20002000              // stack_pointer
    },
    0x20001000,               // program_buffer
    0x20000000,               // algo_start
    0x00000114,               // algo_size
    STM32F103RC_FLM,          // image
    FLASH_SECTOR_SIZE         // ram_to_flash_bytes_to_be_written
};

static uint8_t  flash_is_erase_all = 0;

static uint8_t target_flash_init(uint32_t clk) {
    // Download flash programming algorithm to target and initialise.
    if (!swd_write_memory(flash.algo_start, (uint8_t *)flash.image, flash.algo_size)) {
        return 0;
    }

    if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.init, 0, 0 /* clk value is not used */, 0, 0)) {
        return 0;
    }

    return 1;
}

static uint8_t target_flash_erase_sector(unsigned int sector) {

    uint32_t address =	TARGET_FALSH_BASE_ADDR + sector*FLASH_SECTOR_SIZE;
    if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.erase_sector, address, 0, 0, 0)) {
        return 0;
    }

    return 1;
}

static uint8_t target_flash_erase_chip(void) {
	// 1 == O.K. AND 0 == Error
   if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.erase_chip, 0, 0, 0, 0)) {  
        return 0;
    }
    

    flash_is_erase_all = 1;      
    return 1;
}

static uint16_t GetSecNum (unsigned long adr) {
	uint32_t address = adr - TARGET_FALSH_BASE_ADDR;
    uint16_t n = (address >> 11); 
    return (n);
}

uint8_t target_flash_program_page(uint32_t addr, uint8_t * buf, uint32_t size)
{
    static uint16_t lastSecNum = 0xFFF0;
    uint32_t bytes_written = 0;
    
    // Program a page in target flash.
    if (!swd_write_memory(flash.program_buffer, buf, size)) {
        return 0;
    }
    
		/*
    if (addr == 0) {
        if (!target_flash_erase_chip()) { 
            return 0;
        }
    }
		*/
    
    while(bytes_written < size) {
        uint32_t bytes;
        uint16_t currentSecNum = GetSecNum(addr);
        if ((addr < 0x08080000) && (0 == flash_is_erase_all) && (currentSecNum != lastSecNum)) {
            if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.erase_sector, addr, 0, 0, 0)) {
                return 0;
            }
            
            lastSecNum = currentSecNum;
        }
        
        if (size < flash.ram_to_flash_bytes_to_be_written) {
            bytes = size;
        } else {
            bytes = flash.ram_to_flash_bytes_to_be_written;
        }
        
        if (!swd_flash_syscall_exec(&flash.sys_call_param,
                                    flash.program_page,
                                    addr,                                     // arg1
                                    bytes,                                    // arg2
                                    flash.program_buffer + bytes_written, 0)) { // arg3, arg4
            return 0;
        }
        bytes_written += flash.ram_to_flash_bytes_to_be_written;
        addr += flash.ram_to_flash_bytes_to_be_written;
    }

    return 1;
}


#endif
