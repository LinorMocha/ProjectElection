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
        citizen* getCitizenById(int _id);
        char* getCitizenName( citizen* input);
        node* getHead();

        citizenList(const citizenList& input);
        void operator=(const citizenList& input);
        void addNodeToTail(citizen* input);
        void addNodeToHead(citizen* input);
        void printList();
        void printList(int numOfNodeToPrint);
        
     

    };
}