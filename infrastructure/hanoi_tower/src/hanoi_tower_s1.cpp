#include <iostream>
#include "cube.hpp"
#include "stack.hpp"

using namespace hanoi_tower;

int main()
{
    Cube cube_1(2);
    Stack stack_1;

    stack_1.addTopElement(cube_1);
    std::cout << "hello world, stack has a size of " << stack_1.getSize() << std::endl;
}