#include "my_string.h"
void strip_string(char* restrict string, char* restrict delimiters){
	int counter = 0;
	for (char* letter = string; *letter; ++letter){
		for (char* character = delimiters; *character; ++character){
			if (*letter == *character){
				goto bypass;
			}
		}
		string[counter] = *letter;
		counter++;
bypass:
	}
	string[counter] = '\0';
}

