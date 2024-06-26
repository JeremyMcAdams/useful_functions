#include <stdio.h>
#include <stdlib.h>
#include "strnum.h"
#include <time.h>

unsigned int* string_to_uint(char string[]){
    char* string_pointer;
    for(string_pointer = string; *string_pointer; ++string_pointer);
    int str_len = string_pointer - string;
    if (string[0] != '-' && str_len > 9){
        printf("Error! Input is too long to convert\n");
        return 0;
    }
    int *num_array = malloc(sizeof(int) * str_len);
    if (!num_array){
        free(num_array);
        printf("Error: Memory allocation failed");
        return 0;
    }
    
    int counter = 0;
    for ( char* character = string; *character; ++character){
        if (*character >='0' && *character <= '9'){
            num_array[counter] = *character - 48;
        }
        else {
            num_array[counter] = -1;
        }
        
        if (num_array[counter] == -1){
            printf("Error: Non-number detected\n");
            free(num_array);
            return 0;
        }
        counter++;
    }
    int iterator = 0;
    unsigned int number = 0;
    for (int i = str_len -1 ; i >= 0; i--){
        number += power_10(num_array[iterator], i); 
        iterator++;
    }
    unsigned int* number_ptr = &number;
    free(num_array);
    return number_ptr;
}
