#include "State.h"
#include "ElectionRound.h"



namespace proj
{	//ctor
	State::State():numOfRepresentative(0),numId(0), countCitizensInState(0),countVotesInState(0),stateStatus(true)
	{
		
		
	}
	//ctor
	State::State(const State& sta)
	{
		numId = sta.numId;
		numOfRepresentative = sta.numOfRepresentative;
		name = sta.getName();
		countCitizensInState = sta.countCitizensInState;
		stateStatus = sta.stateStatus;
		countVotesInState = sta.countVotesInState;
	}
	//serialize constractor of state
	State::State(istream& in)
	{
		load(in);
	}
	// This function prints the information of the curr state using << operator 
	ostream& operator << (ostream& os, const State& state)
	{
		os << "state number: " << state.getNumId();
		os << "  ||  state name: " << state.getName();
		os << "  ||  state number of rep: " << state.getNumOfRepresentative();
		if (state.getStateStatus())
			os << "  ||  state brand: union "<<endl;
		else
			os << "  ||  state brand: sperated "<< endl;

		return os;
	}
	//dctor
	State::~State()
	{
		
	}
	//operator = copy current state to a new atate
	const State& State::operator=(const State& input)
	{
		numId = input.numId;
		numOfRepresentative = input.numOfRepresentative;
		name = input.name;
		countCitizensInState = input.countCitizensInState;
		countVotesInState = input.countVotesInState;
		return *this;
	}
	//ctor
	State::State(const string _name, int _numRep ,bool Status) : State() 
	{
		ElectionRound::countState++;
		numId = ElectionRound::countState;
		numOfRepresentative = _numRep;
		name = _name;
		stateStatus = Status;
	}
	//This function returns the status of the state
	bool State::getStateStatus()const
	{
		return stateStatus;
	}
	//This function returns the name of the state
	string State::getName()const
	{
		return name;
	}
	//This function returns the ID number of the state
	int State::getNumId()const
	{
		return numId;
	}
	//This function returns the number of the Representative in the curr state
	int State::getNumOfRepresentative()const
	{
		return numOfRepresentative;
	}
	//This function returns how many citizens there is in the curr state
	int State::getHowManyCitizens()const
	{
		return countCitizensInState;
	}
	//This function returns the amount of votes in the current state
	int State::getCountVotesInState()const
	{
		return countVotesInState;
	}
	//This function increases the counter of citizens in the current state
	void State::addCitizen()
	{
	 countCitizensInState++; 
	}
	//This function increases the counter of votes in the current state
	void State::addVote()
	{
		countVotesInState++;
	}
	//This function writes the state data to binary file
	bool State::save(ostream& out) const
	{
		if (!out)//checks if the file works properly
		{
			return false;
		}

		out.write(rcastcc(&numId), sizeof(int));
		out.write(rcastcc(&numOfRepresentative), sizeof(int));
		out.write(rcastcc(&countCitizensInState), sizeof(countCitizensInState));
		out.write(rcastcc(&countVotesInState), sizeof(countVotesInState));
		out.write(rcastcc(&stateStatus), sizeof(stateStatus));
		int len=name.length();
		out.write(rcastcc(&len), sizeof(int));
		out.write(rcastcc(name.c_str()), len);
		

		return (out.good());//Checks if the writes operations to file performed properly
	}
	//This function reads the state data from binary file
	bool State::load(istream& in)
	{
		if (!in)//checks if the file works properly
		{
			return false;
		}
		in.read(rcastc(&numId), sizeof(int));
		in.read(rcastc(&numOfRepresentative), sizeof(int));
		in.read(rcastc(&countCitizensInState), sizeof(countCitizensInState));
		in.read(rcastc(&countVotesInState), sizeof(countVotesInState));
		in.read(rcastc(&stateStatus), sizeof(stateStatus));
		
		int len;
		in.read(rcastc(&len), sizeof(len));
		if (!in.good())//check len reading from file
		{
			return false;
		}
		name.resize(len);
		in.read((char*)&name[0], len);
	
		return (in.good());//Checks if the writes operations to file performed properly
	}
}