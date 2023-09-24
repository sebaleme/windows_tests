/* *****************************************************************************
##
# @file        map_rendering_bev.hpp
# @brief       read the map and display it on the screen
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_MAP_RENDERING_BEV_HPP
#define FSP_MAP_RENDERING_BEV_HPP

#include "types.hpp"

void construct_map(uint32_t* pixels, uint8_t* map);
int32_t computeCellIndex(int32_t cell_row, int32_t cell_column);

#endif /* FSP_MAP_RENDERING_BEV_HPP */