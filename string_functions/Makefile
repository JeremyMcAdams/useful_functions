string_funcs: new_strncpy.o new_strlen.o safe_gets.o new_strstr.o new_strncmp.o new_strcmp.o strip_string.o upper.o lower.o new_strtok.o
	ld -r new_strncpy.o new_strlen.o safe_gets.o new_strstr.o new_strncmp.o new_strcmp.o strip_string.o upper.o lower.o new_strtok.o -o string_funcs.o

new_strncpy.o : new_strncpy.c
	gcc -c new_strncpy.c
new_strlen.o : new_strlen.c 
	gcc -c new_strlen.c
safe_gets.o : safe_gets.c
	gcc -c safe_gets.c
new_strstr.o : new_strstr.c
	gcc -c new_strstr.c
new_strncmp.o : new_strncmp.c
	gcc -c new_strncmp.c
new_strcmp.o : new_strcmp.c
	gcc -c new_strcmp.c
strip_string.o : strip_string.c
	gcc -c strip_string.c
upper.o: upper.c
	gcc -c upper.c
lower.o: lower.c
	gcc -c lower.c
new_strtok.o: new_strtok.c
	gcc -c new_strtok.c

clean : 
	rm new_strncpy.o new_strlen.o safe_gets.o new_strstr.o new_strncmp.o new_strcmp.o lower.o upper.o strip_string.o new_strtok.o
