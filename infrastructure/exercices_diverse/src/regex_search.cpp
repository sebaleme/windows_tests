/* *****************************************************************************
##
# @file        regex_search.cpp
# @brief       leetcode exercices implementation
# @copyright   MIT license
# ****************************************************************************/

// https://leetcode.com/problems/basic-calculator/description/
#include <regex>
#include <iostream>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {

        int result = 0;
        regex reg("[0-9]+");
        smatch match;

        if (std::regex_search(s, match, reg))
        {
            for (int i = 0; i < match.length(); i++)
            {
                cout << match[i];
            }
        }

        return result;
    }
};

int main()
{
    string s = "1 + 1";
    Solution soluce;
    int result = soluce.calculate(s);
    cout << result << endl;
}
