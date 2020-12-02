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
			reSizeStateArray(ElectionRound::countState, phySize * 2);
		
		stateArray[newState.getNumId()] = newState;
		phySize = phySize * 2;		
	}

	void StateArray::reSizeStateArray(int size, int newSize)
	{
		
		State* res = new State [newSize];
		//res[2].getName();
		
	//	cout << res[2].getNumId() << "linor"<< endl;
		res[0] = stateArray[0];
			

		for (int i = 0; i <= newSize; i++)
		{
			res[i]=stateArray[i];
		}
		
		delete stateArray;
		stateArray = res;
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