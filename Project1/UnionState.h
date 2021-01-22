#pragma once
#include "State.h"


namespace proj
{
	class UnionState : virtual public State
	{  
	
	public:

		UnionState();
		UnionState(istream& in);
		UnionState(const string _name, int _numRep,int _numId);
		UnionState(const UnionState& sta);
		ostream& toPrint(ostream& os)const;
		static const int Type;
		void save(ostream& out)const;
		int getStateType()const;

	};
}