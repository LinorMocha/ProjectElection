#pragma once

#include "citizen.h"
#include "citizenList.h"
#include <vector>
#include <iostream>
#include "DynamicArr.h"

using namespace std;

namespace proj {
    class politicalParty {
    private:
        DynamicArray<citizenList*> representativeListByStateArray;
        char *name;
        int numId;
        citizen& head;
        vector<int> votesByStatesArray;
        
        
    public:
        //politicalParty();
        ~politicalParty();
        politicalParty(istream& in, const citizenList& currRound, citizen* _head);
        politicalParty(const char* partyName, citizen* _head);
        politicalParty(const politicalParty& pol);

        //// GETERS
        int getNumId()const;
        char* getName()const;
        const citizen& getPoliticalPartyHead() const;
        int getHowManyVotesOverAll()const;
        int getHowManyVotesForState(int stateId)const;
        int getNumOfRepInList(int stateId)const;
        
        /// OTHER FUNCATIONS
        void addRepresentitive(citizen* citizen, int state);
        void PrintRepListForAllState();
        friend ostream& operator<<(ostream& os,const politicalParty& p_party);
        void addVote(int stateId);
        void PrintWinningRepresentitives(int state, int repCount) const ;
        bool isRep(const citizen& cit);

       bool save(ostream& out) const;
       bool load(istream& in,const citizenList& currList);

    };
}