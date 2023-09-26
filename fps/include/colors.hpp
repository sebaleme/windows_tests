/* *****************************************************************************
##
# @file        colors.hpp
# @brief       Defining colors
# @copyright   MIT license
# ****************************************************************************/
#include <array>

#ifndef FSP_COLORS_HPP
#define FSP_COLORS_HPP

// Using RGB code, highest byte unused
static constexpr int32_t GREEN_DARK{0x0070FF70};
static constexpr int32_t GREEN_LIGHT{0x0095FF95};

static constexpr int32_t RED_DARK{0x00FF7070};
static constexpr int32_t RED_LIGHT{0x00FF9595};

static constexpr int32_t PURPLE_DARK{0x00AA00AA};
static constexpr int32_t PURPLE_LIGHT{0x00FF00FF};

static constexpr int32_t BLUE_DARK{0x007070FF};
static constexpr int32_t BLUE_LIGHT{0x009595FF};

static constexpr int32_t BLACK{0x0};
static constexpr int32_t SKY_BLUE{0x99FFFF};
static constexpr int32_t YELLOW_LIGHT{0xFFFF99};

static std::array<int32_t, 4> colors_dark{GREEN_DARK, RED_DARK, PURPLE_DARK, BLUE_DARK};
static std::array<int32_t, 4> colors_light{GREEN_LIGHT, RED_LIGHT, PURPLE_LIGHT, BLUE_LIGHT};

int32_t getCellColor(int32_t index ,bool f_color_modifyer);

#endif /* FSP_COLORS_HPP */