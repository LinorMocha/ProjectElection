#pragma once

#include "State.h"

namespace proj
{
	class SperatedState : virtual public State
	{
	private:
		
	public:

		SperatedState();
		~SperatedState() { };
		SperatedState(const string _name, int _numRep);
		SperatedState(const SperatedState& sta);
		friend ostream& operator<<(ostream& os, const SperatedState& state);
		const SperatedState& operator=(const SperatedState& input);
		static const int Type;

		int getStateType()const;

	};
}
