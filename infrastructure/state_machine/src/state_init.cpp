/* *****************************************************************************
##
# @file        state_init.cpp
# @brief       state decision
# @copyright   MIT license
# ****************************************************************************/

#include "../include/state_init.hpp"
#include "../include/events.hpp"

Cstate_init::Cstate_init():
    Cstate{state_list::state_init}
{
};

Cstate_init::Cstate_init(const Cstate_init& copy):
    Cstate{state_list::state_init}
{};

state_list Cstate_init::compute_state(active_event_list f_active_events)
{
    state_list state_change_result = state_list::no_change_state;
    std::cout << " Init ongoing" << std::endl;
    if(true == f_active_events[event_list::init_ended])
    {
        state_change_result = state_list::state_run;
    }

    return state_change_result;
}



