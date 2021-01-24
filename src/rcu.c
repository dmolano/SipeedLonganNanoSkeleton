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
    \brief      rcu_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void rcu_init(rcu_periph_enum *rcu_periph)
{
    if (rcu_periph != NULL)
    {
        rcu_periph_enum last_rcu;

        do
        {
            last_rcu = *rcu_periph;
            rcu_periph_clock_enable(*rcu_periph);
            rcu_periph++;
        } while (*rcu_periph != last_rcu);
    }
}