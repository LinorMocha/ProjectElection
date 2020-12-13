#include <iostream>
#include "State.h"
using namespace std;

#pragma once
namespace proj
{
	class citizen
	{
	private:
		char* name;
		int ID;
		State* state;
		int birthYear;
		int vote;

	public:
		citizen();
		citizen(char* _name, int id, State & _state,int _birthYear);
		citizen(const citizen& cit);
		~citizen();
	
		void operator=(const citizen& input);
		void printCitizen();
		//friend ostream& operator<<(ostream& os, const citizen& Citizen);  //overloading to opertor << 

		///// GETERS////////
		int getId() const;
		int getStateId() const;
		int getVote() const;
		int getBirthYear() const;
		char* getName() const;

		///// SETERS//////
		bool setvote(int _vote);

	};
}