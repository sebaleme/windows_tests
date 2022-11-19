/* *****************************************************************************
##
# @file        facebook.cpp
# @brief       main method. This game maps faces with names and orga positions
# @copyright   MIT license
# ****************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include "include/training_mode.hpp"

using namespace std;

void init()
{
    // Initialize random function
    srand(static_cast<uint32_t>(time(NULL)));

    init_input_data();
}

int main()
{
    init();
    training_mode();
    return 0;
}