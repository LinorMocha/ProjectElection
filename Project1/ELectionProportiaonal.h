#pragma once
#include "ElectionRound.h"
#include <fstream>

namespace proj
{
	class ElectionProportiaonal : public ElectionRound {
	private:

	public:
		ElectionProportiaonal(int numRep);
		virtual bool addCitizen(char* _name, int id, int numD, int _birthYear);
		static const int defultSTATE = 1;

		virtual bool addRepresentativetoPoli(int repId, int PoliId, int StateId);


	};



}