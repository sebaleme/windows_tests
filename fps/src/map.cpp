/* *****************************************************************************
##
# @file        map.cpp
# @brief       map access functions
# @copyright   MIT license
# ****************************************************************************/
#include "map.hpp"
#include <cassert>
#include "types.hpp"

// The pixels array starts from bottom left, whereas the map definition starts from top left
int32_t computeCellIndex(int32_t cell_row, int32_t cell_column)
{
    assert(cell_row < MAP_HEIGHT && "input from computeCellIndex out of range");
    assert(cell_column < MAP_WIDTH && "input from computeCellIndex out of range");
    return (MAP_HEIGHT - 1 - cell_row)*MAP_WIDTH + cell_column;
}

int pixel_index(int pos_x, int pos_y)
{
    return pos_y * SCREEN_WIDTH + pos_x;
}
