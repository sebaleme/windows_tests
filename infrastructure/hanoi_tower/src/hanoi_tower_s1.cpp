#include <iostream>
#include "cube.hpp"
#include "game.hpp"
#include "stack.hpp"

using namespace hanoi_tower;

int main()
{
    Game game;
    int iterations{0};
    bool result = game.solve_s1(iterations);
    std::string success = result? "Game solved after " : "Game failed after ";
    std::cout << success << iterations << " iterations with solution 1" << std::endl;
    std::cout << "===================================" << std::endl << std::endl << std::endl;

    Game game2;
    iterations = 0;
    result = game2.solve_s2(iterations);
    success = result? "Game solved after " : "Game failed after ";
    std::cout << success << iterations << " iterations with solution 2" << std::endl;
    std::cout << "===================================" << std::endl << std::endl << std::endl;

    Game game3(3,10);
    iterations = 0;
    result = game3.solve_s1(iterations);
    success = result? "Game solved after " : "Game failed after ";
    std::cout << success << iterations << " iterations with solution 1" << std::endl;
    std::cout << "===================================" << std::endl << std::endl << std::endl;

    Game game4(3,10);
    iterations = 0;
    result = game4.solve_s2(iterations);
    success = result? "Game solved after " : "Game failed after ";
    std::cout << success << iterations << " iterations with solution 2" << std::endl;
}