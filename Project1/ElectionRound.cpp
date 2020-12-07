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
	ElectionRound::~ElectionRound()
	{

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
	void ElectionRound::addCitizen(char* _name, int id, int numD, int _birthYear)
	{
		_stateArray.addCitizenCountToState(numD);
		citizen newC(_name, id, numD, _birthYear);
		_citizenList.addNodeToTail(&newC);
	}
	const citizen& ElectionRound::getCitizenById(int numId)
	{
		return *_citizenList.getCitizenById(numId);
	}
	void ElectionRound::printCitizenList()
	{
		_citizenList.printList();
	}


	////////////  POLITICALPARTY implementation  //////////

	void ElectionRound::addPoliticalParty(char* name, int headId)
	{
		citizen* headPoly = _citizenList.getCitizenById(headId);
		if (headPoly != nullptr)
		{
			_politicalPartyArray.addPoliticalParty(name, headPoly);
		}
		else
			cout << "there is no citizen with this Id in the country" << endl;
	}
	void ElectionRound::printPoliticalPartyArray()
	{
		_politicalPartyArray.printPoliticalPartyArray();
	}

	const politicalParty& ElectionRound::getPoliById(int numId)
	{
		return _politicalPartyArray.getPoliticalPartyById(numId);

	}
	/*const citizenList& ElectionRound::getSelectedRepList(int PoliId, int StateId, int repCount)
	{
		return _politicalPartyArray.getSelectedRepList(PoliId, StateId, repCount);
	}*/

	void ElectionRound::addRepresentativetoPoli(int repId, int PoliId, int StateId)
	{
		citizen* rep = _citizenList.getCitizenById(repId);
		if (rep != nullptr)
			_politicalPartyArray.addRepToPoli(PoliId, StateId, rep);
		else
			cout << "there is no citizen with this Id in the country" << endl;

	}

	void ElectionRound::printElectionResultsForPoli(int poliId)
	{

	}

	///////////// Vote implementation///////////////

	void ElectionRound::addVote(int citizenId, int poliId)
	{
		citizen* cit = _citizenList.getCitizenById(citizenId);
		if (cit == nullptr)
			cout << "there is no citizen with this Id in the country" << endl;

		if (cit->getVote() != -1)
		{
			cit->setvote(poliId);
			_politicalPartyArray.addVote(poliId, cit->getStateId());
		}
		else
			cout << "You already voted" << endl;
	}


	int ElectionRound::calculateNumOfRepInPoliForState(int poliId, int stateId)
	{
		float precent =(float) _politicalPartyArray.getOverAllVotesForPoliInState(poliId, stateId) /_stateArray.getCitizenCount(stateId);
		int num = precent * _stateArray.getStatenumOfRepresentative(stateId);
		return num;
	}
	
	
	int ElectionRound::printElectionResultsForState(int stateId, int *winingPoliID)
	{
		int numberOfRepresentatvie=0;
		int maxVote=0;
		int countVotes=0;
		float precent;
		int votesForPoli;
		int numOfCitizenInState = _stateArray.getCitizenCount(stateId);
		int winingPoli = 0;
		int winingPoliNumOfRepre = 0;
		
		for (int i = 1; i < countPoliticalParty; i++)
		{
			votesForPoli = _politicalPartyArray.getOverAllVotesForPoliInState(i, stateId);
			precent = (float)votesForPoli/numOfCitizenInState ;
			numberOfRepresentatvie = precent * _stateArray.getStatenumOfRepresentative(stateId);
			cout << "for:" << _politicalPartyArray.getName(i) << " number of votes:" << votesForPoli << "precent:" << precent << endl;
			cout << "selected representative list:" << endl;
			_politicalPartyArray.printSelectedRepList(i, stateId, numberOfRepresentatvie);

			if (votesForPoli > maxVote)
			{
				maxVote = votesForPoli;
				winingPoli = i;
				winingPoliNumOfRepre = numberOfRepresentatvie;
			}
			countVotes += votesForPoli;
		}
		int votesTurnOut = (float)(countVotes / numOfCitizenInState) * 100;

		cout << " the votes turn out is" << votesTurnOut;
		cout << " the wining political party is:" << _politicalPartyArray.getName(winingPoli) << endl;
		*winingPoliID = winingPoli;
		return numberOfRepresentatvie;
	}
	////////// Turn Out ////
	void ElectionRound::printElectionResults()
	{
		int len = countPoliticalParty + 1;
		int* numOfRepForPoliArray = new int[len];
		int temp;
		int tempId;
		for (int i = 0; i <= countState; i++)
		{
			temp = printElectionResultsForState(i, &tempId);
			numOfRepForPoliArray[tempId] = temp;
		}
	}
}