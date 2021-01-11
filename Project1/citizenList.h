#pragma once
#include <iostream>
#include "citizen.h"
#include<list>
using namespace std;
namespace proj
{
    class CitizenList
    {
    private:
        list<citizen*> List;
    public:
        CitizenList() { };
        ~CitizenList() { };
        CitizenList(const CitizenList& input);

        void operator=(const CitizenList& input);
        friend ostream& operator<<(ostream& os, const CitizenList& List);

        ///// GETERS ////
       citizen* getCitizenById(int _id) const;
       int getListSize()const;


       void addCitizenToListTail(citizen* input);
       void addCitizenAfter(const citizen* to_insert, citizen* input);
       void load(istream& in);
       void save(ostream& out) const;
       void isCitizenInList(const citizen& cit);
    };
}