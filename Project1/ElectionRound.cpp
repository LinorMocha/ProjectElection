#include "ElectionRound.h"


namespace proj
{
	int ElectionRound::countPoliticalParty = 0;
	int ElectionRound::countState = 0;
	int ElectionRound::countCitizen = 0;

	ElectionRound::ElectionRound(): _stateArray(),_citizenList(),_politicalPartyArray()
	{
		date.day = 0;
		date.month = 0;
		date.year = 0;
	}
	ElectionRound::~ElectionRound()
	{
		
	}


	///////////// STATE implementation//////////////////
	void ElectionRound::addState(char* name, int numRep)
	{
		_stateArray.addState(name, numRep);
		
		_politicalPartyArray.addState();
	}



	void ElectionRound::printStateArray()
	{
		_stateArray.printStateArray();
	}
	const State& ElectionRound::getStateById(int numId)
	{
		return (_stateArray.getStateById(numId));
	}

	///////////// CITIZEN implementation//////////////////
	void ElectionRound::addCitizen(char* _name, int id, int numD, int _birthYear)
	{
		_stateArray.addCitizenCountToState(numD);
		citizen newC(_name, id, numD, _birthYear);
		_citizenList.addNodeToTail(&newC);
	}
	const citizen& ElectionRound::getCitizenById(int numId)
	{
		return *_citizenList.getCitizenById(numId);
	}
	void ElectionRound::printCitizenList()
	{
		_citizenList.printList();
	}


	////////////  POLITICALPARTY implementation  //////////

	void ElectionRound::addPoliticalParty(char* name, int headId)
	{
		citizen * headPoly=_citizenList.getCitizenById(headId);
		if (headPoly != nullptr)
		{
			_politicalPartyArray.addPoliticalParty(name, headPoly);
		}
		else
			cout << "there is no citizen with this Id in the country" << endl;
	}
	void ElectionRound::printPoliticalPartyArray()
	{
		_politicalPartyArray.printPoliticalPartyArray();
	}

	const politicalParty& ElectionRound::getPoliById(int numId)
	{
		return _politicalPartyArray.getPoliticalPartyById(numId);
		
	}
	const citizenList& ElectionRound::getSelectedRepList(int PoliId, int StateId,int repCount)
	{
		return _politicalPartyArray.getSelectedRepList(PoliId, StateId, repCount);
	}

	void ElectionRound::addRepresentativetoPoli(int repId ,int PoliId, int StateId)
	{
		citizen* rep = _citizenList.getCitizenById(repId);
		if (rep != nullptr)
			_politicalPartyArray.addRepToPoli(PoliId, StateId, rep);
		else
			cout << "there is no citizen with this Id in the country" << endl;

	}


	///////////// Vote implementation///////////////

	void ElectionRound::addVote(int citizenId, int poliId)
	{
		citizen* cit = _citizenList.getCitizenById(citizenId);
		cit->setvote(poliId);
		_politicalPartyArray.addVote(poliId, cit->getStateId());
	}
}