/* 
 * This file is part of the Sipeed Longan Nano Skeleton. TFT LCD MODULE - 0.96 inch - 80RGB*160DOTS - MODULE NUMBER:SPD096-IPS
 * LH096T-IG01 is a 80RGBX160 dot-matrix TFT LCD module. This module is composed of a TFT LCD Panel, driver ICs (Main Drive IC ST7735S), FPC and a Backlight unit.
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
#include "rcu.h"
#include "gpio.h"

#ifndef __GD32VF103_SLNS_LCD_H
#define __GD32VF103_SLNS_LCD_H

#define LCD_WIDTH               160
#define LCD_HEIGHT              80

/*!
    \brief      LCD wait status
*/
typedef enum
{
    WAIT_NONE,
    WAIT_READ_U24,
    WAIT_WRITE_U24,
} lcd_wait_status;

/*!
    \brief      Sipeed Longan Nano struct
*/
typedef struct
{
    lcd_wait_status wait_status;
    struct
    {
        uint8_t enabled;
        uint32_t address;
    } frame_background;
    uint16_t width;
    uint16_t height;
} sln_lcd, *sln_lcd_ptr;

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      LCD initialization function.
    \param[in]  sln_lcd_info_ptr
    \param[out] none
    \retval     none
*/
void lcd_init(sln_lcd_ptr sln_lcd_data_ptr);

/*!
    \brief      set pixel
    \param[in]  sln_lcd_info_ptr:
    \param[in]  x: x position
    \param[in]  y: y position
    \param[out] none
    \retval     none
*/
void lcd_setpixel(sln_lcd_ptr sln_lcd_info_ptr, int x, int y, unsigned short int color);

#endif