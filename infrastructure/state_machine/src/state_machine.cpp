/* *****************************************************************************
##
# @file        state_machine.cpp
# @brief       state decision
# @copyright   MIT license
# ****************************************************************************/

#include "../include/state_machine.hpp"
#include "../include/state_init.hpp"
#include "../include/state_run.hpp"

Cstate_machine::Cstate_machine()
{
    Cstate_init init_object;
    Cstate_run run_object;
    m_available_states.insert(std::pair<state_list, Cstate_init>(state_list::state_init, init_object));
    m_available_states.insert(std::pair<state_list, Cstate_run>(state_list::state_run, run_object));
    m_currentState = &m_available_states[state_list::state_init];
}

void Cstate_machine::update_events()
{

}

Cstate& Cstate_machine::find_state(state_list f_state_ID)
{
    for(Cstate state : m_available_states)
    {
        
    }
}

void Cstate_machine::run()
{
    // event manager
    update_events();

    // state computation
    state_list state_ID = m_currentState->compute_state(m_active_events);

    // state update
    m_currentState = &m_available_states[state_ID];
}


