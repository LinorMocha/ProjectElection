#include <iostream>
#include"ElectionRound.h"
#include <typeinfo>
#include "ELectionProportiaonal.h"
#include <fstream>
#include<string>

using namespace std;
using namespace proj;

/// const values ///
const int ADD_STATE = 1;
const int ADD_CITIZEN = 2;
const int ADD_POLITICAL_PARTY = 3;
const int ADD_REPRESENTATIVE = 4;
const int PRINT_STATES = 5;
const int PRINT_CITIZENS = 6;
const int PRINT_POLITICAL_PARTIES = 7;
const int ADD_VOTE = 8;
const int PRINT_RESULT = 9;
const int SAVE_ROUND = 10; 
const int LOAD_ROUND = 11;

//------------------------declartions-------------------------//
void exe(int n);
void PrintMenuSecondary();
void addState();
void addCitizen();
void addPoliticalParties();
void addRepresentative();
void printStates();
void printCitizens();
void printPoliticalParties();
void addVote();
void printResult();
void printMenuPrimary();
void saveElectionRound();
void loadElectionRound();
int printElectionRoundResult();
int* printElectionResultsForState(int stateId);
int printElectionRoundResultForProprotinal();
void switchMode(int input);
ElectionRound* Round;


int main()
{
	int input;
	printMenuPrimary();
	cin >> input;
	if (input == 1)
	{
		int statusRound;
		cout << "*********************************" << endl;
		cout << "for regular election round press 1 ,for proprotinal election round please press 2" << endl;
		
		do {
			
			cin >> statusRound;
			switchMode(statusRound);
		} while (statusRound !=2 && statusRound != 1);

		
		cout << "please enter date first:" << endl;
		int flag = 0;
		while (!flag)
		{
			cout << "enter day" << endl;
			int _day;
			cin >> _day;
			cout << "enter month" << endl;
			int _month;
			cin >> _month;
			cout << "enter year" << endl;
			int _year;
			cin >> _year;
			flag = 1;
			try {
				Round->setDate(_day, _month, _year);
			}
			catch (std::exception& ex) {
				cout << "Error: " << ex.what() << endl;
				cout << "try again:__________________" << endl;
				flag = 0;
			}
		}
		

	}
	else if (input == 2) 
	{
		loadElectionRound();

	}
	else
		return 0;
		
	PrintMenuSecondary();

		int chose;
		cin >> chose;

		while (chose != 12)
		{
			if (chose < 1 || chose > 11)
				throw invalid_argument("worng input, chose a nuber between 1-10");
			else
				exe(chose);
			PrintMenuSecondary();
			cin >> chose;
		}

		cout << "Good bye";

		delete Round;
		return 0;

}

void switchMode(int input)
{
	switch (input)
	{
	case 1:

		Round = new ElectionRound();
		break;
	case 2:
		int numRep;
		cout << "please enter number of representatives" << endl;
		cin >> numRep;
		try {
			Round = new ElectionProportiaonal(numRep);
		}
		catch(exception&ex){
			cout << ex.what() << endl;
			input = 3;
		}
		break;
	default:
		cout << "Error! please press ONLY 1 or 2" << endl;

		break;
	}
}


//This function prints the primary menu
void printMenuPrimary()
{
	cout << "________________________________" << endl;
	cout << " 1- create new election round " << endl;
	cout << " 2- load election round" << endl;
	cout << " 3- exit" << endl;
	cout << "________________________________" << endl;
}
//This function prints the secondary menu
void PrintMenuSecondary()
{
	cout << "________________________________" << endl;
	cout << " 1- add State " << endl;
	cout << " 2- add citizen" << endl;
	cout << " 3- add political party" << endl;
	cout << " 4- add a political party representative" << endl;
	cout << " 5- Print states" << endl;
	cout << " 6- Print citizens" << endl;
	cout << " 7- Print political parties" << endl;
	cout << " 8- add vote" << endl;
	cout << " 9- Print Elecation round result" << endl;
	cout << " 10 -save election round " << endl;
	cout << " 11- load election round" << endl;
	cout << " 12- STOP" << endl;
	cout << "________________________________" << endl;

}
//This function is responsible for all operations
void exe(int n)
{
	switch (n)
	{
	case ADD_STATE:
		addState();
		break;
	case ADD_CITIZEN:
		addCitizen();
		break;
	case ADD_POLITICAL_PARTY:
		addPoliticalParties();
		break;
	case ADD_REPRESENTATIVE:
		addRepresentative();
		break;
	case PRINT_STATES:
		printStates();
		break;
	case PRINT_CITIZENS:
		printCitizens();
		break;
	case PRINT_POLITICAL_PARTIES:
		printPoliticalParties();
		break;
	case ADD_VOTE:
		addVote();
		break;
	case PRINT_RESULT:
		printResult();
		break;
	case SAVE_ROUND:
		saveElectionRound();
		break;
	case LOAD_ROUND:
		loadElectionRound();
		break; 

	}
}
//this function saves the current round election
void saveElectionRound()
{
	ofstream File;
	string Filename;
	cout << "please enter name file to Load:" << endl;
	cin >> Filename;
	File.open(Filename, ios::binary);
	if (!File)
	{
		cout << "Error with File" << endl;
		return;
	}
	///// SAVING STATUS ROUND : proprtional =1 normal=0
	int status;
	if (typeid(*Round) == typeid(ElectionProportiaonal))
		status = 1;
	else
		status = 0;
	
	File.write(rcastcc(&status), sizeof(int));
	
	try {
		Round->save(File);
	}
	catch (std::exception& ex) {
		cout << "Error: " << ex.what() << endl;
		File.close();
		return;
	}

	cout << "Saved successfully" << endl;
	File.close();
}

//this function loads the current round election
void loadElectionRound()
{
	delete Round;
	ifstream fl;
	string Filename;
	cout << "please enter name file to Load:" << endl;
	cin >> Filename;
	
	int status;

	fl.open(Filename, ios::binary);

	if (!fl)
	{
		cout << " Error with FILE" << endl;
		return;
		
	}
	fl.read(rcastc(&status), sizeof(int));
	if (status)
		Round = new ElectionProportiaonal(fl);
	else
		Round = new ElectionRound(fl);
	if (!fl.good())
		cout << " Error with FILE" << endl;
	else
		cout << "Load successfully" << endl;
	fl.close();
}

//this function adds new state to the curr election round
void addState()
{
	if (typeid(*Round) == typeid(ElectionProportiaonal))
	{
		cout << "ERROR" << endl;
	}
	else
	{
		cout << "please enter state name" << endl;
		string input;
		cin.ignore();
		getline(cin,input);
		cin.clear();
		
		cout << "please enter state number of representative" << endl;
		int input2;
		cin >> input2;
		int Status;
		cout << "please enter Status state , for union state press 1 , for sepraeted state press 2" << endl;
		cin >> Status;
		if (Status > 2 || Status < 1)
			cout << "Error: status is 1 or 2" << endl;
		else
		Round->addState(input, input2, Status == 1);
	
	}
}

//this function adds new citizen to the curr election round
void addCitizen()
{

	cout << "please enter citizen name" << endl;  
	string name;
	cin.ignore();
	getline(cin, name);
	cin.clear();
	
	cout << "please enter ID number " << endl;
	int id;
	cin >> id;
	cout << "please enter birth year" << endl;
	int birthYear;
	cin >> birthYear;
	cout << "please enter state number" << endl;
	int stateNum;
	cin >> stateNum;
	try {

		Round->addCitizen(name, id, stateNum, birthYear);
	}
	catch (std::exception& ex) {
		cout << "Error: " << ex.what() << endl;
	}
	
}

//this function adds new party to the curr election round
void addPoliticalParties()
{
	cout << "please enter political party name" << endl; 
	string name;
	cin.ignore();
	getline(cin, name);
	cin.clear();
	
	cout << "please enter political party head Id" << endl;
	int input2;
	cin >> input2;

		try {
			Round->addPoliticalParty(name, input2);
		}
		catch (std::exception& ex) {
			cout << "Error: " << ex.what() << endl;
		}
}

//this function adds new representative to the curr election round
void addRepresentative()
{
	cout << "please enter representative ID" << endl;
	int input;
	cin >> input;
	
	cout << "please enter political party number" << endl;
	int input2;
	cin >> input2;

	cout << "please enter state number" << endl;
	int input3;
	cin >> input3;
	

	try {
		Round->addRepresentativetoPoli(input, input2, input3);
	}
	catch (std::exception& ex) {
		cout << "Error: " << ex.what() << endl;
	}
}
//this function prints the states exsict in the curr election round 
void printStates()
{
	if (typeid(*Round) == typeid(ElectionProportiaonal))
	{
		cout << "ERROR" << endl;
	}
	else {
		cout << "the States in the country are:" << endl;
		try {
			Round->printStateArray();
	     }
		catch (std::exception& ex) {
		cout << "Error: " << ex.what() << endl;
     	}
	}
	
}
//this function prints the citizens exsict in the curr election round
void printCitizens()
{
	cout << "the citizens in the country are:" << endl;
	try {
		Round->printCitizenList();
	}
	catch (std::exception& ex) {
		cout << "Error: " << ex.what() << endl;
	}

}
//this function prints the politcal parties exsict in the curr election round
void printPoliticalParties()
{
	cout << "the political parties in the country are:" << endl;
	
	try {
		Round->printPoliticalPartyArray();
	}
	catch (std::exception& ex) {
		cout << "Error: " << ex.what() << endl;
	}
	
}

//add new vote to current election round
void addVote()
{
	cout << "please enter citizen ID " << endl;
	int input;
	cin >> input;

	cout << "please choose political party" << endl;
	int input1;
	cin >> input1;
	try {
		Round->addVote(input, input1);
	}
	catch (std::exception& ex) {
		cout << "Error: " << ex.what() << endl;
	}
	
}
//prints the result of the current elction
void printResult()
{
	int res;
	if (typeid(*Round) == typeid(ElectionProportiaonal))
	{
		res = printElectionRoundResultForProprotinal();
	}
	else
		 res = printElectionRoundResult();
	if (res == 0)
		cout << "enter first State Citizens and PoliticalParty" << endl;
	if (res == 1)
		cout << " the representative isnt full!. you need to enter more representative" << endl;
}
//This function prints the results of the election round propprotinal
int printElectionRoundResultForProprotinal()
{
	if (Round->countPoliticalParty == 0 || Round->countCitizen == 0)
	{
		return 0;
	}
	/*if (!Round->isRepListComplete())
	{
		return 1;
	}*/
	cout << "__________________________________________________________" << endl;
	cout << " the Elecation Round in date:" << Round->getDay() << "/" << Round->getMonth() << "/" << Round->getYear() << "   result:" << endl;
	int StateID = 1;
	State& sta = Round->getStateById(StateID);

	float precent;
	int winningPoli = 1;
	int* howManyRep = new int[Round->countPoliticalParty]{ 0 };

	if (sta.getCountVotesInState() != 0)
	{
		float* temp = new float[Round->countPoliticalParty];
		for (int i = 0; i < Round->countPoliticalParty; i++)
		{
			temp[i] = (float)Round->getPoliById(i + 1).getHowManyVotesForState(StateID);

		}
		/// כמות ההצבעות חלקי כמות הנציגים
		float votesForRep = (float)sta.getCountVotesInState() / sta.getNumOfRepresentative();

		int j = utils::returnMaxIndexInArray(temp, Round->countPoliticalParty);

		winningPoli = j + 1;

		for (int i = 0; i < sta.getNumOfRepresentative(); i++)
		{
			temp[j] -= votesForRep;
			howManyRep[j]++;
			j = utils::returnMaxIndexInArray(temp, Round->countPoliticalParty);

		}
		delete[]temp;
		int votesForPoli;
		int numOfRep;
		for (int i = 1; i <= Round->countPoliticalParty; i++)
		{
			votesForPoli = Round->getPoliById(i).getHowManyVotesForState(StateID);
			precent = (float)votesForPoli / sta.getCountVotesInState();
			cout << "number of votes : " << votesForPoli;
			cout << " for political party:" << Round->getPoliById(i).getName();
			cout << "  percent of votes: " << precent * 100 << '%' << endl;
			cout << "selected representative list:" << endl;
			numOfRep = howManyRep[i - 1];
			Round->getPoliById(i).printWinningRepListForState(StateID, numOfRep);
			cout << endl;
		}

	}

	precent = (float)sta.getCountVotesInState() / sta.getHowManyCitizens();
	cout << " the voter turn out is:" << precent * 100 << '%' << endl;
	cout << " the winner in the election is political party:" << Round->getPoliById(winningPoli).getName() << endl;
	cout << " the president in the elecation is:" << Round->getPoliById(winningPoli).getPoliticalPartyHead() << endl;
	cout << "__________________________________________________________________" << endl;
}

int printElectionRoundResult()
{
	/*if (Round->countState == 0 || Round->countPoliticalParty == 0 || Round->countCitizen == 0)
	{
		return 0;
	}
	if (!Round->isRepListComplete())
	{
		return 1;
	}
	cout << "__________________________________________________________" << endl;
	cout << " the Elecation Round in date:" << Round->getDay() << "/" << Round->getMonth() << "/" << Round->getYear() << "   result:" << endl;


	int* numOfRepForPoliArray = new int[Round->countPoliticalParty] {0};

	int winingPoli;
	int* temp;
	for (int i = 1; i <= Round->countState; i++)
	{
		temp = printElectionResultsForState(i);
		utils::addArrays(numOfRepForPoliArray, temp, Round->countPoliticalParty);
		delete[]temp;
	}

	int max = 0;
	int maxId = 0;
	for (int j = 0; j < Round->countPoliticalParty; j++)
	{
		cout << Round->getPoliById(j + 1) << endl;
		cout << "political party got " << Round->getPoliById(j + 1).getHowManyVotesOverAll()<< " votes in the elecation" << endl;
		cout << " number of representative for this party: " << numOfRepForPoliArray[j];

		if (numOfRepForPoliArray[j] > max)
		{
			max = numOfRepForPoliArray[j];
			maxId = j;
		}
	}

	cout << " the wining party in the elecation is:" << Round->getPoliById(maxId+1).getName()<< endl;
	cout << " the president in the elecation is:" << Round->getPoliById(maxId+1).getPoliticalPartyHead()<< endl;
	cout << "__________________________________________________________________" << endl;
	*/
	return 2;
}

int* printElectionResultsForState(int stateId)
{

	State& sta = Round->getStateById(stateId);
	
		cout << sta;
	
	float precent;

	int winningPoli = 1;

	int* howManyRep = new int[Round->countPoliticalParty] {0};

	if (sta.getCountVotesInState() != 0)
	{

		float* temp = new float[Round->countPoliticalParty];
		for (int i = 0; i < Round->countPoliticalParty; i++)
		{
			temp[i] = (float)Round->getPoliById(i + 1).getHowManyVotesForState(stateId);

		}
		/// כמות ההצבעות חלקי כמות הנציגים
		float votesForRep = (float)sta.getCountVotesInState() / sta.getNumOfRepresentative();

		int j = utils::returnMaxIndexInArray(temp, Round->countPoliticalParty);

		winningPoli = j + 1;

		for (int i = 0; i < sta.getNumOfRepresentative(); i++)
		{
			temp[j] -= votesForRep;
			howManyRep[j]++;
			j = utils::returnMaxIndexInArray(temp, Round->countPoliticalParty);

		}
		delete[]temp;
		int votesForPoli;
		int numOfRep;
		for (int i = 1; i <= Round->countPoliticalParty; i++)
		{
			votesForPoli = Round->getPoliById(i).getHowManyVotesForState(stateId);
			precent = (float)votesForPoli / sta.getCountVotesInState();
			cout << "number of votes : " << votesForPoli;
			cout << " for political party:" << Round->getPoliById(i).getName();
			cout << "  percent of votes: " << precent * 100 << '%' << endl;
			cout << "selected representative list:" << endl;
			numOfRep = howManyRep[i - 1];
			Round->getPoliById(i).printWinningRepListForState(stateId, numOfRep);
			cout << endl;
		}

	}

	precent = (float)sta.getCountVotesInState() / sta.getHowManyCitizens();

	cout << " the voter turn out is:" << precent * 100 << '%' << endl;
	if (sta.getStateStatus())
	{
		cout << " the State chose:" << Round->getPoliById(winningPoli).getName() << "  to be president!!!" << endl;
		for (int j = 0; j < Round->countPoliticalParty; j++)
		{
			if (j != winningPoli - 1)
			{
				howManyRep[j] = 0;
			}
			else
				howManyRep[j] = sta.getNumOfRepresentative();
		}
	}

	return howManyRep;
}
