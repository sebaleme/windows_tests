/* *****************************************************************************
##
# @file        smart_pointer.hpp
# @brief       reimplementing stuff from the standard library
# @copyright   MIT license
# ****************************************************************************/

#include <vector>
//https://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c

#ifndef SMART_POINTER_INCLUDE
#define SMART_POINTER_INCLUDE

///@brief: shared_pointer
// Basic feature: class with a pointer to the shared object. Object is destroyed when class
// is destroyed.
class shared_pointer_lsm
{
    shared_pointer_lsm(Cstate_machine* pValue): m_pointer{pValue}
    {
        
    };

    ~shared_pointer_lsm()
    {
        delete m_pointer;
    };

    //private:

    Cstate_machine* m_pointer;
    std::vector<Cstate_machine*> m_instances;

};

#endif  //SMART_POINTER_INCLUDE
