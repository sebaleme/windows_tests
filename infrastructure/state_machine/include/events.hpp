/* *****************************************************************************
##
# @file        events.hpp
# @brief       list of events
# @copyright   MIT license
# ****************************************************************************/

#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <map>

enum class event_list
{
    init_ongoing =0,
    init_ended,    
    run_ended  
};

typedef std::map<event_list, bool> active_event_list;

#endif // EVENTS_HPP
