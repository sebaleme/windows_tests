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
        regex reg("(\\d+)\\s(\\+|\\-)\\s(\\d+)");
        smatch match;

        std::regex_search(s, match, reg);
        cout << "match.length(): " << match.length() << endl;
        if((match.length() > 0U)&&(match[2].str()== "+"))
        {
            result = stoi(match[1].str()) + stoi(match[3].str());
        }
        else if((match.length() > 0U)&&(match[2].str()== "-"))
        {
            result = stoi(match[1].str()) - stoi(match[3].str());            
        }
        // for (std::size_t i = 0; i < match.size(); ++i)
        // {
        //     std::string num = match[i].str();
        //     cout << i << ": " << num << endl;
        // }
        return result;
    }
};

int main()
{
    string s = "10 - 8";
    Solution soluce;
    int result = soluce.calculate(s);
    cout << endl;    
    cout << result << endl;
}
