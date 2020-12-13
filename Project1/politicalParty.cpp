
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
#include "citizenList.h"

namespace proj
{
	politicalParty::politicalParty() :representativeListByStateArray(nullptr), name(nullptr), numId(0),head(nullptr),votesByStatesArray(new int()),phySize(1)
	{
        votesByStatesArray[0] = 0;
	}
    politicalParty::politicalParty(const politicalParty& pol)
    {
        numId = pol.numId;
        head = pol.head;
        votesByStatesArray = new int(*pol.votesByStatesArray);
        representativeListByStateArray = new citizenList * (*pol.representativeListByStateArray);
        name=   utils::my_strdup(pol.name);
        phySize = pol.phySize;
    }
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
        int len = ElectionRound::countState + 1;
        representativeListByStateArray = new citizenList * [len];
        for (int i = 0; i < len; i++)
        {
            representativeListByStateArray[i] = new citizenList();
        }
        name = utils::my_strdup(partyName);
        head = _head;
    }

    /*ostream& operator(ostream& os, const politicalParty& p_party)
    {
        os <<"political party ID: "<< p_party.getNumId<< endl;
        os << "political party name: " << p_party.getName << endl;
        os << "the head of political party is: " << endl;
        os << p_party.getPoliticalPartyHead<<endl;
        for (int i = 1; i <= ElectionRound::countState; i++)
        {
            os << "Representative List for State:" << i << endl;
            os << representativeListByStateArray[i] << endl;
        }
        
        return os;
    }*/

    void politicalParty::printPoliticalParty()
    {
        cout << numId << " ";
        cout << name << " ";
        cout << "The Head of the Political Party is:" << " ";
        head->printCitizen();
        for (int i = 1; i <= ElectionRound::countState; i++)
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

    void politicalParty::PrintWinningRepresentitives(int state, int repCount)
    {
        representativeListByStateArray[state]->printList(repCount);
           
	}
    /*void politicalParty::operator=(const politicalParty& input)
    {
        numId = input.numId;
        head = input.head;
        representativeListByStateArray=input.representativeListByStateArray;
        name = input.name;
    }*/
}