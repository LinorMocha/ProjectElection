#include"politicalPartyArray.h"
#include"ElectionRound.h"

namespace proj
{
	//ctor
	PoliticalPartyArray::PoliticalPartyArray() :politicalPartyArray(new politicalParty* ()), phySize(1)
	{

	}
	//dctor
	PoliticalPartyArray::~PoliticalPartyArray()
	{
		for (int i = 0; i <= ElectionRound::countPoliticalParty; i++)
		{
			delete politicalPartyArray[i];
		}
	}
	//This function adds state to a specific political party
	void PoliticalPartyArray::addState()
	{
		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			politicalPartyArray[i]->addState();
		}
	}

	int  PoliticalPartyArray::getRepListLengthForStateInPoli(int poliId, int stateId)
	{
		return politicalPartyArray[poliId]->getNumOfRepInList(stateId);
	}
	//This function returns the amount of votes available for a party within a specific state
	int PoliticalPartyArray::getOverAllVotesForPoliInState(int poliId, int stateId)
	{
		return politicalPartyArray[poliId]->getHowManyVotesForState(stateId);
	}
	//This function returns the amount of votes available for a party
	int PoliticalPartyArray::getOverAllVotesForPoli(int poliId)
	{
		return politicalPartyArray[poliId]->getHowManyVotesOverAll();
	}
	//This function returns the name of the current party
	string PoliticalPartyArray::getName(int poliId)
	{
		return politicalPartyArray[poliId]->getName();
	}
	//Add a new vote acorrding to state ID and party ID
	void PoliticalPartyArray::addVote(int poliId, int stateId)
	{
		politicalPartyArray[poliId]->addVote(stateId);
	}
	//This function creates new party and insert him into an array
	void PoliticalPartyArray::addPoliticalParty(string name, citizen* head)
	{
		politicalParty* newParty = new politicalParty(name, head);

		if (ElectionRound::countPoliticalParty >= phySize)
			reSizePoliticalPartyArray();
		politicalPartyArray[newParty->getNumId()] = newParty;

	}
	//This function returns ref to the desired political Party according to the given ID 
	const politicalParty& PoliticalPartyArray::getPoliticalPartyById(int numId)
	{
		return *politicalPartyArray[numId];
	}
	//This function returns ref to the desired head party according to the given ID 
	const citizen& PoliticalPartyArray::getPoliticalPartyHead(int numId)
	{
		return politicalPartyArray[numId]->getPoliticalPartyHead();
	}
	//This function returns a desired party using the head of party
	 politicalParty* PoliticalPartyArray::getPoliticalPartyByHead(const citizen& head)
	 {
		 for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		 {
			 if (politicalPartyArray[i]->getPoliticalPartyHead().getId() == head.getId())
			 {
				 return politicalPartyArray[i];
			 }
		 }
		 return nullptr;
	 }
	 //Checks whether a citizen is a head of party or a representative
	bool PoliticalPartyArray::isCitizenIsRepORHead(const citizen& cit)
	{
		 for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		 {
			if( politicalPartyArray[i]->getPoliticalPartyHead().getId()== cit.getId())
				 return true;
			 if (politicalPartyArray[i]->isRep(cit))
				 return true;
		 }
		 return false;
	}

	//Printing an array of Political parties
	void PoliticalPartyArray::printPoliticalPartyArray()
	{
		bool IsThereP_P = false;
		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			IsThereP_P = true;;
			cout << *politicalPartyArray[i] << endl;
		}
		if (!IsThereP_P)
			cout << "There is not political parties"<<endl;

		
	}
	//Increasing the array of a politcal party array
	void PoliticalPartyArray::reSizePoliticalPartyArray()
	{
		phySize *= 2;
		politicalParty** res = new politicalParty * [phySize];

		for (int i = 0; i < ElectionRound::countPoliticalParty; i++)
		{
			if (i == 0)
				res[i] = nullptr;
			else
			{
				res[i] = new politicalParty(*politicalPartyArray[i]);

			}

		}
		delete[] politicalPartyArray;

		politicalPartyArray = res;

	}

	//Adding a representative to an existing party
	void PoliticalPartyArray::addRepToPoli(int PolId, int StateId, citizen* rep)
	{
		politicalPartyArray[PolId]->addRepresentitive(rep, StateId);
	}
	//Prints a required array of representatives
	void PoliticalPartyArray::printSelectedRepList(int PoliId, int StateId, int repCount) const
	{
		politicalPartyArray[PoliId]->PrintWinningRepresentitives(StateId, repCount);
	}
	//This function writes the Political Party Array data to binary file
	bool PoliticalPartyArray::save(ostream& out) const
	{
		if (!out)//checks if the file works properly
		{
			return false;
		}
		out.write(rcastcc(&phySize), sizeof(phySize));
		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			politicalPartyArray[i]->save(out);//Keeps the current party inside the arr 
			if (!out.good())
			{
				return false;
			}
		}
		return(out.good());
	}
	//This function reads the Political Party Array data from binary file
	bool PoliticalPartyArray::load(istream& in, const citizenList& currList)
	{
		if (!in)//checks if the file works properly
		{
			return false;
		}
		in.read(rcastc(&phySize), sizeof(phySize));
		if (!in.good())//Checks whether the size reading was performed correctly
		{
			return false;
		}
		politicalPartyArray = new politicalParty * [phySize];//create new politcal party arr

		politicalPartyArray[0] = nullptr;

		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			{
				int headId;
				
				in.read(rcastc(&headId), sizeof(int));

				if (!in.good())
				{
					return false;
				}
				politicalPartyArray[i] = new politicalParty(in, currList, currList.getCitizenById(headId)); //create new politcal party 
				
				if (!in.good())
				{
					return false;
				}
			}

		}
		return (in.good());//Checks if the reads operations from file performed properly
	}
}