/* *****************************************************************************
##
# @file        stack.hpp
# @brief       Stack implementation in context of the hanoi tower exercice
# @copyright   MIT license
# ****************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include "cube.hpp"

namespace hanoi_tower
{

class Stack
{
    public:
    void addTopElement(const Cube& cube);
    Cube removeTopElement();
    Cube& checkTopElement();
    unsigned getSize();
    private:
    std::vector<Cube> data;
};

} // namespace hanoi_tower

#endif STACK_HPP