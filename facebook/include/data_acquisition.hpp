/* *****************************************************************************
##
# @file        data_acquisition.hpp
# @brief       acquisition of the data
# @copyright   MIT license
# ****************************************************************************/

#ifndef DATA_ACQUISITION_HEADER_HPP
#define DATA_ACQUISITION_HEADER_HPP

#include <array>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

std::vector<pair<string, int>> s_people_with_gt;
std::vector<string>  s_house;

// list of existing quizz
enum class quizz_theme: uint8_t{
    GOT = 1U,
    NARUTO = 2U,
    END,
};

bool operator< (int f_input1, quizz_theme f_input2)
{
    return f_input1 < static_cast<int>(f_input2);
};

// interface to access data
string INPUT_PATH_GOT_1 = "C:\\Users\\lsm1so\\Documents\\workspace\\windows_tests\\facebook\\database\\got_name_house.csv";
string INPUT_PATH_NARUTO_1 = "C:\\Users\\lsm1so\\Documents\\workspace\\windows_tests\\facebook\\database\\naruto_name_village.csv";
map<quizz_theme,string> data_selection{
    {quizz_theme::GOT,INPUT_PATH_GOT_1},
    {quizz_theme::NARUTO,INPUT_PATH_NARUTO_1}
};

/// @brief print GT information (for debugging purpose)
void print_GT()
{
    cout << "===================================================" << endl;
    for(int i{0}; i<s_people_with_gt.size(); i++)
    {
        if(s_people_with_gt[i].second < s_house.size())
        {
            cout << s_people_with_gt[i].first << " is in the house " << s_house[s_people_with_gt[i].second] << endl;
        }
        else
        {
            cout << "house vector was not filled properly" << endl;
        }
    }

    cout << "===================================================" << endl;
    cout << endl;
}

/// @brief read CSV and store data into vectors
///        2 interfaces are provided, a vector of houses and a vector of pair containing the names and responses 
void init_input_data()
{
    cout << "Welcome to a little quizz game, please select the topic" << endl;
    bool invalidSelection{true};
    int selection{0};
    while(invalidSelection)
    {
        cout << "1 GOT" << endl;
        cout << "2 Naruto" << endl;
        cin >> selection;
        if(selection > 0 && selection < quizz_theme::END)
        {
            invalidSelection = false;
        }
        else
        {
            cout << "enter a valid selection" << endl;
        }
    }
    cout << data_selection[static_cast<quizz_theme>(selection)].c_str() << endl;
    ifstream fin(data_selection[static_cast<quizz_theme>(selection)].c_str());
    if(!fin.good())
    {
        cout << "Could not open the input file" << endl;
    }

    // get first line
    string line, word, name, house;
    while(getline(fin,line))
    {
        stringstream s(line);
        int index{0};

        //CSV has only two words by line
        while(getline(s, word, ',')) 
        {
            if(index == 0) name = word;
            if(index == 1) house = word;
            index++;
        }

        // Update the houses list
        auto houseIt = find(s_house.begin(), s_house.end(), house);
        int houseIndex{0};
        if(houseIt == s_house.end())
        {
            s_house.push_back(house);
            houseIndex = static_cast<int>(s_house.size()) - 1;
        }
        else
        {
            houseIndex = static_cast<int>(houseIt - s_house.begin());
        }

        // Update the people list
        s_people_with_gt.push_back(make_pair(name, houseIndex));
    }
}

#endif // DATA_ACQUISITION_HEADER_HPP
