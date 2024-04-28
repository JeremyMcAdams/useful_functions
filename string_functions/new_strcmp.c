#include "my_string.h"
int new_strcmp(register const char* string, register const char* comp_string){
    while (*string == *comp_string){
        if (*string == '\0'){
            break;
        }
        string++;
        comp_string++;
    }
    return *string - *comp_string;   
}

