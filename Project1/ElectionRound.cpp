#include "ElectionRound.h"

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
	bool ElectionRound::setDate(int day, int month, int year)
	{

		date.day = day;
		date.month = month;
		date.year = year;
		return true;
	}
	//this function get ref to state according to ID
	State& ElectionRound::getStateById(int id)
	{
		 return _stateArray.getStateById(id);
	}
	//this function get ref to political Party according to ID
	const politicalParty& ElectionRound::getPolitaclPartyById(int id)
	{
		return _politicalPartyArray.getPoliticalPartyById(id);
	}
	//This function returns the total number of votes for party
	int ElectionRound::getOverAllVotesForPoli(int polyId)
	{
		return _politicalPartyArray.getOverAllVotesForPoli(polyId);
	}


	///////////// STATE implementation//////////////////

	//this function adds the state to the state arr snd to the party arr
	bool ElectionRound::addState(const string name, int numRep, bool Status)
	{
		State* sta = new State(name, numRep, Status);
		_stateArray.push_back(sta);
		//_politicalPartyArray.addState();
		return true;
	}
	//this function prints the State Array
	void ElectionRound::printStateArray()
	{
		_stateArray.printStateArray();

	}
	//This function returns ref to the desired state according to the given ID 
	State& ElectionRound::getStateById(int numId) const
	{
		return _stateArray.getStateById(numId);
	}



	///////////// CITIZEN implementation//////////////////
	//This function creates new citizen if he doesn't exist and adds him to the end of the citizen Array
	bool ElectionRound::addCitizen(char* _name, int id, int numD, int _birthYear)
	{
		if (_citizenList.getCitizenById(id) == nullptr && numD <= countState)
		{
			_stateArray.addCitizenCountToState(numD);
			citizen* newC = new citizen(_name, id, _stateArray.getStateById(numD), _birthYear);
			_citizenList.addNodeToTail(newC);
			return true;
		}

		return false;
	}
	//This function returns ref to the desired citizen according to the given ID 
	const citizen& ElectionRound::getCitizenById(int numId)
	{
		return *_citizenList.getCitizenById(numId);
	}
	//this function prints the citizen list
	void ElectionRound::printCitizenList()
	{
		if (_citizenList.getHead() == nullptr)
			cout << "There is not citizens " << endl;
		else
			_citizenList.printList();
	}


	////////////  POLITICALPARTY implementation  //////////
	//This function creates new party if he doesn't exist and adds him to the end of the politcal party array
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
	//this function prints the Political party array
	void ElectionRound::printPoliticalPartyArray()
	{
		_politicalPartyArray.printPoliticalPartyArray();
	}
	//This function returns ref to the desired party according to the given ID 
	const politicalParty& ElectionRound::getPoliById(int numId)
	{
		return _politicalPartyArray.getPoliticalPartyById(numId);
	}

	/////// REPRESENTATIVE ////////
	//This function adds a representative to party 
	bool ElectionRound::addRepresentativetoPoli(int repId, int PoliId, int StateId)
	{
		if (PoliId <= countPoliticalParty && StateId <= countState)//chek if poli excist
		{
			citizen* rep = _citizenList.getCitizenById(repId);
			if (rep != nullptr && !_politicalPartyArray.isCitizenIsRepORHead(*rep))//check if the rep exsict
			{
				_politicalPartyArray.addRepToPoli(PoliId, StateId, rep);

				return true;
			}
		}

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

		if (!_stateArray.save(out)) //saves the state array to file
			return false;

		if (!_citizenList.save(out)) //saves the citizen list to file
			return false;
		
		if (!_politicalPartyArray.save(out)) //saves the politcal party array to file
			return false;
		
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

		if(!_stateArray.load(in))//load the state array from file
			return false;

		if(!_citizenList.load(in, _stateArray))//load the citizen list from file
			return false;

		if (!_politicalPartyArray.load(in, _citizenList))//load the politcal party array from file
			return false;
		
		return(in.good());
	}
}