#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strnum.h"

float string_to_float(char string[]){
    //start array allocation
    char* string_pointer;
    char* decimal_pointer;
    int int_buffer_size;
    for (string_pointer = string; *string_pointer; ++string_pointer){
        if (*string_pointer == '.'){
            int_buffer_size = string_pointer - string;
            decimal_pointer = string_pointer + 1;
        }
    }
    int float_buffer_size = string_pointer - decimal_pointer;
    int float_on = false;
    int sign = false;
    register float *float_array = malloc(sizeof(float) * float_buffer_size);
    register int *num_array = malloc(sizeof(int) * int_buffer_size);
    if (!float_array || !num_array){
        free(float_array);
        free(num_array);
        printf("ErrNo -1: Memory allocation failed\n");
        return -1;
    }
    
    //start counters
    int float_counter = 0; 
    int int_counter = 0;
    
    for (char* character = string; *character; ++character){

        if (float_on && (*character >= '0' && *character <= '9')){
            float_array[float_counter] = *character - 48;
            float_counter++;
        }
        else if (float_on && !(*character >= '0' && *character <= '9')){
            float_array[float_counter] = -1;
        }
        
        if (!float_on){
            if (*character >= '0' && *character <= '9'){
                num_array[int_counter] = *character - 48;
            }
            else if (*character == '-'){
                sign = 1;
            }   
            else if (*character == '.'){
                float_on = 1;
            }
            else {
                num_array[int_counter] = -1;
            }
            int_counter++;
        }
        
        if (num_array[int_counter] == -1 || float_array[float_counter] == -1){
            printf("Errno -2: Non-number dectected\n");
            free(num_array);
            free(float_array);
            return -2;
        }
    }
    
    int counter = 0;
    float number = 0;
    for (int i = int_buffer_size - 1; i >= 0; i--){
        number += power_10(num_array[counter], i);
        counter++;
    }
    for (int  i = 0; i < float_buffer_size; i++){
        number += power_neg10(float_array[i], i + 1);
    }
    if (sign){
        number *= -1;
    }
    free(num_array);
    free(float_array);
    return number;
}

