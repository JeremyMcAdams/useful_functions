#include "my_string.h"
#include <stdio.h>
#define bool int
#define true 1
#define false 0
void new_strncpy(register char* destination, register char* source, register int buffer_length){
    bool source_end = false;
    for (register int i = 0; i <= buffer_length; ++i){
    
        if (source[i] == '\0'){
            while (i < buffer_length){
                destination[i] = '\0';
                i += 1;
            }
            break;
        }
        else if (i == buffer_length){
            destination[i] = '\0';
        }
        else {
            destination[i] = source[i];
        }
    }
    if (buffer_length == 0){
        destination[0] = '\0';
    }
}

