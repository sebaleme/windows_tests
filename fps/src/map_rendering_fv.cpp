/* *****************************************************************************
##
# @file        map_rendering_fv.cpp
# @brief       rendering of the environment in isometric projection
# @copyright   MIT license
# ****************************************************************************/
#include "map_rendering_fv.hpp"
#include "types.hpp"
#include <iostream>
#include <algorithm>

float_t getAngleCurrentColumn(float orientation, int32_t columnIndex)
{
    return orientation + (SCREEN_WIDTH / 2 - columnIndex) * HORIZONTAL_RES;
}


void construct_world(uint32_t* pixels, const StatePlayer& f_player)
{
    // Processing screen from left to right
    for(int32_t pixel_col{0}; pixel_col<SCREEN_WIDTH; pixel_col++)
    {
        // Ray angle and its trigonometric values
        float_t angleDeg = getAngleCurrentColumn(f_player.orientation, pixel_col);
        float_t angleRad = degToRad(angleDeg);
        float_t cosfAngle = cosf(angleRad);
        float_t sinfAngle = sinf(angleRad);

        // Distance to obstacle
        float_t distanceToObstacle{0.F};

        // Current cell information
        int32_t cell_col = static_cast<int32_t>(f_player.x) / CELL_SIZE_PIXELS;
	    int32_t cell_row = static_cast<int32_t>(f_player.y) / CELL_SIZE_PIXELS;
        int32_t cellIndex = computeCellIndex(cell_row ,cell_col);

        // Intersection point
        float_t intersecX = f_player.x;
        float_t intersecY = f_player.y;
        bool intersectionSide = false;

        // Differentiate if we are looking north, south, east or west
        if((angleRad > (0)) || (angleRad < SDL_PI_F /2.F))
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0U)
            {
                // Distance to the east cell (cell_col + 1)
                float_t xDistance = intersecX - cell_col*CELL_SIZE_PIXELS;
                float_t distanceEastCell = xDistance / cosfAngle;
                // Distance to the north cell (cell_row + 1)
                float_t yDistance = intersecY - cell_row*CELL_SIZE_PIXELS;
                float_t distanceNorthCell = yDistance / sinfAngle;
                // Check which cell comes next
                if(distanceEastCell > distanceNorthCell)
                {
                    // Case north cell is the next
                    ++cell_row;
                    intersecX = cosfAngle*distanceNorthCell;
                    intersecY = yDistance;
                    intersectionSide = true;
                }
                else
                {
                    // Case west cell is the next
                    ++cell_col;
                    intersecX = xDistance;
                    intersecY = sinfAngle*distanceEastCell;
                    intersectionSide = false;
                }
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
            distanceToObstacle = intersecX / cosfAngle;

            // Fill pixel column
            int32_t limitCeilingObstacle = static_cast<int32_t>(distanceToObstacle);
            int32_t limitObstacleGround = SCREEN_HEIGHT - static_cast<int32_t>(distanceToObstacle);

            // Ceiling
            for(int32_t pixel_row{0}; pixel_row<limitCeilingObstacle; pixel_row++)
            {
                pixels[pixel_row*SCREEN_WIDTH + pixel_col] = SKY_BLUE;
            }
            // Obstacle
            for(int32_t pixel_row{limitCeilingObstacle}; pixel_row< limitObstacleGround; pixel_row++)
            {
                pixels[pixel_row*SCREEN_WIDTH + pixel_col] = getCellColor(cellIndex,intersectionSide);
            }
            // Ground
            for(int32_t pixel_row{limitObstacleGround}; pixel_row< SCREEN_HEIGHT; pixel_row++)
            {
                pixels[pixel_row*SCREEN_WIDTH + pixel_col] = YELLOW_LIGHT;
            }
        }
        else if((angleRad > (SDL_PI_F / 2.F)) || (angleRad < SDL_PI_F))
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                // Distance to the west cell (cell_col - 1)
                float_t xDistance = intersecX - cell_col*CELL_SIZE_PIXELS;
                float_t distanceWestCell = xDistance / cosfAngle;
                // Distance to the north cell (cell_row + 1)
                float_t yDistance = intersecY - cell_row*CELL_SIZE_PIXELS;
                float_t distanceNorthCell = yDistance / sinfAngle;
                // Check which cell comes next
                if(distanceWestCell > distanceNorthCell)
                {
                    // Case north cell is the next
                    ++cell_row;
                    intersecX = cosfAngle*distanceNorthCell;
                    intersecY = yDistance;
                }
                else
                {
                    // Case west cell is the next
                    cell_col--;
                    intersecX = xDistance;
                    intersecY = sinfAngle*distanceWestCell;
                }
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
        }
        else if(angleRad == (SDL_PI_F / 2.F) || angleRad == -(SDL_PI_F / 2.F))
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                cell_row = (angleRad == SDL_PI_F / 2.F) ? cell_row + 1 : cell_row - 1;
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
        }
        else if(angleRad == 0.F || angleRad == SDL_PI_F)
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                cell_col = (angleRad == 0.F) ? cell_col + 1 : cell_col - 1;
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
        }
        else
        {
            std::cerr << "angle value not plausible" << std::endl;
        }

    }
}