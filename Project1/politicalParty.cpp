
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
#include "citizenList.h"

namespace proj
{
	politicalParty::politicalParty() :representativeList(new citizenList*()), name(nullptr), numId(0),head(nullptr)
	{
        
	}
    politicalParty::~politicalParty()
    {
        delete[] representativeList;
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
            representativeList[i]->printList();
        }
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
        if (state > ElectionRound::countState)
        {
            reSizeRepresentativeList(ElectionRound::countState+1, state + 1);
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
        /// delete???
       /* for (int j = 0; j < size; j++)
        {
           delete[] representativeList[j];
        }*/
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
        head = input.head;
        representativeList=input.representativeList;
        
        name = input.name;
      //  name = utils::my_strdup(input.name);
    }
}