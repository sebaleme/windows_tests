/* *****************************************************************************
##
# @file        ray_casting.cpp
# @brief       rendering of the 3D scene
# @copyright   MIT license
# ****************************************************************************/
#include "ray_casting.hpp"
#include "types.hpp"
#include <math.h>
#include <algorithm>

void prepare_pixels(uint32_t* pixels, position player, uint8_t* map)
{
    // Processing screen from top left to bottom right
    for(int pixel_row{0}; pixel_row<SCREEN_WIDTH; pixel_row++)
    {
        // Compute column content
        float_t distance_object = 3.F;
        float_t angle_lowest_ceiling = atan2(HEIGHT_CEILING - HEIGHT_OBSERVER, distance_object);
        int last_pixel_ceiling = (VERTICAL_FOV/2 - angle_lowest_ceiling)*VERTICAL_RES;
        float_t angle_highest_ground = atan2(HEIGHT_OBSERVER, distance_object);
        int first_pixel_ground = (VERTICAL_FOV/2 - angle_highest_ground)*VERTICAL_RES + SCREEN_HEIGHT/2;
        for(int pixel_col{0}; pixel_col<SCREEN_HEIGHT; pixel_col++)
        {
            if(pixel_col < 200 )
            {
                pixels[pixel_col*SCREEN_WIDTH + pixel_row] = 0x0; // Black
            }
            else if(pixel_col > 400 )
            {
                pixels[pixel_col*SCREEN_WIDTH + pixel_row] = 0xFF000022; // blue
            }
            else // ground
            {
                pixels[pixel_col*SCREEN_WIDTH + pixel_row] = 0x00FF00FF; // purple
            }

        }
    }
    // Printing a single pixel in purple
    int32_t pos_x = std::clamp(static_cast<int32_t>(player.x), 0, SCREEN_WIDTH);
    int32_t pos_y = std::clamp(static_cast<int32_t>(player.y), 0, SCREEN_HEIGHT);
    pixels[pos_y * SCREEN_WIDTH + pos_x] = 0xFFFF0022;
    pixels[(pos_y+1) * SCREEN_WIDTH + pos_x] = 0xFFFF0022;
    pixels[pos_y * SCREEN_WIDTH + (pos_x+1)] = 0xFFFF0022;
    pixels[(pos_y+1) * SCREEN_WIDTH + (pos_x+1)] = 0xFFFF0022;
}