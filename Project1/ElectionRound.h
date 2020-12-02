#pragma once
#include "citizenList.h"
#include "utils.h"
#include "StateArray.h"
namespace proj
{
	class ElectionRound
	{

		private:
			citizenList* _citizenList;
			StateArray _stateArray;
			Date date;

			//רשימת או מערך מפלגות
			

	public:
		static int countPoliticalParty;
		static int countState;
		static int countCitizen;

		ElectionRound();
		~ElectionRound();
		void addState(char* name, int numRep);
	};

}