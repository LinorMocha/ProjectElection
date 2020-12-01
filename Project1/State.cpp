#include "State.h"
#include "ElectionRound.h"
#include "utils.h"


namespace proj
{
	State::State() :name(nullptr), numOfRepresentative(0)
	{
		ElectionRound::countPoliticalParty++;
		numId = ElectionRound::countPoliticalParty;
		//khkjhkj

	}
	
	
	State::State(char* _name, int _numRep) :State()
	{
		numOfRepresentative = _numRep;
		name = utils::my_strdup(_name);
	}


}