#include "utils.h"
#include "citizen.h"
#include "ElectionRound.h"

namespace proj
{
	citizen::citizen() : ID(0), numDistrict(0), name(new char()),vote(-1), birthYear(0)
	{
		name = nullptr;
	}
	citizen::citizen(char* _name, int id, int numD,int _birthYear) : ID(id), numDistrict(numD), birthYear(_birthYear)
	{
		ElectionRound::countCitizen++;
		name =utils::my_strdup(_name);
		vote = -1;
	}
	citizen::citizen(const citizen& cit)
	{
		ID = cit.ID;
		numDistrict = cit.numDistrict;
		birthYear = cit.birthYear;
		name = utils::my_strdup(cit.name);
		vote = cit.vote;
	}

	citizen::~citizen()
	{
		delete[] name;
	}
	void citizen::operator=(const citizen& input)
	{
		ID = input.ID;
		numDistrict = input.numDistrict;
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
		cout << numDistrict << " ";
		cout << birthYear << " ";
	}
}