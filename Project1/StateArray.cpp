#include "StateArray.h"
#include"ElectionRound.h"

namespace proj
{
	StateArray::StateArray() : stateArray(new State()),phySize(1)
	{
				
	}

	StateArray::~StateArray()
	{
		delete[]stateArray;
	}


	void StateArray::addState(char* name, int _numRep)
	{
		State newState(name, _numRep);
		if (ElectionRound::countState > phySize)
			reSizeStateArray(ElectionRound::countState, phySize * 2);
		
		stateArray[newState.getNumId()] = newState;
		phySize = phySize * 2;		
	}

	void StateArray::reSizeStateArray(int size, int newSize)
	{
		State* res = new State [newSize];
		for (int i = 1; i <= size; i++)
		{
			res[i] = stateArray[i];
		}
		
		delete stateArray;
		stateArray = res;
	}


	// יש את הגטרים האלה גם במחוז עצמו צריך להבין אם יש להם צורך גם פה
	State *StateArray::getStateById(int Id)
	{
		return &stateArray[Id];
	}

	int StateArray::getStatenumOfRepresentative(int Id)
	{
		return stateArray[Id].getNumOfRepresentative();
	}


}