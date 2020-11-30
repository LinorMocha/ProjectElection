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
		int vote;

	public:
		citizen();
		citizen(const char* _name, int id, int numD);
		~citizen();
		void operator=(const citizen& input);
	};
}