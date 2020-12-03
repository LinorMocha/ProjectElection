#include "ElectionRound.h"


namespace proj
{
	int ElectionRound::countPoliticalParty = 0;
	int ElectionRound::countState = 0;
	int ElectionRound::countCitizen = 0;

	ElectionRound::ElectionRound(): _stateArray(),_citizenList()
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
		
		citizen newC(_name, id, numD, _birthYear);
		_citizenList.addNodeToTail(&newC);
	}
	const citizen& ElectionRound::getCitizenById(int numId)
	{
		return *_citizenList.getItem(numId);
	}
	void ElectionRound::printCitizenList()
	{
		_citizenList.printList();
	}


	////////////  POLITICALPARTY  //////////

	void ElectionRound::addPoliticalParty(char* name, int headId)
	{

	}




}