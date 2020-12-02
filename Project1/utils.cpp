#include "utils.h"
#include <iostream>
#include <string.h>
using namespace std;

namespace proj {
 
    char* utils::my_strdup(const char* input) {
        if (input == nullptr)
            return nullptr;
        int len = strlen(input) + 1;
        char* output = new char[len];
      
        strcpy_s(output,len, input);
        return output;
    }

    

}