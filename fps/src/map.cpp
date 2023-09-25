/* *****************************************************************************
##
# @file        map.cpp
# @brief       map access functions
# @copyright   MIT license
# ****************************************************************************/
#include "map.hpp"

#include "types.hpp"

int32_t computeCellIndex(int32_t cell_row, int32_t cell_column)
{
    return (MAP_HEIGHT - 1 - cell_row)*MAP_WIDTH + cell_column;
}

int pixel_index(int pos_x, int pos_y)
{
    return pos_y * SCREEN_WIDTH + pos_x;
}
