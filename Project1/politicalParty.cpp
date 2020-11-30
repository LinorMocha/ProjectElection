#include "citizen.h"
#include "politicalParty.h"
#include "utils.h"

namespace proj
{
	politicalparty::politicalparty() :representativeList(new citizenList*[]), name(nullptr), numId(0),head(nullptr)
	{

	}

    void politicalparty::addRepresentitive(citizen* citizen, int state) {
        if (state > this->lastState){
            //resize array
            this->lastState = state;
        }
        this->representativeList[state]->add_node(citizen);
	}

    citizenList* politicalparty::getWinningRepresentitives(int state, int repCount){
        citizenList* stateRepres = new citizenList[];
        node* head = this->representativeList[state].head;
        node* temp = head;
        for (int i = 0; i < repCount; ++i) {
            stateRepres->add_node(temp->value)
            temp = head->next
        }
        return stateRepres;
	}
	//politicalparty::politicalparty(char* partyName, int IdHead)
	//{
	//	politicalparty::name = utils::my_strdup(partyName);
	//	//head = getCitizenById(IdHead);
	//	num=
	//		
	//}


}