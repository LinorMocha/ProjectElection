#pragma once
#include <iostream>
#include"utils.h"
#include "citizenList.h"
#include "citizen.h"


using namespace std;

namespace proj {
   
    citizenList::citizenList():head(nullptr),tail(nullptr), listSize(0) {}

    citizenList::citizenList(const citizenList& input) : citizenList()
    {
        listSize = input.listSize;
        node* index = input.head;
        while (index != nullptr)
        {
            addNodeToTail(index->value);
            index = index->next;
        }

    }
    
    citizenList::~citizenList()
    {
        node* current = head;
        node* next;
        while (current != nullptr)
        {
            next = current->next;
            delete current->value;

            current = next;
        }

    }

    void citizenList::addNodeToTail(citizen* input)
    {
        listSize++;
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
       listSize++;
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
  

    citizen* citizenList::getCitizenById(int _id)const
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
   
    node* citizenList::getHead()const {return head;}

    int citizenList::getListSize() const
    {
        return listSize;
    }

   void citizenList::operator=(const citizenList& input)
   {
       listSize = input.listSize;
       head = input.head;
       tail = input.tail;
   }

   void citizenList::printList(int numOfNodeToPrint)
   {
       node* temp = head;
       int counter = 1;
       while (temp != nullptr && counter <= numOfNodeToPrint)
       {
           cout<<*temp->value;
           temp = temp->next;
           counter++;
       }
   }
   void citizenList::save(ostream& out) const
   {
       out.write(rcastcc(&listSize), sizeof(listSize));
       node* temp = head;
       while (temp != nullptr)
       {
           temp->value->save(out);
           temp = temp->next;
       }
       
   }
   

   void citizenList::printList()
   {
       if (head == nullptr)
           return;
       else {
           node* temp = head;
           while (temp != nullptr) 
           {
               cout<<*temp->value;
               temp = temp->next;
           }
       }
   }
}
