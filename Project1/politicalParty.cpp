
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
#include "citizenList.h"

namespace proj
{
	politicalParty::politicalParty() :representativeListByStateArray(new citizenList*()), name(nullptr), numId(0),head(nullptr),votesByStatesArray(new int()),phySize(1)
	{
        votesByStatesArray[0] = 0;
	}
    //politicalParty::politicalParty(const politicalParty& pol)
    //{
    //    numId = pol.numId;
    //    head = pol.head;
    //    votesByStatesArray = new int[];
    //    representativeListByStateArray = new citizenList * (*pol.representativeListByStateArray);
    //    name=   utils::my_strdup(pol.name);
    //}
    politicalParty::~politicalParty()
    {
        delete[] representativeListByStateArray;
        delete[] name;
        delete[] head;
    }
    politicalParty::politicalParty(char* partyName, citizen* _head) : politicalParty()
    {
        ElectionRound::countPoliticalParty++;
        numId = ElectionRound::countPoliticalParty;
        name = utils::my_strdup(partyName);
        head = _head;
    }
    void politicalParty::printPoliticalParty()
    {
        cout << numId << " ";
        cout << name << " ";
        cout << "The Head of the Political Party is:" << " ";
        head->printCitizen();
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            cout << "Representative List for State:" << i << " ";
            representativeListByStateArray[i]->printList();
        }
    }
    int politicalParty::getHowManyVotesOverAll()
    {
        int res=0;
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            res += votesByStatesArray[i];
        }
        return res;
    }
    int politicalParty::getHowManyVotesForState(int stateId)
    {
        return votesByStatesArray[stateId];
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
            representativeListByStateArray[state]->addNodeToTail(citizen);
    }
    void politicalParty::addState()
    {
        if (phySize < ElectionRound::countState)
        {
            reSizeRepresentativeList();
            reSizeVotesByStateArray();
        }
    }
    void politicalParty::addVote(int stateId)
    {
        votesByStatesArray[stateId]++;
    }
        void politicalParty::reSizeVotesByStateArray()
    {
        int* res = new int[phySize];
        for (int i = 0; i < phySize; i++)
        {
            if (ElectionRound::countState > i)
                res[i] = votesByStatesArray[i];
            else
                res[i] = 0;
        }

        delete[]votesByStatesArray;
        votesByStatesArray = res;
    }
    void politicalParty::reSizeRepresentativeList()
    {
        phySize *= 2;
        citizenList** res = new citizenList*[phySize];
        for (int i = 0; i < phySize; i++)
        {
            if(i < ElectionRound::countState && i!=0)
                res[i] = representativeListByStateArray[i];
            else
            {
                res[i] = new citizenList();
                res[i] = nullptr;
            }
        }
        
		delete[] representativeListByStateArray;
        
       representativeListByStateArray = res;
    }

    const citizenList& politicalParty::getWinningRepresentitives(int state, int repCount)
    {
        citizenList* stateRepres=new citizenList();
        
        node* head = representativeListByStateArray[state]->getHead();
        
        node* temp = head;
        
        for (int i = 0; i < repCount; ++i) 
        {
            stateRepres->addNodeToTail(temp->value);
            temp = head->next;
        }
        
        return *stateRepres;
	}
    /*void politicalParty::operator=(const politicalParty& input)
    {
        numId = input.numId;
        head = input.head;
        representativeListByStateArray=input.representativeListByStateArray;
        name = input.name;
    }*/
}