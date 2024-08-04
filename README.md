# Useful Functions Repository

This Repository is meant for me to get a better understanding of C by recreating functions from the C standard library and make new functions that are useful for general purpose through pointer manipulation and return types

# String_Functions:
string_functions is my way to increase methods of string manipulation in C.  
It is also a way for me to better understand strings. Strings are arrays and therefore have pointers and pointers can be manipulated in ways similar to number arrays and it makes no sense to me.  
So that shall change by the end of this.  

## *new* functions:

All functions that begin with *new* are attempts to copy the exact functionality of the default ones given in *string.h*.  

## Non-*new* functions:

Functions without new in the name are ones that I believe may be useful for string manipulation.  
Most of these were created to help me solve advent of code problems.

### my_string.h:

My string.h is a header file that contains all string functions created for your convenience.

### Makefile:

Included in the string_functions repository is a gnu makefile designed to combine all files in string.h into a single .o file output that can be linked with dependent programs. It also includes a clean command to remove all dependent .o files  

# Function Documentation:

## *int new_strlen* (char* string);  

### Finds the length of character array

Takes a char pointer as an argument and iterates through the pointer until the null pointer is found.  
Returns the length of the string minus the null byte.  

Example:


>#include <stdio.h>  
#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "This is a sample string.";  
>&nbsp;&nbsp;&nbsp;&nbsp;int length = new_strlen(string);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("The length of string is %d\n", length);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;   
>}

Output:  
>The length of string is 24

## char* new_strstr* ( char* string,  char* substring);  

### Finds the first occurrence of a given substring

Returns a char pointer to substring if it exists. Otherwise it returns 0.  

Example:

>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "This is a sample string.";  
>&nbsp;&nbsp;&nbsp;&nbsp;char substring1[] = "is";  
>&nbsp;&nbsp;&nbsp;&nbsp;char substring2[] = "string";   
>&nbsp;&nbsp;&nbsp;&nbsp;char substring3[] = "Hello";   
>
>&nbsp;&nbsp;&nbsp;&nbsp;char* pointer1 = new_strstr(string, substring1);  
>&nbsp;&nbsp;&nbsp;&nbsp;char* pointer2 = new_strstr(string, substring2);  
>&nbsp;&nbsp;&nbsp;&nbsp;char* pointer3 = new_strstr(string, substring3); 
>
>&nbsp;&nbsp;&nbsp;&nbsp;printf(" String start: %lu, %s\n substring1: %lu, %s\n substring2: %lu, %s substring3: %lu, %s\n", string, string, pointer1, pointer1, pointer2, pointer2, pointer3, pointer3);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>}

Output:
>&nbsp;String start: 140735752356960, This is a sample string.  
>&nbsp;substring1: 140735752356962, is is a sample string.  
>&nbsp;substring2: 140735752356977, string.  
>&nbsp;substring3: 0, (null)


## int new_strncmp(const char* string, const char* comp_string, const int len);

### Determines if the number of letters in a string are the same as the comparison string.

Returns 0 if the strings match or...  
Returns the integer difference of the ASCII values of the letters that do not match  

Example:
>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "Test";  
>&nbsp;&nbsp;&nbsp;&nbsp;char comp_string[] = "Tested";  
>&nbsp;&nbsp;&nbsp;&nbsp;int comparison1 = new_strncmp(string, comp_string, 4);  
>&nbsp;&nbsp;&nbsp;&nbsp;int comparison2 = new_strncmp(string, comp_string, 6);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("comparison1: %d, comparison2: %d\n", comparison1, comparison2);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>}  

Output:  
>comparison1: 0, comparison2: -101  

## int new_strcmp(const char* string, const char* comp_string);

### Determines if a string up to the length specified is the same as the comparison string

Returns 0 if the string matches or ...  
Returns the integer difference of the ASCII values of the letters that do not match

Example:  

>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "Test";  
>&nbsp;&nbsp;&nbsp;&nbsp;char comp_string[] = "Test";  
>&nbsp;&nbsp;&nbsp;&nbsp;char comp_string2[] = "Tested";  
>&nbsp;&nbsp;&nbsp;&nbsp;int comparison1 = new_strcmp(string, comp_string);  
>&nbsp;&nbsp;&nbsp;&nbsp;int comparison2 = new_strcmp(string, comp_string2);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("comparison1: %d, comparison2: %d\n", comparison1, comparison2);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>}  

Output:
>comparison1: 0, comparison2: -101  

## void safe_gets(char* destination, int buffer_size);
### Takes a user input string and puts it into a designated string buffer with a cutoff at the buffer size to prevent buffer overflow

No return value. Directly acts on the string array provided in the destination argument.

Example:  
>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char buffer[100];  
>&nbsp;&nbsp;&nbsp;&nbsp;safe_gets(buffer, 100);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("%s", buffer);  
>}

Output:

>Output varies by input

## void new_strncpy(char* destination, char* source, int buffer_length);
 

### Copies the contents of 1 character array and puts it into another character array up to the size given in the buffer_length argument

No return. Function acts directly on destination character array.  

Example:
>#include <stdio.h>  
>#include "my_string.h" 
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char source[] = "This is a sample string."  
>&nbsp;&nbsp;&nbsp;&nbsp;char destination[20];  
>&nbsp;&nbsp;&nbsp;&nbsp;new_strncpy(destination, source, 20);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("%s", destination);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;
>} 

Output:
>This is a sample str

## void strip_string(char* string, char* delimiters);

### Takes a given character array and removes all characters in the delimiters argument

Example:
>#include <stdio.h>  
>#include "my_string.h"  
>#include <stdbool.h>
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "Hello there! This is my sample string.";  
>&nbsp;&nbsp;&nbsp;&nbsp;char delimiters[] = "!. ";  
>&nbsp;&nbsp;&nbsp;&nbsp;strip_string(string, delimiters);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("%s\n", string);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>  }

Output:
>HellothereThisismysamplestring

## char* new_strtok(char* string, char* delimiters);  

### Breaks a given character array into component parts based on given delimiters and returns the pointer to the beginning of the last fragment

>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "Hello there! This is my sample string.";  
>&nbsp;&nbsp;&nbsp;&nbsp;char delimiters[] = "!. ";  
>&nbsp;&nbsp;&nbsp;&nbsp;char token_buffer[10];  
>&nbsp;&nbsp;&nbsp;&nbsp;char* fragment = new_strtok(string, delimiters);  
>&nbsp;&nbsp;&nbsp;&nbsp;while(1) {  
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (fragment == NULL) { break;}  
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new_strncpy(token_buffer, fragment, sizeof(token_buffer));  
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;printf("%s\n", token_buffer);  
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fragment = new_strtok(string, delimiters);  
>&nbsp;&nbsp;&nbsp;&nbsp;}  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
}  

Output:  
>Hello  
>there  
>This  
>is  
>my  
>sample  
>string  

## unsigned test_strtok(char* string, char* delimiters, char** pointers);
### Takes a given character array and returns the length of a given token. This version preserves the parent string.

Example:
>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "Hello there! This is my sample string.";  
>&nbsp;&nbsp;&nbsp;&nbsp;char delimiters[] = "!. ";  
>&nbsp;&nbsp;&nbsp;&nbsp;char* pointers[2] = {0}; //it is important to initialize the pointers to 0 for the function to work.  
>&nbsp;&nbsp;&nbsp;&nbsp;char token_buffer[10];  
>&nbsp;&nbsp;&nbsp;&nbsp;unsigned token_len = test_strtok(string, delimiters, pointers);  
>&nbsp;&nbsp;&nbsp;&nbsp;while(pointers[0] != 0) {  
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;new_strncpy(token_buffer, pointers[0], token_len);  
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;printf("%s\n", token_buffer);  
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;token_len = test_strtok(string, delimiters, pointers);  
>&nbsp;&nbsp;&nbsp;&nbsp;}  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>  }  

Output:  
>Hello  
>there  
>This  
>is  
>my  
>sample  
>string  

## char* cat_string(char* storage_string, char* to_add);
### Takes a target string and appends it to the end of a string buffer and returns a pointer to the last end point.

Example: 
>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[100] = "This is my sample string.";  
>&nbsp;&nbsp;&nbsp;&nbsp;char* last_loc = cat_string(string, " Here is an appended part. ");  
>&nbsp;&nbsp;&nbsp;&nbsp;last_loc = cat_string(last_loc, "And here is even more stuff");  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("%s\n", string);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>}

Output:
>This is my sample string. Here is an appended part. And here is even more stuff

Use of last_loc (last location) speeds up function by allowing the program to skip walking the string buffer to find the null byte.

## char* catn_string(char* storage_string, char* to_add, unsigned len);

### Takes target string and appends the length specified to the end of a string buffer and returns a pointer to the last end point.

Example:
>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[100] = "This is my sample string.";  
>&nbsp;&nbsp;&nbsp;&nbsp;char* last_loc = cat_string(string, " Here is an appended part. ", 20);  
>&nbsp;&nbsp;&nbsp;&nbsp;last_loc = cat_string(last_loc, "And here is even more stuff", 20);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("%s\n", string);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>}

Output:
>This is my sample string. Here is an appendedAnd here is even mor

# type_conversion

### strnum.h

A header file containing the type conversion functions.  


### Makefile
Included in this folder is a gnu makefile that converts all the functions in strnum.h to a single .o file that can be linked to any program you want.

# Function Documentation:

Being reworked