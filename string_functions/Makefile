string_funcs: my_strncpy.o my_strlen.o my_safe_gets.o
	ld -r test_str.o my_strncpy.o my_strlen.o my_safe_gets.o -o string_funcs.o


new_strncpy.o : my_strncpy.c
	gcc -c my_strncpy.c
new_strlen.o : my_strlen.c 
	gcc -c my_strlen.c
safe_gets.o : my_safe_gets.c
	gcc -c my_safe_gets.c
clean : 
	rm test_str.o my_strncpy.o my_strlen.o my_safe_gets.o
