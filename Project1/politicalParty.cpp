
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
#include "citizenList.h"

namespace proj
{
	politicalParty::politicalParty() :representativeList(new citizenList()), name(nullptr), numId(0),head(nullptr), lastState(0)
	{
        ElectionRound::countPoliticalParty++;
        numId = ElectionRound::countPoliticalParty;
	}
    politicalParty::politicalParty(char* partyName, citizen* _head) : politicalParty()
    {
        name = utils::my_strdup(partyName);
        head = _head;
    }
    char *politicalParty::getName()
    {
        return name;
    }

    citizen* politicalParty::getPoliticalPartyHead()
    {
        return head;
    }

    int politicalParty::getNumId()
    {
        return numId;
    }
    void politicalParty::addRepresentitive(citizen* citizen, int state) 
    {
        if (state > lastState)
        {
            reSizeRepresentativeList(lastState + 1, state + 1);
            lastState = state;
        }
       representativeList[state].addNodeToTail(citizen);
    }

    void politicalParty::reSizeRepresentativeList(int size, int newSize)
    {
        citizenList* res = new citizenList[newSize];
       // No data in cell zero
        for (int i = 1; i < size; i++)
        {
            res[i] = representativeList[i];
        }
                
    }

    citizenList* politicalParty::getWinningRepresentitives(int state, int repCount)
    {
        citizenList* stateRepres=new citizenList();
        
        node* head = representativeList[state].getHead();
        
        node* temp = head;
        
        for (int i = 0; i < repCount; ++i) 
        {
            stateRepres->addNodeToTail(temp->value);
            temp = head->next;
        }
        
        return stateRepres;
	}
    
}