/* *****************************************************************************
##
# @file        state_machine.cpp
# @brief       state decision
# @copyright   MIT license
# ****************************************************************************/

#include "../include/state_machine.hpp"
#include "../include/state_init.hpp"
#include "../include/state_run.hpp"

std::ostream& operator<<(std::ostream& f_out, const event_list f_value)
{
    const char* s = 0;
    switch(f_value)
    {
        case(event_list::init_ongoing): s = "init_ongoing"; break;
        case(event_list::init_ended): s = "init_ended"; break;
        case(event_list::run_ended): s = "run_ended"; break;
    }
    return f_out << s;
}

std::ostream& operator<<(std::ostream& f_out, const state_list f_value)
{
    const char* s = 0;
    switch(f_value)
    {
        case(state_list::undefined): s = "undefined"; break;
        case(state_list::init): s = "init"; break;
        case(state_list::run): s = "run"; break;
        case(state_list::post_run): s = "end"; break;
    }
    return f_out << s;
}

Cstate_machine::Cstate_machine()
{
    m_available_states.insert(std::pair<state_list, std::shared_ptr<Cstate>>(state_list::init, std::make_shared<Cstate_init>()));
    m_available_states.insert(std::pair<state_list, std::shared_ptr<Cstate>>(state_list::run, std::make_shared<Cstate_run>()));
    m_active_events.insert(std::pair<event_list,bool>(event_list::init_ongoing, true));
    m_active_events.insert(std::pair<event_list,bool>(event_list::init_ended, false));
    m_active_events.insert(std::pair<event_list,bool>(event_list::run_ended, false));
    m_currentState = m_available_states[state_list::init];
    m_nextState = state_list::init;
}

void Cstate_machine::update_events(event_list f_new_event)
{
    std::map<event_list, bool>::iterator it = m_active_events.find(f_new_event);
    if (it != m_active_events.end())
    {
        it->second = true;
    }
    std::cout << " event " << f_new_event << " is now set to " << it->second << std::endl;
}

void Cstate_machine::update_state()
{
    if ( m_available_states.find(m_nextState) == m_available_states.end() )
    {
        std::cout << " requested state is not available: " << m_nextState << std::endl;
    }
    else
    {
        m_currentState = m_available_states[m_nextState];
        std::cout << " state changed to " << m_nextState << std::endl;
    }
}

void Cstate_machine::run()
{
    std::cout << " entering SM" << std::endl;

    // state computation
    status state = m_currentState->compute_state(m_active_events, m_nextState);

    // state update
    if (state == status::change_state_req)
    {
        update_state();
    }
}


