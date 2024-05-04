#ifndef MY_STRING_H
#define MY_STRING_H
void new_strncpy(register char* destination, register char* source, register const unsigned int buffer_length);
int new_strlen(register char* string);
void safe_gets(register char* destination, register int buffer_size);
char* new_strstr(register char* string, register char* substring);
int new_strcmp(register const char* string, register const char* comp_string);
int new_strncmp(register const char* string, register const char* comp_string, register const int len);
void strip_string(register char* string, register char* delimiters);
void upper(register char* string);
void lower(register char* string);
char* new_strtok(register char* string, register char* delimiters);
#endif
