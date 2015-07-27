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
#include "board.h"

/* Each board should have a unique ID and secret. For information
 *	about obtaining a secret contact support@mbed.org
 */
#define BOARD_ID        "2000"
#define BOARD_SECRET    "xxxxxxxx"


#if !defined(BOARD_SECRET) || !defined(BOARD_ID)
// TODO: how to check a string value using the preprocessor...
#error contact support@mbed.org to obtain a secret and board ID
#endif

BOARD board = {
    BOARD_ID,      // board id
    BOARD_SECRET   // board secret
};

/* Weak declaration of the board_init function for boards that don't use it */
__weak void board_init(void) {
}
