/* *****************************************************************************
##
# @file        main.cpp
# @brief       main method for the FPS game. This app implements basic games functionalities
# @copyright   MIT license
# ****************************************************************************/
#include "init.hpp"
#include "input.hpp"
#include "types.hpp"
#include <iostream>


int main()
{
    std::cout << "Hello world" << std::endl;

    CApplication app{};
    initSDL(app);

    while(1)
    {
        // Without this, the programm stalls when we interract with the window
        doInput();
    }

    return 0;
}