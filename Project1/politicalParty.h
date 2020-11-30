#pragma once
#include "citizen.h"
#include "citizenList.h"
namespace proj
{
	class politicalparty
	{
	private:
		citizenList** presentativeList;
		char* name;
		int numId;
		citizen* head;
	public:
		politicalparty();
		//politicalparty(char* partyName, int IdHead);

	};
}