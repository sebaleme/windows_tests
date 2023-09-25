/* *****************************************************************************
##
# @file        map.hpp
# @brief       level map definition and access functions
# @copyright   MIT license
# ****************************************************************************/

#ifndef FSP_MAP_HPP
#define FSP_MAP_HPP

#include <SDL3/SDL.h>

// Map size
static constexpr int8_t MAP_WIDTH{8};
static constexpr int8_t MAP_HEIGHT{8};

// 0 means empty, else an object
// each value is represented through a color
static const uint8_t g_map[MAP_WIDTH*MAP_HEIGHT]=
{
    1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,2,0,0,1,
    1,0,0,0,2,2,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,2,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};

int32_t computeCellIndex(int32_t cell_row, int32_t cell_column);

#endif /* FSP_MAP_RENDERING_BEV_HPP */