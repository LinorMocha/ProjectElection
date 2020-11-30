#include "VotersBook.h"
#include "citizen.h"
#include "utils.h"

namespace proj
{
	VotersBook::VotersBook() :list(new citizenList())
	{

	}
	VotersBook::~VotersBook()
	{
		delete list;
	}
	void VotersBook::addCitizen(char* _name, int _id, int _numD, int _birthYear)
	{
		citizen temp(_name, _id, _numD, _birthYear);
		list->add_node(&temp);
	}
	
	citizen* VotersBook::getCitizenById(int _id)
	{
		
		return list->getItem(_id);
	}
	



}
