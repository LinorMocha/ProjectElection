#pragma once
#include <iostream>
#include "State.h"
using namespace std;

namespace proj
{
	class citizen
	{
	private:
		string name;
		int ID;
		State& state;
		int birthYear;
		int vote;

	public:
		
		citizen(const string _name, int id, State & _state,int _birthYear);
		citizen(const citizen& cit);
		~citizen();
		citizen(istream& in,State& sta);

		const citizen& operator=(const citizen& input);
		friend ostream& operator<<(ostream& os, const citizen& Citizen); 

		///// GETERS////////
		int getId() const;
		int getStateId() const;
		int getVote() const;
		int getBirthYear() const;
		const string getName() const;

		///// SETERS//////
		bool setvote(int _vote);

		bool save(ostream& out)const;
		bool load(istream& in);

	};
}