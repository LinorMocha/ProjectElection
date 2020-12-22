#pragma once
#include "citizenList.h"
#include "utils.h"
#include "StateArray.h"
#include"politicalPartyArray.h"
namespace proj
{
	class ElectionRound
	{

	protected:
		citizenList _citizenList;
		StateArray _stateArray;
		PoliticalPartyArray _politicalPartyArray;
		Date date;			

	public:
		static int countPoliticalParty;
		static int countState;
		static int countCitizen;
		
		ElectionRound();
		ElectionRound(istream& in);
		~ElectionRound();
		
		virtual bool setDate( int day,int month,int year);
		
		//////////////GETTERS///////////////////
		int getDay() const { return date.day; };
		int getMonth() const { return date.month; };
		int getYear() const { return date.year; };
		State& getStateById(int id);
		const politicalParty&	getPolitaclPartyById(int id);
		int getOverAllVotesForPoli(int polyId);

		
		/////////// STATE //////////////////
		bool addState(char* name, int numRep,bool Status); ///
		virtual void printStateArray();
		virtual State& getStateById(int numId) const ;
		virtual int* printElectionResultsForState(int stateId);
		
		/////////// CITIZEN //////////////////
		virtual bool addCitizen(char* _name, int id, int numD, int _birthYear);
		virtual const citizen& getCitizenById(int numId);
		void printCitizenList();

		////////////  Representative//////////
		virtual bool addRepresentativetoPoli(int repId, int PoliId, int StateId);
		virtual bool isRepListComplete();
		
		////////////  POLITICALPARTY  //////////
		virtual bool addPoliticalParty(char* name, int headId);
		virtual void printPoliticalPartyArray();
		virtual const politicalParty& getPoliById(int numId);
		
		/////////// Vote //////////////
		virtual bool addVote(int citizenId, int poliId);
		
		////// Turn Out ///////
		virtual int printElectionResults();

		/*virtual void save(ostream& out) const;
		virtual void load(istream& in); */
	};

}