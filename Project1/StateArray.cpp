#include "StateArray.h"
#include"ElectionRound.h"

namespace proj
{
	//ctor
	StateArray::StateArray() : stateArray(new State*()),phySize(1)
	{
		
	}
	//dctor
	StateArray::~StateArray()
	{
		for (int i = 0; i <= ElectionRound::countState; i++)
		{
			delete stateArray[i];
		}

	}
	/*StateArray::StateArray(istream& in)
	{
		load(in);
	}*/

	//
	void StateArray::addCitizenCountToState(int stateId)
	{
		stateArray[stateId]->addCitizen();
	}
	//
	void StateArray::addVoteCountToState(int stateId)
	{
		stateArray[stateId]->addVote();
	}

	////This function writes the state array data to binary file
	bool StateArray::save(ostream& out) const
	{
		if (!out)//checks if the file works properly
		{
			return false;
		}
		out.write(rcastcc(&phySize), sizeof(phySize));
		for (int i = 1; i <= ElectionRound::countState; i++)
		{
			stateArray[i]->save(out); //saves current state in the arr 
			if (!out.good())
			{
				return false;
			}
		}

		return(out.good());//Checks if the writes operations to file performed properly
	}

	//This function reads the  state array data from binary file
	bool StateArray::load(istream& in)
	{
		if (!in)//checks if the file works properly
		{
			return false;
		}
		in.read(rcastc(&phySize), sizeof(phySize));
		if (!in.good())
		{
			return false;
		}
		State** res = new State * [phySize]; //creates new State array
		for (int i = 0; i <= ElectionRound::countState; i++)
		{
			if (i == 0)
				res[i] = nullptr;
			else
				res[i] = new State(in);
			if (!in.good())
			{
				return false;
			}
		}
		stateArray = res;
		return(in.good());
	}
	//this function add new state to the arr
	void StateArray::addState(const string name, int _numRep, bool Status)
	{
		State* newState = new State(name, _numRep ,Status);
		

		if (ElectionRound::countState >= phySize)//Check if there's enough space for new state in the arr
			reSizeStateArray();
		
		stateArray[newState->getNumId()] = newState;
			
	}
	//this function increasing the array if he doesn't big enough
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
	//this function prints the state array
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

	
	//This function returns ref to the desired state according to the given ID 
	State& StateArray::getStateById(int Id) const
	{
		return *stateArray[Id];
	}
	//This function returns the number of Representative in a particular state
	int StateArray::getStatenumOfRepresentative(int Id) const
	{
		return stateArray[Id]->getNumOfRepresentative();
	}
	//This function returns the number of citizens in a particular state
	int StateArray::getCitizenCount(int stateId) const
	{
		return stateArray[stateId]->getHowManyCitizens();
	}
	//This function returns the physical size of the arr
	int StateArray:: getPhySize() const
	{
		return phySize;
	}
}