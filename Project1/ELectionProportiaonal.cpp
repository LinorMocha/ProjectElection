#include "ELectionProportiaonal.h"
#pragma once
namespace proj {

	//ctor of ElectionProportiaonal
	ElectionProportiaonal::ElectionProportiaonal(int numRep) : ElectionRound()
	{
		char n[] = "backgroundState";
		State* backgroundState = new State(n,numRep,false);
		_stateArray.push_back(backgroundState);
		countState = defultSTATE;
	}

	////serialize constractor for ElectionProportiaonal
	ElectionProportiaonal::ElectionProportiaonal(istream& in)
	{
		load(in);
	}
	
	//this function creates new citizen using name, ID ,Birth_Year ,numD
	void ElectionProportiaonal::addCitizen(char* _name, int id, int numD, int _birthYear)
	{
		addCitizen(_name, id, defultSTATE, _birthYear);
	}

	//Adding a representative to party according to repressentative ID ,party ID and state ID
	void ElectionProportiaonal::addRepresentativetoPoli(int repId, int PoliId, int StateId)
	{
		addRepresentativetoPoli(repId, PoliId, defultSTATE);
	}
}