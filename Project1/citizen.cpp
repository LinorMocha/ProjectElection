#include "utils.h"
#include "citizen.h"

namespace proj
{
	citizen::citizen() : ID(0), numDistrict(0), name(nullptr),vote(-1)
	{
		
	}
	citizen::citizen(const char* _name, int id, int numD) : ID(id), numDistrict(numD)
	{
		citizen::name =utils::my_strdup(_name);
		vote = -1;
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

	



}