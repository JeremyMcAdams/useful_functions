#include <stdio.h>
#include <stdlib.h>
#include "strnum.h"

int string_to_int(char string[]){
    char* string_pointer;
    for(string_pointer = string; *string_pointer; ++string_pointer);
    int str_len = string_pointer - string;
    if (string[0] != '-' && str_len > 9){
        printf("Error! Input is too long to convert\n");
        return -1;
    }
    else if (string[0] == '-' && str_len > 10){
        printf("Error! Input is too long to convert\n");
        return -1;
    }
    int buffer_size = str_len;
    int *num_array = malloc(sizeof(int) * str_len);
    if (!num_array){
        free(num_array);
        printf("Errno -1: Memory allocation failed");
        return -1;
    }
    int sign = 0;
    int i = 0;
    for (char* character = string; *character; ++character){
        if (i == buffer_size){
            buffer_size += 1;
            num_array = realloc(num_array, buffer_size * sizeof(int));
            if (!num_array){
                free(num_array);
                printf("Errno -1: Memory reallocation failure\n");
                return -1;
            }
        }
        if (*character == '-'){
            sign = 1;
        }
        else if (*character >='0' && *character <= '9'){
            num_array[i] = *character - 48;
        }
        else {
            num_array[i] = -1;
        }
        
        if (num_array[i] == -1){
            printf("Errno -2: Non-number dectected\n");
            free(num_array);
            return -2;
        }
        i++;
    }
    int iter = 0;
    int number = 0;
    for (int i = buffer_size -1 ; i >= 0; i--){
        number += power_10(num_array[iter], i); 
        iter++;
    }
    if (sign){
        number *= -1;
    }
    free(num_array);
    return number;
}
