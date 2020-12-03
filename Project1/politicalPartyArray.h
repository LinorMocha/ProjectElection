#pragma once
#include <iostream>
#include"politicalParty.h"
using namespace std;
namespace proj
{
    class PoliticalPartyArray
    {
    private:
        politicalParty* politicalPartyArray;
        int phySize;
    public:
        PoliticalPartyArray();
        ~PoliticalPartyArray();

        const politicalParty& getPoliticalPartyById(int Id);
        void addPoliticalParty(char* name, citizen * head);
        void reSizePoliticalPartyArray();
        void printPoliticalPartyArray();
        const citizen& getPoliticalPartyHead(int numID);

     };
}
