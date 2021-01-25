/* *****************************************************************************
##
# @file        smart_pointer.hpp
# @brief       reimplementing stuff from the standard library
# @copyright   MIT license
# ****************************************************************************/

#include <vector>
// https://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c

#ifndef SMART_POINTER_INCLUDE
    #define SMART_POINTER_INCLUDE

/// @brief: shared_pointer
// Basic feature: class with a pointer to the shared object. Object is destroyed when class
// is destroyed.
template < typename T > 
class CSharedPointerLsm
{
public:
    // constructor
    CSharedPointerLsm(T *pValue) :
        m_pointer{pValue},
        m_count{1}
    {
        std::cout << "First pointer instance " << std::endl;
    };

    //Copy constructor
    CSharedPointerLsm(const CSharedPointerLsm& SP2) :
        m_pointer{SP2.m_pointer},
        m_count{SP2.m_count}
    {
        //m_instances.push_back(SP2);
        std::cout << "This is the " << m_count << " pointer instance " << std::endl;
    };

    // destructor
    ~CSharedPointerLsm()
    {
        if(--m_count == 0)
        {
            delete m_pointer;
            std::cout << "Object has been removed: " << std::endl;
        }
    };

    //Add classic pointer operators
    T& operator* ()
    {
        return *m_pointer;
    }

    T* operator-> ()
    {    
        return m_pointer;
    }
private:
    T *m_pointer;
    uint32_t m_count;
    std::vector<CSharedPointerLsm *> m_instances;
};

#endif  // SMART_POINTER_INCLUDE
