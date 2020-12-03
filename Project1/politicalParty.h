#pragma once

#include "citizen.h"
#include "citizenList.h"

namespace proj {
    class politicalParty {
    private:
        citizenList** representativeList;
        char *name;
        int numId;
        citizen *head;
       
    public:
        politicalParty();
        politicalParty(const politicalParty& pol);
        politicalParty(char* partyName, citizen* _head);
        ~politicalParty();
        int getNumId();
        char* getName();
        citizen* getPoliticalPartyHead();
        void operator=(const politicalParty& input);
        void reSizeRepresentativeList(int size, int newSize);
        void addRepresentitive(citizen* citizen, int state);
        void printPoliticalParty();
        // לאחר תוצאות הבחירות ניקח את הרשימה שלנו לפי מחוזות ונביא רק את הנציגים שנבחרו (לפי מספר סידורי)
        const citizenList& getWinningRepresentitives(int state, int repCount);

    };
}