#include "my_string.h"
int new_strncmp(const char* string, const char* comp_string, const int len){
	for (int i = 0; i < len; ++i){
		if (*string != *comp_string){
			return (*string - *comp_string);
		}
		string++;
		comp_string++;
	}
	return 0;
}

