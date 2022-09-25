/* *****************************************************************************
##
# @file        vector_erase.cpp
# @brief       https://www.hackerrank.com/challenges/vector-erase/problem?isFullScreen=true
# @copyright   MIT license
# ****************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    std::fstream inputs("C:\\Users\\sebal\\Documents\\repos\\windows_tests\\infrastructure\\exercices_diverse\\inputs\\vector_erase.txt", std::ios_base::in);
    // Create vector and fill values
    vector<int> vect{};
    int num{-1}, j{-1};
    inputs >> num;
    
    for (int i=0;i<num;i++)
    {
        inputs >> j;
        vect.push_back(j);
    }
    
    // Remove elements
    inputs >> j;
    int a{0},b{0};
    inputs >> a >> b;
    
    // Case element index is included in interval
    if(j<b) b--;
    if(j<a) a--;
    // All index -1, because given index starts at 1
    vect.erase(vect.begin()+j-1);
    vect.erase(vect.begin()+a-1,vect.begin()+b);
    
    // Print results
    cout << vect.size() << endl;
    
    for(const auto& element : vect)
    {
        cout << element << " ";
    }
    cout << endl;
       
    return 0;
}
