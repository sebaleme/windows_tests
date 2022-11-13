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

using namespace std;

static constexpr int NUMBER_OF_PEOPLE = 15;

// Using a vector of pair during runtime, but arrays to store the data
std::vector<pair<string, int>> s_people;
std::array<string, NUMBER_OF_PEOPLE> s_peopleArray
{{
    "ned", "kathleen", "robb", "Sansa", "bran", "arya", "rickon", "jon", // GT stark
    "robert", "stannis", "renly", // GT baratheon
    "tywin", "jaime", "cersei", "joeffrey"  // GT lannister
}};

std::array<string, 3> s_house =
{{
    "stark", "baratheon", "lannister"
}};

// Results
std::array<int, NUMBER_OF_PEOPLE> s_houseGT =
{{
    0, 0, 0,0,0,0,0,0,1,1,1,2,2,2,2
}};

void init()
{
    // Initialize random function
    srand(static_cast<uint32_t>(time(NULL)));

    // Initialize input vector
    for(int i{0}; i<NUMBER_OF_PEOPLE; i++)
    {
        s_people.push_back(make_pair(s_peopleArray[i],s_houseGT[i]));
    }
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
    init();
    int indexPeople{rand() % 15};
    bool wannaPlay{true};
    string answer;
    int score{0}, iteration{0};

    while (wannaPlay)
    {
        iteration++;

        // Interaction with user
        cout << "from which house is " << s_people[indexPeople].first << "?" << endl;
        cin >> answer;

        // Process user response
        std::array<string, 3>::iterator houseIt;
        houseIt = find(s_house.begin(), s_house.end(), answer);
        if(houseIt != s_house.end())
        {
            if(*houseIt == s_house[s_people[indexPeople].second])
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
        s_people.erase(s_people.begin() + indexPeople);
        indexPeople = rand() % (15 - iteration);

        cout << endl << "play again ? y/n" << endl;
        cin >> answer;
        wannaPlay = (answer == "y");
    }

    // Give result
    cout << "================================" << endl;
    float scoreFloat = (float)score / (float) iteration;
    cout << "you got " << score << "/" << iteration << comment(scoreFloat) << endl;
    return 0;
}