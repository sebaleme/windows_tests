/* *****************************************************************************
##
# @file        linked_list.cpp
# @brief       https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
# @copyright   MIT license
# ****************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};

    ~Node() {cout << "node " << key << " destroyed" << endl;};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
// Sad that we cannot use smart pointer, can t add memory header at top of the file
// LRU least recently used
class LRUCache : public Cache
{
    public:
    LRUCache(int f_capacity)
    {
        cp = f_capacity;
        m_currentSize = 0;
        head = nullptr;
        tail = nullptr;
    }

    int getSize() {return m_currentSize;}

    int countNodes() 
    {
        int result{0};
        if(m_currentSize>0)
        {
            Node* pointer{head};
            while(pointer != nullptr)
            {
                result++;
                pointer = pointer->next;
            }
        }
        return result;
    }

    void set(int f_key, int f_value) override
    {
        // empty list is a different case
        if(m_currentSize == 0)
        {
            Node* nodeP{new Node(f_key,f_value)};
            tail = nodeP;
            head = nodeP;
            mp[f_key] = nodeP;
            m_currentSize = 1;
        }
        else {
            // Check if entry exists
            Node* nodeP{mp[f_key]};
            if(nodeP == nullptr)
            {
                // Entry does not exist yet, add it
                if(m_currentSize<cp)
                {
                    Node* newNodeP{new Node(nullptr,head,f_key,f_value)};
                    head->prev = newNodeP; // previous first node is now second
                    head = newNodeP;
                    mp[f_key] = newNodeP;
                    m_currentSize++;
                }
                else // List full, remove last element and add a new one
                {
                    // Remove last element
                    mp[tail->key] = nullptr;
                    Node* lastElement{tail};
                    lastElement->prev->next = nullptr;
                    tail = tail->prev;
                    delete lastElement;
                    // add new one
                    Node* newNodeP{new Node(nullptr,head,f_key,f_value)};
                    head->prev = newNodeP; // previous first node is now second
                    head = newNodeP;
                    mp[f_key] = newNodeP;
                }
            }
            else // Move entry to top of the list
            {
                nodeP->value = f_value;
                // Nothing else to do if entry was already the first element
                if(head != nodeP)
                {
                    // special case if entry was the last element
                    if(tail == nodeP)
                    {
                        // previous element becomes new tail
                        nodeP->prev->next = nullptr;
                        tail = nodeP->prev;
                    }
                    else {
                        // link previous with next
                        nodeP->prev->next = nodeP->next;
                        nodeP->next->prev = nodeP->prev;
                    }
                    // First node is now second
                    head->prev = nodeP;
                    // Update current node
                    nodeP->prev = nullptr;
                    nodeP->next = head;
                    // Current node is the new head
                    head = nodeP;
                }
            }
        }
    }

    int get(int f_key) override
    {
        int returnValue{-1};
        // If cache size not empty, look for given key
        if((cp > 0)&&(m_currentSize >0))
        {
            Node* nodeP{mp[f_key]};
            if(nodeP != nullptr)
            {
                returnValue = nodeP->value;
            }
        }
        return returnValue;
    }

    private:
    int m_currentSize;
};

int main() {
    int n, capacity,i;
    //ifstream inputs;
    std::fstream inputs("C:\\Users\\sebal\\Documents\\repos\\windows_tests\\infrastructure\\exercices_diverse\\inputs\\linked_list.txt", std::ios_base::in);
    //inputs.open("linked_list.txt");
    inputs >> n >> capacity;
    int line{1};
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command;
        inputs >> command;
        if(command == "get") {
            int key;
            inputs >> key;
            line++;
            cout << "line " << line << ", " << l.getSize() << " nodes, (check: " << l.countNodes() << ") GET " << key << " " << l.get(key) << endl;
        }
        else if(command == "set") {
            int key, value;
            inputs >> key >> value;
            line++;
            l.set(key,value);
            //cout << "line " << line << ", " << l.getSize() << " nodes, (check: " << l.countNodes() << ") SET " << key << endl;
        }
    }
   return 0;
}