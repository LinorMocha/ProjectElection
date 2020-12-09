#include"citizen.h"
#include "politicalParty.h"
#include"citizenList.h"
#include "utils.h"
#include <iostream>
#include"ElectionRound.h"
#include "StateArray.h"

using namespace std;
using namespace proj;

void exe(int n);
void printMenu();
void exe1();
void exe2();
void exe3();
void exe4();
ElectionRound a;

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
	case 1:
		exe1();
		break;
	case 2:
		exe2();
		break;
	case 3:
		exe3();
		break;
	case 4:
		exe4();
		break;

	}
}
void exe1()
{
	cout << "please enter state name" << endl;
	char* input = new char[utils::MAXSIZE];
	cin >> input;
	char* name = utils::my_strdup(input);
	cout << "please enter state number of representative" << endl;
	int input2;
	cin >> input2;
	a.addState(name, input2);
	a.printStateArray();
}
void exe2()
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
	a.addCitizen(name, id,stateNum, birthYear);
	a.printCitizenList();
}
void exe3()
{
	cout << "please enter political party name" << endl;
	char* input = new char[utils::MAXSIZE];
	cin >> input;
	char* name = utils::my_strdup(input);
	cout << "please enter political party head Id" << endl;
	int input2;
	cin >> input2;
	a.addPoliticalParty(name, input2);
	a.printPoliticalPartyArray();
}
void exe4()
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

	a.addRepresentativetoPoli(input, input2, input3);
	a.printPoliticalPartyArray();
}