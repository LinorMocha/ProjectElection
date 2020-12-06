
#pragma once
#include <iostream>

#include "State.h"
using namespace std;
namespace proj
{
    class StateArray
    {
    private:
        State** stateArray;
        int phySize;
    public:
        StateArray();
        ~StateArray();
        const State& getStateById(int Id);
        
        int getStatenumOfRepresentative(int Id);
        int getCitizenCount(int stateId);

        void addState(char* name, int _numRep);
        void reSizeStateArray();
        void printStateArray();
        void addCitizenCountToState(int stateId);

    };
}
