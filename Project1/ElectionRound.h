#pragma once
#include "citizenList.h"
#include "utils.h"
#include "StateArray.h"
#include"politicalPartyArray.h"
namespace proj
{
	class ElectionRound
	{

		private:
			citizenList _citizenList;
			StateArray _stateArray;
			PoliticalPartyArray _politicalPartyArray;
			Date date;

			//רשימת או מערך מפלגות
			

	public:
		static int countPoliticalParty;
		static int countState;
		static int countCitizen;

		ElectionRound();
		~ElectionRound();

		/////////// STATE //////////////////
		void addState(char* name, int numRep);
		void printStateArray();
		const State& getStateById(int numId);

		/////////// CITIZEN //////////////////
		void addCitizen(char* _name, int id, int numD, int _birthYear);
		const citizen& getCitizenById(int numId);
		void printCitizenList();

		////////////  Representative//////////



		////////////  POLITICALPARTY  //////////
		void addPoliticalParty(char* name, int headId);
		void printPoliticalPartyArray();
		const politicalParty& getPoliById(int numId);
		const citizenList& getSelectedRepList(int PoliId, int StateId,int repCount);
	};

}