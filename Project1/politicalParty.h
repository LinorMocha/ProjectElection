#pragma once

#include "citizen.h"
#include "citizenList.h"

namespace proj {
    class politicalparty {
    private:
        citizenList **representativeList;
        char *name;
        int numId;
        int lastState;
        citizen *head;
    public:
        politicalparty();
        //politicalparty(char* partyName, int IdHead);

    };
}