/* *****************************************************************************
##
# @file        print_list.cpp
# @brief       main method
# @copyright   MIT license
# ****************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

// Exercise 5.1: Simple stream I/O
int main(int argc, char **argv)
{
    std::vector<std::string> shopping_list;
    std::cout << "Have " << (argc - 1) << " arguments" << std::endl;

    for (int i = 0; i < argc; ++i)
    {
        if (i != 0)
        {
            shopping_list.emplace_back(argv[i]);
        }
    }

    std::string shopping_item;
    do
    {
        std::cout << "Please enter your shopping list: ";
        std::cin >> shopping_item;
        if(shopping_item != "done")
        {
            shopping_list.emplace_back(shopping_item);
        }
    }
    while(shopping_item != "done");

    for (string item: shopping_list)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
