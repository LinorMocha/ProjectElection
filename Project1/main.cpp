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
	
	printMenu();
	
	int chose;
	cin >> chose;
	
	while (chose != 10)
	{
		if (chose < 1 || chose>10)
			cout << "worng . enter again" << endl;
		else
		exe(chose);
		printMenu();
		cin >> chose;
	}
	
	cout << "bay bay";

	return 0;
}

void printMenu()
{
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
	cout << "please enter ID number" << endl;
	int id;
	cin >> id;
	cout << "please enter birth year" << endl;
	int birthYear;
	cin >> birthYear;
	cout << "please enter state number" << endl;
	int stateNum;
	cin >> stateNum;
	Round.addCitizen(name, id,stateNum, birthYear);

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
	Round.addPoliticalParty(name, input2);
	
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

	Round.addRepresentativetoPoli(input, input2, input3);
	
}
void printStates()
{
	cout << "the State in the country are:" << endl;
	Round.printStateArray();
}
void printCitizens()
{
	cout << "the citizen in the country are:" << endl;
	Round.printCitizenList();
}
void printPoliticalParties()
{
	cout << "the political parties in the country are:" << endl;
	Round.printPoliticalPartyArray();
	
}
void addVote()
{
	cout << "please enter citizen ID" << endl;
	int input;
	cin >> input;
	cout << "please choose political party" << endl;
	int input1;
	cin >> input1;
	Round.addVote(input, input1);
}

void printResult()
{
	cout << "Elecation round result" << endl;
	Round.printElectionResults();
}