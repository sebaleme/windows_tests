/* *****************************************************************************
##
# @file        ray_casting.hpp
# @brief       Ray casting class
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_RAY_CASTING_HPP
#define FSP_RAY_CASTING_HPP

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

void update_player_position(uint32_t* pixels, position player, uint8_t* map);


#endif /* FSP_RAY_CASTING_HPP */