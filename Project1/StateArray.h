
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
    public:
        StateArray();
        ~StateArray();
        State* getStateById(int Id);
        int getStatenumOfRepresentative(int Id);

        // להוסיף מחיקת איבר
        //להוסיף getters
    };
}
