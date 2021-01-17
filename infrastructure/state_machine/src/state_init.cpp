/* *****************************************************************************
##
# @file        state_init.cpp
# @brief       state decision
# @copyright   MIT license
# ****************************************************************************/

#include "../include/state_init.hpp"
#include "../include/events.hpp"

Cstate_init::Cstate_init():
    Cstate{state_list::init}
{
};

Cstate_init::Cstate_init(const Cstate_init& copy):
    Cstate{state_list::init}
{};

status Cstate_init::compute_state(active_event_list f_active_events,
                                state_list& f_target_state)
{
    status state_change_result = status::no_change_state;

    std::cout << " Init ongoing" << std::endl;
    if(true == f_active_events[event_list::init_ended])
    {
        state_change_result = status::change_state_req;
        f_target_state = state_list::run;
    }

    return state_change_result;
}



