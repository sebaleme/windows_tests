/* *****************************************************************************
##
# @file        stack.cpp
# @brief       Implementation of the stack class methods for the hanoi tour problem
# @copyright   MIT license
# ****************************************************************************/
#include "stack.hpp"

namespace hanoi_tower
{

void Stack::addTopElement(const Cube& cube)
{
    data.push_back(cube);
};

Cube Stack::removeTopElement()
{
    if(data.size() > 0)
    {
        Cube cube = data.back();
        data.pop_back();
        return cube;
    }
    else
    {
        // Return invalid cube if stack is empty
        Cube cube(0);
        return cube;
    }
};

Cube& Stack::checkTopElement()
{
    return data.back();
};

unsigned Stack::getSize()
{
    return data.size();
};

std::ostream& operator<<(std::ostream& stream, const Stack& stack)
{
    for (auto& cube : stack.data)
    {
        stream << cube << ", ";
    }
    stream << std::endl;
    return stream;
}

} // namespace hanoi_tower

