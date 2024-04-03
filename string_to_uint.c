#include <stdio.h>
#include <stdlib.h>
#include "strnum.h"
#include <time.h>
long int power_10(const int num, const int exponent){
    const int base = 10;
    long int number = 1;
    for (int i = 0; i < exponent; i++){
        number *= base;
    }
    number *= num;
    return number;
}

unsigned int string_to_uint(char string[]){
    char* string_pointer;
    for(string_pointer = string; *string_pointer; ++string_pointer);
    int str_len = string_pointer - string;
    if (string[0] != '-' && str_len > 9){
        printf("Error! Input is too long to convert\n");
        return -1;
    }
    int *num_array = malloc(sizeof(int) * str_len);
    if (!num_array){
        free(num_array);
        printf("Errno -1: Memory allocation failed");
        return -1;
    }
    
    int counter = 0;
    for (char* character = string; *character; ++character){
        if (*character >='0' && *character <= '9'){
            num_array[counter] = *character - 48;
        }
        else {
            num_array[counter] = -1;
        }
        
        if (num_array[counter] == -1){
            printf("Errno -2: Non-number dectected\n");
            free(num_array);
            return -2;
        }
        counter++;
    }
    int iter = 0;
    int number = 0;
    for (int i = str_len -1 ; i >= 0; i--){
        number += power_10(num_array[iter], i); 
        iter++;
    }

    free(num_array);
    return number;
}

int main(){
    char string[] = "12354329";
    clock_t start, stop;
    start = clock();
    int number = string_to_uint(string);
    stop = clock();
    printf("%d\n", number);
    printf("Function took %lf sec\n", (stop - start)/ (double) CLOCKS_PER_SEC);
    return 0;
}
