#include "my_string.h"
#define bool int
#define true 1
#define false 0
void my_strncpy(char destination[], char* source, const int buffer_length){
    bool source_end = false;
    for (int i = 0; i < buffer_length; ++i){
        if (source[i] == '\0'){
            source_end = true;
        }
        else if (i == buffer_length - 1){
            destination[i] = '\0';
        }
        else if (source_end){
            destination[i] = '\0';
        }
        else {
            destination[i] = source[i]; 
        }   
    }
}

