/* *****************************************************************************
##
# @file        regex_search.cpp
# @brief       leetcode exercices implementation
# @copyright   MIT license
# ****************************************************************************/

// https://leetcode.com/problems/basic-calculator/description/

// Soluce inspired from:
// http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/regex/regex_iterator.html

#include <regex>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int result = 0;

        // Stage 1: extract operators from string
        std::map<int, string> operatorMap;
        regex reg1("(\\+|\\-)");
        auto words_begin = std::sregex_iterator(s.begin(), s.end(), reg1);
        auto words_end = std::sregex_iterator();

        std::ptrdiff_t const operatorNumber(std::distance(words_begin, words_end));
        cout << " (number of operators): " << operatorNumber << endl;

        int count = 0;

        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;
            std::string match_str = match.str();
            operatorMap.insert(pair<int, string>(count, match_str));
            count++;
        }

        // Stage 2: extract operand from string and compute operation
        regex reg2("[0-9]+");
        auto words_begin2 = std::sregex_iterator(s.begin(), s.end(), reg2);
        auto words_end2 = std::sregex_iterator();

        int count2 = 0;

        for (std::sregex_iterator i = words_begin2; i != words_end2; ++i)
        {
            std::smatch match2 = *i;
            std::string match_str2 = match2.str();

            if (count2 == 0)
            {
                result = stoi(match_str2);
            }
            else
            {
                if (operatorMap[count2 - 1] == "+")
                {
                    result = result + stoi(match_str2);
                }
                else if (operatorMap[count2 - 1] == "-")
                {
                    result = result - stoi(match_str2);
                }
            }
            count2++;
        }

        return result;
    }
};

int main()
{
    string s = "1+   20000 -   8000 + 24-100 ";
    Solution soluce;
    int result = soluce.calculate(s);
    cout << result << endl;
}
