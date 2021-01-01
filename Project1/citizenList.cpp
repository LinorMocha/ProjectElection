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

   void citizenList::printList(int numOfNodeToPrint) const 
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

   bool citizenList::save(ostream& out) const
   {
       if (!out)
       {
           return false;
       }
       out.write(rcastcc(&listSize), sizeof(listSize));
       node* temp = head;
       while (temp != nullptr)
       {
           if (!temp->value->save(out))
               return false;
           temp = temp->next;
       }
       return(out.good());
   }


   bool citizenList::load(istream& in, const StateArray& currStateArray)
   {
       if (!in)
       {
           return false; 
       }
       int list_size;
       in.read(rcastc(&list_size), sizeof(list_size));
       if (!in.good())
       {
           return false;
       }
       int tempStateId;
       for (int i = 0; i < list_size; i++)
       {
           in.read(rcastc(&tempStateId), sizeof(int));
           citizen* cit = new citizen(in, currStateArray.getStateById(tempStateId));
           addNodeToTail(cit);
       }
       return(in.good());

   }

   bool citizenList::saveById(ostream& out) const
   {
       if (!out)
       {
           return false;
       }
       out.write(rcastcc(&listSize), sizeof(listSize));
       node* temp = head;
       int tempCitizenId;
       while (temp != nullptr)
       {
           tempCitizenId = temp->value->getId();
           out.write(rcastcc(&tempCitizenId), sizeof(int));
           temp = temp->next;
       }
       return(out.good());
   }

   bool citizenList::loadById(istream& in, const citizenList& currList)
   {
       if (!in)
       {
           return false;
       }
       int size_list;
       in.read(rcastc(&size_list), sizeof(size_list));
       if (!in.good())
       {
           return false;
       }
       for (int i = 0; i < size_list; i++)
       {
           int citizenId;
           in.read(rcastc(&citizenId), sizeof(int));
           if (!in.good())
           {
               return false;
           }
           addNodeToTail(currList.getCitizenById(citizenId));
       }
       return (in.good());
   }


   void citizenList::printList()const 
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
