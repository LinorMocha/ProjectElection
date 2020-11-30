#pragma once
#include <iostream>
#include "representativeList.h"
#include "citizen.h"
using namespace std;

namespace proj {
    representativeList::representativeList()
    {
        head = nullptr;
        tail = nullptr;
    }
    representativeList::~representativeList()
    {
            node* current = head;
            node* next;
            while (current != nullptr) 
            {
                next = current->next;
                delete current;
                current = next;
            }
    }

   void representativeList::add_node(citizen newrepre)
    {
        node* tmp = new node;
        tmp->represent = &newrepre ;
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



}
