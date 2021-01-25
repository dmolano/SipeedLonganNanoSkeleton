/* 
 * This file is part of the Sipeed Longan Nano Skeleton. Serial peripheral interface (SPI).
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

#include "spi.h"

// ---------------------------------------------------------------------
// Local Prototypes
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Bodies
// ---------------------------------------------------------------------
/*!
    \brief      set 8 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_set_8bit()
{
    if (SPI_CTL0(SPI0) & (uint32_t)(SPI_CTL0_FF16))
    {
        SPI_CTL0(SPI0) &= ~(uint32_t)(SPI_CTL0_SPIEN);
        // ---------------v
        SPI_CTL0(SPI0) &= ~(uint32_t)(SPI_CTL0_FF16);
        SPI_CTL0(SPI0) |= (uint32_t)(SPI_CTL0_SPIEN);
    }
}

/*!
    \brief      set 8 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_wait_idle()
{
    while (SPI_STAT(SPI0) & SPI_STAT_TRANS)
        ;
}

/*!
    \brief      set 8 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_wait_tbe()
{
    while (!(SPI_STAT(SPI0) & SPI_STAT_TBE))
        ;
}
