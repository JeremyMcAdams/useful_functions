string_to_num.o: string_to_int.o string_to_uint.o string_to_float.o string_to_double.o string_to_longint.o mult_10.o
	ld -r string_to_int.o string_to_uint.o string_to_float.o string_to_double.o string_to_longint.o mult_10.o -o string_to_num.o

string_to_int.o: string_to_int.c
	gcc -c string_to_int.c
	
string_to_uint.o : string_to_uint.c
	gcc -c string_to_uint.c
	
string_to_float.o : string_to_float.c
	gcc -c string_to_float.c

string_to_double.o : string_to_double.c
	gcc -c string_to_double.c
	
string_to_longint.o : string_to_longint.c
	gcc -c string_to_longint.c
	
mult_10.o : mult_10.c
	gcc -c mult_10.c
	
clean : 
	rm string_to_int.o string_to_uint.o string_to_float.o string_to_double.o string_to_longint.o mult_10.o
	
