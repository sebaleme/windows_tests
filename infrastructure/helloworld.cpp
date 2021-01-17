/* *****************************************************************************
##
# @file        helloworld.cpp
# @brief       main method
# @copyright   MIT license
# ****************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "state_machine/include/state_machine.hpp"
#include "state_machine/include/events.hpp"

using namespace std;

int main()
{
    Cstate_machine sm;
    
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    for (std::uint32_t i = 0U; i < 10U; i++)
    {
        cout << "run " << i << endl;
        if(i == 3) 
        {
            sm.update_events(event_list::init_ended);
        }
        if(i == 6) 
        {
            sm.update_events(event_list::run_ended);
        }
        sm.run();
    }
}
