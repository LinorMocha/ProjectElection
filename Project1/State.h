#pragma once
#include "DynamicArr.h"
#include "RepresentativeList.h"
#include<iostream>
#include <string.h>
#include <vector>
using namespace std;

namespace proj
{
	class State
	{
	protected:
		string name;
		int numId;
		int numOfRepresentative;
		int countCitizensInState;
		int countVotesInState;
		//an array that is full only when we nedded to caculte elecation round
		vector <int> howManyRepFromEachPoly;
		

		
	public:

		State();
		State(const string _name, int _numRep);
		State(const State& Sta);
		State(istream& in);
		~State();
		const State& operator=(const State& input);
		friend ostream& operator<<(ostream& os, const State& state);
	
		/// GETERS ///
		virtual int getStateType()const = 0;
		int getNumOfRepresentative()const;
		int getNumId()const;
		string getName()const;
		int getHowManyCitizens()const;
		int getCountVotesInState()const;
		


		//// SETERS /////
	     void addCitizen();
		 void addVote();

		 void save(ostream& out)const;
		 void load(istream& in);

	};
}


