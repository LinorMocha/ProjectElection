#pragma once

#include "citizen.h"
#include "citizenList.h"
#include <iostream>
using namespace std;

namespace proj {
    class politicalParty {
    private:
        citizenList** representativeListByStateArray;
        char *name;
        int numId;
        citizen *head;
        int* votesByStatesArray;
        int phySize;
        
    public:
        politicalParty();
        politicalParty(char* partyName, citizen* _head);
        ~politicalParty();
        // to check if necessery
        //void operator=(const politicalParty& input);
         politicalParty(const politicalParty& pol);

        //// GETERS
        int getNumId();
        char* getName();
        citizen* getPoliticalPartyHead();
        int getHowManyVotesOverAll();
        int getHowManyVotesForState(int stateId);
        int getNumOfRepInList(int stateId);
        /// OTHER FUNCATIONS
        void reSizeRepresentativeList();
        void addRepresentitive(citizen* citizen, int state);
        void PrintRepListForAllState();

        friend ostream& operator<<(ostream& os,const politicalParty& p_party);
        void addState();
        void reSizeVotesByStateArray();
        void addVote(int stateId);
        void PrintWinningRepresentitives(int state, int repCount);
        bool isRep(const citizen& cit);
    };
}