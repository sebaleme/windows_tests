/* *****************************************************************************
##
# @file        state_player.hpp
# @brief       Description of the player state, like position and orientation
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_STATE_PLAYER_HPP
#define FSP_STATE_PLAYER_HPP

#include <SDL3/SDL.h>

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

// X is horizontal, Y is vertical
// (0,0) is bottom left
struct StatePlayer
{
	float_t x; 			 // metres
	float_t y;			 // metres
	float_t direction;   // degrees
	float_t radius;   	 // metres
	float_t orientation; // degrees
};

EOrientation computeGeneralDirection(const StatePlayer& player);

#endif /* FSP_STATE_PLAYER_HPP */