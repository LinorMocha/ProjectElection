#pragma once


namespace proj
{
	struct Date
	{
		int day;
		int month;
		int year;
	};

	class utils
	{
	public:
		static char* my_strdup(char* input);
		static int myStrlen(char* input);
		static void initArr(int* arr,int size);
		static int MAXSIZE;
		static int returnMaxIndexInArray(float* arr, int size);

	};

}