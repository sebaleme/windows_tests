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

int32_t computeObjectSize(float_t objectDistance)
{
    float val = sqrt(static_cast<float_t>(SCREEN_HEIGHT))-objectDistance/1.41F;
    return std::min(static_cast<int32_t>(val),SCREEN_HEIGHT);
}

void fillColumn(uint32_t* pixels, int32_t pixel_col, int32_t cellIndex, float_t distanceToObstacle, bool intersectionSide)
{
            // Fill pixel column
            int32_t objectSize = computeObjectSize(distanceToObstacle);
            int32_t limitCeilingObstacle = (SCREEN_HEIGHT - objectSize)/2;
            int32_t limitObstacleGround = objectSize + limitCeilingObstacle;

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
        int32_t playerCell = computeCellIndex(cell_row, cell_col);

        // Intersection point
        float_t intersecX = f_player.x;
        float_t intersecY = f_player.y;
        bool intersectionSide = false;

        // Differentiate if we are looking north, south, east or west
        if((angleRad > 0.F) && (angleRad < SDL_PI_F /2.F))
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0U)
            {
                // Distance to the east cell (cell_col + 1)
                float_t xDistance = (cell_col+1) * CELL_SIZE_PIXELS - intersecX;
                float_t distanceEastCell = xDistance / cosfAngle;
                // Distance to the north cell (cell_row + 1)
                float_t yDistance = (cell_row+1) * CELL_SIZE_PIXELS - intersecY;
                float_t distanceNorthCell = yDistance / sinfAngle;
                // Check which cell comes next
                if(distanceEastCell > distanceNorthCell)
                {
                    // Case north cell is the next
                    ++cell_row;
                    intersecX += cosfAngle*distanceNorthCell;
                    intersecY = static_cast<float_t>(cell_row * CELL_SIZE_PIXELS);
                    intersectionSide = true;
                }
                else
                {
                    // Case west cell is the next
                    ++cell_col;
                    intersecX = static_cast<float_t>(cell_col * CELL_SIZE_PIXELS);
                    intersecY += sinfAngle*distanceEastCell;
                    intersectionSide = false;
                }
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
            distanceToObstacle = intersecX / cosfAngle;
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, intersectionSide);
        }
        else if((angleRad > (SDL_PI_F / 2.F)) && (angleRad < SDL_PI_F))
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
                distanceToObstacle = intersecX / cosfAngle;
                fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, intersectionSide);
            }
        }
        else if((angleRad > -(SDL_PI_F / 2.F)) && (angleRad < 0.F))
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                // Distance to the west cell (cell_col - 1)
                float_t xDistance = intersecX - cell_col*CELL_SIZE_PIXELS;
                float_t distanceWestCell = xDistance / cosfAngle;
                // Distance to the south cell (cell_row - 1)
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
                distanceToObstacle = intersecX / cosfAngle;
                fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, intersectionSide);
            }
        }
        else if( angleRad == 0.F)
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                cell_col++;
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
            int32_t player_col = static_cast<int32_t>(f_player.x) / CELL_SIZE_PIXELS;
            distanceToObstacle = cell_col* CELL_SIZE_PIXELS - f_player.x;
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, false);
        }
        else if (angleRad == SDL_PI_F / 2.F)
        {
            // Look for the first obstacle
            while (g_map[cellIndex] == 0)
            {
                cell_row = (angleRad == SDL_PI_F / 2.F) ? cell_row + 1 : cell_row - 1;
                cellIndex = computeCellIndex(cell_row, cell_col);
            }
            int32_t player_col = static_cast<int32_t>(f_player.x) / CELL_SIZE_PIXELS;
            distanceToObstacle = abs(cell_col - player_col) * CELL_SIZE_PIXELS + f_player.x - player_col * CELL_SIZE_PIXELS;
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, false);
        }
        else if(angleRad == SDL_PI_F)
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                cell_col = (angleRad == 0.F) ? cell_col + 1 : cell_col - 1;
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
            distanceToObstacle = intersecX / cosfAngle;
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, false);
        }
        else if (angleRad == 0.F)
        {
            // Look for the first obstacle
            while (g_map[cellIndex] == 0)
            {
                cell_col = (angleRad == 0.F) ? cell_col + 1 : cell_col - 1;
                cellIndex = computeCellIndex(cell_row, cell_col);
            }
            distanceToObstacle = intersecX / cosfAngle;
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, false);
        }
        else
        {
            std::cerr << "angle value not plausible" << std::endl;
        }

    }
}