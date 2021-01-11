﻿#include "ElectionRound.h"
#include <exception>

namespace proj
{
	//------------------static values------------------//
	int ElectionRound::countPoliticalParty = 0;
	int ElectionRound::countState = 0;
	int ElectionRound::countCitizen = 0;
	//ctor
	ElectionRound::ElectionRound() : _stateArray(), _citizenList(), _politicalPartyArray()
	{
		date.day = 0;
		date.month = 0;
		date.year = 0;
	}
	////serialize constractor for ElectionRound
	ElectionRound::ElectionRound(istream& in)
	{
		load(in);
			
	}
	//distractor
	ElectionRound::~ElectionRound()
	{

	}
	//set the date of the election round
	void ElectionRound::setDate(int day, int month, int year)//turn into void?
	{
		if (year <= 0)
			throw invalid_argument("Invalid year");
		if (month < 1 || month > 12)
			throw invalid_argument("Invalid month");
		if(day<1 || day > maxDayPerMonthArr[month])
			throw invalid_argument("Invalid day");
		date.day = day;
		date.month = month;
		date.year = year;
		
	}

	///////////// STATE implementation//////////////////

	//this function adds the state to the state arr snd to the party arr
	void ElectionRound::addState(const string name, int numRep, bool Status)
	{
		State* sta = new State(name, numRep, Status);
		_stateArray.push_back(sta);
		
	}
	//this function prints the State Array
	void ElectionRound::printStateArray()
	{
		if (countState <= 0)
			throw invalid_argument("there is no state");
		_stateArray.print(); 
	}

	//This function returns ref to the desired state according to the given ID 
	State& ElectionRound::getStateById(int numId) const	{return *_stateArray[numId-1];}


	///////////// CITIZEN implementation//////////////////
	//This function creates new citizen if he doesn't exist and adds him to the end of the citizen Array
	void ElectionRound::addCitizen(const string _name, int id, int numD, int _birthYear)
	{
		if (numD < countState)
			throw invalid_argument("state dont exsit");
		if (id < 100000000 || id>999999999)
			throw invalid_argument("id not valid ");
		if ((date.year-_birthYear) < 18) 
			throw  invalid_argument("The citizen is too young to vote");
		
		if(!isNumberIdAvilable(id))
			throw invalid_argument("the citizen is alredy exsict");
		
			citizen* newC = new citizen(_name, id, *_stateArray[numD], _birthYear);
			_citizenList.addCitizenToListTail(newC);
			countCitizen++;
			_stateArray[numD]->addCitizen();
	}
	
	//This function returns ref to the desired citizen according to the given ID 
	const citizen& ElectionRound::getCitizenById(int numId)
	{
		return *_citizenList.getCitizenById(numId);
	}
	
	//if id is taken throw
	bool ElectionRound::isNumberIdAvilable(int numId)
	{
		try
		{
			_citizenList.getCitizenById(numId);
		}
		catch(int id) //the Number id is Avilable
		{
			return true;
		}

		return false;
	}

	//this function prints the citizen list
	void ElectionRound::printCitizenList()
	{
		if (_citizenList.isEmpty())
			throw  invalid_argument("there is no citizen");
		
		cout << _citizenList << endl;		
	}


	////////////  POLITICALPARTY implementation  //////////
	//This function creates new party if he doesn't exist and adds him to the end of the politcal party array
	void ElectionRound::addPoliticalParty(const string name, int headId)
	{
		if (isNumberIdAvilable(headId))
		{
			throw invalid_argument("there is no head poly according to this given id ");
		}
		citizen headPoly = getCitizenById(headId);
		try
		{
			auto itArr = _politicalPartyArray.begin();
			int temp;
			while (itArr != _politicalPartyArray.end())
			{
				(*itArr)->isRep(headPoly);
			}
		}
		catch(std::exception& ex)
		{
			throw invalid_argument("citizen is already rep");
		}
		politicalParty* poly = new politicalParty(name, &headPoly);
		_politicalPartyArray.push_back(poly);
	}
	//this function get ref to political Party according to ID
	const politicalParty& ElectionRound::getPolitaclPartyById(int id)
	{
		return *_politicalPartyArray[id];
	}
	//This function returns the total number of votes for party
	int ElectionRound::getOverAllVotesForPoli(int polyId)
	{
		return *_politicalPartyArray[polyId].getOverAllVotesForPoli;
	}
	//this function prints the Political party array
	void ElectionRound::printPoliticalPartyArray()
	{
		_politicalPartyArray.print();
	}
	//This function returns ref to the desired party according to the given ID 
	const politicalParty& ElectionRound::getPoliById(int numId)
	{
		/*return _politicalPartyArray.getPoliticalPartyById(numId);*/
		return *_politicalPartyArray[numId];
	}

	/////// REPRESENTATIVE ////////
	//This function adds a representative to party 
	bool ElectionRound::addRepresentativetoPoli(int repId, int PoliId, int StateId)
	{
		try
		{
			
		}
		
		
		//if (PoliId <= countPoliticalParty && StateId <= countState)//chek if poli excist
		//{
		//	citizen* rep = _citizenList.getCitizenById(repId);
		//	if (rep != nullptr && !_politicalPartyArray.isCitizenIsRepORHead(*rep))//check if the rep exsict
		//	{
		//		_politicalPartyArray.addRepToPoli(PoliId, StateId, rep);

		//		return true;
		//	}
		//}

		return false;
	}

	//
	bool ElectionRound::isRepListComplete()
	{
		int numOfExsitesRep;
		for (int i = 1; i <= countState; i++)
		{
			for (int j = 1; j <= countPoliticalParty; j++)
			{

				numOfExsitesRep = _politicalPartyArray.getRepListLengthForStateInPoli(j, i);
				if (numOfExsitesRep < _stateArray.getStatenumOfRepresentative(i))
					return false;
			}
		}
		return true;
	
	}

	///////////// Vote implementation///////////////

	//This function adds votes of citizens who haven't voted yet
	bool ElectionRound::addVote(int citizenId, int poliId)
	{
		citizen* cit = _citizenList.getCitizenById(citizenId);
		if (cit != nullptr && cit->getVote() == -1 && poliId > 0 && poliId <= countPoliticalParty)
		{
			cit->setvote(poliId);
			_politicalPartyArray.addVote(poliId, cit->getStateId());
			_stateArray.addVoteCountToState(cit->getStateId());
			return true;
		}
		else
		{
			return false;
		}
	}


	//This function writes the curr round data to binary file
	bool ElectionRound::save(ostream& out) const
	{
		if (!out)//checks if the file works properly
		{
			return false;
		}
		out.write(rcastcc(&date.day), sizeof(int));
		out.write(rcastcc(&date.month), sizeof(int));
		out.write(rcastcc(&date.year), sizeof(int));
		out.write(rcastcc(&countCitizen), sizeof(int));
		out.write(rcastcc(&countState), sizeof(int));
		out.write(rcastcc(&countPoliticalParty), sizeof(int));

		try//save the state array to file
		{
			auto itArr = _stateArray.begin();
			int temp;
			while (itArr != _stateArray.end())
			{
				(*itArr)->save(out);
			}
		}
		catch (std::exception& ex)
		{
			throw invalid_argument("save stateArray to file didn't preforemd proprtaly");
		}
		try//save the citizen list to file
		{
			_citizenList.save(out);
		}
		catch (std::exception& ex)
		{
			throw invalid_argument("save citizenList to file didn't preforemd proprtaly");
		}
		try//save the politcal party array to file
		{
			auto itArr = _politicalPartyArray.begin();
			int temp;
			while (itArr != _politicalPartyArray.end())
			{
				(*itArr)->save(out);
			}
		}
		catch (std::exception& ex)
		{
			throw invalid_argument("load stateArray to file didn't preforemd proprtaly");
		}
		return true;
	}


	//This function reads the curr round data from binary file
	bool ElectionRound::load(istream& in)
	{
		if (!in)//checks if the file works properly
		{
			return false;
		}
		in.read(rcastc(&date.day), sizeof(int));
		in.read(rcastc(&date.month), sizeof(int));
		in.read(rcastc(&date.year), sizeof(int));
		in.read(rcastc(&countCitizen), sizeof(int));
		in.read(rcastc(&countState), sizeof(int));
		in.read(rcastc(&countPoliticalParty), sizeof(int));
		try//load the state array from file
		{
			auto itArr = _stateArray.begin();
			int temp;
			while (itArr != _stateArray.end())
			{
				(*itArr)->load(in);
			}
		}
		catch (std::exception& ex)
		{
			throw invalid_argument("load stateArray to file didn't preforemd proprtaly");
		}
		try//load the citizen list from file
		{
			_citizenList.load(in);
		}
		catch (std::exception& ex)
		{
			throw invalid_argument("load citizenList to file didn't preforemd proprtaly");
		}
		try//load the politcal party array from file
		{
			auto itArr = _politicalPartyArray.begin();
			int temp;
			while (itArr != _politicalPartyArray.end())
			{
				(*itArr)->load(in, _citizenList);
			}
		}
		catch (std::exception& ex)
		{
			throw invalid_argument("load stateArray to file didn't preforemd proprtaly");
		}
		return(in.good());
	}
}