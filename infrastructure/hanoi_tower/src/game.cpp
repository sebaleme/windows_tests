/* *****************************************************************************
##
# @file        game.cpp
# @brief       Implementation of the stack class methods for the hanoi tour problem
# @copyright   MIT license
# ****************************************************************************/
#include "game.hpp"

namespace hanoi_tower
{

Game::Game():Game(3, 4){};

Game::Game(int stack_number, int cube_number)
{
    for(int i{0}; i< stack_number; i++)
    {
        Stack stack;
        stacks.push_back(stack);
    }
    std::cout << stacks.size() << " stacks have been created" << std::endl;
    if(stacks.size() > 0)
    {
        for(int i{0}; i< cube_number; i++)
        {
            Cube cube(static_cast<double>(cube_number-i));
            stacks[0].addTopElement(cube);
        }
    }
};

std::ostream& operator<<(std::ostream& stream, const Game& game)
{
    for (int i{0}; i< game.stacks.size(); i++)
    {
        stream << "stack[" << i <<"] " << game.stacks[i];
    }
    return stream;
}

int Game::getStackSize() const
{
    return stacks.size();
}

void Game::solve()
{
    std::cout << stacks.size() << std::endl;
}

} // namespace hanoi_tower