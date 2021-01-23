#pragma once
#include "ElectionRound.h"
#include <fstream>

namespace proj
{
	class ElectionProportiaonal : virtual public ElectionRound {
	public:
		ElectionProportiaonal(istream& in);
		ElectionProportiaonal(int numRep);
		virtual void addRepresentativetoPoli(int repId, int PoliId, int StateId);
		virtual void addCitizen(const string _name, int id, int numD, int _birthYear);
		static const int defultSTATE = 1;


	};



}