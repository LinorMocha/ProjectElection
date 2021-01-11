
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
namespace proj
{
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
        name = partyName;
        RepListByStateArray.resize(ElectionRound::countState);

     /*for (int i = 0; i < ElectionRound::countState; i++){
          RepresentativeList* lst=new RepresentativeList();
          RepListByStateArray.push_back(lst);
     }*/
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
    politicalParty::~politicalParty() { }

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
        return RepListByStateArray[stateId].getListSize();
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
        RepListByStateArray[state].addCitizenToListTail(_citizen);
    }
  
    //This function checks whether a specific citizen is a representative
    void politicalParty::isRep(const citizen& cit)
    {
        if (cit.getId() == head.getId())
            throw invalid_argument("citizen is already headPoliticalParty");
        
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            try {
                RepListByStateArray[i].isCitizenInList(cit);
            }

            catch (std::exception& ex) {
                throw invalid_argument("citizen is already rep");
           }
        }
        
    }
    
    //This function writes the politcal party data to binary file
    void politicalParty::save(ostream& out) const
    {
        int temp = head.getId();
        out.write(rcastcc(&temp), sizeof(int));
        out.write(rcastcc(&numId), sizeof(numId));
        
        for (int i : votesByStatesArray){
            if (i <= ElectionRound::countState)
            {
                temp = i;
                out.write(rcastcc(&temp), sizeof(int));
            }
        }
        // Saving each List in the array
        for (RepresentativeList it : RepListByStateArray) {
           
            it.save(out);
        }

        int len = name.length();
        out.write(rcastcc(&len), sizeof(int));
        out.write(rcastcc(name.c_str()), len);

        //Checks if the writes operations to file performed properly
        if (!out){
            throw invalid_argument("error with file");
        }
       
    }
    //This function reads the politcal party data from binary file

    void politicalParty::load(istream& in, const list<citizen*>& currList)
    {
        in.read(rcastc(&numId), sizeof(numId));
        
        votesByStatesArray.resize(ElectionRound::countState);
        for(int i=0; i< ElectionRound::countState;i++){
            in.read(rcastc(&votesByStatesArray[i]), sizeof(int));
        }

        RepListByStateArray.resize(ElectionRound::countState);
              
        // Reading for each citizen only his ID in the file!
        for (RepresentativeList it : RepListByStateArray)
        {
            it.load(in, currList);
        }
        int len;
        in.read(rcastc(&len), sizeof(len));
        name.resize(len); 
        in.read((char*)&name[0], len);
        if (!in.good())
            throw invalid_argument("error with file");
    }
    
    //this function adds vote to the total number of votes
    void politicalParty::addVote(int stateId)
    {
        
        if (votesByStatesArray.capacity() <= stateId-1)
            votesByStatesArray.push_back(0);
     
        votesByStatesArray[stateId-1]++;
    }
    
    //this function prints the wining list 
    void politicalParty::printWinningRepListForState(int state, int repCount) const
    {
        RepListByStateArray[state].printWininigList(repCount);
    }

    //Prints all arrays of representatives in all states
    void politicalParty::PrintRepListForAllState()
    {
        RepListByStateArray.print();
    }
}