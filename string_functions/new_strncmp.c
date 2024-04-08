#include "my_string.h"
int new_strncmp(register const char* string, register const char* comp_string, register const int len){
	for (int i = 0; i < len; ++i){
		if (*string != *comp_string){
			return (*string - *comp_string);
		}
		string++;
		comp_string++;
	}
	return 0;
}

