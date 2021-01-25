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
    // TFT_SCL = GPIO_PIN_5 (AF=>Alternate Function: SPI0_SCK); TFT_SDA = GPIO_PIN_7 (AF=>Alternate Function: SPI0_MOSI)
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5 | GPIO_PIN_7);
    // TFT_RS = GPIO_PIN_0 (RS); TFT_RST = GPIO_PIN_1 (RST=Reset); TFT_CS = GPIO_PIN_2 (CS=Chip Selection)
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);

    // TFT_RS=0 & TFT_RST=0
    gpio_bit_reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1); // DC=0, RST=0
    // TFT_CS = 1 => Disable TFT
    gpio_bit_set(GPIOB, GPIO_PIN_2); // Disable lcd cs
    time_delay_1ms(1);
    // TFT_RST = 1 => Reset TFT
    gpio_bit_set(GPIOB, GPIO_PIN_1); // RST=1
    time_delay_1ms(5);
    // Deinit SPI and DMA.
    spi_i2s_deinit(SPI0);
    dma_deinit(DMA0, DMA_CH1);
    dma_deinit(DMA0, DMA_CH2);
    // Configure DMA, do not enable.
    DMA_CHCTL(DMA0, DMA_CH1) = (uint32_t)(DMA_PRIORITY_ULTRA_HIGH | DMA_CHXCTL_MNAGA); // Receive.
    DMA_CHCTL(DMA0, DMA_CH2) = (uint32_t)(DMA_PRIORITY_ULTRA_HIGH | DMA_CHXCTL_DIR);   // Transmit.
    DMA_CHPADDR(DMA0, DMA_CH1) = (uint32_t)&SPI_DATA(SPI0);
    DMA_CHPADDR(DMA0, DMA_CH2) = (uint32_t)&SPI_DATA(SPI0);
    // Configure and enable SPI.
    SPI_CTL0(SPI0) = (uint32_t)(SPI_MASTER | SPI_TRANSMODE_FULLDUPLEX | SPI_FRAMESIZE_8BIT | SPI_NSS_SOFT | SPI_ENDIAN_MSB | SPI_CK_PL_LOW_PH_1EDGE | SPI_PSC_8);
    SPI_CTL1(SPI0) = (uint32_t)(SPI_CTL1_DMATEN);
    spi_enable(SPI0);
    // TFT_CS = 0 => Enable TFT
    gpio_bit_reset(GPIOB, GPIO_PIN_2);
}