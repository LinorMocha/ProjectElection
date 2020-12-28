#include "ElectionRound.h"

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
	ElectionRound::ElectionRound(istream& in)
	{
		load(in);
			
	}

	ElectionRound::~ElectionRound()
	{

	}

	bool ElectionRound::setDate(int day, int month, int year)
	{

		date.day = day;
		date.month = month;
		date.year = year;
		return true;
	}

	State& ElectionRound::getStateById(int id)
	{
		 return _stateArray.getStateById(id);
	}

	const politicalParty& ElectionRound::getPolitaclPartyById(int id)
	{
		return _politicalPartyArray.getPoliticalPartyById(id);
	}

	int ElectionRound::getOverAllVotesForPoli(int polyId)
	{
		return _politicalPartyArray.getOverAllVotesForPoli(polyId);
	}


	///////////// STATE implementation//////////////////
	bool ElectionRound::addState(char* name, int numRep, bool Status)
	{
		_stateArray.addState(name, numRep, Status);

		_politicalPartyArray.addState();
		return true;
	}
	void ElectionRound::printStateArray()
	{
		_stateArray.printStateArray();

	}
	State& ElectionRound::getStateById(int numId) const
	{
		return _stateArray.getStateById(numId);
	}



	///////////// CITIZEN implementation//////////////////
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
	const citizen& ElectionRound::getCitizenById(int numId)
	{
		return *_citizenList.getCitizenById(numId);
	}
	void ElectionRound::printCitizenList()
	{
		if (_citizenList.getHead() == nullptr)
			cout << "There is not citizens " << endl;
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
				numOfExsitesRep = _politicalPartyArray.getRepListLengthForStateInPoli(j, i);
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




	

	void ElectionRound::save(ostream& out) const
	{
		
		out.write(rcastcc(&date.day), sizeof(int));
		out.write(rcastcc(&date.month), sizeof(int));
		out.write(rcastcc(&date.year), sizeof(int));
		out.write(rcastcc(&countCitizen), sizeof(int));
		out.write(rcastcc(&countState), sizeof(int));
		out.write(rcastcc(&countPoliticalParty), sizeof(int));

		_stateArray.save(out);
		_citizenList.save(out);
		_politicalPartyArray.save(out);
	}

	void ElectionRound::load(istream& in)
	{
		in.read(rcastc(&date.day), sizeof(int));
		in.read(rcastc(&date.month), sizeof(int));
		in.read(rcastc(&date.year), sizeof(int));
		in.read(rcastc(&countCitizen), sizeof(int));
		in.read(rcastc(&countState), sizeof(int));
		in.read(rcastc(&countPoliticalParty), sizeof(int));

		_stateArray.load(in);
		_citizenList.load(in, _stateArray);
		_politicalPartyArray.load(in, _citizenList);
	}
}