
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
namespace proj
{
	/*politicalParty::politicalParty() :representativeListByStateArray(nullptr), name(nullptr), numId(0),head(nullptr),votesByStatesArray(nullptr),phySize(1)
	{
    }*/

    //serialize constractor of political Party
    politicalParty::politicalParty(istream& in, const list<citizen*>& currRound, citizen* _head): head(*_head)
    {
        load(in, currRound);

    }
    //ctor
    politicalParty::politicalParty(const string partyName, citizen* _head) : head(*_head)
    {
        ElectionRound::countPoliticalParty++;
        numId = ElectionRound::countPoliticalParty;
               
       
      for (int i = 0; i < ElectionRound::countState; i++)
        {
          list<citizen*>* lst=new list<citizen*>();
          RepListByStateArray.push_back(lst);
        }

        name = partyName;
       
    }
    //copy ctor
    politicalParty::politicalParty(const politicalParty& pol): head(pol.head)
    {
        numId = pol.numId;
        RepListByStateArray = pol.RepListByStateArray;
        votesByStatesArray = pol.votesByStatesArray;
        name = pol.name;
    }
    //dctor
    politicalParty::~politicalParty()
    {
        RepListByStateArray;
    }

    // This function prints the information of the curr politcal party 
    ostream& operator<<(ostream& os, const politicalParty& p_party)
    {

        os << "political party name: " << p_party.name;
        os << "  ||  ID: " << p_party.numId;
        os << "  ||  the head of political party is: ";
        os << p_party.head << endl;
        p_party.RepListByStateArray.print();
        return os;
    }

    ///////// GETERS /////////
    //Returns the number of representatives within a state of a politcal party
    int politicalParty::getNumOfRepInList(int stateId)const
    {
       list<citizen*> tempList= RepListByStateArray[stateId];
       return tempList.size();
    }

    //Returns the total number of votes in politcal party
   int politicalParty::getHowManyVotesOverAll()const
   {
        int res=0;
        for (int it : votesByStatesArray)
        {
            res += it;
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
    void politicalParty::addRepresentitive(citizen* _citizen, int state) 
    {
        list<citizen*> listToInsert = RepListByStateArray[state];

        listToInsert.push_back(_citizen);

    }
  
    //This function checks whether a specific citizen is a representative
    void politicalParty::isRep(const citizen& cit)
    {
        if (cit.getId() == head.getId())
            throw invalid_argument("citizen is alaredy headPoliticalParty");
        list<citizen*> listTemp;
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            listTemp = RepListByStateArray[i];
            auto it = std::find(listTemp.begin(), listTemp.end(), &cit);
            if (it != listTemp.end())
                throw invalid_argument("citizen is alardy rep");
        }
        
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