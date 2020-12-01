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

        void operator=(const citizenList& input);
        void addNodeToTail(citizen* input);
        void addNodeToHead(citizen* input);

        citizen* getItem(int _id);
        node* getHead();
    };
}