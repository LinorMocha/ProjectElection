#pragma once

#include <iostream>
#include <list>
#include "DynamicArr.h"
#include "RepresentativeList.h"
using namespace std;

namespace proj {
    class politicalParty {
    private:
        
        DynamicArray<RepresentativeList> RepListByStateArray;
        string name;
        int numId;
        citizen& head;
        DynamicArray<int> votesByStatesArray;
        
        
    public:
        
        ~politicalParty();
        politicalParty(istream& in, const list<citizen*>& currRound, citizen* _head);
        politicalParty(const string partyName, citizen* _head);
        politicalParty(const politicalParty& pol);

        //// GETERS
        int getNumId()const;
        string getName()const;
        const citizen& getPoliticalPartyHead() const;
        int getHowManyVotesOverAll()const;
        int getHowManyVotesForState(int stateId)const;
        int getNumOfRepInList(int stateId)const;
        
        /// OTHER FUNCATIONS
        void addRepresentitive(citizen* _citizen, int state);
        void PrintRepListForAllState();
        friend ostream& operator<<(ostream& os,const politicalParty& p_party);
        void addVote(int stateId);
        void printWinningRepListForState(int state, int repCount) const ;
        void isRep(const citizen& cit);


       void save(ostream& out) const;
       void load(istream& in,const list<citizen*>& currList);

    };
}