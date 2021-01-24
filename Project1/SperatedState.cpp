#include "SperatedState.h"
#include "utils.h"

namespace proj
{
	const int SperatedState::Type = 2;
	
	//Ctor
	SperatedState::SperatedState() : State(){ }
	
	//Ctor
	SperatedState::SperatedState(const string _name, int _numRep, int _numId): State(_name,_numRep,_numId)
	{
		
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
	
	ostream& SperatedState::toPrint(ostream& os) const
	{

		os << "  ||  state brand: sperated " << endl;
		return os;
	}
	
	//Copy Ctor
	SperatedState::SperatedState(const SperatedState& sta) :State(sta)
	{
	}
	
	
	//return state type
	int SperatedState::getStateType() const
	{
		return Type;
	}

	
}