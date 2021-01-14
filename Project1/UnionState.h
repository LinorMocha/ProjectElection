#pragma once
#include "State.h"

namespace proj
{
	class UnionState : virtual public State
	{  
	
	public:

		UnionState();
		~UnionState() { };
		UnionState(const string _name, int _numRep);
		UnionState(const UnionState& sta);
		friend ostream& operator<<(ostream& os, const UnionState& state);
		const UnionState& operator=(const UnionState& input);
		static const int Type;
		

		int getStateType()const;

	};
}