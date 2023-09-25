/* *****************************************************************************
##
# @file        map.cpp
# @brief       map access functions
# @copyright   MIT license
# ****************************************************************************/
#include "map.hpp"

int32_t computeCellIndex(int32_t cell_row, int32_t cell_column)
{
    return (MAP_HEIGHT - 1 - cell_row)*MAP_WIDTH + cell_column;
}
