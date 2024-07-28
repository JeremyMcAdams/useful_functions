#include "my_string.h"
#include <stdint.h>
unsigned test_strtok(register char* string, register char* delimiters, register char** pointers) {
        if (pointers[1] != 0 && *(pointers[1])  == '\0') {
                pointers[0] = 0;
                pointers[1] = 0;
                return 0;
        }
        else if (pointers[0] != 0) {
                pointers[0] = pointers[1];
        }
        else if (pointers[0] == 0) {
                pointers[0] = string;
        }

        string = pointers[0];
        uint8_t delimiter_found;
        while(1) {
            delimiter_found = 0;
                for (char* character = delimiters; *character; character++) {
                        if (*string == *character) {
                                delimiter_found = 1;
                                break;
                        }
                }
                if (delimiter_found == 0) {
                        break;
                }
                string += 1;
        }
        if (*string == '\0') {
                pointers[0] = 0;
                pointers[1] = 0;
                return 0;
        }
        pointers[0] = string;

        while(1) {
               for (char* character = delimiters; *character; character++) {
                        if (*string == *character) {
                                pointers[1] = string; 
                                return pointers[1] - pointers[0];
                        }
                        else if (*string == '\0') {
                                pointers[1] = string;
                                // the + 1 for this value exists to avoid a off by 1 error that ends up causing the last element to break 
                                return (pointers[1] - pointers[0]) + 1;
                        }
               }
               string += 1;
        }
        return 0; //never reached
}
