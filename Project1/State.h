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
		State();
		State(char* _name, int _numRep);
		int getNumOfRepresentative();
		int getNumId();
		char* getName();
		const State& operator=(const State& input);
	};
}


