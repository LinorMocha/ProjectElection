#pragma once


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
		void printState();
		
		/// GETERS ///
		int getNumOfRepresentative();
		int getNumId();
		char* getName();
		int getHomManyCitizens();
		
		//// SETERS /////
		void addCitizen();

	};
}


