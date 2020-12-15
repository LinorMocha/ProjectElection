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

        State& getStateById(int Id) const;
        int getStatenumOfRepresentative(int Id) const;
        int getCitizenCount(int stateId) const;
        int getPhySize() const;

        void addState(char* name, int _numRep);
        void reSizeStateArray();
        void printStateArray();
        void addCitizenCountToState(int stateId);
        void addVoteCountToState(int stateId);
    };
}
