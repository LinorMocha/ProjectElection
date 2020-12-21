#include "ELectionProportiaonal.h"
#pragma once
namespace proj {


	ElectionProportiaonal::ElectionProportiaonal(int numRep) : ElectionRound()
	{
		char n[] = "backgroundState";
		_stateArray.addState(n, numRep, false); //name ?
	}

	int ElectionProportiaonal::countState = defultSTATE;
	
	bool ElectionProportiaonal::addCitizen(char* _name, int id, int numD, int _birthYear)
	{
		if (_citizenList.getCitizenById(id))
		{
			_stateArray.addCitizenCountToState(defultSTATE);
			citizen* newC = new citizen(_name, id, _stateArray.getStateById(defultSTATE), _birthYear);
			_citizenList.addNodeToTail(newC);
			return true;
		}

		return false;
	}
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