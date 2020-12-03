#include "StateArray.h"
#include"ElectionRound.h"

namespace proj
{
	StateArray::StateArray() : stateArray(new State()),phySize(1)
	{
		cout << "con state aaray" << endl;
	}

	StateArray::~StateArray()
	{
		delete[]stateArray;
	}


	void StateArray::addState(char* name, int _numRep)
	{
		State newState(name, _numRep);
		if (ElectionRound::countState > phySize)
			reSizeStateArray();
		
		stateArray[newState.getNumId()] = newState;
		phySize = phySize * 2;		
	}

	void StateArray::reSizeStateArray()
	{
		phySize *= 2;
		State* res = new State[phySize];

		for (int i = 0; i <= ElectionRound::countState; i++)
		{
			State a=stateArray[i];
			res[i] = a;
		}
		delete[] stateArray;
		stateArray = res;
	}
	void StateArray::printStateArray()
	{
		for (int i = 1; i < ElectionRound::countState; i++)
			stateArray[i].printState();
	}


	// יש את הגטרים האלה גם במחוז עצמו צריך להבין אם יש להם צורך גם פה
	const State& StateArray::getStateById(int Id)
	{
		return stateArray[Id];
	}

	int StateArray::getStatenumOfRepresentative(int Id)
	{
		return stateArray[Id].getNumOfRepresentative();
	}


}