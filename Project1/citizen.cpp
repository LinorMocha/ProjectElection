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
	int citizen::getStateId() const
	{
		return state->getNumId();
	}
	
	int citizen::getVote() const
	{
		return vote;
	}

	int citizen::getBirthYear() const
	{
		return birthYear;
	}

	int citizen::getId() const
	{
		return ID;
	}
	char* citizen::getName() const
	{
		return name;
	}
	bool citizen::setvote(int _vote) 
	{
		 vote = _vote;
		 return true;
	}

	//ostream& operator<<(ostream& os, const citizen& Citizen)
	//{
	//	os <<" Name: " <<Citizen.getName <<endl;
	//  os <<"citizen ID: " <<Citizen.getId << endl;
	//	os <<"birth year: " << Citizen.getBirthYear << endl;
	//	os <<"state: " << Citizen.getStateId << endl;
	///	state->printState();*/
	//	
	//	return os;
	//}


	void citizen::printCitizen()
	{
		cout << endl;
		cout <<"name of citizen:"<< name <<endl;
		cout <<"ID of citizen: "<<ID <<endl;
		cout << "birth year of citizen " << birthYear << endl << endl;
		//state->printState();
		
			
	}

	//check if id exist
	
}