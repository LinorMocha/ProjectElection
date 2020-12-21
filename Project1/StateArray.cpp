#include "StateArray.h"
#include"ElectionRound.h"

namespace proj
{
	StateArray::StateArray() : stateArray(new State*()),phySize(1)
	{
		
	}

	StateArray::~StateArray()
	{
		for (int i = 0; i <= ElectionRound::countState; i++)
		{
			delete stateArray[i];
		}
		


	}
	void StateArray::addCitizenCountToState(int stateId)
	{
		stateArray[stateId]->addCitizen();
	}
	void StateArray::addVoteCountToState(int stateId)
	{
		stateArray[stateId]->addVote();
	}

	void StateArray::save(ostream& out) const
	{
		out.write(rcastcc(&phySize), sizeof(phySize));
		for (int i = 1; i <= ElectionRound::countState; i++)
		{
			stateArray[i]->save(out);
		}


	}

	void StateArray::load(istream& in)
	{
		in.read(rcastc(&phySize), sizeof(phySize));
		State** res = new State * [phySize];
		for (int i = 0; i <= ElectionRound::countState; i++)
		{
			if (i == 0)
				res[i] = nullptr;
			else
				res[i] = new State(in);
		}
		stateArray = res;

	}

	void StateArray::addState(char* name, int _numRep, bool Status)
	{
		State* newState = new State(name, _numRep ,Status);
		

		if (ElectionRound::countState >= phySize)
			reSizeStateArray();
		
		stateArray[newState->getNumId()] = newState;
			
	}

	void StateArray::reSizeStateArray()
	{
		phySize *= 2;
		State** res = new State*[phySize];

		for (int i = 0; i < ElectionRound::countState; i++)
		{
			if (i == 0)
				res[i] = nullptr;
			else
			res[i]= new State(*stateArray[i]);
		}
		delete[] stateArray;
		stateArray = res;
	}
	void StateArray::printStateArray()
	{
		int i;
		for ( i = 1; i <= ElectionRound::countState; i++)
		{
			cout<<*(stateArray[i]);
		}
		if(i==1)
			cout << "There is not states" << endl;

	}

	

	State& StateArray::getStateById(int Id) const
	{
		return *stateArray[Id];
	}

	int StateArray::getStatenumOfRepresentative(int Id) const
	{
		return stateArray[Id]->getNumOfRepresentative();
	}

	int StateArray::getCitizenCount(int stateId) const
	{
		return stateArray[stateId]->getHowManyCitizens();
	}
	int StateArray:: getPhySize() const
	{
		return phySize;
	}
}