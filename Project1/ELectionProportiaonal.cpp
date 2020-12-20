#include "ELectionProportiaonal.h"
#pragma once

proj::ElectionProportiaonal::ElectionProportiaonal(int numRep) : ElectionRound()
{
	_stateArray.addState("backgroundState", numRep , false); //name ?
}
