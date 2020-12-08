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
    m_available_states.insert(std::pair<state_list, std::shared_ptr<Cstate>>(state_list::state_init, std::make_shared<Cstate_init>()));
    m_available_states.insert(std::pair<state_list, std::shared_ptr<Cstate>>(state_list::state_run, std::make_shared<Cstate_run>()));
    m_currentState = m_available_states[state_list::state_init];
}

void Cstate_machine::update_events()
{

}

void Cstate_machine::run()
{
    // event manager
    update_events();

    // state computation
    state_list state_ID = m_currentState->compute_state(m_active_events);

    // state update
    m_currentState = m_available_states[state_ID];
}


