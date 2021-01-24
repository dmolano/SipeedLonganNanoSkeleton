/* 
 * This file is part of the Sipeed Longan Nano Skeleton. General-purpose and alternate-function I/Os (GPIO and AFIO)
 * Copyright (c) 2021 Dionisio Molano Robledo.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "gd32vf103.h"

#ifndef __GD32VF103_SLNS_GPIO_H
#define __GD32VF103_SLNS_GPIO_H

#define RED_LED_BOARD_GPIO_PIN GPIO_PIN_13
#define GREEN_LED_BOARD_GPIO_PIN GPIO_PIN_1
#define BLUE_LED_BOARD_GPIO_PIN GPIO_PIN_2

#define RED_LED_BOARD_GPIO_PORT GPIOC
#define GREEN_LED_BOARD_GPIO_PORT GPIOA
#define BLUE_LED_BOARD_GPIO_PORT GPIOA

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      GPIO initialization function on the board's LEDs.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void slns_gpio_leds_in_board_init();

#endif