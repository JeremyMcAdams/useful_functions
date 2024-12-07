#include "my_string.h"
int new_strncmp(register const char* restrict string, register const char* restrict comp_string, const int len){
	for (register int i = 0; i < len; ++i){
		if (*string != *comp_string){
			return (*string - *comp_string);
		}
		string++;
		comp_string++;
	}
	return 0;
}

