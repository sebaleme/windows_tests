/* *****************************************************************************
##
# @file        helloworld.cpp
# @brief       main method
# @copyright   MIT license
# ****************************************************************************/

#include "containers.hpp"

// Helper functions
std::ostream& operator<<(std::ostream& f_out, const std::vector<std::string> f_value)
{
    for (std::string value: f_value)
    {
        f_out << value << " ";
    }
    return f_out;
}

// Vector methods
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

void CVectorStrings::replaceItem(std::string f_previousItem, std::string f_nextItem)
{
    auto iter = std::find(m_shoppingList.begin(), m_shoppingList.end(), f_previousItem);

    if (iter != m_shoppingList.end())
    {
        int index = iter - m_shoppingList.begin();
        m_shoppingList[index] = f_nextItem;
    }
}

void CVectorStrings::print()
{
    std::cout << "shopping list size: " << m_shoppingList.size() << std::endl;
    std::cout << m_shoppingList << std::endl;
}

// Map methods
CMapStrings::CMapStrings()
{
}

void CMapStrings::addItem(std::string f_item)
{
    // m_shopping_list2.insert(std::pair<int,std::string>(0,f_item));
}

void CMapStrings::addItem(std::list<std::string> f_items)
{
    // for (auto item: f_items)
    // {
    //     m_shopping_list2.insert(item);
    // }
}

void CMapStrings::removeLastItem()
{
    // m_shoppingList.pop_back();
}
