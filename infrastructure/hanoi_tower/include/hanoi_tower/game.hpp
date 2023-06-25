/* *****************************************************************************
##
# @file        game.hpp
# @brief       Game class initializing and managing the environment
# @copyright   MIT license
# ****************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "stack.hpp"
#include <iostream>

namespace hanoi_tower
{

class Game
{
    public:
    Game();
    Game(int stack_number, int cube_number);
    void solve();

    friend std::ostream& operator<<(std::ostream& stream, const Game& game);

    private:
    std::vector<Stack> stacks;
};

} // namespace hanoi_tower

#endif  // GAME_HPP