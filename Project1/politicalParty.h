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
       // politicalParty(const politicalParty& pol);
        politicalParty(char* partyName, citizen* _head);
        ~politicalParty();
        int getNumId();
        char* getName();
        citizen* getPoliticalPartyHead();
        //void operator=(const politicalParty& input);
        void reSizeRepresentativeList();
        void addRepresentitive(citizen* citizen, int state);
        void printPoliticalParty();
        void addState();
        void reSizeVotesByStateArray();
        void addVote(int stateId);
        // לאחר תוצאות הבחירות ניקח את הרשימה שלנו לפי מחוזות ונביא רק את הנציגים שנבחרו (לפי מספר סידורי)
        const citizenList& getWinningRepresentitives(int state, int repCount);

    };
}