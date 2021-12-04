/* *****************************************************************************
##
# @file        list_add_number.cpp
# @brief       leetcode exercices implementation
# @copyright   MIT license
# ****************************************************************************/

// https://leetcode.com/problems/add-two-numbers/submissions/


#include <regex>
#include <iostream>
#include <string>
#include <map>

using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // Carry flag for single digit
        int carry = 0;
         
        // check inputs
        if(l1 == nullptr)
        {
            return l2;
        }
        if(l2 == nullptr)
        {
            return l1;
        }
        
        // Prepare output
        ListNode* result{new ListNode()};
        
        // Check which list is longer, l1 has to be the longest
        int counterL1 = 1;
        int counterL2 = 1;
        ListNode* temp = l1;
        while(temp->next)
        {
            temp = temp->next;
            counterL1++;
        }
        
        temp = l2;
        while(temp->next)
        {
            temp = temp->next;
            counterL2++;
        }
        cout << "Size of both list: " << counterL1 << " and " << counterL2 << endl;

        if(counterL2 > counterL1)
        {
            cout << "swaping " << endl;
            swap(l1,l2);
        }
        
        result->val = l1->val + l2->val;
        // Attach to the not empty chain
        result->next = l1->next ? l1->next : l2->next;
        
        if(result->val > 9)
        {
            result->val = result->val - 10;
            carry = 1;
        }
        
        // Abort condition l1
        while(l1->next)
        {
            // Get next l1 node
            l1 = l1->next;
            
            // Update l2
            if(l2->next != nullptr)
            { 
                l2 = l2->next;
            }
            else
            {
                l2->val = 0;
            }
            
            //Update output value
            l1->val += l2->val + carry;
            
            // Only single digit value in node
            if(l1->val > 9)
            {
                l1->val = l1->val - 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
    
        // Continue incrementing if l2 not empty
        if(l2->next)
        {
            cout << "looping l2 " << endl;
            // Next node is l2, update l1
            l1 = l2->next;
            l2 = l2->next;
            l1->val += carry;
            
            // Only single digit value in node
            if(l1->val > 9)
            {
                l1->val = l1->val - 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            if(l1->next != nullptr)
            {
                while(l1->next)
                {
                    l1 = l1->next;
                    l1->val += carry;
                    
                    // Only single digit value in node
                    if(l1->val > 9)
                    {
                        l1->val = l1->val - 10;
                        carry = 1;
                    }
                    else
                    {
                        carry = 0;
                    }
                }  
            }
        }

        // Create new node at the end if latest result is higher than 9
        if(carry == 1)
        {
            ListNode* carryNode{new ListNode(1)};
            // Special case if both inputs are of size 1
            if(result->next)
            {
                l1->next = carryNode; 
            }
            else
            {
                result->next = carryNode; 
            }

        }
        return std::move(result);
    }
};

void printList(ListNode* f_list)
{
    ListNode* temp = f_list; 
    cout << "result: ";
    while(temp->next)
    {
        cout << temp->val << ", ";
        temp = temp->next;
        if(temp->next == nullptr)
        {
            cout << temp->val;
        }
    }
    cout << endl;
}

ListNode* createList(string f_numbers)
{
    ListNode* previousList{nullptr};
    vector<ListNode*>* objptr = new vector<ListNode*>();

    if(f_numbers.size() > 0)
    {
        bool last = true;
        for(int i = static_cast<int>(f_numbers.size()-1); i>-1; i--)
        {
            // Read value from input string
            int value = (int)f_numbers[i] - 48;

            // Last object is constructed first
            if(last)
            {
                objptr->push_back(new ListNode(value));
                last= false;
            }
            else
            {
                objptr->push_back(new ListNode(value, previousList));
            }
            previousList = objptr->back();
        }
    }

    if(!objptr->empty())
    {
        previousList = (*objptr)[f_numbers.size()-1];
    }
    return previousList;
}

int main()
{
    ListNode* l1{createList("9999999")};
    ListNode* l2{createList("9999")};

    printList(l1);
    printList(l2);

    Solution soluce;
    ListNode* result = soluce.addTwoNumbers(l1,l2);

    printList(result);
}
