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
#include <LPC11Uxx.h>
#include <RTL.h>

#include "gpio.h"

static uint16_t isr_flags;
static OS_TID isr_notify;

#define SW_RESET_BUTTON    1

#ifdef SW_RESET_BUTTON

#if defined(BOARD_MB2100)
#define RESET_PORT        (0)
#define RESET_PIN         (2)
#else 
#define RESET_PORT        (1)
#define RESET_PIN         (19)
#endif

#define RESET_INT_CH      (0)
#define RESET_INT_MASK    (1 << RESET_INT_CH)

#endif	//(SW_RESET_BUTTON)


#define PIN_CFG0          (1<<20)
#define PIN_CFG1          (1<<16)
#define PIN_CFG2          (1<<11)
#define PIN_CFG3          (1<<14)

#define PIN_DAP_LED       (1<<13)
#define PIN_CDC_LED       (1<<12)

void gpio_init(void) {
    // enable clock for GPIO port 0
    LPC_SYSCON->SYSAHBCLKCTRL |= (1UL << 6);

	//config the CFG 4 pins as input
    LPC_GPIO->DIR[0]  &= ~(PIN_CFG0);
    LPC_GPIO->CLR[0]  |= (PIN_CFG0);
    LPC_GPIO->DIR[0]  &= ~(PIN_CFG1);
    LPC_GPIO->CLR[0]  |= (PIN_CFG1);
	LPC_IOCON->TDI_PIO0_11 |= 0x01;  //change to GPIO mode
  	LPC_GPIO->DIR[0]  &= ~(PIN_CFG2);
    LPC_GPIO->CLR[0]  |= (PIN_CFG2);
	LPC_IOCON->TRST_PIO0_14 |= 0x01;  //change to GPIO mode	
    LPC_GPIO->DIR[0]  &= ~(PIN_CFG3);
    LPC_GPIO->CLR[0]  |= (PIN_CFG3);
	
    // configure GPIO-LED as output
    // DAP led (green)
	LPC_IOCON->TDO_PIO0_13 |= 0x01;  //change to GPIO mode		  
    LPC_GPIO->DIR[0]  |= (PIN_DAP_LED);
    LPC_GPIO->CLR[0]  |= (PIN_DAP_LED);

    // Serial LED (blue)
    LPC_IOCON->TMS_PIO0_12 |= 0x01;
    LPC_GPIO->DIR[0]  |= (PIN_CDC_LED);
    LPC_GPIO->CLR[0]  |= (PIN_CDC_LED);

    // configure Button as input
#if SW_RESET_BUTTON
    LPC_GPIO->DIR[RESET_PORT]  &= ~(1 << RESET_PIN);
#endif

    /* Enable AHB clock to the FlexInt, GroupedInt domain. */
    LPC_SYSCON->SYSAHBCLKCTRL |= ((1<<19) | (1<<23) | (1<<24));
}

void gpio_set_dap_led(uint8_t state) {
    if (state) {
        LPC_GPIO->SET[0] |= (PIN_DAP_LED);
    } else {
        LPC_GPIO->CLR[0] |= (PIN_DAP_LED);
    }
}

void gpio_set_cdc_led(uint8_t state) {
    if (state) {
        LPC_GPIO->SET[0] |= (PIN_CDC_LED);
    } else {
        LPC_GPIO->CLR[0] |= (PIN_CDC_LED);
    }
}

static uint32_t gpio_get_config0(void)
{
	return ((LPC_GPIO->PIN[0] & PIN_CFG0) != 0x00)? PIN_HIGH:PIN_LOW;
}

static uint32_t gpio_get_config1(void)
{
	return ((LPC_GPIO->PIN[0] & PIN_CFG1) != 0x00)? PIN_HIGH:PIN_LOW;
}

static uint32_t gpio_get_config2(void)
{
	return ((LPC_GPIO->PIN[0] & PIN_CFG2) != 0x00)? PIN_HIGH:PIN_LOW;
}

static uint32_t gpio_get_config3(void)
{
	return ((LPC_GPIO->PIN[0] & PIN_CFG3) != 0x00)? PIN_HIGH:PIN_LOW;
}

uint8_t gpio_get_config(uint8_t cfgid)
{
    uint8_t rc = 0;
	switch (cfgid)
	{
        case PIN_CONFIG_DT01:
            rc = gpio_get_config0();
            break;

		case PIN_CONFIG_1:
			rc = gpio_get_config1();
			break;

		case PIN_CONFIG_2:
			rc = gpio_get_config2();
            break;

		case PIN_CONFIG_3:
			rc = gpio_get_config3();
			break;
    }

	return rc;
}

void gpio_enable_button_flag(OS_TID task, uint16_t flags) {
    /* When the "reset" button is pressed the ISR will set the */
    /* event flags "flags" for task "task" */

    /* Keep a local copy of task & flags */
    isr_notify=task;
    isr_flags=flags;

#if SW_RESET_BUTTON
    LPC_SYSCON->STARTERP0 |= RESET_INT_MASK;
    LPC_SYSCON->PINTSEL[RESET_INT_CH] = (RESET_PORT) ? (RESET_PIN + 24) : (RESET_PIN);

    if (!(LPC_GPIO_PIN_INT->ISEL & RESET_INT_MASK))
        LPC_GPIO_PIN_INT->IST = RESET_INT_MASK;

    LPC_GPIO_PIN_INT->IENF |= RESET_INT_MASK;

    NVIC_EnableIRQ(FLEX_INT0_IRQn);
#endif
}

void FLEX_INT0_IRQHandler() {
    isr_evt_set(isr_flags, isr_notify);
    NVIC_DisableIRQ(FLEX_INT0_IRQn);

    // ack interrupt
    LPC_GPIO_PIN_INT->IST = 0x01;
}
