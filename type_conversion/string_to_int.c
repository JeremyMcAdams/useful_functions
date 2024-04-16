#include <stdio.h>
#include <stdlib.h>
#include "strnum.h"

int* string_to_int(char string[]){
    char* string_pointer;
    for(string_pointer = string; *string_pointer; ++string_pointer);
    int str_len = string_pointer - string;
    
    if (string[0] != '-' && str_len > 9){
        printf("Error! Input is too long to convert\n");
        return 0;
    }
    else if (string[0] == '-' && str_len > 10){
        printf("Error! Input is too long to convert\n");
        return 0;
    }
    
    int *num_array = malloc(sizeof(int) * str_len);
    if (!num_array){
        free(num_array);
        printf("Error: Memory allocation failed");
        return 0;
    }
    int sign = 0;
    int counter = 0;
    for (char* character = string; *character; ++character){
        if (*character == '-'){
            sign = 1;
        }
        else if (*character >='0' && *character <= '9'){
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
    int number;
    number = 0;
    for (int i = str_len -1 ; i >= 0; i--){
        number += power_10(num_array[iterator], i); 
        iterator++;
    }
    if (sign){
        number *= -1;
    }
    free(num_array);
    int* number_ptr = &number;
    return number_ptr;
}

