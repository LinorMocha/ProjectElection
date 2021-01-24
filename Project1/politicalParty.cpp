#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"
namespace proj
{
  //serialize constractor of political Party
    politicalParty::politicalParty(istream& in, const CitizenList& currRound, citizen* _head) : head(*_head)
    {
        load(in, currRound);

    }
    
    //ctor
    politicalParty::politicalParty(const string partyName, citizen* _head) : head(*_head)
    {
        numId = ElectionRound::countPoliticalParty + 1 ;
        name = partyName;
        RepListByStateArray.resize(ElectionRound::countState);
        votesByStatesArray.resize(ElectionRound::countState);
        utils::initArray(votesByStatesArray.begin(), ElectionRound::countState);
    }

    
    //copy ctor
    politicalParty::politicalParty(const politicalParty& pol): head(pol.head)
    {
        this->operator=(pol);
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
        p_party.PrintRepListForAllState();
        return os;
    }
    
    const politicalParty& politicalParty::operator=(const politicalParty& input)
    {
        name = input.name;
        numId = input.numId;
        head = input.head;
        RepListByStateArray = input.RepListByStateArray;
        votesByStatesArray = input.votesByStatesArray;

        return *this;
    }

    bool politicalParty::operator==(int id)
    {
        return numId == id;
    }

    ///////// GETERS /////////
    //Returns the number of representatives within a state of a politcal party
    int politicalParty::getNumOfRepInList(int stateId)const
    {
        return RepListByStateArray[stateId].getListSize();
    }

    void politicalParty::setVote(int stateId, int numToSet)
    {
        votesByStatesArray[stateId-1]=numToSet;

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
        return votesByStatesArray[stateId-1];
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
        RepListByStateArray[state-1].addCitizenToListTail(_citizen);
        
        
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
                throw ex;
           }
        }
        
    }
    
    //This function writes the politcal party data to binary file
    void politicalParty::save(ostream& out) const
    {
        int temp = head.getId();
        out.write(rcastcc(&temp), sizeof(int));
        out.write(rcastcc(&numId), sizeof(numId));
        
        for (int i = 0; i < ElectionRound::countState;i++) {
            temp = votesByStatesArray[i];
            out.write(rcastcc(&temp), sizeof(int));
            
        }
        // Saving each List in the array
        for (int i = 0; i < ElectionRound::countState;i++) {
            RepListByStateArray[i].save(out);
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
    void politicalParty::load(istream& in, const CitizenList& currList)
    {
        in.read(rcastc(&numId), sizeof(numId));
        
        int temp;

        for(int i=0; i< ElectionRound::countState;i++){
            in.read(rcastc(&temp), sizeof(int));
            votesByStatesArray.push_back(temp);
        }

        RepListByStateArray.resize(ElectionRound::countState);
              
        // Reading for each citizen only his ID in the file!
        for (int i=0;i<ElectionRound::countState;i++)
        {
            RepListByStateArray[i].load(in, currList);
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
        int toResize = votesByStatesArray.capacity() - stateId;
        if (toResize < 0)
        {
            for (int i = 0; i <= toResize; i++)
                votesByStatesArray.push_back(0);
        }
         votesByStatesArray[stateId-1]= votesByStatesArray[stateId - 1] + 1;
    }
    
    //this function prints the wining list 
    void politicalParty::printWinningRepListForState(int state, int repCount) const
    {
        RepListByStateArray[state-1].printWininigList(repCount);
    }

    //Prints all arrays of representatives in all states
    void politicalParty::PrintRepListForAllState() const
    {
        for (int i = 0; i < ElectionRound::countState; i++)
        {
            cout << "representative List for state number:  " << i + 1 << endl;
            cout << "_________________________________" << endl;
            cout << RepListByStateArray[i] << endl;
        }
    }
}