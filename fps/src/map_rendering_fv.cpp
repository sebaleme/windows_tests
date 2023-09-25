/* *****************************************************************************
##
# @file        map_rendering_fv.cpp
# @brief       rendering of the environment in isometric projection
# @copyright   MIT license
# ****************************************************************************/
#include "map_rendering_fv.hpp"
#include "types.hpp"
#include <math.h>
#include <algorithm>

void construct_world(uint32_t* pixels, uint8_t* map)
{
    // Processing screen from top left to bottom right
    for(int pixel_row{0}; pixel_row<SCREEN_WIDTH; pixel_row++)
    {
        // Compute column content
        for(int pixel_col{0}; pixel_col<SCREEN_HEIGHT; pixel_col++)
        {

        }
    }
}