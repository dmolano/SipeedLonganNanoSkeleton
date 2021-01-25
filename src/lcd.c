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
#include "spi.h"

#define RCUS_FOR_LCD 5
#define SENTINEL_NODE 1

typedef enum ST7735S_Command_Type
{
    NOP = 0x00,
    SWRESET = 0x01,   /* Software Reset */
    RDDID = 0x04,     /* Read Display ID */
    RDDST = 0x09,     /* Read Display Status */
    RDDPM = 0x0a,     /* Read Display Power Mode */
    RDDMADCTL = 0x0b, /* Read Display MADCTL */
    RDDCOLMOD = 0x0c, /* Read Display Pixel Format */
    RDDIM = 0x0d,     /* Read Display Image Mode */
    RDDSM = 0x0e,     /* Read Display Signal Mode */
    RDDSDR = 0x0f,    /* Read Display Self-Diagnostic Result */
    SLPIN = 0x10,     /* Sleep In */
    SLPOUT = 0x11,    /* Sleep Out */
    PTLON = 0x12,     /* Partial Display Mode On */
    NORON = 0x13,     /* Normal Display Mode On */
    INVOFF = 0x20,    /* Display Inversion Off */
    INVON = 0x21,     /* Display Inversion On */
    GAMSET = 0x26,    /* Gamma Set */
    DISPOFF = 0x28,   /* Display Off */
    DISPON = 0x29,    /* Display On */
    CASET = 0x2a,     /* Column Address Set */
    RASET = 0x2b,     /* Row Address Set */
    RAMWR = 0x2c,     /* Memory Write */
    RGBSET = 0x2d,    /* Color Setting 4k, 65k, 262k */
    RAMRD = 0x2e,     /* Memory Read */
    PTLAR = 0x30,     /* Partial Area */
    SCRLAR = 0x33,    /* Scroll Area Set */
    TEOFF = 0x34,     /* Tearing Effect Line OFF */
    TEON = 0x35,      /* Tearing Effect Line ON */
    MADCTL = 0x36,    /* Memory Data Access Control */
    VSCSAD = 0x37,    /* Vertical Scroll Start Address of RAM */
    IDMOFF = 0x38,    /* Idle Mode Off */
    IDMON = 0x39,     /* Idle Mode On */
    COLMOD = 0x3a,    /* Interface Pixel Format */
    RDID1 = 0xda,     /* Read ID1 Value */
    RDID2 = 0xdb,     /* Read ID2 Value */
    RDID3 = 0xdc,     /* Read ID3 Value */
    FRMCTR1 = 0xb1,   /* Frame Rate Control in normal mode, full colors */
    FRMCTR2 = 0xb2,   /* Frame Rate Control in idle mode, 8 colors */
    FRMCTR3 = 0xb3,   /* Frame Rate Control in partial mode, full colors */
    INVCTR = 0xb4,    /* Display Inversion Control */
    PWCTR1 = 0xc0,    /* Power Control 1 */
    PWCTR2 = 0xc1,    /* Power Control 2 */
    PWCTR3 = 0xc2,    /* Power Control 3 in normal mode, full colors */
    PWCTR4 = 0xc3,    /* Power Control 4 in idle mode 8colors */
    PWCTR5 = 0xc4,    /* Power Control 5 in partial mode, full colors */
    VMCTR1 = 0xc5,    /* VCOM Control 1 */
    VMOFCTR = 0xc7,   /* VCOM Offset Control */
    WRID2 = 0xd1,     /* Write ID2 Value */
    WRID3 = 0xd2,     /* Write ID3 Value */
    NVFCTR1 = 0xd9,   /* NVM Control Status */
    NVFCTR2 = 0xde,   /* NVM Read Command */
    NVFCTR3 = 0xdf,   /* NVM Write Command */
    GMCTRP1 = 0xe0,   /* Gamma '+'Polarity Correction Characteristics Setting */
    GMCTRN1 = 0xe1,   /* Gamma '-'Polarity Correction Characteristics Setting */
    GCV = 0xfc,       /* Gate Pump Clock Frequency Variable */
} ST7735S_Command;

// ---------------------------------------------------------------------
// Local Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_mode_cmd();

/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_mode_data();

/*!
    \brief      set command
    \param[in]  command: ST7735S command
    \param[out] none
    \retval     none
*/
void lcd_reg(ST7735S_Command command);

/*!
    \brief      set unsigned byte data
    \param[in]  data: data
    \param[out] none
    \retval     none
*/
void lcd_u8c(uint8_t data);

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
    // Initialization settings. Based on lcd.c in gd32v_lcd example.
    static const uint8_t init_sequence[] =
        {
            0x21, 0xff,
            0xb1, 0x05, 0x3a, 0x3a, 0xff,
            0xb2, 0x05, 0x3a, 0x3a, 0xff,
            0xb3, 0x05, 0x3a, 0x3a, 0x05, 0x3a, 0x3a, 0xff,
            0xb4, 0x03, 0xff,
            0xc0, 0x62, 0x02, 0x04, 0xff,
            0xc1, 0xc0, 0xff,
            0xc2, 0x0d, 0x00, 0xff,
            0xc3, 0x8d, 0x6a, 0xff,
            0xc4, 0x8d, 0xee, 0xff,
            0xc5, 0x0e, 0xff,
            0xe0, 0x10, 0x0e, 0x02, 0x03, 0x0e, 0x07, 0x02, 0x07, 0x0a, 0x12, 0x27, 0x37, 0x00, 0x0d, 0x0e, 0x10, 0xff,
            0xe1, 0x10, 0x0e, 0x03, 0x03, 0x0f, 0x06, 0x02, 0x08, 0x0a, 0x13, 0x26, 0x36, 0x00, 0x0d, 0x0e, 0x10, 0xff,
            0x3a, 0x55, 0xff,
            0x36, 0x78, 0xff,
            0x29, 0xff,
            0x11, 0xff,
            0xff};

    // Initialize the display.
    for (const uint8_t *p = init_sequence; *p != 0xff; p++)
    {
        lcd_reg(*p++);
        if (*p == 0xff)
        {
            continue;
        }
        spi_wait_idle();
        lcd_mode_data();
        while (*p != 0xff)
        {
            lcd_u8c(*p++);
        }
    }
}

/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_mode_cmd()
{
    gpio_bit_reset(GPIOB, GPIO_PIN_0);
}

/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_mode_data()
{
    gpio_bit_set(GPIOB, GPIO_PIN_0);
}

/*!
    \brief      set command
    \param[in]  command: ST7735S command
    \param[out] none
    \retval     none
*/
void lcd_reg(ST7735S_Command command)
{
    spi_wait_idle();
    spi_set_8bit();
    lcd_mode_cmd();
    spi_i2s_data_transmit(SPI0, command);
}

/*!
    \brief      set unsigned byte data
    \param[in]  data: data
    \param[out] none
    \retval     none
*/
void lcd_u8c(uint8_t data)
{
    spi_wait_tbe();
    spi_i2s_data_transmit(SPI0, data);
}
