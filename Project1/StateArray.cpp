#include "StateArray.h"
#include"ElectionRound.h"

namespace proj
{
	StateArray::StateArray() : stateArray(new State*()),phySize(1)
	{
		cout << "con state aaray" << endl;
	}

	StateArray::~StateArray()
	{
		for (int i = 0; i <= ElectionRound::countState; i++)
		{
			delete[] stateArray[i];
		}
	}
	void StateArray::addCitizenCountToState(int stateId)
	{
		stateArray[stateId]->addCitizen();
	}

	void StateArray::addState(char* name, int _numRep)
	{
		State* newState = new State(name, _numRep);
		

		if (ElectionRound::countState > phySize)
			reSizeStateArray();
		
		stateArray[newState->getNumId()] = newState;
			
	}

	void StateArray::reSizeStateArray()
	{
		phySize *= 2;
		State** res = new State*[phySize];

		for (int i = 0; i <= ElectionRound::countState; i++)
		{
			res[i]= new State(*stateArray[i]);
		}
		delete[] stateArray;
		stateArray = res;
	}
	void StateArray::printStateArray()
	{
		for (int i = 1; i < ElectionRound::countState; i++)
			stateArray[i]->printState();
	}

	const State& StateArray::getStateById(int Id)
	{
		return *stateArray[Id];
	}

	int StateArray::getStatenumOfRepresentative(int Id)
	{
		return stateArray[Id]->getNumOfRepresentative();
	}

	int StateArray::getCitizenCount(int stateId)
	{
		return stateArray[stateId]->getHomManyCitizens();
	}
}