#include <iostream>
#include "cube.hpp"
#include "game.hpp"
#include "stack.hpp"

using namespace hanoi_tower;

void init(Stack stack)
{

}

int main()
{
    Cube cube_1(2);
    Stack stack_1;
    Game game;

    stack_1.addTopElement(cube_1);
    std::cout << "hello world, stack has a size of " << stack_1.getSize() << std::endl;
    std::cout << game << std::endl;
}