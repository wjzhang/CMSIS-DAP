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
#include "target_reset.h"
#include "swd_host.h"
#include "target_ids.h"


typedef struct{
    void    (*init)(void);
    uint8_t (*unlock)(void);
    uint8_t (*setstate)(TARGET_RESET_STATE);
}Target_Reset;

//
void nrf51_target_before_init_debug(void);
uint8_t nrf51_target_unlock_sequence(void);
uint8_t nrf51_target_set_state(TARGET_RESET_STATE state);
void stm32f051_target_before_init_debug(void);
uint8_t stm32f051_target_unlock_sequence(void) ;
uint8_t stm32f051_target_set_state(TARGET_RESET_STATE state);
void stm32f103_target_before_init_debug(void);
uint8_t stm32f103_target_unlock_sequence(void) ;
uint8_t stm32f103_target_set_state(TARGET_RESET_STATE state);
void stm32f405_target_before_init_debug(void);
uint8_t stm32f405_target_unlock_sequence(void) ;
uint8_t stm32f405_target_set_state(TARGET_RESET_STATE state);
void stm32f071_target_before_init_debug(void);
uint8_t stm32f071_target_unlock_sequence(void) ;
uint8_t stm32f071_target_set_state(TARGET_RESET_STATE state);


uint8_t default_target_set_state(TARGET_RESET_STATE state) {
    return swd_set_target_state(state);
}

static const Target_Reset targets[] = {
    {nrf51_target_before_init_debug    , nrf51_target_unlock_sequence    , nrf51_target_set_state    },
    {stm32f051_target_before_init_debug, stm32f051_target_unlock_sequence, stm32f051_target_set_state},
    {stm32f103_target_before_init_debug, stm32f103_target_unlock_sequence, stm32f103_target_set_state},
    {stm32f405_target_before_init_debug, stm32f405_target_unlock_sequence, stm32f405_target_set_state},   
    {stm32f071_target_before_init_debug, stm32f071_target_unlock_sequence, stm32f071_target_set_state}
};


void target_before_init_debug(void) {
    if(targetID != Target_UNKNOWN){    
        targets[targetID].init();
    }
}

uint8_t target_unlock_sequence(void) {
    if(targetID != Target_UNKNOWN){    
        return  targets[targetID].unlock();
    }else{
        return 1;
    }
}

uint8_t target_set_state(TARGET_RESET_STATE state) {
    if(targetID != Target_UNKNOWN){    
        return targets[targetID].setstate(state);
    }else{
        return default_target_set_state(state);
    }
}
