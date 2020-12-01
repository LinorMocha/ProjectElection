#pragma once
#include <iostream>
#include "citizenList.h"
#include "citizen.h"
using namespace std;

namespace proj {
   citizenList::citizenList():head(nullptr),tail(nullptr)
    {
       
        cout << "cons" << endl;
    }jkk
   citizenList::~citizenList()
    {
            node* current = head;
            node* next;
            while (current != nullptr) 
            {
                next = current->next;
                delete current;
                current = next;
            }
            cout << "delete" << endl;
    }

   void citizenList::add_node(citizen* input)
    {
        node* tmp = new node;
        tmp->value = input;
        tmp->next = nullptr;
        
        if (head == nullptr)
        {
            head = tmp;
            tail = tmp;
            tmp->prev = nullptr;
        }
        else
        {
            tmp->prev = tail;
            tail->next = tmp;
            tail = tail->next;
            
        }
    }

   citizen* citizenList::getItem(int _id)
   {
       node* current = head;

       while (current != nullptr)
       {
           if (current->value->getId() == _id)
               return current->value;
           current = current->next;
       }
       return nullptr;
   }


}
