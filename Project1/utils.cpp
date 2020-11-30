#include "utils.h"
#include <iostream>
#include <string.h>
using namespace std;

namespace proj {
 
    char* utils::my_strdup(const char* input) {
        // We need strlen(src) + 1, since we have to account for '\0'
        int len = strlen(input) + 1;
        char* output = new char[len];
        if (output == nullptr)
            return nullptr;
        strcpy_s(output,len, input);
        return output;
    }

    

}