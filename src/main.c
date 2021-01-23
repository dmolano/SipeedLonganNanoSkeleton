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

#include "main.h"

// ---------------------------------------------------------------------
// Prototypes
// ---------------------------------------------------------------------

/*!
    \brief      init function
    \param[in]  sipeed_longan_nano Sipeed Longan Nano data
    \param[out] none
    \retval     system error
*/
int main_init(sipeed_longan_nano_ptr sln_data_ptr);

/*!
    \brief      loop function
    \param[in]  sipeed_longan_nano Sipeed Longan Nano data
    \param[out] none
    \retval     system error
*/
int main_loop(sipeed_longan_nano_ptr sln_data_ptr);

// ---------------------------------------------------------------------
// Bodies
// ---------------------------------------------------------------------
/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    sipeed_longan_nano sln_data;
    int result;

    result = main_init(&sln_data);
    if (result == NO_ERROR_INIT_SLN)
    {
        result = main_loop(&sln_data);
    }
    return result;
}

/*!
    \brief      init function
    \param[in]  sipeed_longan_nano Sipeed Longan Nano data
    \param[out] none
    \retval     system error
*/
int main_init(sipeed_longan_nano_ptr sln_data_ptr)
{
    int result = NO_ERROR_INIT_SLN;

    return result;
}

/*!
    \brief      loop function
    \param[in]  sipeed_longan_nano Sipeed Longan Nano data
    \param[out] none
    \retval     system error
*/
int main_loop(sipeed_longan_nano_ptr sln_data_ptr)
{
    int result = NO_ERROR_INIT_SLN;

    while (FOREVER)
    {
        time_delay_1ms(ONE_SECOND_TIME);
    }
    return result;
}
