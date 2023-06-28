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
    bool solve_s1(int& iterations);
    bool solve_s2(int& iterations);

    friend std::ostream& operator<<(std::ostream& stream, const Game& game);

    private:
    bool moveCube(int stackID_1, int stackID_2);
    bool moveCube(Stack& source, Stack& target);
    bool move_s2(int& start, int& end, Stack& source, Stack& target, Stack& spare, int& depth, int& iterations);
    int m_total_cube_num;
    std::vector<Stack> stacks;
};

} // namespace hanoi_tower

#endif  // GAME_HPP