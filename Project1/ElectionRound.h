#pragma once
#include "citizenList.h"
#include "utils.h"

namespace proj
{
	class ElectionRound
	{

		private:
			citizenList* _citizenList;
			
			Date date;

			//רשימת או מערך מחוזות
			//רשימת או מערך מפלגות
			

	public:
		static int countPoliticalParty;
		static int countState;
		static int countCitizen;


	};

}