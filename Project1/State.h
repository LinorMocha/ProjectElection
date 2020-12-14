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
		int countVotesInState;

	public:

		State();
		State(char* _name, int _numRep);
		State(const State& Sta);
		~State();
		const State& operator=(const State& input);

		
		friend ostream& operator<<(ostream& os, const State& state);
	
		/// GETERS ///
		int getNumOfRepresentative()const;
		int getNumId()const;
		char* getName()const;
		int getHowManyCitizens()const;
		int getCountVotesInState()const;

		//// SETERS /////
	     void addCitizen();
		 void addVote();
	};
}


