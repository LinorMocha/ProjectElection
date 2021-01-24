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
	UnionState::UnionState(const string _name, int _numRep,int _numId):State(_name,_numRep,_numId)
	{
	}
	
	//Copy Ctor
	UnionState::UnionState(const UnionState& sta):State(sta)
	{
	
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