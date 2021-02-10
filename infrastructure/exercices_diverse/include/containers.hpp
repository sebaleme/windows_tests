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
#include <map>
#include <string>
#include <algorithm>
#include <list>

class CVectorStrings
{
public:
    CVectorStrings();

    void print();

    void addItem(std::string f_item);

    void removeItem(std::string f_item);

    void removeLastItem();

    void replaceItem(std::string f_previousItem, std::string f_nextItem);

private:
    std::vector<std::string> m_shoppingList;
};

class CMapStrings
{
public:
    CMapStrings();

    void print();

    void addItem(std::string f_item);

    void addItem(std::list<std::string> f_items);

    void removeItem(std::string f_item);

    void removeLastItem();

    void replaceItem(std::string f_previousItem, std::string f_nextItem);

private:
    std::map<int, std::string> m_shoppingList2;
};
#endif  // CONTAINERS_HPP
