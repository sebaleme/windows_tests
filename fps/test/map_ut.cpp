/* *****************************************************************************
##
# @file        map.cpp
# @brief       tests for map access functions
# @copyright   MIT license
# ****************************************************************************/

#include "map.hpp"

#include <gtest/gtest.h>

// Check that the map access is working, considering that the cell coordinates
// are given in the classical coordonate system, (0,0) is bottom left
static uint8_t g_map_test[MAP_WIDTH*MAP_HEIGHT];

void fillMap()
{
  for(int32_t i{0}; i< MAP_WIDTH*MAP_HEIGHT; i++)
  {
    g_map_test[i] = i;
  }
}

// Check the origin cell (positionBottomLeft)
TEST(computeCellIndex, cellIndex_test1) {
  // cell_row is going up, and cell_column is increasing to the right
  int32_t cell_row{0}, cell_column{0};
  fillMap();
  int32_t cellIndex = computeCellIndex(cell_row, cell_column);
  EXPECT_EQ(g_map_test[cellIndex], MAP_WIDTH*(MAP_HEIGHT-1));
}

// Check the cell (1,1), the first which is not a wall (initialPlayerPosition)
TEST(computeCellIndex, cellIndex_test2) {
  int32_t cell_row{1}, cell_column{1};
  fillMap();
  int32_t cellIndex = computeCellIndex(cell_row, cell_column);
  EXPECT_EQ(g_map_test[cellIndex], MAP_WIDTH*(MAP_HEIGHT-2)+1);
}

// Check the cell (0,MAP_WIDTH-1), the bottom right corner
TEST(computeCellIndex, cellIndex_test3) {
  int32_t cell_row{0}, cell_column{MAP_WIDTH-1};
  fillMap();
  int32_t cellIndex = computeCellIndex(cell_row, cell_column);
  EXPECT_EQ(g_map_test[cellIndex], MAP_WIDTH*MAP_HEIGHT-1);
}

// Check the cell (MAP_HEIGHT-1,0), the top left corner
TEST(computeCellIndex, cellIndex_test4) {
  int32_t cell_row{MAP_HEIGHT-1}, cell_column{0};
  fillMap();
  int32_t cellIndex = computeCellIndex(cell_row, cell_column);
  EXPECT_EQ(g_map_test[cellIndex], 0);
}

// Check the cell (3,5), a random cell
TEST(computeCellIndex, cellIndex_test5) {
  int32_t cell_row{3}, cell_column{5};
  fillMap();
  int32_t cellIndex = computeCellIndex(cell_row, cell_column);
  EXPECT_EQ(g_map_test[cellIndex], MAP_WIDTH*4+cell_column);
}