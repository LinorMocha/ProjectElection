#pragma once


namespace proj
{

#define rcastcc reinterpret_cast<const char*> 
#define rcastc reinterpret_cast<char*> 

	struct Date
	{
		int day;
		int month;
		int year;
	};

	class utils
	{
	public:
		static char* my_strdup(const char* input);
		static int myStrlen(const char* input);
		static void initArr(int* arr,int size);
		static int MAXSIZE;
		static int returnMaxIndexInArray(float* arr, int size);
		static void addArrays(int* arr1, int* arr2, int size);
	};

}