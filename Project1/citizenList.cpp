#pragma once
#include <iostream>
#include "citizenList.h"
#include "citizen.h"
using namespace std;

namespace proj {
   citizenList::citizenList():head(nullptr),tail(nullptr)
    {
     
       cout << "const" << endl;
    }
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

   void citizenList::addNodeToTail(citizen* input)
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
   void citizenList::addNodeToHead(citizen* input)
   {
       node* tmp = new node;
       tmp->value = input;
       tmp->prev = nullptr;
       if (head == nullptr)
       {
           head = tmp;
           tail = tmp;
           head->next = nullptr;
       }
       else
       {
           head->prev = tmp;
           tmp->next = head;
           head=tmp;
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
   node* citizenList::getHead()
   {
       
       return head;
   }

   void citizenList::operator=(const citizenList& input)
   {
       head = input.head;
       
       tail = input.tail;
   }

   
   void citizenList::printList()
   {
       node* temp = head;
       while (temp != nullptr)
       {
           temp->value->printCitizen();
           temp = temp->next;
       }
   }
}
