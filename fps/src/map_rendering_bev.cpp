/* *****************************************************************************
##
# @file        map_rendering_bev.cpp
# @brief       rendering of map, BEV
# @copyright   MIT license
# ****************************************************************************/
#include "map_rendering_bev.hpp"
#include "colors.hpp"
#include "types.hpp"


void construct_map(uint32_t* pixels)
{
    // Processing screen from top left to bottom right
    for(int pixel_row{0}; pixel_row<SCREEN_WIDTH; pixel_row++)
    {
        // Compute column content
        for(int pixel_col{0}; pixel_col<SCREEN_HEIGHT; pixel_col++)
        {
            // Computing cell coordinate
            int32_t cell_x = pixel_row/CELL_SIZE_PIXELS;
            int32_t cell_y = pixel_col/CELL_SIZE_PIXELS;
            // Adjacent cells don t have same color (check pattern)
            bool color_modifyer = false;
            if((pixel_col % (2*CELL_SIZE_PIXELS) < CELL_SIZE_PIXELS) && (pixel_row % (2*CELL_SIZE_PIXELS) < CELL_SIZE_PIXELS) ||
            (pixel_col % (2*CELL_SIZE_PIXELS) > CELL_SIZE_PIXELS) && (pixel_row % (2*CELL_SIZE_PIXELS) > CELL_SIZE_PIXELS))
            {
                color_modifyer = true;
            }
            // The pixels array starts from bottom left, whereas the map definition starts from
            // top left
            int32_t index = computeCellIndex(cell_x,cell_y);
            pixels[pixel_row*SCREEN_WIDTH + pixel_col] = getCellColor(index,color_modifyer);
        }
    }
}