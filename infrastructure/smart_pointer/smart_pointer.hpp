/* *****************************************************************************
##
# @file        smart_pointer.hpp
# @brief       reimplementing stuff from the standard library
# @copyright   MIT license
# ****************************************************************************/

// https://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c

#ifndef SMART_POINTER_INCLUDE
#define SMART_POINTER_INCLUDE

/// @brief: reference counter
// Basic feature: class counting the shared pointer instances pointing to the current object
class RC
{
public:

    // constructor
    RC() :
        m_count{0U}
    {
    };

    void addRef()
    {
        m_count++;
    };

    int release()
    {
        return --m_count;
    };

    int get()
    {
        return m_count;
    };
private:
    uint32_t m_count;
};

/// @brief: shared_pointer
// Basic feature: class with a pointer to the shared object. Object is destroyed when class
// is destroyed.
template <typename T>
class CSharedPointerLsm
{
public:

    // constructor
    CSharedPointerLsm(T *pValue) :
        m_pointer{pValue},
        m_name{"pointer_1"}
    {
        // Create counter, initialize it to 1
        m_refCounter = new RC;
        m_refCounter->addRef();
        std::cout << "Pointer instance: " << m_name << " has been created in position " << m_refCounter->get() <<
            std::endl;
    };

    // Copy constructor
    CSharedPointerLsm(const CSharedPointerLsm& SP2) :
        m_pointer{SP2.m_pointer},
        m_refCounter{SP2.m_refCounter},
        m_name{"pointer_" + std::to_string(SP2.m_refCounter->get() + 1U)}
    {
        // Update counter value
        m_refCounter->addRef();
        std::cout << "Pointer instance: " << m_name << " has been created in position " << m_refCounter->get() <<
            std::endl;
    };

    // destructor
    ~CSharedPointerLsm()
    {
        // Update counter value
        std::cout << "Pointer " << m_name << " has been removed, there are still " << m_refCounter->release() <<
            " left " << std::endl;

        if (m_refCounter->get() == 0)
        {
            delete m_pointer;
            std::cout << "Object has been removed" << std::endl;
        }
    };

    // Add classic pointer operators
    T& operator*()
    {
        return *m_pointer;
    }

    T *operator->()
    {
        return m_pointer;
    }
private:
    T *m_pointer;
    RC *m_refCounter;
    std::string m_name;
};

#endif  // SMART_POINTER_INCLUDE
