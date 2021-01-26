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
#include "smart_pointer/smart_pointer.hpp"

using namespace std;

int main()
{
    // We don t want to have the instance in stack, so let create it in heap
    CSharedPointerLsm<Cstate_machine> pSm(new Cstate_machine());

    // We create a second and third pointer of the SM to test the shared pointer
    CSharedPointerLsm<Cstate_machine> pSm2(pSm);
    {
        CSharedPointerLsm<Cstate_machine> pSm3(pSm2);
    }

    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    for (std::uint32_t i = 0U; i < 10U; i++)
    {
        cout << "run " << i << endl;

        if (i == 3)
        {
            pSm->update_events(event_list::init_ended);
        }

        if (i == 6)
        {
            pSm->update_events(event_list::run_ended);
        }
        pSm->run();
    }
}
