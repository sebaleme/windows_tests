/* *****************************************************************************
##
# @file        helloworld.cpp
# @brief       main method
# @copyright   MIT license
# ****************************************************************************/

#include "containers.hpp"

std::ostream& operator<<(std::ostream& f_out, const std::vector<std::string> f_value)
{
    for (std::string value: f_value)
    {
        f_out << value << " ";
    }
    return f_out;
}

CVectorStrings::CVectorStrings()
{

}

void CVectorStrings::addItem(std::string f_item)
{
    m_shoppingList.push_back(f_item);
}

void CVectorStrings::removeLastItem()
{
    m_shoppingList.pop_back();
}

void CVectorStrings::removeItem(std::string f_item)
{
    // Erase-remove idiom. Remove move the target items to the container end, return an iterator to the first tail element.
    // Erase supress this element, and implicitly those behinds
    m_shoppingList.erase(std::remove(m_shoppingList.begin(), m_shoppingList.end(), f_item), m_shoppingList.end());
}

void CVectorStrings::print()
{
    std::cout << "shopping list size: " << m_shoppingList.size() << std::endl;
    std::cout << m_shoppingList << std::endl;
}
