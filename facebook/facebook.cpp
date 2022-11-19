/* *****************************************************************************
##
# @file        facebook.cpp
# @brief       main method. This game maps faces with names and orga positions
# @copyright   MIT license
# ****************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include "include/training_mode.hpp"
#include "include/test_mode.hpp"

using namespace std;

QuizzSelection init(int selection)
{
    QuizzSelection result;
    // Initialize random function
    srand(static_cast<uint32_t>(time(NULL)));

    result = init_input_data(selection);

    return result;
}

int menu()
{
    cout << "please select the topic" << endl;
    bool invalidSelection{true};
    int selection{0};
    while(invalidSelection)
    {
        for(int i{1};i<quizz_theme::END;i++)
        {
            cout << i << " " << static_cast<quizz_theme>(i) << endl;
        }
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

    return selection;
}

int main()
{
    cout << "Welcome to a little quizz game" << endl;
    int selection{menu()};
  
    QuizzSelection currentSession{init(selection)};

    switch (currentSession.first)
    {
        case session::TEST:
        {
            test_mode(currentSession.second);
            break;
        }
        case session::TRAINING:
        {
            training_mode(currentSession.second);
            break;
        }
        default:
            break;
        }
    return 0;
}