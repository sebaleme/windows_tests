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
#include <utility>
#include "quizz_interfaces.hpp"
	

using namespace std;

std::vector<pair<string, int>> s_people_with_gt;
std::vector<string> s_house;

array<string,2> cout_1{"house","village"};
array<string,2> cout_2{"GoT","Naruto"};

// Helper function, overloading operator
ostream& operator<<(ostream& f_out, const quizz_theme f_input)
{
    const char *s = 0;

    switch(f_input)
    {
        case quizz_theme::GOT_TEST:
        {
            s = "GoT Test";
            break;
        }
        case quizz_theme::GOT_TRAINING:
        {
            s = "GoT Training";
            break;
        }
        case quizz_theme::NARUTO_TEST:
        {
            s = "Naruto Test";
            break;
        }
        case quizz_theme::NARUTO_TRAINING:
        {
            s = "Naruto Training";
            break;
        }
        default:
        {
            s = "INVALID";
        }
    }
    return f_out << s;
};

// interface to access data
string INPUT_PATH_GOT_1 = "C:\\Users\\lsm1so\\Documents\\workspace\\windows_tests\\facebook\\database\\got_name_house.csv";
string INPUT_PATH_NARUTO_1 = "C:\\Users\\lsm1so\\Documents\\workspace\\windows_tests\\facebook\\database\\naruto_name_village.csv";
map<quizz_theme,string> data_selection{
    {quizz_theme::GOT_TRAINING,INPUT_PATH_GOT_1},
    {quizz_theme::GOT_TEST,INPUT_PATH_GOT_1},
    {quizz_theme::NARUTO_TRAINING,INPUT_PATH_NARUTO_1},
    {quizz_theme::NARUTO_TEST,INPUT_PATH_NARUTO_1},
};

using QuizzSelection = pair<session,themes>;

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
QuizzSelection init_input_data(int f_selection)
{
    QuizzSelection result;
    ifstream fin(data_selection[static_cast<quizz_theme>(f_selection)].c_str());

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

    // selection information
    result.first = (f_selection%2 == 0)? session::TEST : session::TRAINING;
    result.second = (f_selection <= 2)? themes::GoT : themes::Naruto;

    return result;
}

#endif // DATA_ACQUISITION_HEADER_HPP
