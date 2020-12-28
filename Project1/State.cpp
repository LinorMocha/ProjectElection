#include "State.h"
#include "ElectionRound.h"



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

	State::State(istream& in)
	{
		load(in);
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
	State::State(const char* _name, int _numRep ,bool Status) : State()
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
	const char* State::getName()const
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
	void State::save(ostream& out) const
	{
		out.write(rcastcc(&name), sizeof(name));
		out.write(rcastcc(&numId), sizeof(numId));
		out.write(rcastcc(&numOfRepresentative), sizeof(numOfRepresentative));
		out.write(rcastcc(&countCitizensInState), sizeof(countCitizensInState));
		out.write(rcastcc(&countVotesInState), sizeof(countVotesInState));
		out.write(rcastcc(&stateStatus), sizeof(stateStatus));
	}
	void State::load(istream& in)
	{
		in.read(rcastc(&name), sizeof(name));
		in.read(rcastc(&numId), sizeof(numId));
		in.read(rcastc(&numOfRepresentative), sizeof(numOfRepresentative));
		in.read(rcastc(&countCitizensInState), sizeof(countCitizensInState));
		in.read(rcastc(&countVotesInState), sizeof(countVotesInState));
		in.read(rcastc(&stateStatus), sizeof(stateStatus));
	}
}