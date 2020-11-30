#pragma once
#include "citizen.h"
#include "representativelist.h"
namespace proj
{
	class politicalparty
	{
	private:
		representativeList** list;
		char* name;
		int num;
		citizen* head;
	public:
		politicalparty();
		politicalparty(char* partyName, int IdHead);

	};
}