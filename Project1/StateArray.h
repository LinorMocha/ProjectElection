
#pragma once
#include <iostream>

#include "State.h"
using namespace std;
namespace proj
{
    class StateArray
    {
    private:
        State* stateArray;
        int phySize;
    public:
        StateArray();
        ~StateArray();
        State* getStateById(int Id);
        int getStatenumOfRepresentative(int Id);
        void addState(char* name, int _numRep);
        void reSizeStateArray(int size, int newSize)
        // להוסיף מחיקת איבר
        //להוסיף getters
    };
}
