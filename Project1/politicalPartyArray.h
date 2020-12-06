#pragma once
#include <iostream>
#include"politicalParty.h"
using namespace std;
namespace proj
{
    class PoliticalPartyArray
    {
    private:
        politicalParty** politicalPartyArray;
        int phySize;
    public:
        PoliticalPartyArray();
        ~PoliticalPartyArray();
        
        ///// GETERS ////
        int getOverAllVotesForPoli(int poliId);
        int getOverAllVotesForPoliInState(int poliId, int stateId);
        char* getName(int poliId);


        void addState();
        const politicalParty& getPoliticalPartyById(int Id);
        void addPoliticalParty(char* name, citizen * head);
        void reSizePoliticalPartyArray();
        void printPoliticalPartyArray();
        const citizen& getPoliticalPartyHead(int numID);
        //const citizenList& getSelectedRepList(int PoliId, int StateId, int repCount);
        void printSelectedRepList(int PoliId, int StateId, int repCount);

        void addRepToPoli(int PolId, int StateId, citizen* rep);
        void addVote(int poliId,int stateId);
     };
}
