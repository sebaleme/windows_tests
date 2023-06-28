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
    explicit Game();
    Game(int stack_number, int cube_number);
    int getStackSize() const;
    void solve();

    friend std::ostream& operator<<(std::ostream& stream, const Game& game);

    private:
    void moveCube(int stackID_1, int stackID_2);
    int m_total_cube_num{0};
    std::vector<Stack> stacks;
};

} // namespace hanoi_tower

#endif  // GAME_HPP