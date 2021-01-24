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

#include "gpio.h"
#include "time.h"

// ---------------------------------------------------------------------
// Local Prototypes
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Bodies
// ---------------------------------------------------------------------
/*!
    \brief      GPIO initialization function on the board's LEDs.
    \param[in]  none.
    \param[out] none
    \retval     none
*/
void slns_gpio_leds_in_board_init()
{
    gpio_init(RED_LED_BOARD_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, RED_LED_BOARD_GPIO_PIN);
    gpio_init(GREEN_LED_BOARD_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GREEN_LED_BOARD_GPIO_PIN);
    gpio_init(BLUE_LED_BOARD_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, BLUE_LED_BOARD_GPIO_PIN);
    GPIO_BOP(RED_LED_BOARD_GPIO_PORT) = RED_LED_BOARD_GPIO_PIN;
    GPIO_BOP(GREEN_LED_BOARD_GPIO_PORT) = GREEN_LED_BOARD_GPIO_PIN;
    GPIO_BOP(BLUE_LED_BOARD_GPIO_PORT) = BLUE_LED_BOARD_GPIO_PIN;
}

/*!
    \brief      LCD initialization function over DMA.
    \param[in]  none.
    \param[out] none
    \retval     none
*/
void slns_gpio_lcd_over_dma_init()
{
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5 | GPIO_PIN_7);
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);

    gpio_bit_reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1); // DC=0, RST=0
    gpio_bit_set(GPIOB, GPIO_PIN_2); // Disable lcd cs
    time_delay_1ms(1);
    gpio_bit_set(GPIOB, GPIO_PIN_1); // RST=1
    time_delay_1ms(5);
}