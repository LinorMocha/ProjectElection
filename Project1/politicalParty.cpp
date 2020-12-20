
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
#include "citizenList.h"

namespace proj
{
	/*politicalParty::politicalParty() :representativeListByStateArray(nullptr), name(nullptr), numId(0),head(nullptr),votesByStatesArray(nullptr),phySize(1)
	{
    }*/
    politicalParty::politicalParty(char* partyName, citizen* _head) : head(*_head)
    {

        ElectionRound::countPoliticalParty++;
        numId = ElectionRound::countPoliticalParty;
        phySize = ElectionRound::countState + 1;
        representativeListByStateArray = new citizenList * [phySize];
        votesByStatesArray = new int[phySize];

        for (int i = 0; i < phySize; i++)
        {
            representativeListByStateArray[i] = new citizenList();
            votesByStatesArray[i] = 0;
        }

        name = utils::my_strdup(partyName);
       
    }

    politicalParty::politicalParty(const politicalParty& pol): head(pol.head)
    {
        numId = pol.numId;
      
        votesByStatesArray = new int[pol.phySize];
        representativeListByStateArray = new citizenList * [pol.phySize];
        for (int i = 0; i < pol.phySize; i++)
        {
            pol.representativeListByStateArray[i]->printList();
            representativeListByStateArray[i] = new citizenList(*pol.representativeListByStateArray[i]);
            votesByStatesArray[i] = pol.votesByStatesArray[i];
        }
        
        
        name=   utils::my_strdup(pol.name);
        phySize = pol.phySize;
    }
    politicalParty::~politicalParty()
    {
        delete[] representativeListByStateArray;
        delete[] name;
        delete[] votesByStatesArray;
     }

   
    ostream& operator<<(ostream& os, const politicalParty& p_party)
    {

        os << "political party name: " << p_party.name;
        os << "  ||  ID: " << p_party.numId;
        os << "  ||  the head of political party is: ";
        os << p_party.head << endl;
        for (int i = 1; i <= ElectionRound::countState; i++)
        {
            os << "Representative List for State number " << i << "is:" << endl;
            p_party.representativeListByStateArray[i]->printList();
        }
        return os;
    }

    ///////// GETERS /////////

    int politicalParty::getNumOfRepInList(int stateId)const
    {
        return representativeListByStateArray[stateId]->getListSize();
    }

   int politicalParty::getHowManyVotesOverAll()const
    {
        int res=0;
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            res += votesByStatesArray[i];
        }
        return res;
    }
    int politicalParty::getHowManyVotesForState(int stateId)const
    {
        return votesByStatesArray[stateId];
    }
    char *politicalParty::getName() const 
    {
        return name;
    }

    const citizen& politicalParty::getPoliticalPartyHead() const
    {
        return head;
    }

    int politicalParty::getNumId()const
    {
        return numId;
    }

    //////////////////////////////////////

    void politicalParty::addRepresentitive(citizen* citizen, int state) 
    {
            representativeListByStateArray[state]->addNodeToTail(citizen);
    }
    void politicalParty::addState()
    {
        if (phySize <= ElectionRound::countState)
        {
            reSizeRepresentativeList();
            reSizeVotesByStateArray();
        }
    }

    bool politicalParty::isRep(const citizen& cit)
    {
        for (int i = 1; i <= ElectionRound::countState; i++)
        {
            if (representativeListByStateArray[i] != nullptr)
            {
                if (representativeListByStateArray[i]->getCitizenById(cit.getId()) != nullptr)
                    return true;
            }
        }
        return false;
    }

    void politicalParty::save(ostream& out) const
    {
        out.write(rcastcc(&name), sizeof(name));
        out.write(rcastcc(&numId), sizeof(numId));
        out.write(rcastcc(&phySize), sizeof(phySize));
        head.save(out);
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            out.write(rcastcc(&votesByStatesArray[i]), sizeof(int)); 
        }
        for (int j = 0; j < ElectionRound::countState; j++)
        {
            
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
            if (ElectionRound::countState > i && i!=0)
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
                
            }
        }
        
		delete[] representativeListByStateArray;
        
       representativeListByStateArray = res;
    }

    void politicalParty::PrintWinningRepresentitives(int state, int repCount)
    {
        representativeListByStateArray[state]->printList(repCount);
           
	}
    void politicalParty::PrintRepListForAllState()
    {
        for (int i = 1; i <= ElectionRound::countState; i++)
        {
            representativeListByStateArray[i]->printList();
        }

    }

  

 
}