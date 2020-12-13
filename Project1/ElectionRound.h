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
		int printElectionResultsForState(int stateId);

		/////////// CITIZEN //////////////////
		void addCitizen(char* _name, int id, int numD, int _birthYear);
		const citizen& getCitizenById(int numId);
		void printCitizenList();

		////////////  Representative//////////
		void addRepresentativetoPoli(int repId, int PoliId, int StateId);

		////////////  POLITICALPARTY  //////////
		void addPoliticalParty(char* name, int headId);
		void printPoliticalPartyArray();
		const politicalParty& getPoliById(int numId);
		//const citizenList& getSelectedRepList(int PoliId, int StateId,int repCount);
		void printElectionResultsForPoli(int poliId);


		/////////// Vote //////////////
		void addVote(int citizenId, int poliId);
		int calculateNumOfRepInPoliForState(int poliId, int stateId);

		////// Turn Out ///////
		void printElectionResults();
	};

}