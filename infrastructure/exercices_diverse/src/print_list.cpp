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
#include <regex>

using namespace std;

int main(int argc, char **argv)
{
    // Exercise 5.1: Simple stream I/O
    vector<string> shopping_list;
    cout << "Have " << (argc - 1) << " arguments" << std::endl;

    for (int i = 0; i < argc; ++i)
    {
        if (i != 0)
        {
            shopping_list.emplace_back(argv[i]);
        }
    }

    string shopping_item;
    do
    {
        cout << "Please enter your shopping list: ";
        // std::cin cannot handle whitespace in strings, but geline and ws can
        getline(cin >> ws, shopping_item);

        if (shopping_item != "done")
        {
            shopping_list.emplace_back(shopping_item);
        }
    }
    while(shopping_item != "done");

    for (string item: shopping_list)
    {
        cout << item << "; ";
    }
    cout << endl;

    // Exercise 5.2: String manipulations
    string congrats =
        "Congratulations Mrs. <name>, you and Mr. <name> are the lucky recipients of a trip for two to XXXXXX. Your trip to XXX is already scheduled.";
    regex reg("\\<name\\>");
    string resultRegex = regex_replace(congrats, reg, "Luzer");
    regex reg2("(XXX)+");
    resultRegex = regex_replace(resultRegex, reg2, "Siberia");
    regex reg3("lucky");
    resultRegex = regex_replace(resultRegex, reg3, "unlucky", regex_constants::format_first_only);
    smatch m;
    string insertString = "scheduled";
    regex reg4(insertString);
    regex_search(resultRegex, m, reg4);
    resultRegex.insert(m.position()+insertString.length(), string(" in december"));
    cout << resultRegex << endl;
}
