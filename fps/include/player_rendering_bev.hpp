/* *****************************************************************************
##
# @file        player_rendering_bev.hpp
# @brief       function declaration for the player rendering on 2D map
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_PLAYER_RENDERING_BEV_HPP
#define FSP_PLAYER_RENDERING_BEV_HPP

#include "types.hpp"

// Each direction is 45° wide
enum class EOrientation
{
    North = 0,
    North_Est,
    Est,
    South_Est,
    South,
    South_West,
    West,
    North_West,
    invalid
};

void update_player_position(uint32_t* pixels, StatePlayer player);


#endif /* FSP_PLAYER_RENDERING_BEV_HPP */