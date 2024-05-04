#include <stdio.h>
#include <string.h>
#include <time.h>
char* new_strtok(register char* string, register char* delimiters){    
    static char* holder = 0;
    register char* token = 0;
    register char* delimiter = delimiters;
    if (holder != 0){
        string = holder;
    }
    else {
        holder = string;
    }
    if (*string++ == '\0'){
        holder = 0;
        return NULL;
    }
    //spanp in the original version served to skip delimiter values before a useful value
    string--;
skip_delimiter:
    for (; *delimiter; delimiter++){
        if (*string == *delimiter){
            string++;
            goto skip_delimiter;
        }
    }
    holder = string;   
    for(; *string; ++string){
        for (delimiter = delimiters; *delimiter; ++delimiter){ 
            if (*string == *delimiter){
                *string = '\0';
                 string++;
                 token = holder;
                 holder = string;
                 return token;
            }
        }
    }
    
    token = holder;
    holder = string;
    return token;
}
