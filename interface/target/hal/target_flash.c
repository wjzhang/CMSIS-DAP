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

#include "target_flash.h"
#include "target_ids.h"

//declare
uint16_t nrf51_GetSecNum (unsigned long adr);
unsigned long nrf51_GetSecAddress(uint16_t sector);
extern const TARGET_FLASH NRF51_flash;

uint16_t stm32f051_GetSecNum (unsigned long adr);
unsigned long stm32f051_GetSecAddress(uint16_t sector);
extern const TARGET_FLASH stm32f051_flash;

uint16_t stm32f103_GetSecNum (unsigned long adr);
unsigned long stm32f103_GetSecAddress(uint16_t sector);
extern const TARGET_FLASH stm32f103_flash;

uint16_t stm32f405_GetSecNum (unsigned long adr);
unsigned long stm32f405_GetSecAddress (uint16_t sector);
extern const TARGET_FLASH stm32f405_flash;

uint16_t stm32f071_GetSecNum (unsigned long adr);
unsigned long stm32f071_GetSecAddress(uint16_t sector);
extern const TARGET_FLASH stm32f071_flash;

static const Target_Flash targets_flash[] ={
    {nrf51_GetSecNum    , nrf51_GetSecAddress    , &NRF51_flash    },
    {stm32f051_GetSecNum, stm32f051_GetSecAddress, &stm32f051_flash},
    {stm32f103_GetSecNum, stm32f103_GetSecAddress, &stm32f103_flash},
    {stm32f405_GetSecNum, stm32f405_GetSecAddress, &stm32f405_flash},
    {stm32f071_GetSecNum, stm32f071_GetSecAddress, &stm32f071_flash}   
};


uint32_t target_flash_autoincrementpagesize(void){
        if(targetID != Target_UNKNOWN){
            return targets_flash[targetID].flash->auto_increment_page_size;
        }
        else{
            return 0;
        }
}

uint32_t target_flash_baseaddress(void){
        if(targetID != Target_UNKNOWN){
            return targets_flash[targetID].flash->flash_base_addr;    
        }
        else{
            return 0;
        }
}

uint32_t target_flash_sectorsize(void){
        if(targetID != Target_UNKNOWN){
            return targets_flash[targetID].flash->flash_sector_size;    
        }
        else{
            return 0;
        }
}

uint8_t target_flash_init(uint32_t clk) {
    if(targetID == Target_UNKNOWN){
        return 0;
    }
    // Download flash programming algorithm to target and initialise.
    if (!swd_write_memory(targets_flash[targetID].flash->algo_start, (uint8_t *)targets_flash[targetID].flash->image, targets_flash[targetID].flash->algo_size)) {
        return 0;
    }

    if (!swd_flash_syscall_exec(&targets_flash[targetID].flash->sys_call_param, targets_flash[targetID].flash->init, 0, 0 /* clk value is not used */, 0, 0)) {
        return 0;
    }

    return 1;
}


uint8_t target_flash_erase_sector(unsigned int sector) {
    uint32_t address = 0;

    if(targetID == Target_UNKNOWN){
        return 0;
    }    
    
    address =	targets_flash[targetID].GetSecAddress(sector);
    if (!swd_flash_syscall_exec(&targets_flash[targetID].flash->sys_call_param, targets_flash[targetID].flash->erase_sector, address, 0, 0, 0)) {
        return 0;
    }

    return 1;    
}

static uint8_t  flash_is_erase_all = 0;

uint8_t target_flash_erase_chip(void) {
    if(targetID == Target_UNKNOWN){
        return 0;
    }    
	// 1 == O.K. AND 0 == Error
   if (!swd_flash_syscall_exec(&targets_flash[targetID].flash->sys_call_param, targets_flash[targetID].flash->erase_chip, 0, 0, 0, 0)) {  
        return 0;
    }
    
    flash_is_erase_all = 1;      
    return 1;    
}

uint8_t target_flash_program_page(uint32_t addr, uint8_t * buf, uint32_t size){
    static uint16_t lastSecNum = 0xFFFF;
    uint32_t bytes_written = 0;

    if(targetID == Target_UNKNOWN){
        return 0;
    }    
    // Program a page in target flash.
    if (!swd_write_memory(targets_flash[targetID].flash->program_buffer, buf, size)) {
        return 0;
    }
    
   
    while(bytes_written < size) {
        uint32_t bytes;
        uint32_t nextsectoraddress = 0;
        uint16_t currentSecNum = targets_flash[targetID].GetSecNum(addr);
        if ((0 == flash_is_erase_all) && (currentSecNum != lastSecNum)) {
            if(!target_flash_erase_sector(currentSecNum)){
                return 0;
            }
						
            lastSecNum = currentSecNum;
        }
				
        if ((size - bytes_written) < targets_flash[targetID].flash->ram_to_flash_bytes_to_be_written) {
            bytes = size - bytes_written;
        } else {
            bytes = targets_flash[targetID].flash->ram_to_flash_bytes_to_be_written;
        }

        //check is cross sectors
        nextsectoraddress = targets_flash[targetID].GetSecAddress(currentSecNum) + target_flash_sectorsize();
        if((addr + bytes)  >  nextsectoraddress){
            bytes = nextsectoraddress - addr;
        }
        
        if (!swd_flash_syscall_exec(&targets_flash[targetID].flash->sys_call_param,
                                    targets_flash[targetID].flash->program_page,
                                    addr,                                     // arg1
                                    bytes,                                    // arg2
                                    targets_flash[targetID].flash->program_buffer + bytes_written, 0)) { // arg3, arg4
            return 0;
        }
				
        bytes_written += bytes;
        addr += bytes;
    }

    return 1;    
}

