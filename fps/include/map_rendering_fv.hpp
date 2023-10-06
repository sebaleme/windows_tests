/* *****************************************************************************
##
# @file        map_rendering_fv.hpp
# @brief       function declaration for the 3D map rendering
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_MAP_RENDERING_FV_HPP
#define FSP_MAP_RENDERING_FV_HPP

#include "types.hpp"

float_t getAngleCurrentColumn_regularAngle(float_t orientation, int32_t columnIndex);
float_t getAngleCurrentColumn_regularDistance(float_t orientation, int32_t columnIndex);
void construct_world(uint32_t* pixels, const StatePlayer& f_player);

#endif /* FSP_MAP_RENDERING_FV_HPP */