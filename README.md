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

Note: As of this time I have observed some abnormal behavior using this in my advent of code Day1_part2.c program. Occasionally ghost characters appear but also not in the buffer it seems. I cannot replicate this with normal string tests. I am still working on piecing together why this occurs. Keep this in mind if you want to play with this code.

## void strip_string(char* string, char* delimiters);

### Takes a given character array and removes all characters in the delimiters argument

Example:
>#include <stdio.h>  
>#include "my_string.h"  
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "Hello there! This is my sample string.";  
>&nbsp;&nbsp;&nbsp;&nbsp;char delimiters[] = "!. ";  
>&nbsp;&nbsp;&nbsp;&nbsp;strip_string(string, delimiters);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("%s\n", string);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>  }

Output:
>HellothereThisismysamplestring



# type_conversion

### strnum.h

A header file containing the type conversion functions
Update: All conversion functions have a changed return type. They now return pointers to the calculated values to allow for better error handling.

### Makefile
Included in this folder is a gnu makefile that converts all the functions in strnum.h to a single .o file that can be linked to any program you want.

# Function Documentation:

## string_to_int(char* string);

### Takes a string of number characters and converts them to an int

Returns an int or...  
Returns -2 with an error warning if a non-number character has been detected. (Negative numbers are accepted)

Example:

>#include <stdio.h>
>#include "strnum.h"
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "-12345";  
>&nbsp;&nbsp;&nbsp;&nbsp;int* number = string_to_int(string);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("Number you entered: %d\n", *number);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>}


Output:
>Number you entered: -12345


## string_to_uint(char* string);

### Takes a string of number characters and converts them to a unsigned int

Returns a pointer to an unsigned int or 0 if an error occurs.

>#include <stdio.h>
>#include "strnum.h"
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "95682";  
>&nbsp;&nbsp;&nbsp;&nbsp;int* number = string_to_uint(string);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("Number you entered: %d\n", *number);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>}

Output:
>Number you entered: 95682

## string_to_longint(char* string);

### Takes a string of number characters and converts them to a long int
See string_to_int. This function follows the same rules

## string_to_float(char* string);

### Takes a string of number characters and converts them to a float

Returns a float pointer or 0 if an error occurs. (Negative numbers are accepted)

>#include <stdio.h>
>#include "strnum.h"
>int main(){  
>&nbsp;&nbsp;&nbsp;&nbsp;char string[] = "3.1415";  
>&nbsp;&nbsp;&nbsp;&nbsp;float* number = string_to_float(string);  
>&nbsp;&nbsp;&nbsp;&nbsp;printf("Number you entered: %f\n", *number);  
>&nbsp;&nbsp;&nbsp;&nbsp;return 0;  
>}

Output:
>Number you entered: 3.141500

Note: As of right now for an integer to be a valid entry a '.' must be added to the end of the number. 
Example:
>3.  

## string_to_double(char* string);

### Takes a string of number characters and converts them to a double
Returns a double pointer or 0 if an error occurs.
See string to float above. This function follows the same rules
