#include "SperatedState.h"

namespace proj
{
	const int SperatedState::Type = 2;
	SperatedState::SperatedState() : State()
	{
	}
	SperatedState::SperatedState(const string _name, int _numRep) : State(_name, _numRep)
	{
	}
	SperatedState::SperatedState(const SperatedState& sta)
	{
		numId = sta.numId;
		numOfRepresentative = sta.numOfRepresentative;
		name = sta.name;
		countCitizensInState = sta.countCitizensInState;
		countVotesInState = sta.countVotesInState;
		
	}

	const SperatedState& SperatedState::operator=(const SperatedState& input)
	{
		numId = input.numId;
		numOfRepresentative = input.numOfRepresentative;
		name = input.name;
		countCitizensInState = input.countCitizensInState;
		countVotesInState = input.countVotesInState;
		
		return *this;
	}



	ostream& operator<<(ostream& os, const SperatedState& state)
	{
		os << state;
		os << "  ||  state brand: sperated " << endl;
		return os;
	}

	int SperatedState::getStateType() const
	{
		return Type;
	}
}