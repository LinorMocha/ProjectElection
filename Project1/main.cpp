#include"citizen.h"
#include "politicalParty.h"
#include"citizenList.h"
#include "utils.h"
#include <iostream>
#include"ElectionRound.h"
#include "StateArray.h"
#include <typeinfo>
#include "ELectionProportiaonal.h"
#include <fstream>

using namespace std;
using namespace proj;

/// const ///
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
		cin >> statusRound;
		if (statusRound == 1)
		{
			Round = new ElectionRound();
		}
		if (statusRound == 2)
		{
			int numRep;
			cout << "please enter number of representatives" << endl;
			cin >> numRep;
			Round = new ElectionProportiaonal(numRep);
		}
		cout << "please enter date first:" << endl;
		cout << "enter day" << endl;
		int _day;
		cin >> _day;
		cout << "enter month" << endl;
		int _month;
		cin >> _month;
		cout << "enter year" << endl;
		int _year;
		cin >> _year;
		Round->setDate(_day, _month, _year);

	}
	else if (input == 2) //add constractor to file + add operator = 
	{
	/*	ElectionRound(file)
			round = file*/
	}
	else
		return 0;
		
	PrintMenuSecondary();

		int chose;
		cin >> chose;

		while (chose != 10)
		{
			if (chose < 1 || chose>10)
				cout << "worng . enter again chose a nuber between 1-10" << endl;
			else
				exe(chose);
			PrintMenuSecondary();
			cin >> chose;
		}

		cout << "Good bye";

		return 0;

}

void printMenuPrimary()
{
	cout << "________________________________" << endl;
	cout << " 1- create new election round " << endl;
	cout << " 2- load election round" << endl;
	cout << " 3- exit" << endl;
	cout << "________________________________" << endl;
}

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

void saveElectionRound()
{
	ifstream inFile;
	char* input = new char[utils::MAXSIZE];
	cout << "please enter name file to save:" << endl; // àðâìéú ú÷éðä ?
	cin >> input; 
	char* name = utils::my_strdup(input);
	inFile.open(name,ios::binary);
	if (!inFile)
	{
		cout << "Error with inFile" << endl;
		return;
	}


}

void loadElectionRound()
{
	 
	char* input = new char[utils::MAXSIZE];
	cout << "please enter name file to load :" << endl;
	cin >> input;
	char* name = utils::my_strdup(input);
	
}

void addState()
{
	if (typeid(Round) == typeid(ElectionProportiaonal))
	{
		cout << "ERROR" << endl;
	}
	else
	{
		cout << "please enter state name" << endl;
		char* input = new char[utils::MAXSIZE];
		cin >> input;
		char* name = utils::my_strdup(input);
		cout << "please enter state number of representative" << endl;
		int input2;
		cin >> input2;
		int Status;
		cout << "please enter Status state , for union state press 1 , for sepraeted state press 2" << endl;
		cin >> Status;
		Round->addState(name, input2,Status==1);


	}
	

}

void addCitizen()
{
	cout << "please enter citizen name" << endl;  
	char* input = new char[utils::MAXSIZE];
	cin >> input;
	char* name = utils::my_strdup(input);
	cout << "please enter ID number " << endl;
	int id;
	cin >> id;
	cout << "please enter birth year" << endl;
	int birthYear;
	cin >> birthYear;
	cout << "please enter state number" << endl;
	int stateNum;
	cin >> stateNum;
	if (!Round->addCitizen(name, id, stateNum, birthYear))
		cout << "EROR! please enter an exsited state and a new ID"<<endl;
}
void addPoliticalParties()
{
	cout << "please enter political party name" << endl; 
	char* input = new char[utils::MAXSIZE];
	cin >> input;
	char* name = utils::my_strdup(input);
	cout << "please enter political party head Id" << endl;
	int input2;
	cin >> input2;

	if (!Round->addPoliticalParty(name, input2))
	{
		cout << "EROR! please enter an exsited state and citizen" << endl;
    }
	
}

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
	

	if (!Round->addRepresentativetoPoli(input, input2, input3))
		cout << "EROR! please enter an exsited state, citizen and political party, Representative can represent only one political party! " << endl;
	
}
void printStates()
{
	cout << "the States in the country are:" << endl;
	Round->printStateArray();
}
void printCitizens()
{
	cout << "the citizens in the country are:" << endl;
	
	Round->printCitizenList();
}
void printPoliticalParties()
{
	cout << "the political parties in the country are:" << endl;
	Round->printPoliticalPartyArray();
	
}
void addVote()
{
	cout << "please enter citizen ID " << endl;
	int input;
	cin >> input;

	cout << "please choose political party" << endl;
	int input1;
	cin >> input1;

	if(!Round->addVote(input, input1))
		cout<<"Id dont exsict or you aleardy voted"<<endl;
}

void printResult()
{

	int res = printElectionRoundResult();
	if (res == 0)
		cout << "enter first State Citizens and PoliticalParty" << endl;
	if (res == 1)
		cout << " the representative isnt full!. you need to enter more representative" << endl;
}
int printElectionRoundResult()
{
	if (Round->countState == 0 || Round->countPoliticalParty == 0 || Round->countCitizen == 0)
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
		cout << " number of representative for this party: " << numOfRepForPoliArray[j + 1];

		if (numOfRepForPoliArray[j] > max)
		{
			max = numOfRepForPoliArray[j];
			maxId = j;
		}
	}

	cout << " the wining party in the elecation is:" << Round->getPoliById(maxId).getName()<< endl;
	cout << " the president in the elecation is:" << Round->getPoliById(maxId).getPoliticalPartyHead()<< endl;
	cout << "__________________________________________________________________" << endl;

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

		int j = utils::returnMaxIndexInArray(temp, Round->countState);

		winningPoli = j + 1;

		for (int i = 0; i < sta.getNumOfRepresentative(); i++)
		{
			temp[j] -= votesForRep;
			howManyRep[j]++;
			j = utils::returnMaxIndexInArray(temp, Round->countState);

		}
		delete[]temp;
		int votesForPoli;
		int numOfRep;
		for (int i = 1; i <= Round->countPoliticalParty; i++)
		{
			votesForPoli = Round->getPoliById(i).getHowManyVotesForState(stateId);
			precent = (float)votesForPoli / sta.getCountVotesInState();
			cout << "number of votes : " << votesForPoli;
			cout << "for political party:" << Round->getPoliById(i).getName();
			cout << "percent of votes:" << precent << '%' << endl;
			cout << "selected representative list:" << endl;
			numOfRep = howManyRep[i - 1];
			Round->getPoliById(i).PrintWinningRepresentitives(stateId, numOfRep);
			cout << endl;
		}

	}

	precent = (float)sta.getCountVotesInState() / sta.getHowManyCitizens();

	cout << " the State voter turn out is:" << precent * 100 << '%' << endl;
	if (sta.getStateStatus())
	{
		cout << " the State chose:" << Round->getPoliById(winningPoli).getName() << "  to be president!!!" << endl;
		for (int j = 0; j < Round->countPoliticalParty; j++)
		{
			if (j != winningPoli - 1)
			{
				howManyRep[j] = 0;
			}
		}
	}

	return howManyRep;
}
