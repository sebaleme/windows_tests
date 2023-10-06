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

// Check the case orientation is 0 and first ray (highest angle)
TEST(getAngleCurrentColumn_regularDistance, wallAngle_test1) {
  float_t orientation{0.F};
  int32_t index{0};
  float_t angle_current_column = getAngleCurrentColumn_regularDistance(orientation, index);
  EXPECT_EQ(angle_current_column, HORIZONTAL_FOV/2.F);
}

// Check the case orientation is 0 and middle ray (null angle)
TEST(getAngleCurrentColumn_regularDistance, wallAngle_test2) {
  float_t orientation{0.F};
  int32_t index{SCREEN_WIDTH / 2};
  float_t angle_current_column = getAngleCurrentColumn_regularDistance(orientation, index);
  EXPECT_EQ(angle_current_column, 0.F);
}

TEST(getAngleCurrentColumn_regularDistance, wallAngle_test3)
{
    // angleResults contains the regular spaced angles
    std::vector<float_t> angleResults(SCREEN_WIDTH / 2);
    std::iota(std::begin(angleResults), std::end(angleResults), 0.F);
    std::transform(std::begin(angleResults), std::end(angleResults), std::begin(angleResults), [](float_t value) {
        return (static_cast<float_t>(SCREEN_WIDTH) / 2.F - value) * HORIZONTAL_INCREMENT;
    });
    EXPECT_NEAR(angleResults[0], HORIZONTAL_FOV / 2.F, 0.01F);
    EXPECT_NEAR(angleResults[1], HORIZONTAL_FOV / 2.F - HORIZONTAL_INCREMENT, 0.01F);
    float_t orientation{0.F};
    for (int32_t index{1}; index < angleResults.size(); index++)
    {
        float_t angle_current_column = getAngleCurrentColumn_regularDistance(orientation, index);
        EXPECT_GT(angle_current_column, angleResults[index]) << "for index " << index;
    }
}
