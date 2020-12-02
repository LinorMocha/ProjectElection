#include"citizen.h"
#include "politicalParty.h"
#include"citizenList.h"
#include "utils.h"
#include <iostream>
#include"ElectionRound.h"
#include "StateArray.h"
using namespace std;
using namespace proj;

int main()
{
	
	char a[] = "jmvj";
		
		State d(a,12);
		State b;
		b = d;
		cout << b.getNumOfRepresentative()<<endl;
		cout << b.getName();
		
		StateArray ab;

				ab.reSizeStateArray(2, 4);

	/*char* n;
		char c = 'a';
		n = &c;
		a.addState(n, 3);
		a.addState(n, 3);
		a.addState(n, 3);
		a.reSizeStateArray(0, 4);
		cout << ElectionRound::countState << endl;*/

	

	return 0;
}