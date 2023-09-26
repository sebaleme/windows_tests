/* *****************************************************************************
##
# @file        colors.cpp
# @brief       Colors accessing functions
# @copyright   MIT license
# ****************************************************************************/

#include "colors.hpp"
#include "map.hpp"

int32_t getCellColor(int32_t index ,bool f_color_modifyer)
{
    int32_t color{colors_dark[g_map[index]]};
    if(f_color_modifyer)
    {
        color = colors_light[g_map[index]];
    }

    return color;
}
