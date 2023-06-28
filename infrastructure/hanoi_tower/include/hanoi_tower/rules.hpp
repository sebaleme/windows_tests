/* *****************************************************************************
##
# @file        rules.hpp
# @brief       rules definition for the hanoi tower game
# @copyright   MIT license
# ****************************************************************************/
#ifndef RULES_HPP
#define RULES_HPP

#include "stack.hpp"

namespace hanoi_tower
{

bool rule_1(Stack source, Stack dest)
{
    bool result{false};
    if(source.getSize() > 0)
    {
        Cube source_cube{source.checkTopElement()};
        if((dest.getSize()==0)||(dest.checkTopElement().getLength() > source_cube.getLength()))
        {
            result = true;
        }
    }
    
    return result;
}

bool rule_success(Stack last_stack, int total_cube_num)
{
    bool result{false};
    if(last_stack.getSize() == total_cube_num)
    {
        result = true;
    }
    
    return result;
}

} // namespace hanoi_tower

#endif  // RULES_HPP