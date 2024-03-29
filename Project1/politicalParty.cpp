﻿
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
#include "citizenList.h"

namespace proj
{
	/*politicalParty::politicalParty() :representativeListByStateArray(nullptr), name(nullptr), numId(0),head(nullptr),votesByStatesArray(nullptr),phySize(1)
	{
    }*/
    //serialize constractor of political Party
    politicalParty::politicalParty(istream& in, const citizenList& currRound, citizen* _head) :head(*_head)
    {
        load(in, currRound);

    }
    //ctor
    politicalParty::politicalParty(const char* partyName, citizen* _head) : head(*_head)
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
    //ctor
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
    //dctor
    politicalParty::~politicalParty()
    {
        delete[] representativeListByStateArray;
        delete[] name;
        delete[] votesByStatesArray;
     }

    // This function prints the information of the curr politcal party 
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
    //Returns the number of representatives within a state of a politcal party
    int politicalParty::getNumOfRepInList(int stateId)const
    {
        return representativeListByStateArray[stateId]->getListSize();
    }
    //Returns the total number of votes in politcal party
   int politicalParty::getHowManyVotesOverAll()const
    {
        int res=0;
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            res += votesByStatesArray[i+1];
        }
        return res;
    }
   //Returns the number of votes within a state
    int politicalParty::getHowManyVotesForState(int stateId)const
    {
        return votesByStatesArray[stateId];
    }
    //Returns the name of the party
    char *politicalParty::getName() const 
    {
        return name;
    }
    //Returns a ref to the head of party 
    const citizen& politicalParty::getPoliticalPartyHead() const
    {
        return head;
    }
    //Returns the serial number of a party
    int politicalParty::getNumId()const
    {
        return numId;
    }

    //////////////////////////////////////
    //Add new representative in curr state
    void politicalParty::addRepresentitive(citizen* citizen, int state) 
    {
            representativeListByStateArray[state]->addNodeToTail(citizen);
    }
    //Add state
    void politicalParty::addState()
    {
        if (phySize <= ElectionRound::countState)
        {
            reSizeRepresentativeList();
            reSizeVotesByStateArray();
        }
    }
    //This function checks whether a specific citizen is a representative
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
    //This function writes the politcal party data to binary file
    bool politicalParty::save(ostream& out) const
    {
        if (!out)//checks if the file works properly
        {
            return false;
        }
        int temp = head.getId();
        out.write(rcastcc(&temp), sizeof(int));
        out.write(rcastcc(&numId), sizeof(numId));
        out.write(rcastcc(&phySize), sizeof(phySize));
        for (int i = 0; i <= ElectionRound::countState; i++)
        {
            out.write(rcastcc(&votesByStatesArray[i]), sizeof(int));
        }
        for (int j = 1; j <= ElectionRound::countState; j++)
        {
            if (!representativeListByStateArray[j]->saveById(out))
                return false;
        }
        int len = utils::myStrlen(name);
        out.write(rcastcc(&len), sizeof(int));
        out.write(name, len);
        return(out.good());//Checks if the writes operations to file performed properly
       
    }
    //This function reads the politcal party data from binary file
    bool politicalParty::load(istream& in, const citizenList& currList)
    {
        if (!in)//checks if the file works properly
        {
            return false;
        }
        int len;
       
        in.read(rcastc(&numId), sizeof(numId));
        in.read(rcastc(&phySize), sizeof(phySize));
        if (!in.good())
        {
            return false;
        }
        votesByStatesArray = new int[phySize];
        for (int i = 0; i < phySize; i++)
        {
            if (i <= ElectionRound::countState)
                in.read(rcastc(&votesByStatesArray[i]), sizeof(int));
            else
                votesByStatesArray[i] = 0;
        }
        representativeListByStateArray = new citizenList * [phySize];
        for (int i = 0; i < phySize; i++)
        {
            if (i <= ElectionRound::countState && i != 0)
            {
                representativeListByStateArray[i] = new citizenList();
                if(!representativeListByStateArray[i]->loadById(in, currList))
                     return false;
            }
            else
                representativeListByStateArray[i] = new citizenList();
        }

        in.read(rcastc(&len), sizeof(len));
        if (!in.good())
        {
            return false;
        }
        len++;
        name = new char[len];
        in.read(name,len-1);
        name[len - 1] = '\0';
        return (in.good());
    }
    //this function adds vote to the total number of votes
    void politicalParty::addVote(int stateId)
    {
        votesByStatesArray[stateId]++;
    }
    //This function increases the votes by state array
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
    //This function increases the Representative arr
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

    void politicalParty::PrintWinningRepresentitives(int state, int repCount) const
    {
        representativeListByStateArray[state]->printList(repCount);
           
	}
    //Prints all arrays of representatives in all states
    void politicalParty::PrintRepListForAllState()
    {
        for (int i = 1; i <= ElectionRound::countState; i++)
        {
            representativeListByStateArray[i]->printList();
        }

    }
}