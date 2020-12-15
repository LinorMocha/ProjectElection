#include"citizen.h"
#include "politicalParty.h"
#include"citizenList.h"
#include "utils.h"
#include <iostream>
#include"ElectionRound.h"
#include "StateArray.h"

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


void exe(int n);
void printMenu();
void addState();
void addCitizen();
void addPoliticalParties();
void addRepresentative();
void printStates();
void printCitizens();
void printPoliticalParties();
void addVote();
void printResult();

ElectionRound Round;

int main()
{
	cout << "*********************************" << endl;
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


	printMenu();
	
	int chose;
	cin >> chose;

	while (chose != 10)
	{
		if (chose < 1 || chose>10)
			cout << "worng . enter again chose a nuber between 1-10" << endl;
		else
		exe(chose);
		printMenu();
		cin >> chose;
	}
	
	cout << "Good bye";

	return 0;
}

void printMenu()
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
	cout << " 10- STOP" << endl;
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

	}
}

void addState()
{
	cout << "please enter state name" << endl;
	char* input = new char[utils::MAXSIZE];
	cin >> input;
	char* name = utils::my_strdup(input);
	cout << "please enter state number of representative" << endl;
	int input2;
	cin >> input2;
	Round.addState(name, input2);

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
	if (!Round.addCitizen(name, id, stateNum, birthYear))
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

	if (!Round.addPoliticalParty(name, input2))
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
	

	if (!Round.addRepresentativetoPoli(input, input2, input3))
		cout << "EROR! please enter an exsited state, citizen and political party, Representative can represent only one political party! " << endl;
	
}
void printStates()
{
	cout << "the States in the country are:" << endl;
	Round.printStateArray();
}
void printCitizens()
{
	cout << "the citizens in the country are:" << endl;
	
	Round.printCitizenList();
}
void printPoliticalParties()
{
	cout << "the political parties in the country are:" << endl;
	Round.printPoliticalPartyArray();
	
}
void addVote()
{
	cout << "please enter citizen ID " << endl;
	int input;
	cin >> input;

	cout << "please choose political party" << endl;
	int input1;
	cin >> input1;

	if(!Round.addVote(input, input1))
		cout<<"Id dont exsict or you aleardy voted"<<endl;
}

void printResult()
{
	
	int res=Round.printElectionResults();
	if (res == 0)
		cout << "enter first State Citizens and PoliticalParty" << endl;
	if (res == 1)
		cout << " the representative isnt full!. you need to enter more representative" << endl;
}