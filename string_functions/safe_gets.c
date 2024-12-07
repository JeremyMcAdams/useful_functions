#include <stdio.h>
#include "my_string.h"
void safe_gets(char* restrict destination, const unsigned buffer_size){
    for (int i = 0; i < buffer_size; ++i){
        int character = getchar();
        if ((char) character == '\n' || (char) character == -1 || (char) character == '\0'){
            destination[i] = '\0';
            break;
        }
        else if (i == buffer_size - 1){
            destination[i] == '\0';
        }
        else {
            destination[i] = (char) character;
        }   
    }

}
