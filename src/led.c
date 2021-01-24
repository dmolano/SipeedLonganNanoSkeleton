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

#include "led.h"

#define RCUS_FOR_BOARDS_LEDS 2
#define SENTINEL_NODE 1

// ---------------------------------------------------------------------
// Local Prototypes
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Bodies
// ---------------------------------------------------------------------
/*!
    \brief      led_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_init()
{
    struct
    {
        rcu_periph_enum rcu_periph[RCUS_FOR_BOARDS_LEDS + SENTINEL_NODE];
    } rcus_periph = {{RCU_GPIOA, RCU_GPIOC, RCU_GPIOC}};
    // Sentinel node ---------------------------^ (The same item as above.)

    /* enable the leds clock in board */
    slns_rcu_init((rcu_periph_enum *) &rcus_periph);
    /* configure led GPIO ports */
    slns_gpio_leds_in_board_init();
}

/*!
    Turn on and off the X part of the RGB LED
    by clearing its bit.
    \brief      led_rgb_flash function
    \param[in]  count: count in milliseconds
    \param[in]  led_rgb_on: led RGB on function
    \param[in]  led_rgb_off: led RGB off function
    \param[out] none
    \retval     none
*/
void led_rgb_flash(uint32_t count, void (*led_rgb_on)(void), void (*led_rgb_off)(void))
{
    led_rgb_on();
    time_delay_1ms(count);
    led_rgb_off();
}

/*!
    Flash times the X part of the RGB LED
    by clearing its bit
    \brief      led_rgb_flash_times function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[in]  led_rgb_flash: led RGB flash function
    \param[out] none
    \retval     none
*/
void led_rgb_flash_times(uint32_t count, uint32_t times, uint32_t off_count, void (*led_rgb_flash)(uint32_t))
{
    while (times--)
    {
        led_rgb_flash(count);
        if (times)
        {
            time_delay_1ms(off_count);
        }
    }
}

/*!
    Turn on the red part of the RGB LED
    by clearing PC13
    \brief      led_red_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_red_on()
{
    GPIO_BC(GPIOC) = GPIO_PIN_13;
}

/*!
    Turn off the red part of the RGB LED
    by setting PC13
    \brief      led_red_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_red_off()
{
    GPIO_BOP(GPIOC) = GPIO_PIN_13;
}

/*!
    Turn on and off the red part of the RGB LED
    by flashing PC13
    \brief      led_red_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void led_red_flash(uint32_t count)
{
    led_rgb_flash(count, &led_red_on, &led_red_off);
}

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
void led_red_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    led_rgb_flash_times(count, times, off_count, &led_red_flash);
}

/*!
    Turn on the blue part of the RGB LED
    by clearing PA1
    \brief      led_green_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_green_on()
{
    GPIO_BC(GPIOA) = GPIO_PIN_1;
}

/*!
    Turn off the green part of the RGB LED
    by setting PA1
    \brief      led_green_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_green_off()
{
    GPIO_BOP(GPIOA) = GPIO_PIN_1;
}

/*!
    Turn on and off the green part of the RGB LED
    by flashing PA1
    \brief      led_green_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void led_green_flash(uint32_t count)
{
    led_rgb_flash(count, &led_green_on, &led_green_off);
}

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
void led_green_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    led_rgb_flash_times(count, times, off_count, &led_green_flash);
}

/*!
    Turn on the blue part of the RGB LED
    by clearing PA2
    \brief      led_blue_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_blue_on()
{
    GPIO_BC(GPIOA) = GPIO_PIN_2;
}

/*!
    Turn off the blue part of the RGB LED
    by setting PA2
    \brief      led_blue_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_blue_off()
{
    GPIO_BOP(GPIOA) = GPIO_PIN_2;
}

/*!
    Turn on the blue part of the RGB LED
    by flashing PA1
    \brief      led_blue_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void led_blue_flash(uint32_t count)
{
    led_rgb_flash(count, &led_blue_on, &led_blue_off);
}

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
void led_blue_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    led_rgb_flash_times(count, times, off_count, &led_blue_flash);
}
