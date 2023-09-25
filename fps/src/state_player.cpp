/* *****************************************************************************
##
# @file        state_player.cpp
# @brief       Process the current player state
# @copyright   MIT license
# ****************************************************************************/
#include "state_player.hpp"

#include "types.hpp"


EOrientation computeGeneralDirection(const StatePlayer& player)
{
    EOrientation result{EOrientation::invalid};
    const float_t& angle = player.orientation;
    if((angle >= 112.5F)&&(angle < 157.5F ))
    {
        result = EOrientation::North_West;
    }
    else if((angle >= 67.5F)&&(angle < 112.5F ))
    {
        result = EOrientation::North;
    }
    else if((angle >= 22.5F)&&(angle < 67.5F ))
    {
        result = EOrientation::North_Est;
    }
    else if((angle >= -22.5F)&&(angle < 22.5F ))
    {
        result = EOrientation::Est;
    }
    else if((angle >= -67.5F)&&(angle < -22.5F ))
    {
        result = EOrientation::South_Est;
    }
    else if((angle >= -112.5F)&&(angle < -67.5F ))
    {
        result = EOrientation::South;
    }
    else if((angle >= -157.5F)&&(angle < -112.5F ))
    {
        result = EOrientation::South_West;
    }
    else if(
        ((angle >= -180.f)&&(angle <= -157.5F ))||
        ((angle >= 157.5F)&&(angle <= 180.F ))
    )
    {
        result = EOrientation::West;
    }
    else
    {
        //Do nothing
    }
    return result;
}