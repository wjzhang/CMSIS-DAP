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

#define FLASH_SECTOR_SIZE                  (1024)
#define TARGET_AUTO_INCREMENT_PAGE_SIZE    (1024)
#define TARGET_FALSH_BASE_ADDR		   (0x08000000)

static uint8_t target_flash_init(uint32_t clk);
static uint8_t target_flash_uninit(void);
static uint8_t target_flash_erase_chip(void);
static uint8_t target_flash_erase_sector(uint32_t adr);
static uint8_t target_flash_program_page(uint32_t adr, uint8_t * buf, uint32_t size);


static const uint32_t STM32F051_FLM[] = {
		0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x49544853, 0x48546048, 0x20006048, 0xb5104770, 0x20344603, 0x60e04c4f, 0xbd102000, 0x20004601, 
    0xb5004770, 0x23002200, 0x6902484a, 0x40102080, 0xd1012880, 0xffe4f7ff, 0x4846bf00, 0x07d868c3, 
    0xd1fa0fc0, 0x69024843, 0x43022004, 0x61024841, 0x20406902, 0x483f4302, 0xbf006102, 0x68c3483d, 
    0x0fc007d8, 0x483bd1fa, 0x21046902, 0x43884610, 0x48384602, 0x20006102, 0xb510bd00, 0x22004603, 
    0x48342400, 0x20806902, 0x28804010, 0xf7ffd101, 0xbf00ffb7, 0x68c4482f, 0x0fc007e0, 0x482dd1fa, 
    0x20026902, 0x482b4302, 0x61436102, 0x20406902, 0x48284302, 0xbf006102, 0x68c44826, 0x0fc007e0, 
    0x4824d1fa, 0x21026902, 0x43884610, 0x48214602, 0x20006102, 0xb5f7bd10, 0x22004615, 0x27002600, 
    0x462c9b00, 0x6902481b, 0x40102080, 0xd1012880, 0xff86f7ff, 0x4817bf00, 0x07f068c6, 0xd1fa0fc0, 
    0x4814e01b, 0x20016902, 0x48124302, 0x88206102, 0xbf008018, 0x68c6480f, 0x0fc007f0, 0x8820d1fa, 
    0x42888819, 0x480bd006, 0x08526902, 0x61020052, 0xbdfe2001, 0x1ca41c9b, 0x98011c7f, 0x42b80840, 
    0x4804d8df, 0x08526902, 0x61020052, 0xe7f02000, 0x45670123, 0x40022000, 0xcdef89ab, 0x00000000, 
};

static const TARGET_FLASH flash = {
    0x2000002F, // Init
    0x2000003D, // UnInit
    0x20000043, // EraseChip
    0x2000009B, // EraseSector
    0x200000F7, // ProgramPage

    // RSB : base adreess is address of Execution Region PrgData in map file
    //       to access global/static data
    // RSP : Initial stack pointer
    {
      0x20000001,             // breakpoint location
      0x20000020+0x00000180,  // static_base
      0x20000C00              // stack_pointer
    },
    0x20000400,               // program_buffer
    0x20000000,               // algo_start
    0x00000180,               // algo_size
    STM32F051_FLM,          // image
    FLASH_SECTOR_SIZE       // ram_to_flash_bytes_to_be_written
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
