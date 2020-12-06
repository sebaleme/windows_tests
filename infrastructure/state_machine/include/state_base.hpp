/* *****************************************************************************
##
# @file        state_base.hpp
# @brief       abstract class for state classes
# @copyright   MIT license
# ****************************************************************************/

#ifndef STATE_BASE_HPP
#define STATE_BASE_HPP

#include "events.hpp"

enum class state_list
{
    no_change_state =0,
    state_init,
    state_run,    
    state_end  
};

class Cstate
{
    public:
    // initialize state class
    Cstate(state_list f_class_name)
    {
        state_ID = f_class_name;
    };

    // the map requires this constuctor
    Cstate()
    {
        state_ID = state_list::no_change_state;
    };

    // Copy constructor to fill the state_list map
    Cstate(const Cstate& copy)
    {
    };

    // GCC requires a destructor
    ~Cstate()
    {
    };
    
    // run the state machine
    virtual state_list compute_state(active_event_list f_active_events) =0;

    private:
    // class name
    state_list state_ID;
};

#endif // STATE_BASE_HPP