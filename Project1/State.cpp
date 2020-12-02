#include "State.h"
#include "ElectionRound.h"
#include "utils.h"


namespace proj
{
	State::State() :name(nullptr), numOfRepresentative(0)
	{
		
		numId = ElectionRound::countPoliticalParty;
		ElectionRound::countPoliticalParty++;
		cout << "con state" << endl;

	}
	
	void State::operator=(const State& input)
	{
		numId = input.numId;
		numOfRepresentative = input.numOfRepresentative;
		name = utils::my_strdup(input.name);
		
	}
	State::State(char* _name, int _numRep) :State()
	{
		numOfRepresentative = _numRep;
		name = utils::my_strdup(_name);
	}

	char* State::getName()
	{
		return name;
	}
	int State::getNumId()
	{
		return numId;
	}
	int State::getNumOfRepresentative()
	{
		return numOfRepresentative;
	}
}