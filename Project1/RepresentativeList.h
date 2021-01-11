#pragma once
#include <iostream>
#include "citizen.h"
#include "citizenList.h"

#include<list>
using namespace std;
namespace proj
{
    class RepresentativeList : public CitizenList
    {
    private:
          list<citizen*> RepList;
    public:
        RepresentativeList() { };
        ~RepresentativeList(){ } ;
        RepresentativeList(const RepresentativeList& input);
      
        void operator=(const RepresentativeList& input);
        friend ostream& operator<<(ostream& os, const RepresentativeList& List);
        citizen* getHead()const { return *RepList.begin(); }
        void printWininigList(int numOfCitizenToPrint)const ;
        void save(ostream& out) const;
        void load(istream& in, const CitizenList& currList);
     };
}