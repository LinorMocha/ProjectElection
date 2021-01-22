#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace proj
{

#define rcastcc reinterpret_cast<const char*> 
#define rcastc reinterpret_cast<char*> 
	static const int maxDayPerMonthArr[13]={ -1,31,28,31,30,31,30,31,31,30,31,30,31 };
	

	struct Date
	{
		int day;
		int month;
		int year;
	};
	class utils
	{
	public:
		template <class iterator>
		static void initArray(iterator begin, int size)
		{
			for (int i=0;i<size; i++,begin++)
			{
				(*begin) = 0;
				
			}
		}

		template <class iterator>
		static void deleteElementInArray(iterator begin, iterator end)
		{
			iterator temp = begin;
			while (temp != end)
			{
				temp++;
				delete (*begin);
				begin = temp;
			}
		}

		template <class T>
		static int returnMaxIndexInArray(vector<T> arr, int size)
		{
			float max = 0;
			int maxId = 0;
			for (int i = 0; i < size; i++)
			{
				if (max < arr[i])
				{
					max = arr[i];
					maxId = i;
				}
			}
			return maxId;
		}

		template <class iterator,class T> 
		static iterator Find(iterator begin,iterator end,T& toFind)
		{
			for (; begin != end; ++begin)
			{
				if ((**begin) == toFind)
					return begin;
			}
			return end;
		}

		template <class iterator>
		static void print(iterator begin, iterator end)
		{
			while (begin != end)
			{
				cout << (**begin) << endl;
				begin++;
			}
		}
		//This function chains two arrays together
		static void addArrays(vector<int>& arr1, vector<int>& arr2, int size)
		{
			for (int i = 0; i < size; i++)
			{
				if (arr2[i] != 0)
					arr1[i] = arr1[i] + arr2[i];
			}
		}
		
		enum StateSaveStatus { defualt, Union, sepretad };

	};

}