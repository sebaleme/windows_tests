/* *****************************************************************************
##
# @file        state_init.hpp
# @brief       init class for the state machine
# @copyright   MIT license
# ****************************************************************************/

#ifndef STATE_INIT_HPP
#define STATE_INIT_HPP

#include "state_base.hpp"
class Cstate_init : public Cstate
{
    public:
    // initialize state class
    Cstate_init();

    // Copy constructor to fill the state_list map
    Cstate_init(const Cstate_init& copy);

    // GCC requires a destructor
    ~Cstate_init()
    {};
    
    // run the state machine
    status compute_state(const active_event_list f_active_events,
                            state_list& f_target_state) override;

    private:
};

#endif //STATE_INIT_HPP