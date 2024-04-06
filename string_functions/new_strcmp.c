#include "my_string.h"
int new_strcmp(const char* string, const char* comp_string){
	for (; *string; ++string){
		if (*string != *comp_string){
			return *string - *comp_string;
		}
		string++;
		comp_string++;
	}
	return 0;
}

