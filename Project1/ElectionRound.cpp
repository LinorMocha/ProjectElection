﻿#include "ElectionRound.h"
#include "utils.h"


namespace proj
{
	int ElectionRound::countPoliticalParty = 0;
	int ElectionRound::countState = 0;
	int ElectionRound::countCitizen = 0;
	
	ElectionRound::ElectionRound() : _stateArray(), _citizenList(), _politicalPartyArray()
	{
		date.day = 0;
		date.month = 0;
		date.year = 0;
	}
	ElectionRound::~ElectionRound()	{}

	void ElectionRound::setDate(int day, int month, int year)
	{
		
		date.day = day;
		date.month = month;
		date.year = year;
	}

	///////////// STATE implementation//////////////////
	void ElectionRound::addState(char* name, int numRep)
	{
		_stateArray.addState(name, numRep);

		_politicalPartyArray.addState();
	}
	void ElectionRound::printStateArray()
	{
		_stateArray.printStateArray();
	}
	const State& ElectionRound::getStateById(int numId)
	{
		return (_stateArray.getStateById(numId));
	}

	///////////// CITIZEN implementation//////////////////
	bool ElectionRound::addCitizen(char* _name, int id, int numD, int _birthYear)
	{
		if (_citizenList.getCitizenById(id) == nullptr && numD<= countState)
		{
			_stateArray.addCitizenCountToState(numD);
			citizen* newC = new citizen(_name, id, _stateArray.getStateById(numD), _birthYear);
			_citizenList.addNodeToTail(newC);
			return true;
		}

		return false;
	}
	const citizen& ElectionRound::getCitizenById(int numId)
	{
		return *_citizenList.getCitizenById(numId);
	}
	void ElectionRound::printCitizenList()
	{
		if (_citizenList.getHead() == nullptr)
			cout << "There is not citizens "<<endl;
		else
		_citizenList.printList();
	}


	////////////  POLITICALPARTY implementation  //////////

	bool ElectionRound::addPoliticalParty(char* name, int headId)
	{
		citizen* headPoly = _citizenList.getCitizenById(headId);
		if (headPoly != nullptr && !_politicalPartyArray.isCitizenIsRepORHead(*headPoly))
		{
			_politicalPartyArray.addPoliticalParty(name, headPoly);
			
			return true;
		}
		else
			return false;
	}
	void ElectionRound::printPoliticalPartyArray()
	{
		_politicalPartyArray.printPoliticalPartyArray();
	}

	const politicalParty& ElectionRound::getPoliById(int numId)
	{
		return _politicalPartyArray.getPoliticalPartyById(numId);

	}
	
	/////// REPRESENTATIVE ////////

	bool ElectionRound::addRepresentativetoPoli(int repId, int PoliId, int StateId)
	{
		if (PoliId <= countPoliticalParty && StateId <= countState)
		{
			citizen* rep = _citizenList.getCitizenById(repId);
			if (rep != nullptr && !_politicalPartyArray.isCitizenIsRepORHead(*rep))
			{
				_politicalPartyArray.addRepToPoli(PoliId, StateId, rep);
				
				return true;
			}
		}
		
		return false;
	}

	
	bool ElectionRound::isRepListComplete()
	{
		int numOfExsitesRep;
		for (int i = 1; i <= countState; i++)
		{
			for (int j = 1; j <= countPoliticalParty; j++)
			{
				numOfExsitesRep=_politicalPartyArray.getRepListLengthForStateInPoli(j, i);
				if (numOfExsitesRep < _stateArray.getStatenumOfRepresentative(i))
					return false;
			}
		}
		return true;
	}

	///////////// Vote implementation///////////////

	bool ElectionRound::addVote(int citizenId, int poliId)
	{
		citizen* cit = _citizenList.getCitizenById(citizenId);
		if (cit != nullptr && cit->getVote() == -1 && poliId>0 && poliId <= countPoliticalParty )
		{
			cit->setvote(poliId);
			_politicalPartyArray.addVote(poliId, cit->getStateId());
			cout <<"the vote for poli is"<< _politicalPartyArray.getOverAllVotesForPoliInState(poliId, cit->getStateId())<<endl;
			_stateArray.addVoteCountToState(cit->getStateId());
			return true;
		}
		else
		{
			return false;
		}
	}


	
	
	int ElectionRound::printElectionResultsForState(int stateId)
	{
		State& sta = _stateArray.getStateById(stateId);
		
		cout << sta;
		
		float precent;
		
		int winningPoli = 1;
		
		if (sta.getCountVotesInState() != 0)
		{

			float* temp = new float[countPoliticalParty];
			int* howManyRep = new int[countPoliticalParty];
			utils::initArr(howManyRep, countPoliticalParty);
			for (int i = 0; i < countPoliticalParty; i++)
			{
				temp[i] = (float)_politicalPartyArray.getOverAllVotesForPoliInState(i + 1, stateId);

			}
			/// כמות ההצבעות חלקי כמות הנציגים
			float votesForRep = (float) sta.getCountVotesInState() / sta.getNumOfRepresentative();

			int j = utils::returnMaxIndexInArray(temp, countState);
			
			winningPoli = j + 1;
			
			for (int i = 0; i < _stateArray.getStatenumOfRepresentative(stateId); i++)
			{
				temp[j] -= votesForRep;
				howManyRep[j]++;
				j = utils::returnMaxIndexInArray(temp, countState);

			}

			int votesForPoli;
			int numOfRep;
			for (int i = 1; i <= countPoliticalParty; i++)
			{
				votesForPoli = _politicalPartyArray.getOverAllVotesForPoliInState(i, stateId);
				precent = (float)votesForPoli / sta.getCountVotesInState();
				cout << "number of votes : " << votesForPoli;
				cout << " for political party:" << _politicalPartyArray.getName(i);
				cout << "  percent of votes: " << precent*100 << '%' << endl;
				cout << "selected representative list:" << endl;
				numOfRep = howManyRep[i - 1];
				_politicalPartyArray.printSelectedRepList(i, stateId, numOfRep);
				cout << endl;
			}
		}

		precent = (float)sta.getCountVotesInState() / sta.getHowManyCitizens();
		
		cout << " the State voter turn out is:" << precent*100 << '%' << endl;

		cout << " the State chose:" << _politicalPartyArray.getName(winningPoli) << "  to be president!!!" << endl;

		return winningPoli;
	
	}
	
	

	////////// Turn Out /////////////////////
	int ElectionRound::printElectionResults()
	{
		if (countState == 0 || countPoliticalParty == 0 || countCitizen == 0)
		{
			return 0;
		}
		if (!isRepListComplete())
		{
			return 1;
		}
		cout << "__________________________________________________________" << endl;
		cout << " the Elecation Round in date:" <<date.day<<"/"<<date.month <<"/"<< date.year << "   result:"<<	endl;

		int len = countPoliticalParty + 1;
		int* numOfRepForPoliArray = new int[len];
		utils::initArr(numOfRepForPoliArray, len);
		int winingPoli;
		
		for (int i = 1; i <= countState; i++)
		{
			winingPoli = printElectionResultsForState(i);
			numOfRepForPoliArray[winingPoli] += _stateArray.getStatenumOfRepresentative(i);
		}

		int max = 0;
		int maxId = 0;
		for (int j = 1; j < len; j++)
		{
			cout << _politicalPartyArray.getPoliticalPartyById(j)<<endl;
			cout<< "political party got "<<_politicalPartyArray.getOverAllVotesForPoli(j)<<" votes in the elecation"<<endl;
			cout << " number of representative for this party: " << numOfRepForPoliArray[j];
			
			if (numOfRepForPoliArray[j] > max)
			{
				max = numOfRepForPoliArray[j];
				maxId = j;
			}
		}

		cout << " the wining party in the elecation is:" << _politicalPartyArray.getName(maxId)<< endl;
		cout << " the president in the elecation is:" << *_politicalPartyArray.getPoliticalPartyHead(maxId) << endl;
		cout << "__________________________________________________________________" << endl;

		return 2;
	}
}