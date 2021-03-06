/* 
 * This file is part of the Sipeed Longan Nano Skeleton. Reset and clock unit (RCU).
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

#include "rcu.h"

// ---------------------------------------------------------------------
// Local Prototypes
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Bodies
// ---------------------------------------------------------------------
/*!
    \brief      RCUs initialization function.
    \param[in]  Pointer to a non-repeating list of rcu_periph_enum.
                The list will end when two contiguous items are repeated.
    \param[out] none
    \retval     none
*/
void slns_rcu_init(rcu_periph_enum *rcu_periph)
{
    if (rcu_periph != NULL)
    {
        rcu_periph_enum sentinel_node;

        do
        {
            sentinel_node = *rcu_periph;
            rcu_periph_clock_enable(*rcu_periph);
            rcu_periph++;
        } while (*rcu_periph != sentinel_node);
    }
}