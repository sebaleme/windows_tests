/* *****************************************************************************
##
# @file        smart_pointer.hpp
# @brief       reimplementing stuff from the standard library
# @copyright   MIT license
# ****************************************************************************/

#include <vector>
//https://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c

// shared_pointer
template<type T>
class shared_pointer_lsm
{
    shared_pointer_lsm();

    private:

    T* m_pointer;
    std::vector<> m_instances;

}