/* *****************************************************************************
##
# @file        ray_casting.cpp
# @brief       rendering of the 3D scene
# @copyright   MIT license
# ****************************************************************************/
#include "ray_casting.hpp"
#include "types.hpp"
#include "math.h"

void prepare_pixels(uint32_t* pixels, position player, uint8_t* map)
{
    // Printing a single pixel in purple
    pixels[10 * SCREEN_WIDTH + 5] = 0xFFFF00FF;

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
            if(pixel_col < last_pixel_ceiling )
            {
                pixels[pixel_col*SCREEN_WIDTH + pixel_row] = 0x0F;
            }
            if(pixel_col > first_pixel_ground )
            {
                pixels[pixel_col*SCREEN_WIDTH + pixel_row] = 0xFFFF00FF;
            }
            else // ground
            {
                pixels[pixel_col*SCREEN_WIDTH + pixel_row] = 0x00FF00FF;
            }

        }
    }
}