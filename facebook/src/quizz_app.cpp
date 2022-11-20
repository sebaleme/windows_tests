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

void init(themes selection)
{
    // Initialize random function
    srand(static_cast<uint32_t>(time(NULL)));

    init_input_data(selection);
}

themes theme_menu()
{
    cout << "please select a theme" << endl;
    bool invalidSelection{true};
    int selection{0};
    while(invalidSelection)
    {
        cout << "=========================================" << endl;
        for(int i{0};i<themes::END;i++)
        {
            cout << i << " " << static_cast<themes>(i) << endl;
        }
        cout << "=========================================" << endl;
        cin >> selection;
        if(selection >= 0 && selection <= themes::END)
        {
            invalidSelection = false;
        }
        else
        {
            cout << "enter a valid selection" << endl;
        }
    }
    return static_cast<themes>(selection);
}

quizz_mode mode_menu()
{
    cout << "please select a mode" << endl;
    bool invalidSelection{true};
    int selection{0};
    while(invalidSelection)
    {
        cout << "=========================================" << endl;
        for(int i{0};i<quizz_mode::END;i++)
        {
            cout << i << " " << static_cast<quizz_mode>(i) << endl;
        }
        cout << "=========================================" << endl;
        cin >> selection;
        if(selection >= 0 && selection <= quizz_mode::END)
        {
            invalidSelection = false;
        }
        else
        {
            cout << "enter a valid selection" << endl;
        }
    }
    return static_cast<quizz_mode>(selection);
}

int main()
{
    cout << "Welcome to a little quizz game" << endl;
    themes theme_selection{themes::Invalid};
    while (theme_selection == themes::Invalid)
    {
        theme_selection = theme_menu();
    }
    
    quizz_mode mode_selection{quizz_mode::QUIZZ_RULES};
    while (mode_selection == quizz_mode::QUIZZ_RULES)
    {
        mode_selection = mode_menu();
        if(mode_selection==quizz_mode::QUIZZ_RULES)
        {
            display_rules();
        }
    }

    if(mode_selection != quizz_mode::EXIT)
    {
        init(theme_selection);
        CCurrentSession currentSession{theme_selection};

        switch (mode_selection)
        {
            case quizz_mode::TEST:
            {
                test_mode(currentSession);
                break;
            }
            case quizz_mode::TRAINING:
            {
                training_mode(theme_selection);
                break;
            }
            case quizz_mode::BEST_SCORES:
            {
                currentSession.displayScores();
                break;
            }
            default:
                break;
        }
    }
    return 0;
}