// Type your code here, or load an example.
#include <iostream>

using namespace std;
class CData
{
    public:
    CData(int f_machine, int f_maison):
        m_machine{f_machine},
        m_maison{f_maison}
    {
    }
    int m_machine;
    int m_maison;
};

CData createCData(int f_machine, int f_maison)
{
    CData temp(f_machine, f_maison);
    return temp;
}

template<typename T>
class CMySharedPointer
{
public:
    // constructor
    CMySharedPointer(const T& f_value)
    {
        m_valuePointer = new T(f_value);
        m_counterPointer = new int(1);
        m_name = "pointer" + to_string(*m_counterPointer);
        cout << m_name << " created and containing value " << m_valuePointer->m_maison
                << " and " << m_valuePointer->m_machine << endl; 
    };

    // copy constructor
    CMySharedPointer(CMySharedPointer& f_sp):
        m_counterPointer{f_sp.m_counterPointer},
        m_valuePointer{f_sp.m_valuePointer}
    {
        (*m_counterPointer)++;
        m_name = "pointer" + to_string(*m_counterPointer);
        cout << m_name << " copied, counter equals " << *m_counterPointer << endl; 
    }

    // move constructor
    CMySharedPointer(T&& f_object):
        m_valuePointer{&f_object}
    {
        // Since f_object is an rvalue, no object will be created, only the ownership will be taken
        m_valuePointer = new CData(f_object); 
        m_counterPointer = new int(1);
        cout << m_name << " moved and counter equals " << *m_counterPointer << endl; 
    }

    // destructor
    ~CMySharedPointer()
    {
        (*m_counterPointer)--;
        cout << m_name << " deleted, counter equals " << *m_counterPointer << endl; 
        if(*m_counterPointer < 1)
        {
            delete m_valuePointer;
            delete m_counterPointer;
            cout << "Last shared pointer instance removed" << endl; 
        }
    };

    T& operator* ()
    {
        return *m_valuePointer;
    }

    T* operator->()
    {
        return m_valuePointer;
    }
private:
    int* m_counterPointer;
    T*  m_valuePointer;
    string m_name;
};

int main(void)
{
    CMySharedPointer<CData>* spPtr = nullptr;

    {
    CData number{1534236469, 555};
   // CMySharedPointer<CData> sp(number);

    {
        //CMySharedPointer<CData> sp2(sp);
    }

    //CMySharedPointer<CData> sp3(sp);
    //cout << "machine: " << sp->m_machine << endl;
    //CMySharedPointer<CData> sp4(sp);
    //cout << "value stored at position: " << &sp << endl;

    //CMySharedPointer<CData> spExt(CData(25,35));
    //CMySharedPointer<CData> spExt2(createCData(25,35));
    //CMySharedPointer<CData> spExt3(move(number));
    spPtr = new CMySharedPointer<CData>(move(number));
    cout << number.m_maison << endl;
    {
    //spPtr = new CMySharedPointer<CData>(CData(1,2));
    }
    //delete spPtr;
    }
    cout << (*spPtr)->m_maison << endl;
}


