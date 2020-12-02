
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
#include "citizenList.h"

namespace proj
{
	politicalParty::politicalParty() :representativeList(new citizenList*()), name(nullptr), numId(0),head(nullptr), lastState(0)
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
       representativeList[state]->addNodeToTail(citizen);
    }

    void politicalParty::reSizeRepresentativeList(int size, int newSize)
    {
        citizenList** res = new citizenList*[newSize];
        for (int i = 0; i < newSize; i++)
        {
            res[i] = new citizenList();
            
            if(i < size && i!=0)
                res[i] = representativeList[i];
            else
                res[i] = nullptr;
        }

        for (int j = 0; j < size; j++)
        {
           delete[] representativeList[j];
        }
       representativeList = res;
    }

    citizenList* politicalParty::getWinningRepresentitives(int state, int repCount)
    {
        citizenList* stateRepres=new citizenList();
        
        node* head = representativeList[state]->getHead();
        
        node* temp = head;
        
        for (int i = 0; i < repCount; ++i) 
        {
            stateRepres->addNodeToTail(temp->value);
            temp = head->next;
        }
        
        return stateRepres;
	}
    void politicalParty::operator=(const politicalParty& input)
    {
        numId = input.numId;
        representativeList=input.representativeList;
        lastState = input.lastState;
        name = utils::my_strdup(input.name);
    }
}