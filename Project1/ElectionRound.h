#pragma once
#include "citizenList.h"
#include "utils.h"
#include "StateArray.h"
#include"politicalPartyArray.h"
#include"DynamicArr.h"

namespace proj
{
	
	class ElectionRound
	{


	protected:
		DynamicArray<State*>  _stateArray;
		DynamicArray<politicalParty*> _politicalPartyArray;

		citizenList _citizenList;
		//StateArray _stateArray;
		//PoliticalPartyArray _politicalPartyArray;
		Date date;			

	public:
		
		static int countPoliticalParty;
		static int countState;
		static int countCitizen;
		
		ElectionRound();
		ElectionRound(istream& in);
		~ElectionRound();
		
		bool setDate( int day,int month,int year);
		
		//////////////GETTERS///////////////////
		int getDay() const { return date.day; };
		int getMonth() const { return date.month; };
		int getYear() const { return date.year; };
		State& getStateById(int id);
		const politicalParty&	getPolitaclPartyById(int id);
		int getOverAllVotesForPoli(int polyId);

		
		/////////// STATE //////////////////
		bool addState(const string name, int numRep,bool Status); ///
		void printStateArray();
		State& getStateById(int numId) const ;
		
		
		/////////// CITIZEN //////////////////
		virtual bool addCitizen(char* _name, int id, int numD, int _birthYear);
		const citizen& getCitizenById(int numId);
		void printCitizenList();

		////////////  Representative//////////
		virtual bool addRepresentativetoPoli(int repId, int PoliId, int StateId);
		bool isRepListComplete();
		
		////////////  POLITICALPARTY  //////////
		bool addPoliticalParty(char* name, int headId);
		void printPoliticalPartyArray();
		const politicalParty& getPoliById(int numId);
		
		/////////// Vote //////////////
		bool addVote(int citizenId, int poliId);
		
		////// Turn Out ///////
		
		bool save(ostream& out) const;
		bool load(istream& in); 
	};

}