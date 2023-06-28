#include <iostream>
#include "cube.hpp"
#include "game.hpp"
#include "stack.hpp"

using namespace hanoi_tower;

int main()
{
    Game game;
    int iterations{0};
    bool result = game.solve(iterations);
    std::string success = result? "Game solved after " : "Game failed after ";
    std::cout << success << iterations << " iterations" << std::endl;
}