#ifndef MY_STRING_H
#define MY_STRING_H
void new_strncpy(char* destination, char* source, const int buffer_length);
int new_strlen(char* string);
void safe_gets(char* destination, int buffer_size);
char* new_strstr(char* string, char* substring);
int new_strcmp(const char* string, const char* comp_string);
int new_strncmp(const char* string, const char* comp_string, const int len);
#endif
