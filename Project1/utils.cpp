#include "utils.h"
#include <iostream>

using namespace std;

namespace proj {
    int utils::MAXSIZE = 30;
    int utils::myStrlen(char* input)
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
 
    char* utils::my_strdup(char* input) 
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
    void utils::initArr(int* arr,int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

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

}