#pragma once

#include "citizen.h"
#include "citizenList.h"

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
       // politicalParty(const politicalParty& pol);

        //// GETERS
        int getNumId();
        char* getName();
        citizen* getPoliticalPartyHead();
        int getHowManyVotesOverAll();
        int getHowManyVotesForState(int stateId);

        /// OTHER FUNCATIONS
        void reSizeRepresentativeList();
        void addRepresentitive(citizen* citizen, int state);
        void printPoliticalParty();
        void addState();
        void reSizeVotesByStateArray();
        void addVote(int stateId);
        const citizenList& getWinningRepresentitives(int state, int repCount);

    };
}