/* *****************************************************************************
##
# @file        map_rendering_ut.cpp
# @brief       tests for ray casting functions
# @copyright   MIT license
# ****************************************************************************/
#include "map_rendering_fv.hpp"
#include <algorithm>
#include <numeric>
#include <gtest/gtest.h>

// Check that the angles yield a constant distance between 2 columns
TEST(getAngleToWallNormal, wallAngle_test1)
{
    // Get initial value for enabling comparison
    float_t distanceToWallMiddlePrevious = tanf(getAngleToWallNormal(0))*DISTANCE_WALL_PLAYER;
    float_t intervalRef = distanceToWallMiddlePrevious *2 / SCREEN_WIDTH;
    // Check angle of each column, when the distance between each column is constant
    for (int32_t columnIndex{1}; columnIndex < SCREEN_WIDTH; columnIndex++)
    {
        float_t angleToWallNormal = getAngleToWallNormal(columnIndex);
        float_t distanceToWallMiddle = tanf(angleToWallNormal)*DISTANCE_WALL_PLAYER;
        float_t interval = distanceToWallMiddlePrevious - distanceToWallMiddle;
        // Since columns number is usually huge compared to the screen size, use small error threshold
        EXPECT_NEAR(interval, intervalRef, 0.001F);
        distanceToWallMiddlePrevious = distanceToWallMiddle;
    }
}

// Check the case orientation is 0 and first ray (highest angle)
TEST(getAngleCurrentColumn_regularDistance, wallAngle_test2) {
    float_t orientation{ 0.F };
    int32_t index{ 0 };
    float_t angleToWallNormal = getAngleToWallNormal(index);
    float_t angle_current_column = getAngleCurrentColumn_regularDistance(orientation, angleToWallNormal);
    EXPECT_EQ(angle_current_column, HORIZONTAL_FOV / 2.F);
}

// Check the case orientation is 0 and middle ray (null angle)
TEST(getAngleCurrentColumn_regularDistance, wallAngle_test3) {
    float_t orientation{ 0.F };
    int32_t index{ SCREEN_WIDTH / 2 };
    float_t angleToWallNormal = getAngleToWallNormal(index);
    float_t angle_current_column = getAngleCurrentColumn_regularDistance(orientation, angleToWallNormal);
    EXPECT_EQ(angle_current_column, 0.F);
}

TEST(getAngleCurrentColumn_regularDistance, wallAngle_test4)
{
    // angleResults contains the regular spaced angles
    std::vector<float_t> angleResults(SCREEN_WIDTH / 2);
    std::iota(std::begin(angleResults), std::end(angleResults), 0.F);
    std::transform(std::begin(angleResults), std::end(angleResults), std::begin(angleResults), [](float_t value) {
        return (static_cast<float_t>(SCREEN_WIDTH) / 2.F - value) * HORIZONTAL_INCREMENT;
        });
    EXPECT_NEAR(angleResults[0], HORIZONTAL_FOV / 2.F, 0.01F);
    EXPECT_NEAR(angleResults[1], HORIZONTAL_FOV / 2.F - HORIZONTAL_INCREMENT, 0.01F);
    float_t orientation{ 0.F };
    for (int32_t index{ 1 }; index < angleResults.size(); index++)
    {
        float_t angleToWallNormal = getAngleToWallNormal(index);
        float_t angle_current_column = getAngleCurrentColumn_regularDistance(orientation, angleToWallNormal);
        // In the case of regular distance between 2 columns, the angles distance between 2 columns are higher 
        // than the average in the center and smaller on the edges, that s why the angle for the regularDistance
        // usecase is always higher than the one for regularAngle.
        EXPECT_GT(angle_current_column, angleResults[index]) << "for index " << index;
    }
}
