#include"politicalPartyArray.h"
#include"ElectionRound.h"

namespace proj
{
	PoliticalPartyArray::PoliticalPartyArray() :politicalPartyArray(new politicalParty()), phySize(1)
	{

	}
	PoliticalPartyArray::~PoliticalPartyArray()
	{
		delete[]politicalPartyArray;
	}
	void PoliticalPartyArray::addPoliticalParty(char* name, citizen* head)
	{
		politicalParty newParty(name, head);

		if (ElectionRound::countPoliticalParty > phySize)
			reSizePoliticalPartyArray();
		politicalPartyArray[newParty.getNumId()] = newParty;
		
	}

	const politicalParty& PoliticalPartyArray::getPoliticalPartyById(int numId)
	{
		return politicalPartyArray[numId];
	}
	const citizen& PoliticalPartyArray::getPoliticalPartyHead(int numId)
	{
		return *politicalPartyArray[numId].getPoliticalPartyHead();
	}
	void PoliticalPartyArray::printPoliticalPartyArray()
	{
		for (int i = 0; i < ElectionRound::countPoliticalParty; i++)
		{
			politicalPartyArray[i].printPoliticalParty();
		}
		
	}
	void PoliticalPartyArray::reSizePoliticalPartyArray()
	{
		phySize *= 2;
		politicalParty* res = new politicalParty[phySize];

		for (int i = 1; i <= ElectionRound::countPoliticalParty; i++)
		{
			res[i] = politicalPartyArray[i];
		}

	politicalPartyArray = res;
	}
}