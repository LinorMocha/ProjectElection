#include "StateArray.h"


namespace proj
{
	StateArray::StateArray() : stateArray(nullptr)
	{

	}

	StateArray::~StateArray()
	{
		delete[]stateArray;
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