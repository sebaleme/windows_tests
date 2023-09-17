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

void update_player_position(uint32_t* pixels, position player, uint8_t* map)
{
    // Ignore position requests if outside of screen
    int32_t pos_x = std::clamp(static_cast<int32_t>(player.x), 0, SCREEN_WIDTH);
    int32_t pos_y = std::clamp(static_cast<int32_t>(player.y), 0, SCREEN_HEIGHT);
    // Printing a main square
    for(int width{0}; width < CURSOR_SIZE; width++)
    {
        for(int height{0}; height < CURSOR_SIZE; height++)
        {
            pixels[(pos_y + height) * SCREEN_WIDTH + pos_x + width] = BLUE_DARK;
        }
    }
    // Printing right FOV limit
    for(int fov_right{0}; fov_right < CURSOR_SIZE*2; fov_right++)
    {
        pixels[(pos_y + CURSOR_SIZE + fov_right) * SCREEN_WIDTH + pos_x + CURSOR_SIZE + fov_right] = BLUE_DARK;
    }
    // Printing left FOV limit
    for(int fov_right{0}; fov_right < CURSOR_SIZE*2; fov_right++)
    {
        pixels[(pos_y + CURSOR_SIZE + fov_right) * SCREEN_WIDTH + pos_x - fov_right] = BLUE_DARK;
    }
}