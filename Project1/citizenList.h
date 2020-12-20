#pragma once
#include <iostream>
#include "citizen.h"

using namespace std;
namespace proj
{
    struct node
    {
        citizen* value;
        node* next;
        node* prev;
    };

    class citizenList
    {
    private:
        node* head,*tail;
    public:
        citizenList();
        ~citizenList();
        citizenList(const citizenList& input);
        void operator=(const citizenList& input);

        ///// GETERS ////
        citizen* getCitizenById(int _id) const;
        node* getHead()const;
        int getListSize()const;
      

        void addNodeToTail(citizen* input);
        void addNodeToHead(citizen* input);
        void printList();
        void printList(int numOfNodeToPrint);
    };
}