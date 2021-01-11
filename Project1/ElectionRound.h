#pragma once
#include "citizenList.h"
#include "utils.h"
#include "StateArray.h"
#include"politicalPartyArray.h"
#include"DynamicArr.h"
#include <iostream>
#include <list>
using namespace std;
namespace proj
{
	class ElectionRound
	{


	protected:
		DynamicArray<State*>  _stateArray;
		DynamicArray<politicalParty*> _politicalPartyArray;
		CitizenList _citizenList;
		Date date;			

	public:
		
		static int countPoliticalParty;
		static int countState;
		static int countCitizen;
		
		ElectionRound();
		ElectionRound(istream& in);
		~ElectionRound();
		
		void setDate( int day,int month,int year);
		
		//////////////GETTERS///////////////////
		int getDay() const { return date.day; };
		int getMonth() const { return date.month; };
		int getYear() const { return date.year; };
	

		
		/////////// STATE //////////////////
		void addState(const string name, int numRep,bool Status); ///
		void printStateArray();
		State& getStateById(int numId) const ;
		
		
		/////////// CITIZEN //////////////////
		virtual void addCitizen(const string _name, int id, int numD, int _birthYear);
		const citizen& getCitizenById(int numId);
		bool isNumberIdAvilable(int numId);
		void printCitizenList();
		


		////////////  Representative//////////
		virtual bool addRepresentativetoPoli(int repId, int PoliId, int StateId);
		bool isRepListComplete();
		
		////////////  POLITICALPARTY  //////////
		void addPoliticalParty(const string name, int headId);
		void printPoliticalPartyArray();
		const politicalParty& getPoliById(int numId);
		const politicalParty& getPolitaclPartyById(int id);
		int getOverAllVotesForPoli(int polyId);


		/////////// Vote //////////////
		bool addVote(int citizenId, int poliId);
		
		////// Turn Out ///////
		
		bool save(ostream& out) const;
		bool load(istream& in); 
	};

}