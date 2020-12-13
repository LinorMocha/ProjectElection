#pragma once

#include<iostream>
using namespace std;
namespace proj
{
	class State
	{
	private:
		char* name;
		int numId;
		int numOfRepresentative;
		int countCitizensInState;

	public:

		State();
		State(char* _name, int _numRep);
		State(const State& Sta);
		~State();
		const State& operator=(const State& input);
		bool IsStateIDValid(int Numid);
		//void printState();
		friend ostream& operator<<(ostream& os, const State& state);
	
		/// GETERS ///
		int getNumOfRepresentative()const;
		int getNumId()const;
		char* getName()const;
		int getHowManyCitizens()const;
		
		//// SETERS /////
	     bool addCitizen();

	};
}


