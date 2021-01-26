/* 
 * This file is part of the Sipeed Longan Nano Skeleton. 
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

#ifndef __GD32VF103_SLNS_DMA_H
#define __GD32VF103_SLNS_DMA_H

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      wait recive
    \param[in]  none
     \param[out] none
    \retval     none
*/
void dma_wait_recv();

/*!
    \brief      send unsigned byte to DMA peripheral
    \param[in]  dma_const_data_value: data
    \param[in]  count: count
    \param[out] none
    \retval     none
*/
void dma_send_const_u8(uint32_t dma_const_data_value_address, uint32_t count);

/*!
    \brief      send unsigned half word to DMA peripheral
    \param[in]  dma_const_data_value_address: data
    \param[in]  count: count
    \param[out] none
    \retval     none
*/
void dma_send_const_u16(uint32_t dma_const_data_value_address, uint32_t count);

#endif