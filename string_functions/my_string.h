#ifndef MY_STRING_H
#define MY_STRING_H
void new_strncpy(char* destination, char* source, const unsigned int buffer_length);
int new_strlen(char* string);
void safe_gets(char* destination, unsigned buffer_size);
char* new_strstr(char* string, char* substring);
int new_strcmp(const char* string, const char* comp_string);
int new_strncmp(const char* string, const char* comp_string, const int len);
void strip_string(char* string, char* delimiters);
void upper(char* string);
void lower(char* string);
char* new_strtok(char* string, char* delimiters);
unsigned immut_strtok(char* string, char* delimiters, char** pointers);
char* cat_string(char* storage_string, const char* to_add);
char* catn_string(char* storage_string, const char* to_add, const unsigned len);
#endif
