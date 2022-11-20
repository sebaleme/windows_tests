/* *****************************************************************************
##
# @file        test_mode.hpp
# @brief       challenging quizz mode with permanent score 
# @copyright   MIT license
# ****************************************************************************/

#ifndef TEST_MODE_HEADER_HPP
#define TEST_MODE_HEADER_HPP

#include <time.h>
#include <chrono>
#include <iomanip>
#include "data_acquisition.hpp"
#include "include/quizz_evaluation.hpp"

using namespace std;

void test_mode(themes f_theme)
{
    int indexPeople{rand() % static_cast<int>(s_people_with_gt.size())};
    string answer;
    int score{0}, iteration{10};
    auto start = std::chrono::system_clock::now();

    while (iteration)
    {
        iteration--;

        // Interaction with user
        cout << "from which " << cout_1[static_cast<int>(f_theme)] << " is " 
                << s_people_with_gt[indexPeople].first << "?" << endl;
        cin >> answer;

        // Process user response
        std::vector<string>::iterator houseIt;
        houseIt = find(s_house.begin(), s_house.end(), answer);
        if(houseIt != s_house.end())
        {
            if(*houseIt == s_house[s_people_with_gt[indexPeople].second])
            {
                cout << "nice one" << endl;
                score++;
            }
            else
            {
                cout << "nope!" << endl;
            }
        }
        else
        {
            cout << "wrong, this is not even a " << cout_1[static_cast<int>(f_theme)] << " in " 
                    << cout_2[static_cast<int>(f_theme)] << endl;
        }

        // Prepare next question
        s_people_with_gt.erase(s_people_with_gt.begin() + indexPeople);
        indexPeople = rand() % s_people_with_gt.size();
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    // Give result
    cout << "================================" << endl;
    float scoreFloat = (float)score / 10.F;
    cout << "you got " << score << "/10 in " << std::fixed << std::setprecision(0) 
            << elapsed_seconds.count() << "s" << comment(scoreFloat) << endl;
}

#endif // TEST_MODE_HEADER_HPP
