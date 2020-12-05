#pragma once


namespace proj
{
	class State
	{
	private:
		char* name;
		int numId;
		int numOfRepresentative;
	public:
		int countCitizens;

		State();
		State(char* _name, int _numRep);
		State(const State& Sta);
		~State();
		int getNumOfRepresentative();
		int getNumId();
		char* getName();
		const State& operator=(const State& input);
		void printState();
	};
}


