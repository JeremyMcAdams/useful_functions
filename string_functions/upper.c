#include "my_string.h"
void upper2(register char* string){
    register unsigned int conversion = 32;
    for(; *string; ++string){
        if (*string >= 'a' && *string <= 'z'){
            *string = *string - conversion;
        }
    }
}
