#include "citizen.h"
#include "politicalParty.h"
#include "utils.h"

namespace proj
{
	politicalparty::politicalparty() :list(nullptr), name(nullptr), num(0),head(nullptr)
	{

	}
	politicalparty::politicalparty(char* partyName, int IdHead)
	{
		politicalparty::name = utils::my_strdup(partyName);
		head = getCitizenById(IdHead);
		num=
			
	}


}