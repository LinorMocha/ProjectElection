#include "UnionState.h"
#include <vector>
#include "utils.h"

namespace proj
{
	const int UnionState::Type = 1;
	
	//Ctor
	UnionState::UnionState() : State(){	}
	
	//Serialize constractor of state
	UnionState::UnionState(istream& in){ 
		try {
			load(in);
		}
		catch (std::exception& ex) {
			throw ex;
		}
	}

	//Ctor
	UnionState::UnionState(const string _name, int _numRep,int _numId):UnionState()
	{
		if (_numRep <= 0)
			throw invalid_argument("Error! number of representative cant be negative ");
		numId = _numId;
		name = _name;
		numOfRepresentative = _numRep;
	}
	
	//Copy Ctor
	UnionState::UnionState(const UnionState& sta)
	{
		this->operator=(sta);
	}
	// This function prints the information of the curr state using << operator 
	ostream& UnionState::toPrint(ostream& os)const
	{
		os << "  ||  state type: union" <<endl;
		return os;
	}

	

	//return state type
	int UnionState::getStateType() const
	{
		return Type;
	}

	

}