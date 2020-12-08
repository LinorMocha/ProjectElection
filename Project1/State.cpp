#include "State.h"
#include "ElectionRound.h"
#include "utils.h"


namespace proj
{
	State::State():name(new char()), numOfRepresentative(0),numId(0), countCitizensInState(0)
	{
		name = nullptr;
		
	}
	
	State::State(const State& sta)
	{
		numId = sta.numId;
		numOfRepresentative = sta.numOfRepresentative;
		name = utils::my_strdup(sta.name);
		countCitizensInState = sta.countCitizensInState;
	}

	void State::printState()
	{
		cout << numId << " ";
		cout << name << " ";
		cout << numOfRepresentative << " ";
	}
	State::~State()
	{
		delete[] name;
	}
	const State& State::operator=(const State& input)
	{
		numId = input.numId;
		numOfRepresentative = input.numOfRepresentative;
		name = input.name;
		countCitizensInState = input.countCitizensInState;
		return *this;
	}
	State::State(char* _name, int _numRep) :State()
	{
		ElectionRound::countState++;
		numId = ElectionRound::countState;
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
	int State::getHomManyCitizens()
	{
		return countCitizensInState;
	}

	void State::addCitizen()
	{
		countCitizensInState++;
	}

}