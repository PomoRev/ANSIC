# target: requirements
#	recipe

CFLAGS += -ansi -pedantic -Wall

a.out: printloop.o 
	gcc printloop.o -o a.out

printloop.o: printloop.c
	gcc -c $(CFLAGS) printloop.c 

# b.out: printloop.c 
# 	gcc $(CFLAGS) printloop.c -o b.out

clean:
	rm *.o a.out 



