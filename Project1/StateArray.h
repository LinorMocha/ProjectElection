#pragma once
#include <iostream>
#include "State.h"
#include "DynamicArr.h"

using namespace std;
namespace proj
{
    class StateArray
    {
    private:
        DynamicArray<State**> stateArray;
        int phySize;
    public:
        StateArray();
        ~StateArray();
        /* StateArray(istream& in);*/
        State& getStateById(int Id) const;
        int getStatenumOfRepresentative(int Id) const;
        int getCitizenCount(int stateId) const;
        int getPhySize() const;

        void addState(const string name, int _numRep , bool Status);
        void reSizeStateArray();
        void printStateArray();
        void addCitizenCountToState(int stateId);
        void addVoteCountToState(int stateId);

        bool save(ostream& out)const;
        bool load(istream& in);
    };
}
