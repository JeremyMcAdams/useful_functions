#include "my_string.h"
int new_strlen(register char* string){
    char* end_pointer;
    for(end_pointer = string; *end_pointer; ++end_pointer);
    return end_pointer - string;
}

