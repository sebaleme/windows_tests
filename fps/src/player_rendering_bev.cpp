/* *****************************************************************************
##
# @file        player_rendering_bev.cpp
# @brief       rendering of the player position on the 2D map
# @copyright   MIT license
# ****************************************************************************/
#include "player_rendering_bev.hpp"

#include "map.hpp"
#include "state_player.hpp"
#include "types.hpp"
#include <math.h>
#include <algorithm>


bool main_square_tilted(EOrientation quadrant)
{
    bool result{false};
    if( (quadrant == EOrientation::North_Est) ||
        (quadrant == EOrientation::North_West) ||
        (quadrant == EOrientation::South_Est) ||
        (quadrant == EOrientation::South_West)
    )
    {
        result = true;
    }
    return result;
}

// The player display has 8 possible positions
void player_rendering_bev(uint32_t* pixels, const StatePlayer player)
{
    // Ignore position requests if outside of screen
    int32_t pos_x = static_cast<int32_t>(player.x);
    int32_t pos_y = static_cast<int32_t>(player.y);

    // Player orientation
    EOrientation quadrant = computeGeneralDirection(player);

    // Printing the player position as a main square
    if(main_square_tilted(quadrant))
    {
        for(int height{0}; height < CURSOR_SIZE/2; height++)
        {
            int minWidth{CURSOR_SIZE/2-height};
            int maxWidth{CURSOR_SIZE/2+1+height};
            for(int width{minWidth}; width < maxWidth; width++)
            {
                pixels[pixel_index(pos_x + width, pos_y + height)] = BLUE_DARK;
            }
        }
        for(int height{CURSOR_SIZE/2}; height < CURSOR_SIZE+1; height++)
        {
            int minWidth{height-CURSOR_SIZE/2};
            int maxWidth{3*CURSOR_SIZE/2+1-height};
            for(int width{minWidth}; width < maxWidth; width++)
            {
                pixels[pixel_index(pos_x + width, pos_y + height)] = BLUE_DARK;
            }
        }
    }
    else // print regular square
    {
        for(int width{0}; width < CURSOR_SIZE; width++)
        {
            for(int height{0}; height < CURSOR_SIZE; height++)
            {
                pixels[pixel_index(pos_x + width, pos_y + height)] = BLUE_DARK;
            }
        }
    }

    if(quadrant == EOrientation::North)
    {
        for(int fov{0}; fov < CURSOR_SIZE*2; fov++)
        {
            // Printing right FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE + fov, pos_y + CURSOR_SIZE + fov)] = BLUE_DARK;
            // Printing left FOV limit
            pixels[pixel_index(pos_x - fov,pos_y + CURSOR_SIZE + fov)] = BLUE_DARK;
        }
    }
    else if(quadrant == EOrientation::South)
    {
        for(int fov{0}; fov < CURSOR_SIZE*2; fov++)
        {
            // Printing right FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE + fov, pos_y - fov)] = BLUE_DARK;
            // Printing left FOV limit
            pixels[pixel_index(pos_x - fov, pos_y - fov)] = BLUE_DARK;
        }
    }
    else if(quadrant == EOrientation::Est)
    {
        for(int fov{0}; fov < CURSOR_SIZE*2; fov++)
        {
            // Printing left FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE + fov, pos_y + CURSOR_SIZE + fov)] = BLUE_DARK;
            // Printing right FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE + fov, pos_y - fov)] = BLUE_DARK;
        }
    }
    else if(quadrant == EOrientation::West)
    {
        for(int fov{0}; fov < CURSOR_SIZE*2; fov++)
        {
            // Printing right FOV limit
            pixels[pixel_index(pos_x - fov, pos_y + CURSOR_SIZE + fov)] = BLUE_DARK;
            // Printing left FOV limit
            pixels[pixel_index(pos_x - fov, pos_y - fov)] = BLUE_DARK;
        }
    }
    else if(quadrant == EOrientation::North_Est)
    {
        for(int fov{0}; fov < CURSOR_SIZE*2; fov++)
        {
            // Printing left FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE/2, pos_y + CURSOR_SIZE + fov)] = BLUE_DARK;
            // Printing right FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE + fov, pos_y + CURSOR_SIZE/2)] = BLUE_DARK;
        }
    }
    else if(quadrant == EOrientation::North_West)
    {
        for(int fov{0}; fov < CURSOR_SIZE*2; fov++)
        {
            // Printing left FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE/2, pos_y + CURSOR_SIZE + fov)] = BLUE_DARK;
            // Printing right FOV limit
            pixels[pixel_index(pos_x - fov, pos_y + CURSOR_SIZE/2)] = BLUE_DARK;
        }
    }
    else if(quadrant == EOrientation::South_Est)
    {
        for(int fov{0}; fov < CURSOR_SIZE*2; fov++)
        {
            // Printing left FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE + fov, pos_y + CURSOR_SIZE/2)] = BLUE_DARK;
            // Printing right FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE/2, pos_y - fov)] = BLUE_DARK;
        }
    }
    else if(quadrant == EOrientation::South_West)
    {
        for(int fov{0}; fov < CURSOR_SIZE*2; fov++)
        {
            // Printing left FOV limit
            pixels[pixel_index(pos_x - fov, pos_y + CURSOR_SIZE/2)] = BLUE_DARK;
            // Printing right FOV limit
            pixels[pixel_index(pos_x + CURSOR_SIZE/2, pos_y - fov)] = BLUE_DARK;
        }
    }
}