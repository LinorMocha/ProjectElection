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

	ostream& operator << (ostream& os, const State& state)
	{
		os << "state number:" << state.getNumId()<< endl;
		os << "state name:" << state.getName() << endl;
		os << "state number of rep:" << state.getNumOfRepresentative() << endl;
		return os;
	}

	void State::printState()
	{
		cout <<"state number:"<< numId <<endl;
		cout <<"state name:"<< name << endl;
		cout << "state number of rep:" << numOfRepresentative << endl;
		
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

	char* State::getName()const
	{
		return name;
	}
	int State::getNumId()const
	{
		return numId;
	}
	int State::getNumOfRepresentative()const
	{
		return numOfRepresentative;
	}
	int State::getHowManyCitizens()const
	{
		return countCitizensInState;
	}
	bool State:: IsStateIDValid(int Numid)
	{

	}

	bool State::addCitizen()
	{
		return countCitizensInState++;  // there`s a break up point here when we add citizen before we add state - should return a statment to the user
	}

}