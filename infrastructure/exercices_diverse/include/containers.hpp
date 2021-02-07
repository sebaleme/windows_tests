/* *****************************************************************************
##
# @file        containers.hpp
# @brief       exercices implementation
# @copyright   MIT license
# ****************************************************************************/

#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class CVectorStrings
{
public:
    CVectorStrings();

    void print();
    void addItem(std::string f_item);
    void removeItem(std::string f_item);
    void removeLastItem();

private:

    std::vector<std::string> m_shoppingList;
};

#endif  // CONTAINERS_HPP
