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
		bool addCitizen(char* _name, int id, int numD, int _birthYear);
		const citizen& getCitizenById(int numId);
		void printCitizenList();

		////////////  Representative//////////
		bool addRepresentativetoPoli(int repId, int PoliId, int StateId);
		bool isRepListComplete();
		
		////////////  POLITICALPARTY  //////////
		bool addPoliticalParty(char* name, int headId);
		void printPoliticalPartyArray();
		const politicalParty& getPoliById(int numId);
		
		


		/////////// Vote //////////////
		bool addVote(int citizenId, int poliId);
		
		////// Turn Out ///////
		int printElectionResults();
	};

}