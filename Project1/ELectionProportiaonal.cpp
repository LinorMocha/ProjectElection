#include "ELectionProportiaonal.h"
#pragma once
namespace proj {

	//ctor of ElectionProportiaonal
	ElectionProportiaonal::ElectionProportiaonal(int numRep) : ElectionRound()
	{
		char n[] = "backgroundState";
		_stateArray.addState(n, numRep, false); 
		countState = defultSTATE;
	}
	////serialize constractor for ElectionProportiaonal
	ElectionProportiaonal::ElectionProportiaonal(istream& in)
	{
		load(in);
	}
	//this function creates new citizen using name, ID ,Birth_Year ,numD
	bool ElectionProportiaonal::addCitizen(char* _name, int id, int numD, int _birthYear)
	{
		if (_citizenList.getCitizenById(id)==nullptr)
		{
			_stateArray.addCitizenCountToState(defultSTATE);
			citizen* newC = new citizen(_name, id, _stateArray.getStateById(defultSTATE), _birthYear);
			_citizenList.addNodeToTail(newC);
			return true;
		}

		return false;
	}

	//Adding a representative to party according to repressentative ID ,party ID and state ID
	bool ElectionProportiaonal::addRepresentativetoPoli(int repId, int PoliId, int StateId)
	{
		if (PoliId <= countPoliticalParty)
		{
			citizen* rep = _citizenList.getCitizenById(repId);
			if (rep != nullptr && !_politicalPartyArray.isCitizenIsRepORHead(*rep))
			{
				_politicalPartyArray.addRepToPoli(PoliId, defultSTATE, rep);

				return true;
			}
		}

		return false;
	}
	

}