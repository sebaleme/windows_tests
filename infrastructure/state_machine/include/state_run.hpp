/* *****************************************************************************
##
# @file        state_run.hpp
# @brief       run class for the state machine
# @copyright   MIT license
# ****************************************************************************/

#ifndef STATE_RUN_HPP
#define STATE_RUN_HPP

#include "state_base.hpp"

class Cstate_run : public Cstate
{
    public:
    // initialize state class
    Cstate_run();

    // Copy constructor to fill the state_list map
    Cstate_run(const Cstate_run& copy);

    // GCC requires a destructor
    ~Cstate_run()
    {};
    
    // run the state machine
    status compute_state(const active_event_list f_active_events,
                        state_list& f_target_state) override;

    private:
};

#endif //STATE_RUN_HPP