#pragma once
#include "DynamicArr.h"
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
			
	public:

		State();
		State(const string _name, int _numRep, int _numId);
		State(const State& Sta);
		State(istream& in);
		virtual ~State();
		virtual const State& operator=(const State& input);
		friend ostream& operator<<(ostream& os, const State& state);
		virtual ostream& toPrint(ostream& os)const = 0 ;
		virtual bool operator==(const State& input);
		virtual bool operator==(const int id);

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


