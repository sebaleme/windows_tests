/* *****************************************************************************
##
# @file        game.cpp
# @brief       Implementation of the stack class methods for the hanoi tour problem
# @copyright   MIT license
# ****************************************************************************/
#include "game.hpp"
#include "rules.hpp"

namespace hanoi_tower
{

Game::Game():Game(3, 4){};

Game::Game(int stack_number, int cube_number):m_total_cube_num{cube_number}
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

bool Game::moveCube(int stackID_1, int stackID_2)
{
    bool result{false};
    if(rule_1(stacks[stackID_1], stacks[stackID_2]))
    {
        stacks[stackID_2].addTopElement(stacks[stackID_1].removeTopElement());
        result = true;
    }
    else if(rule_1(stacks[stackID_2], stacks[stackID_1]))
    {
        stacks[stackID_1].addTopElement(stacks[stackID_2].removeTopElement());
        result = true;
    }
    return result;
}

bool Game::moveCube(Stack& source, Stack& target)
{
    bool result{false};
    if(rule_1(source, target))
    {
        target.addTopElement(source.removeTopElement());
        result = true;
    }
    else if(rule_1(target, source))
    {
        source.addTopElement(target.removeTopElement());
        result = true;
    }
    return result;
}

bool Game::solve_s1(int& iterations)
{
    while(stacks.back().getSize() < m_total_cube_num )
    {
        std::cout << *this << std::endl;
        iterations = moveCube(0,1) ? iterations + 1 : iterations;
        std::cout << *this << std::endl;
        iterations = moveCube(0,2) ? iterations + 1 : iterations;
        std::cout << *this << std::endl;
        iterations = moveCube(1,2) ? iterations + 1 : iterations;

        if(iterations > 200) break;
    }
    std::cout << *this << std::endl;
    return rule_success(stacks.back(), m_total_cube_num);
}

bool Game::solve_s2(int& iterations)
{
    std::cout << *this << std::endl;
    int start {0}, end{m_total_cube_num-1}, depth{0};
    while(stacks.back().getSize() != m_total_cube_num)
    {
        move_s2(start, end, stacks[0], stacks.back(), stacks[1], depth, iterations);
        end--;
    }
    std::cout << *this << std::endl;
    return rule_success(stacks.back(), m_total_cube_num);
}

bool Game::move_s2(int& start, int& end, Stack& source, Stack& target, Stack& spare, int& depth, int& iterations)
{
    if(start != end)
    {
        int start_loc =start+1;
        int depth_loc =depth+1;
        // Move subTower to the spare stack
        move_s2(start_loc, end, source, spare, target, depth_loc, iterations);
        // Move the bigger element to the target
        move_s2(start, start, source, target, spare, depth_loc, iterations);
        // Move the subTower from the spare tower to the target
        move_s2(start_loc, end, spare, target, source, depth_loc, iterations);
    }
    else
    {
        moveCube(source,target);
        iterations++;
        std::cout << *this << std::endl;
    }
    return true;
}

} // namespace hanoi_tower