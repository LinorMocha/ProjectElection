#include "utils.h"
#include <iostream>

using namespace std;

namespace proj {
 
    char* utils::my_strdup(const char* input) {
        if (input == nullptr)
            return nullptr;
       // int len = strlen(input) + 1;
        char* output = new char[30];
        int i = 0;
        while (input[i] != '/0')
        {
            output[i] = input[i];
            i++;
        }
        output[i] = '/0';
        return output;
    }

    

}