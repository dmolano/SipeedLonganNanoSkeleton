/* 
 * This file is part of the Sipeed Longan Nano Skeleton. LEDs in board: PC13(red led) , PA1 (green led) and PA2 (blue led)
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
#include "time.h"
#include "rcu.h"
#include "gpio.h"

#ifndef __GD32VF103_SLNS_LED_H
#define __GD32VF103_SLNS_LED_H

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------

/*!
    \brief      led_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_init();

/*!
    Turn on the red part of the RGB LED
    by clearing PC13
    \brief      led_red_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_red_on();

/*!
    Turn off the red part of the RGB LED
    by setting PC13
    \brief      led_red_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_red_off();

/*!
    Turn on and off the red part of the RGB LED
    by flashing PC13
    \brief      led_red_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void led_red_flash(uint32_t count);

/*!
    Turn on the red part of the RGB LED
    by flashing PC13
    \brief      led_red_flash_times function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void led_red_flash_times(uint32_t count, uint32_t times, uint32_t off_count);

/*!
    Turn on the blue part of the RGB LED
    by clearing PA1
    \brief      led_green_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_green_on();

/*!
    Turn off the green part of the RGB LED
    by setting PA1
    \brief      led_green_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_green_off();

/*!
    Turn on and off the green part of the RGB LED
    by flashing PA1
    \brief      led_green_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void led_green_flash(uint32_t count);

/*!
    Turn on the green part of the RGB LED
    by flashing PA1
    \brief      led_green_flash_times function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void led_green_flash_times(uint32_t count, uint32_t times, uint32_t off_count);

/*!
    Turn on the blue part of the RGB LED
    by clearing PA2
    \brief      led_blue_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_blue_on();

/*!
    Turn off the blue part of the RGB LED
    by setting PA2
    \brief      led_blue_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_blue_off();

/*!
    Turn on the blue part of the RGB LED
    by flashing PA1
    \brief      led_blue_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void led_blue_flash(uint32_t count);

/*!
    Turn on the blue part of the RGB LED
    by flashing PA1
    \brief      led_blue_flash_times function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void led_blue_flash_times(uint32_t count, uint32_t times, uint32_t off_count);

#endif