/* *****************************************************************************
##
# @file        facebook.cpp
# @brief       main method. This game maps faces with names and orga positions
# @copyright   MIT license
# ****************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include <time.h>
#include "include/data_acquisition.hpp"

using namespace std;

void init()
{
    // Initialize random function
    srand(static_cast<uint32_t>(time(NULL)));

    init_input_data();
}

string comment(float f_score)
{
    string result;

    if(f_score == 0.)
    {
        result = ", that bad?";
    }
    else if((f_score > 0.)&&(f_score < 0.5))
    {
        result = ", you have a long road to climb";
    }
    else if((f_score >= 0.5)&&(f_score < 1.0))
    {
        result = ", still need to improve";
    }
    else
    {
        result = ", perfect";
    }
    return result;
}

int main()
{
    cout << "Welcome to a little GoT quizz" << endl;
    init();
    int indexPeople{rand() % static_cast<int>(s_people_with_gt.size())};
    bool wannaPlay{true};
    string answer;
    int score{0}, iteration{0};

    while (wannaPlay)
    {
        iteration++;

        // Interaction with user
        cout << "from which house is " << s_people_with_gt[indexPeople].first << "?" << endl;
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
            cout << "wrong, this is not even a house in GoT!" << endl;
        }

        // Prepare next question
        s_people_with_gt.erase(s_people_with_gt.begin() + indexPeople);
        indexPeople = rand() % s_people_with_gt.size();

        cout << endl << "play again ? y/n" << endl;
        cin >> answer;
        wannaPlay = (answer == "y");
    }

    // Give result
    cout << "================================" << endl;
    float scoreFloat = (float)score / (float)iteration;
    cout << "you got " << score << "/" << iteration << comment(scoreFloat) << endl;
    return 0;
}