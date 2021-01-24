/* 
 * This file is part of the Sipeed Longan Nano Skeleton. TFT LCD MODULE - 0.96 inch - 80RGB*160DOTS - MODULE NUMBER:SPD096-IPS
 * LH096T-IG01 is a 80RGBX160 dot-matrix TFT LCD module. This module is composed of a TFT LCD Panel, driver ICs (Main Drive IC ST7735S), FPC and a Backlight unit.
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

#include "lcd.h"

#define RCUS_FOR_LCD 5
#define SENTINEL_NODE 1

// ---------------------------------------------------------------------
// Local Prototypes
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Bodies
// ---------------------------------------------------------------------
/*!
    \brief      LCD initialization function.
    \param[in]  sln_lcd_info_ptr
    \param[out] none
    \retval     none
*/
void lcd_init(sln_lcd_ptr sln_lcd_info_ptr)
{
    struct
    {
        rcu_periph_enum rcu_periph[RCUS_FOR_LCD + SENTINEL_NODE];
    } rcus_periph = {{RCU_GPIOA, RCU_GPIOB, RCU_AF, RCU_DMA0, RCU_SPI0, RCU_SPI0}};
    // Sentinel node ---------------------------^ (The same item as above.)

    /* enable the leds clock in board */
    slns_rcu_init((rcu_periph_enum *) &rcus_periph);
    /* configure led GPIO ports */
    slns_gpio_lcd_over_dma_init();
}