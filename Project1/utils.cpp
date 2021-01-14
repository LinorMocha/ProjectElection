#include "utils.h"
#include <iostream>

using namespace std;

namespace proj {

    
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

    // support  save state acourding to type
    int utils::SaveStateType(State* sta)
    {
        int tempType = sta->getStateType();
        if (tempType == StateSaveStatus::sepretad)
            return StateSaveStatus::sepretad;

        if (tempType == StateSaveStatus::Union)
            return StateSaveStatus::Union;
    }

}