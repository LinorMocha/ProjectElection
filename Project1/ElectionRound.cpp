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
		utils::deleteElementInArray(_stateArray.begin(), _stateArray.end());
		utils::deleteElementInArray(_politicalPartyArray.begin(), _politicalPartyArray.end());

	}


	//set the date of the election round
	void ElectionRound::setDate(int day, int month, int year)
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
	void ElectionRound::addState(const string name, int numRep, int Status)
	{
		State* sta;
		if (Status == utils::Union)
		{
			try {
				sta = new  UnionState(name, numRep,countState+1);
			}
			catch (std::exception& ex) {
				throw ex;
			}
			
		}
		else if (Status == utils::sepretad)
		{
			try {
				sta = new  SperatedState(name, numRep,countState+1);
			}
			catch (std::exception& ex) {
				throw ex;
			}
		}
		else
			throw invalid_argument("status of state can be only 1 or 2");
		_stateArray.push_back(sta);
		countState++;
	}
	//this function prints the State Array
	void ElectionRound::printStateArray()
	{
		if (countState <= 0)
			throw invalid_argument("there is no state");

		for (int i = 0; i < countState; i++)
			cout <<(*_stateArray[i]) << endl;
		//utils::print(_stateArray.begin(), _stateArray.end());
		/*auto itStateArr = _stateArray.begin();
		int temp;
		while (itStateArr != _stateArray.end())
		{
			cout<<(**itStateArr)<<endl;
			itStateArr++;
		}*/
		
	}

	//This function returns ref to the desired state according to the given ID 
	State* ElectionRound::getStateById(int numId) const	{return _stateArray[numId-1];}


	///////////// CITIZEN implementation//////////////////
	
	//This function creates new citizen if he doesn't exist and adds him to the end of the citizen Array
	void ElectionRound::addCitizen(const string _name, int id, int numD, int _birthYear)
	{
		if (numD > countState)
			throw invalid_argument("state dont exsit");
		if ((date.year -_birthYear) < 18) 
			throw  invalid_argument("The citizen is too young to vote");
		try {
			_citizenList.addCitizenToListTail(_name, id, *_stateArray[numD - 1], _birthYear);
		}
		catch(std::exception& ex){
			throw ex;
		}
			countCitizen++;
			_stateArray[numD-1]->addCitizen();
	}
	


	//This function returns ref to the desired citizen according to the given ID 
	const citizen& ElectionRound::getCitizenById(int numId)
	{
		return *_citizenList.getCitizenById(numId);
	}
	
	//
	bool ElectionRound::isNumberIdAvilable(int numId)
	{
		if(_citizenList.getCitizenById(numId)==nullptr)		
			return true;
		else
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
		citizen* headPoly = _citizenList.getCitizenById(headId);
			auto itArr = _politicalPartyArray.begin();
			int temp;
			while (itArr != _politicalPartyArray.end())
			{
				try {
					(*itArr)->isRep(*headPoly);
				}
				catch (exception& ex)
				{
					throw ex;
				}
				itArr++;
			}
		politicalParty* poly = new politicalParty(name, headPoly);
		_politicalPartyArray.push_back(poly);
		countPoliticalParty++;
	}

	//this function get ref to political Party according to ID
	const politicalParty& ElectionRound::getPolitaclPartyById(int id)
	{
		return *_politicalPartyArray[id];
	}
	
	//This function returns the total number of votes for party
	int ElectionRound::getOverAllVotesForPoli(int polyId)
	{
		return _politicalPartyArray[polyId]->getHowManyVotesOverAll();
	}
	
	//this function prints the Political party array
	void ElectionRound::printPoliticalPartyArray()
	{
		if (countPoliticalParty <= 0)
			throw invalid_argument("there is no political parties");
		auto IT = _politicalPartyArray.begin();
		int temp;
		while (IT != _politicalPartyArray.end())
		{
			cout << (**IT) << endl;
			IT++;
		}
	}
	//This function returns ref to the desired party according to the given ID 
	const politicalParty& ElectionRound::getPoliById(int numId)
	{
		
		return *_politicalPartyArray[numId-1];
	}

	////////// REPRESENTATIVE ////////
	//This function adds a representative to party 
	void ElectionRound::addRepresentativetoPoli(int repId, int PoliId, int StateId)
	{
		if(PoliId>countPoliticalParty||PoliId<=0)
			throw invalid_argument("there is no political party with this id ");
		if (StateId > countState || StateId <= 0)
			throw invalid_argument("there is no political party with this id ");


		if(isNumberIdAvilable(repId))
			throw invalid_argument("there is no citizen according to this given id ");
		
		citizen* rep = _citizenList.getCitizenById(repId);
		
		if(isCitizenRepOrHeadOfPoly(*rep))
			throw invalid_argument("there is no head poly according to this given id ");

		_politicalPartyArray[PoliId-1]->addRepresentitive(rep, StateId);

		
	}

	//chaek if representative lists full acourdind states number of representative  
	void ElectionRound::isRepListComplete()
	{
		int numOfExsitesRep;
		for (int i = 0; i < countPoliticalParty; i++)
		{
			for (int j = 0; j < countState; j++)
			{
				if (_politicalPartyArray[i]->getNumOfRepInList(j) < _stateArray[j]->getNumOfRepresentative())
					throw invalid_argument("Representative list is not complete");
			}
		}
	}
	
	// return true if citizen is already representative or head of political party
	bool ElectionRound::isCitizenRepOrHeadOfPoly(const citizen& cit){
		auto itArr = _politicalPartyArray.begin();
		int temp;
		while (itArr != _politicalPartyArray.end())
		{
			try {
				(*itArr)->isRep(cit);
			}

			catch (std::exception& ex)
			{
				return true;
			}
			itArr++;
		}
		return false;
	}

	///////////// Vote implementation///////////////

	//This function adds votes of citizens who haven't voted yet
	void ElectionRound::addVote(int citizenId, int poliId){
		if (poliId <= 0 || poliId > countPoliticalParty)
		{
			throw invalid_argument("error with political party id ");
		}
		if(isNumberIdAvilable(citizenId))
			throw invalid_argument("there is no citizen according to this given id ");
		citizen* cit = _citizenList.getCitizenById(citizenId);
		if(cit->getVote() != -1)
			throw invalid_argument("the citizen already voted ");
			cit->setvote(poliId);
								/// the first poly is in cell 0 in the array
			_politicalPartyArray[poliId-1]->addVote(cit->getStateId());
			_stateArray[(cit->getStateId()-1)]->addVote();
	}


	//This function writes the curr round data to binary file
	void ElectionRound::save(ostream& out) const {
		out.write(rcastcc(&date.day), sizeof(int));
		out.write(rcastcc(&date.month), sizeof(int));
		out.write(rcastcc(&date.year), sizeof(int));
		out.write(rcastcc(&countCitizen), sizeof(int));
		out.write(rcastcc(&countState), sizeof(int));
		out.write(rcastcc(&countPoliticalParty), sizeof(int));
		if (!out.good())
			throw invalid_argument("Error with file");

		//save state array to file
		auto itStateArr = _stateArray.begin();
		int temp;
		while (itStateArr != _stateArray.end())
		{
			try {
				(*itStateArr)->save(out);
			}
			catch (std::exception& ex) {
				throw ex;
			}
			itStateArr++;
		}

		try//save the citizen list to file
		{
			_citizenList.save(out);
		}
		catch (std::exception& ex)
		{
			throw ex;
		}

		//save the politcal party array to file
		auto itPoliticalPartyArr = _politicalPartyArray.begin();
		while (itPoliticalPartyArr != _politicalPartyArray.end())
		{
			try {
				(*itPoliticalPartyArr)->save(out);
			}
			catch (std::exception& ex) {
				throw ex;
			}
			itPoliticalPartyArr++;
		}
	}


	//This function reads the curr round data from binary file
	void ElectionRound::load(istream& in)
	{
		if (!in)//checks if the file works properly
			throw invalid_argument("Error with file");
		
		in.read(rcastc(&date.day), sizeof(int));
		in.read(rcastc(&date.month), sizeof(int));
		in.read(rcastc(&date.year), sizeof(int));
		in.read(rcastc(&countCitizen), sizeof(int));
		in.read(rcastc(&countState), sizeof(int));
		in.read(rcastc(&countPoliticalParty), sizeof(int));
		
		//load the state array from file
		int Status;
		for (int i = 0; i < countState; i++)
		{
			in.read(rcastc(&Status), sizeof(int));
			State* sta;
			if (Status == utils::Union)
			{
				try {
					sta = new UnionState(in);
					_stateArray.push_back(sta);
				}
				catch (std::exception& ex) {
					throw ex;
				}

			}
			else if (Status == utils::sepretad)
			{
				try {
					sta = new  SperatedState(in);
					_stateArray.push_back(sta);
				}
				catch (std::exception& ex) {
					throw ex;
				}
			}
			else
				throw invalid_argument("load stateArray to file didn't preforemd proprtaly");
		
		}
		
		//load the citizen list from file
		int size_list;
		in.read(rcastc(&size_list), sizeof(size_list));
		int tempIdState;
		
		for (int i = 0; i < size_list; i++)
		{
			in.read(rcastc(&tempIdState), sizeof(tempIdState));
			try {
				if (!in.good())
					throw invalid_argument("ERROR with file");

				citizen* newCit = new citizen(getStateById(tempIdState));
				newCit->load(in);
				_citizenList.addCitizenToListTail(newCit);
			}
			catch (bad_alloc& ex) {
				throw ex;
			}
		}
		
		//load the politcal party array from file
		int tempHeadOfPolyId;
		citizen* headOfPoly;
		for (int i = 0; i < countPoliticalParty; i++)
		{
			in.read(rcastc(&tempHeadOfPolyId), sizeof(int));
			headOfPoly = _citizenList.getCitizenById(tempHeadOfPolyId);
			try {
				politicalParty* poly = new politicalParty(in, _citizenList, headOfPoly);
				_politicalPartyArray.push_back(poly);
			}
			catch (exception& ex)
			{
				throw ex;
			}
		}
						
			
	}
	
	
	// this funcation return a vector that say how many rep from each poly won
	// winnig poly update only for union state
	vector<int> ElectionRound::caculateResultForState(int stateId,int & wininigPoly)
	{
		float precent;

		State* sta = getStateById(stateId);

		vector <int> howManyRep(countPoliticalParty);
		vector <float> temp;
		
		// if no one from the state voted all of the vote goes to the first political party
		if (sta->getCountVotesInState() == 0)
			_politicalPartyArray[0]->setVote(stateId, sta->getHowManyCitizens());
		
		for (int i = 0; i < countPoliticalParty; i++)
		{
		 temp.push_back((float)getPoliById(i + 1).getHowManyVotesForState(stateId));
		}
		
		float votesForRep = (float)sta->getCountVotesInState() / sta->getNumOfRepresentative();

		int j = utils::returnMaxIndexInArray(temp, countPoliticalParty);
		wininigPoly = j;
		for (int i = 0; i < sta->getNumOfRepresentative(); i++)
		{
			temp[j] -= votesForRep;
			howManyRep[j]++;

			j = utils::returnMaxIndexInArray(temp, countPoliticalParty);
		}

		
		return howManyRep;
	}
}