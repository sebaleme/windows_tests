/* *****************************************************************************
##
# @file        state_machine.hpp
# @brief       state decision
# @copyright   MIT license
# ****************************************************************************/

#include <map>
#include "events.hpp"
#include "state_base.hpp"
#include <memory>

class Cstate_machine
{
    public:
    // constructor: initialize the states and the state list
    Cstate_machine();
    
    // Method: run the state machine
    void run();


    private:
    //update events
    void update_events();

    // Pointer to current state
    std::shared_ptr<Cstate> m_currentState;

    // available states are stored in this map
    std::map<state_list, std::shared_ptr<Cstate>> m_available_states;

    // list of events with their status
    active_event_list m_active_events;
};
