#pragma once

#include "citizen.h"
#include "citizenList.h"

namespace proj {
    class politicalparty {
    private:
        citizenList **representativeList;
        char *name;
        int numId;
        citizen *head;
        llk
    public:
        politicalparty();
        politicalparty(char* partyName, citizen* _head);

    };
}