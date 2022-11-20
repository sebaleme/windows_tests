/* *****************************************************************************
##
# @file        quizz_app.cpp
# @brief       main method. This app implements basic games functionalities
# @copyright   MIT license
# ****************************************************************************/

#include <iostream>
#include <vector>
#include <array>
#include "../include/training_mode.hpp"
#include "../include/test_mode.hpp"

using namespace std;

void display_rules()
{
    cout << "Welcome in this small quizz application" << endl;
    cout << "You can either start a training session, which is not recorded and does not have a predetermined number of questions." << endl;
    cout << "Or you can start a test session, which contains 10 questions. The user gains 2 points for each correct question" << endl;
    cout << "You can call the help for a question if available. In this case, a correct answer yields only 1 point" << endl;
    cout << "The best results are recorded and ranked. A tie is resolved through the minimum elasped time" << endl;
    cout << "=========================================" << endl;
};

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
        cout << "=========================================" << endl;
        cout << "0 Quizz rules" << endl;
        for(int i{1};i<quizz_theme::END;i++)
        {
            cout << i << " " << static_cast<quizz_theme>(i) << endl;
        }
        cout << "5 Quit" << endl;
        cout << "=========================================" << endl;
        cin >> selection;
        if(selection >= 0 && selection <= quizz_theme::END)
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
    int selection{0};

    while (selection == 0)
    {
        selection = menu();
        if(selection==0)
        {
            display_rules();
        }
    }

    if(selection != 5)
    {
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
    }
    return 0;
}