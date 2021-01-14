#include "UnionState.h"
#include <vector>

namespace proj
{
	const int UnionState::Type = 1;
	UnionState::UnionState() : State()
	{
	}
	UnionState::UnionState(const string _name, int _numRep): State(_name,_numRep)
	{
	}
	UnionState::UnionState(const UnionState& sta)
	{
		this->operator=(sta);
	}

	int UnionState::getStateType() const
	{
		return Type;
	}

	
	ostream& operator<<(ostream& os, const UnionState& state)
	{
		os << state;
		os << "  ||  state brand: union " << endl;
		return os;
    }

}