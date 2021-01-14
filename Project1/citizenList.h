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
        CitizenList()= default;
        ~CitizenList();
        CitizenList(const CitizenList& input);

        const CitizenList& operator=(const CitizenList& input);
        friend ostream& operator<<(ostream& os, const CitizenList& List);

        ///// GETERS ////
       citizen* getCitizenById(int _id) const;
       int getListSize()const;
       bool isEmpty();
       void addCitizenToListTail(const string _name, int id, State& numD, int _birthYear);
       void addCitizenAfter(const citizen* to_insert, citizen* input);
       void load(istream& in);
       void save(ostream& out) const;
       void isCitizenInList(const citizen& cit);
    };
}