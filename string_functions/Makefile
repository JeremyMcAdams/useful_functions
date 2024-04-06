string_funcs: test_str.o my_strncpy.o my_strlen.o my_safe_gets.o
	ld -r test_str.o my_strncpy.o my_strlen.o my_safe_gets.o -o string_funcs.o

test_str.o : test_str.c 
	gcc -c test_str.c 
my_strncpy.o : my_strncpy.c
	gcc -c my_strncpy.c
my_strlen.o : my_strlen.c 
	gcc -c my_strlen.c
my_safe_gets.o : my_safe_gets.c
	gcc -c my_safe_gets.c
clean : 
	rm test_str.o my_strncpy.o my_strlen.o my_safe_gets.o
