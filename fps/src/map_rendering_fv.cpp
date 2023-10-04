/* *****************************************************************************
##
# @file        map_rendering_fv.cpp
# @brief       rendering of the environment in isometric projection
# @copyright   MIT license
# ****************************************************************************/
#include "map_rendering_fv.hpp"
#include "types.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>

float_t getAngleCurrentColumn(float_t orientation, int32_t columnIndex)
{
    float_t raw_angle_deg{orientation + (SCREEN_WIDTH / 2 - columnIndex) * HORIZONTAL_RES};
    while (raw_angle_deg >= 180.F) raw_angle_deg -= 180.F *2;
    while (raw_angle_deg < -180.F) raw_angle_deg += 180.F *2;
    return raw_angle_deg;
}

// We use a linear equation to convert the object distance into object size
int32_t computeObjectSize(float_t objectDistance)
{
    float val = objectDistance * OBJECT_SIZE_ALPHA + OBJECT_SIZE_BETA;
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
                    // Going up, so intersection is at the bottom of the upward cell
                    intersecY = static_cast<float_t>(cell_row * CELL_SIZE_PIXELS);
                    intersectionSide = true;
                    // "intersecX" is the X coordinate of the intersection with the obstacle, so we
                    // need to substract the player x position to compute the ray length.
                    // "distanceNorthCell" is just the current distance within the current cell, 
                    // and not from the player position
                    distanceToObstacle = (intersecX - f_player.x) / cosfAngle;
                }
                else
                {
                    // Case east cell is the next
                    ++cell_col;
                    intersecX = static_cast<float_t>(cell_col * CELL_SIZE_PIXELS);
                    intersecY += sinfAngle*distanceEastCell;
                    intersectionSide = false;
                    distanceToObstacle = (intersecY - f_player.y) / sinfAngle;
                }
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
            if (distanceToObstacle > static_cast<float_t>(SCREEN_WIDTH) * sqrt(2.F))
            {
                std::cout << "unplausible angle" << std::endl;
            }
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, intersectionSide);
        }
        else if((angleRad > (SDL_PI_F / 2.F)) && (angleRad < SDL_PI_F))
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                // Distance to the west cell (cell_col - 1)
                float_t xDistance = intersecX - cell_col*CELL_SIZE_PIXELS;
                float_t distanceWestCell = -xDistance / cosfAngle;
                // Distance to the north cell (cell_row + 1)
                float_t yDistance = (cell_row + 1)*CELL_SIZE_PIXELS - intersecY;
                float_t distanceNorthCell = yDistance / sinfAngle;
                // Check which cell comes next
                if(distanceWestCell > distanceNorthCell)
                {
                    // Case north cell is the next
                    ++cell_row;
                    intersecX += cosfAngle*distanceNorthCell;
                    intersecY = static_cast<float_t>(cell_row * CELL_SIZE_PIXELS);
                    // Cos is negative, but f_player.x is greater than intersectX hence positive distance
                    distanceToObstacle = (intersecX - f_player.x) / cosfAngle;
                }
                else
                {
                    // Case west cell is the next
                    cell_col--;
                    intersecX = static_cast<float_t>((cell_col + 1) * CELL_SIZE_PIXELS);
                    intersecY += sinfAngle*distanceWestCell;
                    distanceToObstacle = (intersecY - f_player.y) / sinfAngle;
                }
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
            if (distanceToObstacle > static_cast<float_t>(SCREEN_WIDTH) * sqrt(2.F))
            {
                std::cout << "unplausible angle" << std::endl;
            }
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, intersectionSide);
        }
        else if((angleRad > -(SDL_PI_F / 2.F)) && (angleRad < 0.F))
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                // Distance to the east cell (cell_col + 1)
                float_t xDistance = (cell_col + 1) * CELL_SIZE_PIXELS - intersecX;
                float_t distanceEastCell = xDistance / cosfAngle;
                // Distance to the south cell (cell_row - 1)
                float_t yDistance = intersecY - cell_row*CELL_SIZE_PIXELS;
                float_t distanceSouthCell = -yDistance / sinfAngle;
                // Check which cell comes next
                if(distanceEastCell > distanceSouthCell)
                {
                    // Case south cell is the next
                    cell_row--;
                    intersecX += cosfAngle * distanceSouthCell;
                    // Going down, so intersection is at the top of the downward cell, hence +1
                    intersecY = static_cast<float_t>((cell_row+1) * CELL_SIZE_PIXELS);
                    distanceToObstacle = (intersecX - f_player.x) / cosfAngle;
                }
                else
                {
                    // Case east cell is the next
                    ++cell_col;
                    intersecX = static_cast<float_t>(cell_col * CELL_SIZE_PIXELS);
                    intersecY += sinfAngle* distanceEastCell;
                    distanceToObstacle = (intersecY - f_player.y) / sinfAngle;
                }
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
            if (distanceToObstacle > static_cast<float_t>(SCREEN_WIDTH) * sqrt(2.F))
            {
                std::cout << "unplausible angle" << std::endl;
            }
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, intersectionSide);
        }
        else if ((angleRad > -SDL_PI_F) && (angleRad < -SDL_PI_F/2))
        {
            // Look for the first obstacle
            while (g_map[cellIndex] == 0)
            {
                // Distance to the west cell (cell_col - 1)
                float_t xDistance = intersecX - cell_col * CELL_SIZE_PIXELS;
                float_t distanceWestCell = -xDistance / cosfAngle;
                // Distance to the south cell (cell_row - 1)
                float_t yDistance = intersecY - cell_row * CELL_SIZE_PIXELS;
                float_t distanceSouthCell = -yDistance / sinfAngle;
                // Check which cell comes next
                if (distanceWestCell > distanceSouthCell)
                {
                    // Case south cell is the next
                    cell_row--;
                    intersecX += cosfAngle * distanceSouthCell;
                    // Going down, so intersection is at the top of the downward cell, hence +1
                    intersecY = static_cast<float_t>((cell_row + 1) * CELL_SIZE_PIXELS);
                    // Cos is negative, but f_player.x is greater than intersectX hence positive distance
                    distanceToObstacle = (intersecX - f_player.x) / cosfAngle;
                }
                else
                {
                    // Case west cell is the next
                    cell_col--;
                    // New position is east of the west cell, so intersecX is cell_col+1
                    intersecX = static_cast<float_t>((cell_col+1) * CELL_SIZE_PIXELS);
                    intersecY += sinfAngle * distanceWestCell;
                    // Sin is negative, but f_player.y is greater than intersectX, so we have a positive distance
                    distanceToObstacle = (intersecY - f_player.y) / sinfAngle;
                }
                cellIndex = computeCellIndex(cell_row, cell_col);
            }
            if (distanceToObstacle > static_cast<float_t>(SCREEN_WIDTH) * sqrt(2.F))
            {
                std::cout << "unplausible angle" << std::endl;
            }
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, intersectionSide);
        }
        else if ((angleRad == -SDL_PI_F / 2.F) || (angleRad == SDL_PI_F / 2.F))
        {
            // Look for the first obstacle
            while (g_map[cellIndex] == 0)
            {
                cell_row = (angleRad == SDL_PI_F / 2.F) ? cell_row + 1 : cell_row - 1;
                cellIndex = computeCellIndex(cell_row, cell_col);
            }
            int32_t player_row = static_cast<int32_t>(f_player.y) / CELL_SIZE_PIXELS;
            distanceToObstacle = abs(cell_row - player_row) * CELL_SIZE_PIXELS + f_player.y - player_row * CELL_SIZE_PIXELS;
            if (distanceToObstacle > static_cast<float_t>(SCREEN_WIDTH) * sqrt(2.F))
            {
                std::cout << "unplausible angle" << std::endl;
            }
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, false);
        }
        else if((angleRad == SDL_PI_F) || (angleRad == -SDL_PI_F) ||  (angleRad == 0.F))
        {
            // Look for the first obstacle
            while(g_map[cellIndex] == 0)
            {
                cell_col = (angleRad == 0.F) ? cell_col + 1 : cell_col - 1;
                cellIndex = computeCellIndex(cell_row,cell_col);
            }
            int32_t player_col = static_cast<int32_t>(f_player.x) / CELL_SIZE_PIXELS;
            distanceToObstacle = abs(cell_col - player_col) * CELL_SIZE_PIXELS + f_player.x - player_col * CELL_SIZE_PIXELS;
            if (distanceToObstacle > static_cast<float_t>(SCREEN_WIDTH) * sqrt(2.F))
            {
                std::cout << "unplausible angle" << std::endl;
            }
            fillColumn(pixels, pixel_col, cellIndex, distanceToObstacle, false);
        }
        else
        {
            std::cerr << "angle value not plausible" << std::endl;
        }

    }
}