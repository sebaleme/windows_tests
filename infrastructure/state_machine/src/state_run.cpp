/* *****************************************************************************
##
# @file        state_run.cpp
# @brief       state decision
# @copyright   MIT license
# ****************************************************************************/

#include "../include/state_run.hpp"
#include "../include/events.hpp"

Cstate_run::Cstate_run():
    Cstate{state_list::run}
{
};

Cstate_run::Cstate_run(const Cstate_run& copy):
    Cstate{state_list::run}
{};

status Cstate_run::compute_state(active_event_list f_active_events,
                                state_list& f_target_state)
{
    status state_change_result = status::no_change_state;
    std::cout << " run ongoing" << std::endl;
    if(true == f_active_events[event_list::run_ended])
    {
        state_change_result = status::change_state_req;
        f_target_state = state_list::post_run;
    }

    return state_change_result;
}



