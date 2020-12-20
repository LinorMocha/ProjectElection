#pragma once
#include "ElectionRound.h"
#include <fstream>

namespace proj
{
	class ElectionProportiaonal : public ElectionRound {
	private:

	public:
		ElectionProportiaonal(int numRep);
		ElectionProportiaonal(istream& in);


	};



}