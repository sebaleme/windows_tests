/* *****************************************************************************
##
# @file        state_run.cpp
# @brief       state decision
# @copyright   MIT license
# ****************************************************************************/

#include "../include/state_run.hpp"
#include "../include/events.hpp"

Cstate_run::Cstate_run():
    Cstate{state_list::state_run}
{
};

Cstate_run::Cstate_run(const Cstate_run& copy):
    Cstate{state_list::state_run}
{};

state_list Cstate_run::compute_state(active_event_list f_active_events)
{
    state_list state_change_result = state_list::no_change_state;

    if(true == f_active_events[event_list::run_ended])
    {
        //state_change_result = state_list::state_post_run;
    }

    return state_change_result;
}



