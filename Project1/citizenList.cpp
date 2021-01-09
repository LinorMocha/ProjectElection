//#pragma once
//#include <iostream>
//#include"utils.h"
//#include "citizenList.h"
//#include "citizen.h"
//
//
//using namespace std;
//
//namespace proj {
//
//  
//    citizenList::citizenList():head(nullptr),tail(nullptr), listSize(0) {}
//
//
//    //constractor - create citizens list
//    citizenList::citizenList(const citizenList& input) : citizenList()
//    {
//        listSize = input.listSize;
//        node* index = input.head;
//        while (index != nullptr)
//        {
//            addNodeToTail(index->value);
//            index = index->next;
//        }
//
//    }
//    //distractor - Deletes the list
//    citizenList::~citizenList()
//    {
//        node* current = head;
//        node* next;
//        while (current != nullptr) 
//        {
//            next = current->next;
//            delete current->value;
//
//            current = next;
//        }
//    }
//    //this function add node to the end of the list
//    void citizenList::addNodeToTail(citizen* input)
//    {
//        listSize++;
//        node* tmp = new node;
//        tmp->value = input;
//        tmp->next = nullptr;
//      
//        if (head == nullptr)
//        {
//            head = tmp;
//            tail = tmp;
//            tmp->prev = nullptr;
//        }
//        else
//        {
//            tmp->prev = tail;
//            tail->next = tmp;
//            tail = tail->next;
//        
//
//        }
//   }
//    //this function add node to the head of the list
//   void citizenList::addNodeToHead(citizen* input)
//   {
//       listSize++;
//       node* tmp = new node;
//       tmp->value = input;
//       tmp->prev = nullptr;
//       if (head == nullptr)
//       {
//           head = tmp;
//           tail = tmp;
//           head->next = nullptr;
//       }
//       else
//       {
//           head->prev = tmp;
//           tmp->next = head;
//           head=tmp;
//       }
//   }
//  
//   //this func returns pointer to citizen according to given ID number
//    citizen* citizenList::getCitizenById(int _id)const
//   {
//       node* current = head;
//
//       while (current != nullptr)
//       {
//           if (current->value->getId() == _id)
//               return current->value;
//           current = current->next;
//       }
//       return nullptr;
//   }
//   //this function returns the haed of the list
//    node* citizenList::getHead()const {return head;}
//    //this function returns the size of list
//    int citizenList::getListSize() const
//    {
//        return listSize;
//    }
//    //operator = copy the size of the list,  the head and the tail
//   void citizenList::operator=(const citizenList& input)
//   {
//       listSize = input.listSize;
//       head = input.head;
//       tail = input.tail;
//   }
//   //this function prints the list using operator<<
//   void citizenList::printList(int numOfNodeToPrint) const 
//   {
//       node* temp = head;
//       int counter = 1;
//       while (temp != nullptr && counter <= numOfNodeToPrint)
//       {
//           cout<<*temp->value;
//           temp = temp->next;
//           counter++;
//       }
//   }
//   //this funcion save the data list to file
//   bool citizenList::save(ostream& out) const
//   {
//       if (!out)//checks if the file works properly
//       {
//           return false;
//       }
//       out.write(rcastcc(&listSize), sizeof(listSize));
//       node* temp = head;
//       while (temp != nullptr)
//       {
//           if (!temp->value->save(out)) 
//               return false;
//           temp = temp->next;
//       }
//       return(out.good());
//   }
//
//   //this funcion load the data list from file
//   bool citizenList::load(istream& in, const StateArray& currStateArray)
//   {
//       if (!in)//checks if the file works properly
//       {
//           return false; 
//       }
//       int list_size;
//       in.read(rcastc(&list_size), sizeof(list_size));
//       if (!in.good())
//       {
//           return false;
//       }
//       int tempStateId;
//       for (int i = 0; i < list_size; i++)//Creates a list of citizens by reading citizens' ID numbers
//       {
//           in.read(rcastc(&tempStateId), sizeof(int));
//           citizen* cit = new citizen(in, currStateArray.getStateById(tempStateId)); //create curr citizen using ctor
//           addNodeToTail(cit);
//       }
//       return(in.good());
//
//   }
//   //this function saves the citizens' ID numbers
//   bool citizenList::saveById(ostream& out) const
//   {
//       if (!out)
//       {
//           return false;
//       }
//       out.write(rcastcc(&listSize), sizeof(listSize));
//       node* temp = head;
//       int tempCitizenId;
//       while (temp != nullptr)
//       {
//           tempCitizenId = temp->value->getId(); //get the id number of the curr citizen in the list
//           out.write(rcastcc(&tempCitizenId), sizeof(int));
//           temp = temp->next;
//       }
//       return(out.good());
//   }
//   //this function loads the citizen list according to the citizens' ID
//   bool citizenList::loadById(istream& in, const citizenList& currList)
//   {
//       if (!in)
//       {
//           return false;
//       }
//       int size_list;
//       in.read(rcastc(&size_list), sizeof(size_list));
//       if (!in.good())
//       {
//           return false;
//       }
//       for (int i = 0; i < size_list; i++)
//       {
//           int citizenId;
//           in.read(rcastc(&citizenId), sizeof(int));
//           if (!in.good())
//           {
//               return false;
//           }
//           addNodeToTail(currList.getCitizenById(citizenId));
//       }
//       return (in.good());
//   }
//
//   //this function prints the citizen list
//   void citizenList::printList()const 
//   {
//       if (head == nullptr)
//           return;
//       else {
//           node* temp = head;
//           while (temp != nullptr) 
//           {
//               cout<<*temp->value;
//               temp = temp->next;
//           }
//       }
//   }
//}
