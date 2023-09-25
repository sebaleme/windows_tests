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

void construct_world(uint32_t* pixels, uint8_t* map, const StatePlayer& f_player)
{
    // Processing screen from top left to bottom right
    for(int pixel_row{0}; pixel_row<SCREEN_WIDTH; pixel_row++)
    {
        // Ray angle
        float_t angleRad = degToRad(f_player.orientation + (SCREEN_WIDTH/2 - pixel_row) *HORIZONTAL_RES);
        // Distance to obstacle
        float_t distance{0.F};
        // Current cell information
        int32_t cell_col = static_cast<int32_t>(f_player.x) / CELL_SIZE;
	    int32_t cell_row = static_cast<int32_t>(f_player.y) / CELL_SIZE;

        // Differentiate if we are looking up, down, left and right
        if((angleRad > 0.F) || (angleRad < SDL_PI_F))
        {
            float_t verticalDistance = (cell_row + 1)*CELL_SIZE - f_player.x;
            distance = verticalDistance/sinf(angleRad);
        }
    }
}