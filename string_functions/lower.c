#include "my_string.h"
void lower(register char* string){
    register const unsigned int conversion= 32; 
    for(;*string; ++string){
        if(*string >= 'A' && *string <= 'Z'){
            *string = *string + conversion;
        }
    }
}
