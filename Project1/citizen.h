#include <iostream>
using namespace std;

#pragma once
namespace proj
{
	class citizen
	{
	private:
		char* name;
		int ID;
		int numDistrict;
		int birthYear;
		int vote;

	public:
		citizen();
		citizen(char* _name, int id, int numD,int _birthYear);
		~citizen();
		void operator=(const citizen& input);
		int getId();
		void setvote(int _vote);
	};
}