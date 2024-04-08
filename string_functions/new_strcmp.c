#include "my_string.h"
int new_strcmp(register const char* string, register const char* comp_string){
	for (; *string; ++string){
		if (*string != *comp_string){
			return *string - *comp_string;
		}
		comp_string++;
	}
	if (*comp_string != '\0'){
		return *string - *comp_string;
	}
	return 0;
}

