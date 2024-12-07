#include "my_string.h"
void clear_trailing(char* restrict line, const char delimiter) {
    char* pointer = 0;
    for (pointer = line; *pointer; ++pointer);
    unsigned len = (pointer - line) - 1;
    while (line[len] == delimiter) {
        line[len] = '\0';
        if (len == 0) { break;} 
        len -= 1;
    }
}
