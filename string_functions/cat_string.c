#include "my_string.h"
char* cat_string(char* storage_string, char* to_add) {
    if (*storage_string != '\0') {
        for (; *storage_string; ++storage_string);
    }
        for (; *to_add; ++to_add) {
            *storage_string = *to_add;
            storage_string += 1;
        }
        *storage_string = '\0';
        return storage_string;
}
