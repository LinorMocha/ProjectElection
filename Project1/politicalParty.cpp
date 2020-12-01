#include "citizen.h"
#include "politicalParty.h"
#include "utils.h"
#include "ElectionRound.h"

namespace proj
{
	politicalparty::politicalparty() :representativeList(new citizenList*[]), name(nullptr), numId(0),head(nullptr)
	{
        ElectionRound::countPoliticalParty++;
        numId = ElectionRound::countPoliticalParty;
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
    politicalparty::politicalparty(char* partyName, citizen* _head) :politicalparty()
    {
        name = utils::my_strdup(partyName);
        head = _head;
    }
}