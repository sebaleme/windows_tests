/* *****************************************************************************
##
# @file        state_base.hpp
# @brief       abstract class for state classes
# @copyright   MIT license
# ****************************************************************************/

#ifndef STATE_BASE_HPP
#define STATE_BASE_HPP

#include "events.hpp"

enum class state_list : std::uint8_t
{
    undefined = 0,
    init,
    run,    
    post_run  
};

enum class status : std::uint8_t
{
    no_change_state =0,
    change_state_req
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
        state_ID = state_list::undefined;
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
    virtual status compute_state(const active_event_list f_active_events, 
                                state_list& f_target_state) =0;

    private:
    // class name
    state_list state_ID;
};

#endif // STATE_BASE_HPP