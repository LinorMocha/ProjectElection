#include "SperatedState.h"
#include "utils.h"

namespace proj
{
	const int SperatedState::Type = 2;
	
	//Ctor
	SperatedState::SperatedState() : State(){ }
	
	//Ctor
	SperatedState::SperatedState(const string _name, int _numRep, int _numId): SperatedState()
	{
		if (_numRep <= 0)
			throw invalid_argument("Error! number of representative cant be negative ");
		numId = _numId;
		name = _name;
		numOfRepresentative = _numRep;
	}
	//Serialize constractor of state
	SperatedState::SperatedState(istream& in) {
		try {
			load(in);
		}
		catch (std::exception& ex) {
			throw ex;
		}
	}
	// This function prints the information of the curr state using << operator 
	ostream& SperatedState::toPrint(ostream& os) const{

		os << "  ||  state brand: sperated " << endl;
		return os;
	}
	
	//Copy Ctor
	SperatedState::SperatedState(const SperatedState& sta)
	{
		numId = sta.numId;
		numOfRepresentative = sta.numOfRepresentative;
		name = sta.name;
		countCitizensInState = sta.countCitizensInState;
		countVotesInState = sta.countVotesInState;
	}
	
	
	//return state type
	int SperatedState::getStateType() const
	{
		return Type;
	}

	// save state
	void SperatedState::save(ostream& out) const
	{
		int tempStatus = getStateType();
		out.write(rcastcc(&tempStatus), sizeof(int));
		save(out);
	}
}