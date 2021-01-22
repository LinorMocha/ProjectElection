#include "State.h"
#include "ElectionRound.h"



namespace proj
{	
	//ctor
	State::State():numOfRepresentative(0),numId(0), countCitizensInState(0),countVotesInState(0){}
	//ctor

	State::State(const string _name, int _numRep) : State()
	{
		if (_numRep <= 0)
			throw invalid_argument("Error! number of representative cant be negative ");
		numId = ElectionRound::countState;
		numOfRepresentative = _numRep;
		name = _name;
	}
	//copy ctor
	State::State(const State& sta)
	{
		numId = sta.numId;
		numOfRepresentative = sta.numOfRepresentative;
		name = sta.getName();
		countCitizensInState = sta.countCitizensInState;
		countVotesInState = sta.countVotesInState;
	
	}
	//serialize constractor of state
	State::State(istream& in)
	{
		load(in);
	}
	// This function prints the information of the curr state using << operator 
	ostream& operator<<(ostream& os, const State& state)
	{
		os << "state number: " << state.numId;
		os << "  ||  state name: " << state.name;
		os << "  ||  state number of rep: " << state.numOfRepresentative;
		return state.toPrint(os);
	}

	//dctor
	State::~State() {  }
	
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

	/*ostream& State::print(ostream& os) const
	{
		os << "state number: " << numId;
		os << "  ||  state name: " << name;
		os << "  ||  state number of rep: " << numOfRepresentative;
		return os;
	}*/

	bool State::operator==(const State& input)
	{
		if (numId == input.numId && numOfRepresentative == input.numOfRepresentative && name == input.name &&
			countCitizensInState == input.countCitizensInState && countVotesInState == input.countVotesInState)
			return true;
		return false;
	}

	bool State::operator==(const int id)
	{
		return (numId == id);
	}
	

	
	//This function returns the name of the state
	string State::getName()const {	return name;}
	
	//This function returns the ID number of the state
	int State::getNumId()const{	return numId;}
	
	//This function returns the number of the Representative in the curr state
	int State::getNumOfRepresentative()const {	return numOfRepresentative;	}
	
	//This function returns how many citizens there is in the curr state
	int State::getHowManyCitizens()const{ return countCitizensInState;	}
	
	//This function returns the amount of votes in the current state
	int State::getCountVotesInState()const{ return countVotesInState;	}

	//This function increases the counter of citizens in the current state
	void State::addCitizen(){ countCitizensInState++;}
	
	//This function increases the counter of votes in the current state
	void State::addVote(){	countVotesInState++;}
	
	//This function writes the state data to binary file
	void State::save(ostream& out) const
	{
		out.write(rcastcc(&numId), sizeof(int));
		out.write(rcastcc(&numOfRepresentative), sizeof(int));
		out.write(rcastcc(&countCitizensInState), sizeof(countCitizensInState));
		out.write(rcastcc(&countVotesInState), sizeof(countVotesInState));
		int len=name.length();
		out.write(rcastcc(&len), sizeof(int));
		out.write(rcastcc(name.c_str()), len);
		if (!out.good())//Checks if the writes operations to file performed properly
			throw invalid_argument("save state to file didn't preforemd proprtaly");
	}
	
	//This function reads the state data from binary file
	void State::load(istream& in)
	{
		
		in.read(rcastc(&numId), sizeof(int));
		in.read(rcastc(&numOfRepresentative), sizeof(int));
		in.read(rcastc(&countCitizensInState), sizeof(countCitizensInState));
		in.read(rcastc(&countVotesInState), sizeof(countVotesInState));
		
		int len;
		in.read(rcastc(&len), sizeof(len));
		if (!in.good())//check len reading from file
		{
			throw invalid_argument("Load state from file didn't preforemd proprtaly");

		}
		name.resize(len);
		in.read((char*)&name[0], len);
		if (!in.good())//check len reading from file
		{
			throw invalid_argument("Load stateArray from file didn't preforemd proprtaly");

		}
		
	}
}