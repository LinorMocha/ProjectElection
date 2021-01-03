#include "utils.h"
#include <iostream>

using namespace std;

namespace proj {
    int utils::MAXSIZE = 30;
    //this function finds the size of the string without '\0'
    int utils::myStrlen(const char* input)
    {
        int i = 0;
        int count = 0;
        while (input[i] != '\0')
        {
            i++;
            count++;
        }
        return count;
    }
    //this function duplicate a string to a new string.
    char* utils::my_strdup(const char* input) 
    {
        if (input == nullptr)
            return nullptr;
        int len = utils::myStrlen(input);
        len++;
        char* output = new char[len];
        int i = 0;
        while (input[i] != '\0')
        {
            output[i] = input[i];
            i++;
        }
        output[i] = '\0';
        return output;
    }
    //Initializes the array to zero
    void utils::initArr(int* arr,int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    //Returns the highest value in the array
    int utils::returnMaxIndexInArray(float* arr, int size)
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
    //This function chains two arrays together
    void utils::addArrays(int* arr1, int* arr2, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr2[i] != 0)
             arr1[i] = arr1[i] + arr2[i];
        }
    }

}