/* *****************************************************************************
##
# @file        stack.hpp
# @brief       Stack of cubes in context of the hanoi tower game
# @copyright   MIT license
# ****************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include "cube.hpp"
#include <iostream>

namespace hanoi_tower
{

class Stack
{
    public:
    Stack(){};
    Stack(const Stack& other):data{other.data}{};
    void addTopElement(const Cube& cube);
    Cube removeTopElement();
    Cube& checkTopElement();
    unsigned getSize();

    friend std::ostream& operator<<(std::ostream& stream, const Stack& stack);
    private:
    std::vector<Cube> data;
};

} // namespace hanoi_tower

#endif STACK_HPP