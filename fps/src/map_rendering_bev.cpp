/* *****************************************************************************
##
# @file        map_rendering_bev.cpp
# @brief       rendering of map, BEV
# @copyright   MIT license
# ****************************************************************************/
#include "map_rendering_bev.hpp"
#include "types.hpp"

int32_t getColor(uint8_t* map, int32_t index ,bool f_color_modifyer)
{
    int32_t color{colors_dark[map[index]]};
    if(f_color_modifyer)
    {
        color = colors_light[map[index]];
    }

    return color;
}

int32_t computeCellIndex(int32_t cell_row, int32_t cell_column)
{
    return (MAP_HEIGHT - 1 - cell_row)*MAP_WIDTH + cell_column;
}


void construct_map(uint32_t* pixels, uint8_t* map)
{
    // Processing screen from top left to bottom right
    for(int pixel_row{0}; pixel_row<SCREEN_WIDTH; pixel_row++)
    {
        // Compute column content
        for(int pixel_col{0}; pixel_col<SCREEN_HEIGHT; pixel_col++)
        {
            // Computing cell coordinate
            int32_t cell_x = pixel_row/CELL_SIZE;
            int32_t cell_y = pixel_col/CELL_SIZE;
            // Adjacent cells don t have same color (check pattern)
            bool color_modifyer = false;
            if((pixel_col % (2*CELL_SIZE) < CELL_SIZE) && (pixel_row % (2*CELL_SIZE) < CELL_SIZE) ||
            (pixel_col % (2*CELL_SIZE) > CELL_SIZE) && (pixel_row % (2*CELL_SIZE) > CELL_SIZE))
            {
                color_modifyer = true;
            }
            // The pixels array starts from bottom left, whereas the map definition starts from
            // top left
            int32_t index = computeCellIndex(cell_x,cell_y);
            pixels[pixel_row*SCREEN_WIDTH + pixel_col] = getColor(map,index,color_modifyer);
        }
    }
}