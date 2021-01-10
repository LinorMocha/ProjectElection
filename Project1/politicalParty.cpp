
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
    politicalParty::politicalParty(const string partyName, citizen* _head) : head(*_head)
    {

        ElectionRound::countPoliticalParty++;
        numId = ElectionRound::countPoliticalParty;
               
       
      representativeListByStateArray =new <list<citizen*>> [ElectionRound::countState];
        
               
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            representativeListByStateArray[i]
                = new <list<citizen*>>();
            
        }

        name = partyName;
       
    }
    //ctor
    politicalParty::politicalParty(const politicalParty& pol): head(pol.head)
    {
        numId = pol.numId;
      
       
        representativeListByStateArray = new citizenList * [pol.phySize];
        for (int i = 0; i < pol.phySize; i++)
        {
            pol.representativeListByStateArray[i]->printList();
            representativeListByStateArray[i] = new citizenList(*pol.representativeListByStateArray[i]);
            votesByStatesArray[i] = pol.votesByStatesArray[i];
        }

        name = pol.name;
       
    }
    //dctor
    politicalParty::~politicalParty()
    {
        delete[] representativeListByStateArray;//no need?
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
        for (auto i : votesByStatesArray)
        {
            res += i;
        }
        return res;
   }

   //Returns the number of votes within a state
    int politicalParty::getHowManyVotesForState(int stateId)const
    {
        return votesByStatesArray[stateId];
    }
    //Returns the name of the party
    string politicalParty::getName() const 
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
        

        for (int i : votesByStatesArray)
        {
            if (i <= ElectionRound::countState)
            out.write(rcastcc(&i), sizeof(int));
       }

        for (int j = 1; j <= ElectionRound::countState; j++)
        {
            if (!representativeListByStateArray[j]->saveById(out))
                return false;
        }
        int len = name.length();
        out.write(rcastcc(&len), sizeof(int));
        out.write(rcastcc(name.c_str()), len);
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
       
        if (!in.good())
        {
            return false;
        }
              
        for (int itr : votesByStatesArray)
        {
            if (itr <= ElectionRound::countState)
                in.read(rcastc(&itr), sizeof(int));
            
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
       
        name.resize(len); 
        in.read((char*)&name[0], len);
        return (in.good());
    }
    //this function adds vote to the total number of votes
    void politicalParty::addVote(int stateId)
    {
        
        if (votesByStatesArray.capacity() <= stateId-1)
            votesByStatesArray.push_back(0);
     
        votesByStatesArray[stateId-1]++;
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