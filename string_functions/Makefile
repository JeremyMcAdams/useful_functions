string_funcs: new_strncpy.o new_strlen.o safe_gets.o new_strstr.o new_strncmp.o new_strcmp.o strip_string.o upper.o lower.o new_strtok.o immut_strtok.o clear_trailing.o cat_string.o catn_string.o
	ld -r new_strncpy.o new_strlen.o safe_gets.o new_strstr.o new_strncmp.o new_strcmp.o strip_string.o upper.o lower.o new_strtok.o immut_strtok.o clear_trailing.o cat_string.o catn_string.o\
		-o string_funcs.o
	

new_strncpy.o : new_strncpy.c
	cc -c new_strncpy.c
new_strlen.o : new_strlen.c 
	cc -c new_strlen.c
safe_gets.o : safe_gets.c
	cc -c safe_gets.c
new_strstr.o : new_strstr.c
	cc -c new_strstr.c
new_strncmp.o : new_strncmp.c
	cc -c new_strncmp.c
new_strcmp.o : new_strcmp.c
	cc -c new_strcmp.c
strip_string.o : strip_string.c
	cc -c strip_string.c
upper.o: upper.c
	cc -c upper.c
lower.o: lower.c
	cc -c lower.c
new_strtok.o: new_strtok.c
	cc -c new_strtok.c
immut_strtok.o: immut_strtok.c
	cc -c immut_strtok.c
clear_trailing.o: clear_trailing.c
	cc -c clear_trailing.c
cat_string.o: cat_string.c
	cc -c cat_string.c
catn_string.o: catn_string.c
	cc -c catn_string.c
clean : 
	rm new_strncpy.o new_strlen.o safe_gets.o new_strstr.o new_strncmp.o new_strcmp.o lower.o upper.o strip_string.o new_strtok.o immut_strtok.o clear_trailing.o cat_string.o catn_string.o
