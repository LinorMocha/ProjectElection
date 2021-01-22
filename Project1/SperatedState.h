#pragma once

#include "State.h"

namespace proj
{
	class SperatedState : virtual public State
	{
	public:

		SperatedState();
		SperatedState(const string _name, int _numRep,int _numID);
		SperatedState(const SperatedState& sta);
		SperatedState(istream& in);
		ostream& toPrint(ostream& os)const;
		static const int Type;
		int getStateType()const;
		void save(ostream& out) const;

	};
}
