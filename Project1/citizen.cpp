#include "utils.h"
#include "citizen.h"
#include "ElectionRound.h"

namespace proj
{
	citizen::citizen() : ID(0), stateId(0), name(new char()),vote(-1), birthYear(0)
	{
		name = nullptr;
	}
	citizen::citizen(char* _name, int id, int numD,int _birthYear) : ID(id), stateId(numD), birthYear(_birthYear)
	{
		ElectionRound::countCitizen++;
		name =utils::my_strdup(_name);
		vote = -1;
	}

	citizen::citizen(const citizen& cit)
	{
		ID = cit.ID;
		stateId = cit.stateId;
		birthYear = cit.birthYear;
		name = utils::my_strdup(cit.name);
		vote = cit.vote;
	}

	citizen::~citizen()
	{
		delete[] name;
	}
	int citizen::getStateId()
	{
		return stateId;
	}
	void citizen::operator=(const citizen& input)
	{
		ID = input.ID;
		stateId = input.stateId;
		vote = input.vote;
		name = utils::my_strdup(input.name);
	}

	int citizen::getId()
	{
		return ID;
	}
	void citizen::setvote(int _vote)
	{
		vote = _vote;
	}

	void citizen::printCitizen()
	{
		cout << name << " ";
		cout << ID << " ";
		cout << stateId << " ";
		cout << birthYear << " ";
	}
}