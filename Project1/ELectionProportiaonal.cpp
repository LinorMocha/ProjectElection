#include "ELectionProportiaonal.h"
#pragma once
namespace proj {


	ElectionProportiaonal::ElectionProportiaonal(int numRep) : ElectionRound()
	{
		_stateArray.addState("backgroundState", numRep, false); //name ?
	}

	int ElectionProportiaonal::countState = 1;
	

}