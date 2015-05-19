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


#define FLASH_SECTOR_SIZE                  (512)		//actual is 16KB/64KB/128KB
#define TARGET_AUTO_INCREMENT_PAGE_SIZE    (512)
#define TARGET_FALSH_BASE_ADDR		   (0x08000000)

static uint8_t target_flash_init(uint32_t clk);
static uint8_t target_flash_uninit(void);
static uint8_t target_flash_erase_chip(void);
static uint8_t target_flash_erase_sector(uint32_t adr);
static uint8_t target_flash_program_page(uint32_t adr, uint8_t * buf, uint32_t size);



static const uint32_t STM32F405_FLM[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,		/*0x0020*/
    0xf1a14601, 0xf44f6200, 0xf04f3380, 0x429a30ff, 0x0b90d201, 0x4a494770, 0x429a440a, 0x2004d201, 	/*0x0040*/
    0x4a474770, 0xf5b14411, 0xd2f92f60, 0xeb002005, 0x47704051, 0x49434844, 0x49446001, 0x20006001, 	/*0x0060*/
    0x49414770, 0x310820f1, 0x20006008, 0x20004770, 0x4a3d4770, 0x320cb500, 0x28006810, 0xf7ffda01, 	/*0x0080*/
    0x4939ffe9, 0x68083108, 0xd4fc03c0, 0xf0406810, 0x60100004, 0xf4406810, 0x60103080, 0x03c06808, 	/*0x00A0*/
    0x6810d4fc, 0x0004f020, 0x20006010, 0xb530bd00, 0x46024d2d, 0x6828350c, 0xda012800, 0xffcaf7ff, 	/*0x00C0*/
    0x34084c29, 0x03c86821, 0x4610d4fc, 0xffa8f7ff, 0x22026829, 0x0178f021, 0x00c0eb02, 0x0001ea40, 	/*0x00E0*/
    0x68286028, 0x3080f440, 0x68206028, 0xd4fc03c0, 0xf0206828, 0x60280002, 0xbd302000, 0x4f1ab5f0, 	/*0x0100*/
    0x370c2400, 0x68384603, 0x2800460e, 0xf7ffda01, 0x4d15ffa1, 0x1101f240, 0x68283508, 0xd4fc03c0, 	/*0x0120*/
    0x4308e014, 0x88106038, 0x68288018, 0xd4fc03c0, 0xf8b38810, 0x4560c000, 0x6838d005, 0x0001f020, 	/*0x0140*/
    0x20016038, 0x1c9bbdf0, 0x1c641c92, 0xebb46838, 0xd3e60f56, 0x60384388, 0xbdf02000, 0xf7ff0000, 	/*0x0160*/
    0xf7fe0000, 0x45670123, 0x40023c04, 0xcdef89ab, 0x00000000, 
};

static const TARGET_FLASH flash = {
    0x20000063, // Init
    0x2000006F, // UnInit
    0x20000073, // EraseChip
    0x200000AF, // EraseSector
    0x200000FD, // ProgramPage

    // RSB : base adreess is address of Execution Region PrgData in map file
    //       to access global/static data
    // RSP : Initial stack pointer
    {
      0x20000001,             // breakpoint location
      0x20000020+0x00000174,  // static_base
      0x20002000              // stack_pointer
    },
    0x20001000,               // program_buffer
    0x20000000,               // algo_start
    0x00000174,               // algo_size
    STM32F405_FLM,            // image
    FLASH_SECTOR_SIZE         // ram_to_flash_bytes_to_be_written
};

static uint16_t GetSecNum (unsigned long adr) {
	uint16_t rc = 0xFFFF;
	if(adr >= 0x08000000 && adr < 0x08010000)
	{
		rc = (adr - 0x08000000)/0x4000;
	}
	else 	if(adr >= 0x08010000 && adr < 0x08020000)
	{
		rc = 4;
	}
	else 	if(adr >= 0x08020000 && adr < 0x08100000)
	{
		rc = 5 + (adr - 0x08020000)/0x20000;
	}
	return rc;
}

static unsigned long GetSecAddress (uint16_t sector) {
	unsigned long rc  = 0x08000000;
	if(sector < 4)
	{
		rc += 0x4000 * sector;
	}
	else if(sector == 4)
	{
		rc += 0x10000;
	}
	else
	{
		rc += (sector-4)*0x20000;
	}
	return rc;
}

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

    uint32_t address =	GetSecAddress(sector);
    if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.erase_sector, address, 0, 0, 0)) {
        return 0;
    }

    return 1;
}

static uint8_t target_flash_erase_chip(void) {
//	 1 == O.K. AND 0 == Error
//   if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.erase_chip, 0, 0, 0, 0)) {
//        return 0;
//    }
    	
    flash_is_erase_all = 0;      
    return 1;
}



uint8_t target_flash_program_page(uint32_t addr, uint8_t * buf, uint32_t size)
{
    static uint16_t lastSecNum = 0xFFFF;
    uint32_t bytes_written = 0;
    
    // Program a page in target flash.
    if (!swd_write_memory(flash.program_buffer, buf, size)) {
        return 0;
    }
    

    while(bytes_written < size) {
        uint32_t bytes;
        uint16_t currentSecNum = GetSecNum(addr);
        if ((addr < 0x08100000) && (0 == flash_is_erase_all) && (currentSecNum != lastSecNum)) {
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
