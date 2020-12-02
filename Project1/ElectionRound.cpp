#include "ElectionRound.h"


namespace proj
{
	int ElectionRound::countPoliticalParty = 0;
	int ElectionRound::countState = 0;
	int ElectionRound::countCitizen = 0;

	ElectionRound::ElectionRound(): _stateArray(),_citizenList(new citizenList())
	{
		date.day = 0;
		date.month = 0;
		date.year = 0;
	}
	ElectionRound::~ElectionRound()
	{
		// delete _stateArray
		delete _citizenList;
	}
	void ElectionRound::addState(char* name, int numRep)
	{
		_stateArray.addState(name, numRep);
	}
	void ElectionRound::printStateArray()
	{

	}

}