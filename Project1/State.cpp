#include "State.h"
#include "ElectionRound.h"
#include "utils.h"


namespace proj
{
	State::State():name(new char()), numOfRepresentative(0),numId(0), countCitizensInState(0),countVotesInState(0),stateStatus(true)
	{
		name = nullptr;
		
	}
	
	State::State(const State& sta)
	{
		numId = sta.numId;
		numOfRepresentative = sta.numOfRepresentative;
		name = utils::my_strdup(sta.name);
		countCitizensInState = sta.countCitizensInState;
		stateStatus = sta.stateStatus;
		countVotesInState = sta.countVotesInState;
	}

	ostream& operator << (ostream& os, const State& state)
	{
		os << "state number: " << state.getNumId();
		os << "  ||  state name: " << state.getName();
		os << "  ||  state number of rep: " << state.getNumOfRepresentative() << endl;
		if (state.getStateStatus())
			os << "  ||  state brand: union ";
		else
			os << "  ||  state brand: sperated ";

		return os;
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
		countVotesInState = input.countVotesInState;
		return *this;
	}
	State::State(char* _name, int _numRep ,bool Status) : State()
	{
		ElectionRound::countState++;
		numId = ElectionRound::countState;
		numOfRepresentative = _numRep;
		name = utils::my_strdup(_name);
		stateStatus = Status;
	}
	bool State::getStateStatus()const
	{
		return stateStatus;
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

	int State::getCountVotesInState()const
	{
		return countVotesInState;
	}

	void State::addCitizen()
	{
	 countCitizensInState++; 
	}

	void State::addVote()
	{
		countVotesInState++;
	}
}