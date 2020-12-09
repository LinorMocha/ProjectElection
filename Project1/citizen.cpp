#include "utils.h"
#include "citizen.h"
#include"ElectionRound.h"

namespace proj
{
	citizen::citizen(): name(nullptr),ID(0),birthYear(0),vote(-1),state(nullptr)
	{
		
	}
	citizen::citizen(char* _name, int id, State & _state,int _birthYear) : state(&_state),ID(id), birthYear(_birthYear)
	{
		ElectionRound::countCitizen++;
		name =utils::my_strdup(_name);
		vote = -1;
	}

	citizen::citizen(const citizen& cit):state(cit.state),ID(cit.ID),birthYear(cit.birthYear),vote(cit.vote)
	{
		
		name = utils::my_strdup(cit.name);
		
	}

	citizen::~citizen()
	{
		delete[] name;
	}
	void citizen::operator=(const citizen& input)
	{
		ID = input.ID;
		state= input.state;
		vote = input.vote;
		name = utils::my_strdup(input.name);
	}
	int citizen::getStateId()
	{
		return state->getNumId();
	}
	
	int citizen::getVote()
	{
		return vote;
	}

	int citizen::getBirthYear()
	{
		return birthYear;
	}

	int citizen::getId()
	{
		return ID;
	}
	char* citizen::getName()
	{
		return name;
	}
	void citizen::setvote(int _vote)
	{
		vote = _vote;
	}

	void citizen::printCitizen()
	{
		cout << name << " ";
		cout << ID << " ";
		state->printState();
		cout << birthYear << " ";
	}


}