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

#ifndef STATE_MACHINE_INCLUDE
#define STATE_MACHINE_INCLUDE

class Cstate_machine
{
    public:
    // constructor: initialize the states and the state list
    Cstate_machine();
    
    // Method: run the state machine
    void run();

    //update events
    void update_events(event_list f_new_event);

    private:
    // update state
    void update_state();

    // Pointer to current state
    std::shared_ptr<Cstate> m_currentState;

    // next state
    state_list m_nextState;

    // available states are stored in this map
    std::map<state_list, std::shared_ptr<Cstate>> m_available_states;

    // list of events with their status
    active_event_list m_active_events;
};

#endif //STATE_MACHINE_INCLUDE
