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
		
	};
}


