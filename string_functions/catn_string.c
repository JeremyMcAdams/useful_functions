#include "my_string.h"
char* catn_string(char* restrict storage_string, const char* restrict to_add, const unsigned len) {
    unsigned iterations = 0;
    if (*storage_string != '\0') {
        for (; *storage_string; ++storage_string);
    }
    for (; *to_add; ++to_add) {
        if (iterations == len) { break;}
        *storage_string = *to_add;
        storage_string += 1;
        iterations += 1;
    }
    *storage_string = '\0';
    return storage_string;
        
}
