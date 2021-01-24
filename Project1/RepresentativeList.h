#pragma once
#include <iostream>
#include "citizenList.h"

using namespace std;
namespace proj
{
    class RepresentativeList : public CitizenList
    {
    public:
        RepresentativeList() { };
        ~RepresentativeList() ;
        RepresentativeList(const RepresentativeList& input);
        
        void operator=(const RepresentativeList& input);
        friend ostream& operator<<(ostream& os, const RepresentativeList& List);
        int getListSize()const;
        void load(istream& in, const CitizenList& currList);
        void addCitizenToListTail(citizen* input);
        citizen* getHead()const;
        void printWininigList(int numOfCitizenToPrint)const ;
        void save(ostream& out) const;
      
    };
}