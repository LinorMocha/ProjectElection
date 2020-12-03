#include "utils.h"
#include <iostream>

using namespace std;

namespace proj {

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

    

}