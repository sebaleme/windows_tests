/* *****************************************************************************
##
# @file        cube.cpp
# @brief       Cube implementation, containing the display method
# @copyright   MIT license
# ****************************************************************************/
#include "cube.hpp"

namespace hanoi_tower
{

std::ostream& operator<<(std::ostream& stream, const Cube& cube)
{
    stream << cube.getLength();
    return stream;
}

} // namespace hanoi_tower