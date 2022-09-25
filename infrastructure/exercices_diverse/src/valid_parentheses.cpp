/* *****************************************************************************
##
# @file        valid_parentheses.cpp
# @brief       leetcode exercice 20 implementation
# @copyright   MIT license
# ****************************************************************************/

// https://leetcode.com/problems/valid-parentheses/


#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        bool res = true;
        std::array<int, 6> countCharacters {0,0,0,0,0,0};
        std::unordered_map<string,int> mapChar { 
            {string("("),0},
            {string(")"),1},
            {string("{"),2},
            {string("}"),3},
            {string("["),4},
            {string("]"),5}
        };

        int iter =0;
        // Go over all character from input string, for each step, the number of closing bracket 
        // should be lower than opening brackets
        for(char &character : s)
        {
            std::string charAsString(1, character);
            int chrIndex = mapChar[charAsString];
            cout << "charAsString: " << charAsString << ", chrIndex: " << chrIndex << endl;
            if( chrIndex < 6)
            {
                countCharacters[chrIndex] ++;
            }
            if(
                (countCharacters[mapChar[")"]] > countCharacters[mapChar["("]]) ||
                (countCharacters[mapChar["}"]] > countCharacters[mapChar["{"]]) ||
                (countCharacters[mapChar["]"]] > countCharacters[mapChar["["]]) 
            )
            {
                res = false;
                break;
            }
            cout << "iter: " << iter << endl;
            iter++;
        }
    
        // check now that all opened brackets were closed
        if(res)
        {
            if(
                (countCharacters[mapChar[")"]] != countCharacters[mapChar["("]]) ||
                (countCharacters[mapChar["}"]] != countCharacters[mapChar["{"]]) ||
                (countCharacters[mapChar["]"]] != countCharacters[mapChar["["]])
            )
            {
                res =false;
            }
        }
        std::cout << "Num (:" << countCharacters[0] << ", num ):" << countCharacters[1] << ", num {:" << countCharacters[2] << std::endl;
        return res;
    }
};

int main()
{
    string s = "([)]";
    Solution soluce;
    int result = soluce.isValid(s);
    cout << result << endl;
}