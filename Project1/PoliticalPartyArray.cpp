#include"politicalPartyArray.h"
#include"ElectionRound.h"

namespace proj
{
	PoliticalPartyArray::PoliticalPartyArray() :politicalPartyArray(new politicalParty*()), phySize(1)
	{

	}
	PoliticalPartyArray::~PoliticalPartyArray()
	{
		delete[]politicalPartyArray;
	}
	void PoliticalPartyArray::addState()
	{
		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			politicalPartyArray[i]->addState();
		}
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

	void PoliticalPartyArray::addVote(int poliId,int stateId)
	{
		politicalPartyArray[poliId]->addVote(stateId);
	}

	void PoliticalPartyArray::addPoliticalParty(char* name, citizen* head)
	{
		politicalParty *newParty=new politicalParty(name, head);

		if (ElectionRound::countPoliticalParty >= phySize)
			reSizePoliticalPartyArray();
		politicalPartyArray[newParty->getNumId()] = newParty;
		
	}

	const politicalParty& PoliticalPartyArray::getPoliticalPartyById(int numId)
	{
		return *politicalPartyArray[numId];
	}
	 citizen* PoliticalPartyArray::getPoliticalPartyHead(int numId)
	{
		return politicalPartyArray[numId]->getPoliticalPartyHead();
	}
	void PoliticalPartyArray::printPoliticalPartyArray()
	{
		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			politicalPartyArray[i]->printPoliticalParty();
		}
		
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
			//res[i] =politicalPartyArray[i];
		}

	politicalPartyArray = res;
	}
	void PoliticalPartyArray::addRepToPoli(int PolId, int StateId, citizen* rep)
	{
		politicalPartyArray[PolId]->addRepresentitive(rep, StateId);
	}

	/*const citizenList& PoliticalPartyArray::getSelectedRepList(int PoliId, int StateId, int repCount)
	{
		return politicalPartyArray[PoliId]->getWinningRepresentitives(StateId, repCount);
	}*/

	void PoliticalPartyArray::printSelectedRepList(int PoliId, int StateId, int repCount)
	{
		politicalPartyArray[PoliId]->PrintWinningRepresentitives(StateId, repCount);
	}
	
}