#include"politicalPartyArray.h"
#include"ElectionRound.h"

namespace proj
{
	PoliticalPartyArray::PoliticalPartyArray() :politicalPartyArray(new politicalParty* ()), phySize(1)
	{

	}
	PoliticalPartyArray::~PoliticalPartyArray()
	{
		for (int i = 0; i <= ElectionRound::countPoliticalParty; i++)
		{
			delete politicalPartyArray[i];
		}

	}
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

	int PoliticalPartyArray::getOverAllVotesForPoliInState(int poliId, int stateId)
	{
		return politicalPartyArray[poliId]->getHowManyVotesForState(stateId);
	}
	int PoliticalPartyArray::getOverAllVotesForPoli(int poliId)
	{
		return politicalPartyArray[poliId]->getHowManyVotesOverAll();
	}
	char* PoliticalPartyArray::getName(int poliId)
	{
		return politicalPartyArray[poliId]->getName();
	}

	void PoliticalPartyArray::addVote(int poliId, int stateId)
	{
		politicalPartyArray[poliId]->addVote(stateId);
	}

	void PoliticalPartyArray::addPoliticalParty(char* name, citizen* head)
	{
		politicalParty* newParty = new politicalParty(name, head);

		if (ElectionRound::countPoliticalParty >= phySize)
			reSizePoliticalPartyArray();
		politicalPartyArray[newParty->getNumId()] = newParty;

	}

	const politicalParty& PoliticalPartyArray::getPoliticalPartyById(int numId)
	{
		return *politicalPartyArray[numId];
	}
	const citizen& PoliticalPartyArray::getPoliticalPartyHead(int numId)
	{
		return politicalPartyArray[numId]->getPoliticalPartyHead();
	}

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
	void PoliticalPartyArray::reSizePoliticalPartyArray()
	{
		phySize *= 2;
		politicalParty** res = new politicalParty*[phySize];

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
	void PoliticalPartyArray::addRepToPoli(int PolId, int StateId, citizen* rep)
	{
		politicalPartyArray[PolId]->addRepresentitive(rep, StateId);
	}

	

	void PoliticalPartyArray::printSelectedRepList(int PoliId, int StateId, int repCount) const
	{
		politicalPartyArray[PoliId]->PrintWinningRepresentitives(StateId, repCount);
	}
	void PoliticalPartyArray::save(ostream& out) const
	{
		out.write(rcastcc(&phySize), sizeof(phySize));
		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			politicalPartyArray[i]->save(out);
		}
	}

	void PoliticalPartyArray::load(istream& in, const citizenList& currList)
	{
		in.read(rcastc(&phySize), sizeof(phySize));
		politicalPartyArray = new politicalParty * [phySize];

		politicalPartyArray[0] = nullptr;

		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			{
				int headId;
				in.read(rcastc(&headId), sizeof(int));
				politicalPartyArray[i] = new politicalParty(in, currList, currList.getCitizenById(headId));
			}

		}
	}
}