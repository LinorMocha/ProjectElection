#include <iostream>
using namespace std;

#pragma once
namespace proj
{
	class citizen
	{
	private:
		char* name;
		int ID;
		int stateId;
		int birthYear;
		int vote;

	public:
		citizen();
		citizen(char* _name, int id, int numD,int _birthYear);
		citizen(const citizen& cit);
		~citizen();
		void operator=(const citizen& input);
		void printCitizen();

		///// GETERS////////
		int getId();
		int getStateId();
		int getVote();
		int getBirthYear();
		char* getName();
		///// SETERS//////
		void setvote(int _vote);

	};
}