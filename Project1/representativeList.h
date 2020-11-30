#pragma once
#include <iostream>
#include "citizen.h"

using namespace std;
namespace proj
{
    struct node
    {
        citizen* represent;
        node* next;
        node* prev;
    };

    class representativeList
    {
    private:
        node* head,*tail;
    public:
        representativeList();
        ~representativeList();
        void add_node(citizen newrepre);
    };
}