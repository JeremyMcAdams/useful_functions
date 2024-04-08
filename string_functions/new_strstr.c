#include "my_string.h"
char* new_strstr(register char* string, register char* substring){
	register char* sub = substring;
	register char* pointer = 0;
	
	for (; *string; string++){
		if (*string == *substring){
			pointer = string;
		}
		while (*substring == *string){
			substring++;
			string++;
			if (*substring == '\0'){
				return pointer;
			}
		}
		if (*string != *substring){
			substring = sub;
		}
	}
	return 0;
}
